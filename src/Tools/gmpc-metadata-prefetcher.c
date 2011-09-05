/* gmpc-metadata-prefetcher.c generated by valac 0.12.0, the Vala compiler
 * generated from gmpc-metadata-prefetcher.vala, do not modify */

/* Gnome Music Player Client (GMPC)
 * Copyright (C) 2004-2011 Qball Cow <qball@gmpclient.org>
 * Project homepage: http://gmpclient.org/
 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gtktransition.h>
#include "gmpc-extras.h"
#include <stdlib.h>
#include <string.h>
#include <libmpd/libmpd.h>
#include <libmpd/libmpdclient.h>
#include <misc.h>
#include <metadata.h>
#include <main.h>
#include <gmpc-meta-watcher.h>

#define _meta_data_free0(var) ((var == NULL) ? NULL : (var = (meta_data_free (var), NULL)))
#define _mpd_freeSong0(var) ((var == NULL) ? NULL : (var = (mpd_freeSong (var), NULL)))


static gpointer gmpc_tools_metadata_prefetcher_parent_class = NULL;

#define use_transition_mpf TRUE
enum  {
	GMPC_TOOLS_METADATA_PREFETCHER_DUMMY_PROPERTY
};
static gint* gmpc_tools_metadata_prefetcher_real_get_version (GmpcPluginBase* base, int* result_length1);
static const gchar* gmpc_tools_metadata_prefetcher_real_get_name (GmpcPluginBase* base);
static void gmpc_tools_metadata_prefetcher_status_changed (GmpcToolsMetadataPrefetcher* self, GmpcConnection* conn, MpdObj* server, ChangedStatusType what);
static GObject * gmpc_tools_metadata_prefetcher_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void _gmpc_tools_metadata_prefetcher_status_changed_gmpc_connection_status_changed (GmpcConnection* _sender, MpdObj* mi, ChangedStatusType what, gpointer self);

static const gint GMPC_TOOLS_METADATA_PREFETCHER_version[3] = {0, 0, 2};

static gint* gmpc_tools_metadata_prefetcher_real_get_version (GmpcPluginBase* base, int* result_length1) {
	GmpcToolsMetadataPrefetcher * self;
	gint* result = NULL;
	gint* _tmp0_;
	self = (GmpcToolsMetadataPrefetcher*) base;
	_tmp0_ = GMPC_TOOLS_METADATA_PREFETCHER_version;
	*result_length1 = G_N_ELEMENTS (GMPC_TOOLS_METADATA_PREFETCHER_version);
	result = _tmp0_;
	return result;
}


static const gchar* gmpc_tools_metadata_prefetcher_real_get_name (GmpcPluginBase* base) {
	GmpcToolsMetadataPrefetcher * self;
	const gchar* result = NULL;
	self = (GmpcToolsMetadataPrefetcher*) base;
	result = "Metadata pre-fetcher";
	return result;
}


static void gmpc_tools_metadata_prefetcher_status_changed (GmpcToolsMetadataPrefetcher* self, GmpcConnection* conn, MpdObj* server, ChangedStatusType what) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (conn != NULL);
	g_return_if_fail (server != NULL);
	_tmp0_ = gmpc_plugin_base_get_enabled ((GmpcPluginBase*) self);
	if (!_tmp0_) {
		return;
	}
	if ((what & MPD_CST_NEXTSONG) == MPD_CST_NEXTSONG) {
		gint _tmp1_;
		gint next_song_id;
		_tmp1_ = mpd_player_get_next_song_id (server);
		next_song_id = _tmp1_;
		if (next_song_id > 0) {
			mpd_Song* _tmp2_ = NULL;
			mpd_Song* song;
			_tmp2_ = mpd_playlist_get_song (server, next_song_id);
			song = _tmp2_;
			if (song != NULL) {
				MetaData* met;
				MetaDataResult md_result = 0;
				MetaData* _tmp3_ = NULL;
				MetaDataResult _tmp4_;
				MetaData* _tmp5_ = NULL;
				MetaDataResult _tmp6_;
				met = NULL;
				g_log ("MetadataPrefetcher", G_LOG_LEVEL_DEBUG, "gmpc-metadata-prefetcher.vala:58: Pre-fetching %s", song->file);
				_tmp4_ = gmpc_meta_watcher_get_meta_path (gmw, song, META_ARTIST_ART, &_tmp3_);
				_meta_data_free0 (met);
				met = _tmp3_;
				md_result = _tmp4_;
				_tmp6_ = gmpc_meta_watcher_get_meta_path (gmw, song, META_ALBUM_ART, &_tmp5_);
				_meta_data_free0 (met);
				met = _tmp5_;
				md_result = _tmp6_;
				_meta_data_free0 (met);
			}
			_mpd_freeSong0 (song);
		}
	}
}


GmpcToolsMetadataPrefetcher* gmpc_tools_metadata_prefetcher_construct (GType object_type) {
	GmpcToolsMetadataPrefetcher * self = NULL;
	self = (GmpcToolsMetadataPrefetcher*) gmpc_plugin_base_construct (object_type);
	return self;
}


GmpcToolsMetadataPrefetcher* gmpc_tools_metadata_prefetcher_new (void) {
	return gmpc_tools_metadata_prefetcher_construct (GMPC_TOOLS_TYPE_METADATA_PREFETCHER);
}


static void _gmpc_tools_metadata_prefetcher_status_changed_gmpc_connection_status_changed (GmpcConnection* _sender, MpdObj* mi, ChangedStatusType what, gpointer self) {
	gmpc_tools_metadata_prefetcher_status_changed (self, _sender, mi, what);
}


static GObject * gmpc_tools_metadata_prefetcher_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	GmpcToolsMetadataPrefetcher * self;
	parent_class = G_OBJECT_CLASS (gmpc_tools_metadata_prefetcher_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = GMPC_TOOLS_METADATA_PREFETCHER (obj);
	((GmpcPluginBase*) self)->plugin_type = 8 + 4;
	g_signal_connect_object (gmpcconn, "status-changed", (GCallback) _gmpc_tools_metadata_prefetcher_status_changed_gmpc_connection_status_changed, self, 0);
	return obj;
}


static void gmpc_tools_metadata_prefetcher_class_init (GmpcToolsMetadataPrefetcherClass * klass) {
	gmpc_tools_metadata_prefetcher_parent_class = g_type_class_peek_parent (klass);
	GMPC_PLUGIN_BASE_CLASS (klass)->get_version = gmpc_tools_metadata_prefetcher_real_get_version;
	GMPC_PLUGIN_BASE_CLASS (klass)->get_name = gmpc_tools_metadata_prefetcher_real_get_name;
	G_OBJECT_CLASS (klass)->constructor = gmpc_tools_metadata_prefetcher_constructor;
}


static void gmpc_tools_metadata_prefetcher_instance_init (GmpcToolsMetadataPrefetcher * self) {
}


GType gmpc_tools_metadata_prefetcher_get_type (void) {
	static volatile gsize gmpc_tools_metadata_prefetcher_type_id__volatile = 0;
	if (g_once_init_enter (&gmpc_tools_metadata_prefetcher_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GmpcToolsMetadataPrefetcherClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gmpc_tools_metadata_prefetcher_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GmpcToolsMetadataPrefetcher), 0, (GInstanceInitFunc) gmpc_tools_metadata_prefetcher_instance_init, NULL };
		GType gmpc_tools_metadata_prefetcher_type_id;
		gmpc_tools_metadata_prefetcher_type_id = g_type_register_static (GMPC_PLUGIN_TYPE_BASE, "GmpcToolsMetadataPrefetcher", &g_define_type_info, 0);
		g_once_init_leave (&gmpc_tools_metadata_prefetcher_type_id__volatile, gmpc_tools_metadata_prefetcher_type_id);
	}
	return gmpc_tools_metadata_prefetcher_type_id__volatile;
}


