/* HTBackdrops.c generated by valac 0.12.0, the Vala compiler
 * generated from HTBackdrops.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <config.h>
#include "gmpc-extras.h"
#include <plugin.h>
#include <config1.h>
#include <libmpd/libmpdclient.h>
#include <libmpd/libmpd.h>
#include <misc.h>
#include <metadata.h>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <gmpc_easy_download.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _meta_data_free0(var) ((var == NULL) ? NULL : (var = (meta_data_free (var), NULL)))
typedef struct _GmpcProviderHTBackdropsProp GmpcProviderHTBackdropsProp;
#define __g_list_free__meta_data_free0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__meta_data_free0_ (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _GmpcProviderHTBackdropsProp {
	GmpcProviderHTBackdrops* this;
	GmpcPluginMetaDataCallback callback;
	gpointer callback_target;
	GDestroyNotify callback_target_destroy_notify;
};


static gpointer gmpc_provider_ht_backdrops_parent_class = NULL;
static GmpcPluginMetaDataIfaceIface* gmpc_provider_ht_backdrops_gmpc_plugin_meta_data_iface_parent_iface = NULL;

#define use_transition_ppbd TRUE
#define some_unique_name_ppbd VERSION
#define log_domain_ppbd "Gmpc.Provider.HTBackdrops"
enum  {
	GMPC_PROVIDER_HT_BACKDROPS_DUMMY_PROPERTY
};
#define GMPC_PROVIDER_HT_BACKDROPS_query "http://htbackdrops.com/api/%s/searchXML?keywords=%s&default_operator=a" \
"nd&fields=title"
#define GMPC_PROVIDER_HT_BACKDROPS_download_url "http://htbackdrops.com/api/%s/download/%s/fullsize"
#define GMPC_PROVIDER_HT_BACKDROPS_thumbnail_url "http://htbackdrops.com/api/%s/download/%s/thumbnail"
#define GMPC_PROVIDER_HT_BACKDROPS_api_key "b3085ed18168f083aa69179b3364c9d8"
static gint* gmpc_provider_ht_backdrops_real_get_version (GmpcPluginBase* base, int* result_length1);
static const gchar* gmpc_provider_ht_backdrops_real_get_name (GmpcPluginBase* base);
static void gmpc_provider_ht_backdrops_real_set_priority (GmpcPluginMetaDataIface* base, gint priority);
static gint gmpc_provider_ht_backdrops_real_get_priority (GmpcPluginMetaDataIface* base);
static void gmpc_provider_ht_backdrops_real_get_metadata (GmpcPluginMetaDataIface* base, const mpd_Song* song, MetaDataType type, GmpcPluginMetaDataCallback callback, void* callback_target);
static void gmpc_provider_ht_backdrops_get_artist_art (GmpcProviderHTBackdrops* self, const mpd_Song* song, GmpcPluginMetaDataCallback callback, void* callback_target);
static void gmpc_provider_ht_backdrops_add_image (GmpcProviderHTBackdrops* self, GList** list, xmlNode* image);
static void gmpc_provider_ht_backdrops_parse_data (GmpcProviderHTBackdrops* self, GList** list, guchar* data, int data_length1);
static void gmpc_provider_ht_backdrops_handle_download (GmpcProviderHTBackdrops* self, const GEADAsyncHandler* handle, GEADStatus status, void* d);
static void gmpc_provider_ht_backdrops_prop_free (GmpcProviderHTBackdropsProp* self);
static guchar* _vala_array_dup1 (guchar* self, int length);
static void _meta_data_free0_ (gpointer var);
static void _g_list_free__meta_data_free0_ (GList* self);
static GmpcProviderHTBackdropsProp* gmpc_provider_ht_backdrops_prop_new (void);
static GmpcProviderHTBackdropsProp* gmpc_provider_ht_backdrops_prop_new (void);
static void _gmpc_provider_ht_backdrops_handle_download_gmpc_async_download_callback_vala (const GEADAsyncHandler* handle, GEADStatus status, void* p, gpointer self);
static GObject * gmpc_provider_ht_backdrops_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void gmpc_provider_ht_backdrops_prop_instance_init (GmpcProviderHTBackdropsProp * self);

static const gint GMPC_PROVIDER_HT_BACKDROPS_version[3] = {0, 0, 2};

static gint* gmpc_provider_ht_backdrops_real_get_version (GmpcPluginBase* base, int* result_length1) {
	GmpcProviderHTBackdrops * self;
	gint* result = NULL;
	gint* _tmp0_;
	self = (GmpcProviderHTBackdrops*) base;
	_tmp0_ = GMPC_PROVIDER_HT_BACKDROPS_version;
	*result_length1 = G_N_ELEMENTS (GMPC_PROVIDER_HT_BACKDROPS_version);
	result = _tmp0_;
	return result;
}


static const gchar* gmpc_provider_ht_backdrops_real_get_name (GmpcPluginBase* base) {
	GmpcProviderHTBackdrops * self;
	const gchar* result = NULL;
	self = (GmpcProviderHTBackdrops*) base;
	result = "Home Theater Backdrops";
	return result;
}


static void gmpc_provider_ht_backdrops_real_set_priority (GmpcPluginMetaDataIface* base, gint priority) {
	GmpcProviderHTBackdrops * self;
	const gchar* _tmp0_ = NULL;
	self = (GmpcProviderHTBackdrops*) base;
	_tmp0_ = gmpc_plugin_base_get_name ((GmpcPluginBase*) self);
	cfg_set_single_value_as_int (config, _tmp0_, "priority", priority);
}


static gint gmpc_provider_ht_backdrops_real_get_priority (GmpcPluginMetaDataIface* base) {
	GmpcProviderHTBackdrops * self;
	gint result = 0;
	const gchar* _tmp0_ = NULL;
	gint _tmp1_;
	self = (GmpcProviderHTBackdrops*) base;
	_tmp0_ = gmpc_plugin_base_get_name ((GmpcPluginBase*) self);
	_tmp1_ = cfg_get_single_value_as_int_with_default (config, _tmp0_, "priority", 0);
	result = _tmp1_;
	return result;
}


static void gmpc_provider_ht_backdrops_real_get_metadata (GmpcPluginMetaDataIface* base, const mpd_Song* song, MetaDataType type, GmpcPluginMetaDataCallback callback, void* callback_target) {
	GmpcProviderHTBackdrops * self;
	gboolean _tmp0_ = FALSE;
	self = (GmpcProviderHTBackdrops*) base;
	g_return_if_fail (song != NULL);
	if (song == NULL) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = song->artist == NULL;
	}
	if (_tmp0_) {
		g_log (log_domain_ppbd, G_LOG_LEVEL_DEBUG, "HTBackdrops.vala:63: Insufficient information. doing nothing");
		callback (NULL, callback_target);
		return;
	}
	switch (type) {
		case META_ARTIST_ART:
		{
			gmpc_provider_ht_backdrops_get_artist_art (self, song, callback, callback_target);
			return;
		}
		default:
		case META_ARTIST_TXT:
		case META_ARTIST_SIMILAR:
		case META_ALBUM_ART:
		case META_ALBUM_TXT:
		case META_SONG_TXT:
		case META_SONG_SIMILAR:
		case META_GENRE_SIMILAR:
		case META_SONG_GUITAR_TAB:
		case META_QUERY_DATA_TYPES:
		case META_QUERY_NO_CACHE:
		{
			break;
		}
	}
	callback (NULL, callback_target);
}


static void gmpc_provider_ht_backdrops_add_image (GmpcProviderHTBackdrops* self, GList** list, xmlNode* image) {
	g_return_if_fail (self != NULL);
	{
		xmlNode* entries;
		entries = image->children;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				if (!_tmp0_) {
					entries = entries->next;
				}
				_tmp0_ = FALSE;
				if (!(entries != NULL)) {
					break;
				}
				if (g_strcmp0 (entries->name, "id") == 0) {
					gchar* _tmp1_ = NULL;
					gchar* _tmp2_;
					gchar* _tmp3_ = NULL;
					gchar* _tmp4_;
					gchar* path;
					gchar* _tmp5_ = NULL;
					gchar* _tmp6_;
					gchar* _tmp7_ = NULL;
					gchar* _tmp8_;
					gchar* thumb_path;
					MetaData* _tmp9_ = NULL;
					MetaData* pitem;
					const gchar* _tmp10_ = NULL;
					MetaData* _tmp11_;
					_tmp1_ = xmlNodeGetContent (entries);
					_tmp2_ = _tmp1_;
					_tmp3_ = g_strdup_printf (GMPC_PROVIDER_HT_BACKDROPS_download_url, GMPC_PROVIDER_HT_BACKDROPS_api_key, _tmp2_);
					_tmp4_ = _tmp3_;
					_g_free0 (_tmp2_);
					path = _tmp4_;
					_tmp5_ = xmlNodeGetContent (entries);
					_tmp6_ = _tmp5_;
					_tmp7_ = g_strdup_printf (GMPC_PROVIDER_HT_BACKDROPS_thumbnail_url, GMPC_PROVIDER_HT_BACKDROPS_api_key, _tmp6_);
					_tmp8_ = _tmp7_;
					_g_free0 (_tmp6_);
					thumb_path = _tmp8_;
					g_log (log_domain_ppbd, G_LOG_LEVEL_DEBUG, "HTBackdrops.vala:109: Entry : %s", path);
					_tmp9_ = meta_data_new ();
					pitem = _tmp9_;
					pitem->type = META_ARTIST_ART;
					_tmp10_ = gmpc_plugin_base_get_name ((GmpcPluginBase*) self);
					pitem->plugin_name = _tmp10_;
					pitem->content_type = META_DATA_CONTENT_URI;
					meta_data_set_uri (pitem, path);
					meta_data_set_thumbnail_uri (pitem, thumb_path);
					_tmp11_ = pitem;
					pitem = NULL;
					*list = g_list_append (*list, _tmp11_);
					_meta_data_free0 (pitem);
					_g_free0 (thumb_path);
					_g_free0 (path);
				}
			}
		}
	}
}


static void gmpc_provider_ht_backdrops_parse_data (GmpcProviderHTBackdrops* self, GList** list, guchar* data, int data_length1) {
	xmlDoc* _tmp0_ = NULL;
	xmlDoc* doc;
	xmlNode* _tmp1_ = NULL;
	xmlNode* root;
	g_return_if_fail (self != NULL);
	_tmp0_ = xmlParseMemory ((const gchar*) data, data_length1);
	doc = _tmp0_;
	if (doc == NULL) {
		return;
	}
	_tmp1_ = xmlDocGetRootElement (doc);
	root = _tmp1_;
	if (root != NULL) {
		{
			xmlNode* child;
			child = root->children;
			{
				gboolean _tmp2_;
				_tmp2_ = TRUE;
				while (TRUE) {
					if (!_tmp2_) {
						child = child->next;
					}
					_tmp2_ = FALSE;
					if (!(child != NULL)) {
						break;
					}
					if (g_strcmp0 (child->name, "images") == 0) {
						{
							xmlNode* image;
							image = child->children;
							{
								gboolean _tmp3_;
								_tmp3_ = TRUE;
								while (TRUE) {
									if (!_tmp3_) {
										image = image->next;
									}
									_tmp3_ = FALSE;
									if (!(image != NULL)) {
										break;
									}
									if (g_strcmp0 (image->name, "image") == 0) {
										gmpc_provider_ht_backdrops_add_image (self, list, image);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


static guchar* _vala_array_dup1 (guchar* self, int length) {
	return g_memdup (self, length * sizeof (guchar));
}


static void _meta_data_free0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (meta_data_free (var), NULL));
}


static void _g_list_free__meta_data_free0_ (GList* self) {
	g_list_foreach (self, (GFunc) _meta_data_free0_, NULL);
	g_list_free (self);
}


static void gmpc_provider_ht_backdrops_handle_download (GmpcProviderHTBackdrops* self, const GEADAsyncHandler* handle, GEADStatus status, void* d) {
	GmpcProviderHTBackdropsProp* p;
	g_return_if_fail (self != NULL);
	g_return_if_fail (handle != NULL);
	p = (GmpcProviderHTBackdropsProp*) d;
	if (status == GEAD_DONE) {
		GList* list;
		gint _tmp0_;
		guchar* _tmp1_ = NULL;
		guchar* _tmp2_;
		guchar* _tmp3_;
		guchar* data;
		gint data_length1;
		gint _data_size_;
		guint _tmp4_;
		GList* _tmp5_;
		list = NULL;
		_tmp1_ = gmpc_easy_handler_get_data_vala_wrap (handle, &_tmp0_);
		_tmp2_ = (_tmp3_ = _tmp1_, (_tmp3_ == NULL) ? ((gpointer) _tmp3_) : _vala_array_dup1 (_tmp3_, _tmp0_));
		data = _tmp2_;
		data_length1 = _tmp0_;
		_data_size_ = _tmp0_;
		if (data != NULL) {
			gmpc_provider_ht_backdrops_parse_data (self, &list, data, data_length1);
		}
		_tmp4_ = g_list_length (list);
		g_log (log_domain_ppbd, G_LOG_LEVEL_DEBUG, "HTBackdrops.vala:163: Download done: results: %u ", _tmp4_);
		_tmp5_ = list;
		list = NULL;
		p->callback (_tmp5_, p->callback_target);
		gmpc_provider_ht_backdrops_prop_free (p);
		data = (g_free (data), NULL);
		__g_list_free__meta_data_free0_0 (list);
	} else {
		if (status == GEAD_PROGRESS) {
		} else {
			GList* list;
			GList* _tmp6_;
			list = NULL;
			_tmp6_ = list;
			list = NULL;
			p->callback (_tmp6_, p->callback_target);
			gmpc_provider_ht_backdrops_prop_free (p);
			__g_list_free__meta_data_free0_0 (list);
		}
	}
}


/** 
     * Get artist art 
     */
static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _gmpc_provider_ht_backdrops_handle_download_gmpc_async_download_callback_vala (const GEADAsyncHandler* handle, GEADStatus status, void* p, gpointer self) {
	gmpc_provider_ht_backdrops_handle_download (self, handle, status, p);
}


static void gmpc_provider_ht_backdrops_get_artist_art (GmpcProviderHTBackdrops* self, const mpd_Song* song, GmpcPluginMetaDataCallback callback, void* callback_target) {
	GmpcProviderHTBackdropsProp* _tmp0_ = NULL;
	GmpcProviderHTBackdropsProp* p;
	GmpcProviderHTBackdrops* _tmp1_;
	GmpcPluginMetaDataCallback _tmp2_;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_;
	gchar* path;
	g_return_if_fail (self != NULL);
	g_return_if_fail (song != NULL);
	_tmp0_ = gmpc_provider_ht_backdrops_prop_new ();
	p = _tmp0_;
	_tmp1_ = _g_object_ref0 (self);
	_g_object_unref0 (p->this);
	p->this = _tmp1_;
	_tmp2_ = callback;
	(p->callback_target_destroy_notify == NULL) ? NULL : (p->callback_target_destroy_notify (p->callback_target), NULL);
	p->callback = NULL;
	p->callback_target = NULL;
	p->callback_target_destroy_notify = NULL;
	p->callback = _tmp2_;
	p->callback_target = callback_target;
	p->callback_target_destroy_notify = NULL;
	_tmp3_ = gmpc_easy_download_uri_escape (song->artist);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_strdup_printf (GMPC_PROVIDER_HT_BACKDROPS_query, GMPC_PROVIDER_HT_BACKDROPS_api_key, _tmp4_);
	_tmp6_ = _tmp5_;
	_g_free0 (_tmp4_);
	path = _tmp6_;
	g_log (log_domain_ppbd, G_LOG_LEVEL_DEBUG, "HTBackdrops.vala:189: Query artist art: %s ", path);
	gmpc_easy_async_downloader_vala (path, p, _gmpc_provider_ht_backdrops_handle_download_gmpc_async_download_callback_vala, self);
	_g_free0 (path);
}


GmpcProviderHTBackdrops* gmpc_provider_ht_backdrops_construct (GType object_type) {
	GmpcProviderHTBackdrops * self = NULL;
	self = (GmpcProviderHTBackdrops*) gmpc_plugin_base_construct (object_type);
	return self;
}


GmpcProviderHTBackdrops* gmpc_provider_ht_backdrops_new (void) {
	return gmpc_provider_ht_backdrops_construct (GMPC_PROVIDER_TYPE_HT_BACKDROPS);
}


static GObject * gmpc_provider_ht_backdrops_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	GmpcProviderHTBackdrops * self;
	parent_class = G_OBJECT_CLASS (gmpc_provider_ht_backdrops_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = GMPC_PROVIDER_HT_BACKDROPS (obj);
	((GmpcPluginBase*) self)->plugin_type = 8 + 32;
	return obj;
}


static GmpcProviderHTBackdropsProp* gmpc_provider_ht_backdrops_prop_new (void) {
	GmpcProviderHTBackdropsProp* self;
	self = g_slice_new0 (GmpcProviderHTBackdropsProp);
	gmpc_provider_ht_backdrops_prop_instance_init (self);
	return self;
}


static void gmpc_provider_ht_backdrops_prop_instance_init (GmpcProviderHTBackdropsProp * self) {
}


static void gmpc_provider_ht_backdrops_prop_free (GmpcProviderHTBackdropsProp* self) {
	_g_object_unref0 (self->this);
	(self->callback_target_destroy_notify == NULL) ? NULL : (self->callback_target_destroy_notify (self->callback_target), NULL);
	self->callback = NULL;
	self->callback_target = NULL;
	self->callback_target_destroy_notify = NULL;
	g_slice_free (GmpcProviderHTBackdropsProp, self);
}


static void gmpc_provider_ht_backdrops_class_init (GmpcProviderHTBackdropsClass * klass) {
	gmpc_provider_ht_backdrops_parent_class = g_type_class_peek_parent (klass);
	GMPC_PLUGIN_BASE_CLASS (klass)->get_version = gmpc_provider_ht_backdrops_real_get_version;
	GMPC_PLUGIN_BASE_CLASS (klass)->get_name = gmpc_provider_ht_backdrops_real_get_name;
	G_OBJECT_CLASS (klass)->constructor = gmpc_provider_ht_backdrops_constructor;
}


static void gmpc_provider_ht_backdrops_gmpc_plugin_meta_data_iface_interface_init (GmpcPluginMetaDataIfaceIface * iface) {
	gmpc_provider_ht_backdrops_gmpc_plugin_meta_data_iface_parent_iface = g_type_interface_peek_parent (iface);
	iface->set_priority = (void (*)(GmpcPluginMetaDataIface* ,gint)) gmpc_provider_ht_backdrops_real_set_priority;
	iface->get_priority = (gint (*)(GmpcPluginMetaDataIface*)) gmpc_provider_ht_backdrops_real_get_priority;
	iface->get_metadata = (void (*)(GmpcPluginMetaDataIface* ,const mpd_Song* ,MetaDataType ,GmpcPluginMetaDataCallback ,void*)) gmpc_provider_ht_backdrops_real_get_metadata;
}


static void gmpc_provider_ht_backdrops_instance_init (GmpcProviderHTBackdrops * self) {
}


GType gmpc_provider_ht_backdrops_get_type (void) {
	static volatile gsize gmpc_provider_ht_backdrops_type_id__volatile = 0;
	if (g_once_init_enter (&gmpc_provider_ht_backdrops_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GmpcProviderHTBackdropsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gmpc_provider_ht_backdrops_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GmpcProviderHTBackdrops), 0, (GInstanceInitFunc) gmpc_provider_ht_backdrops_instance_init, NULL };
		static const GInterfaceInfo gmpc_plugin_meta_data_iface_info = { (GInterfaceInitFunc) gmpc_provider_ht_backdrops_gmpc_plugin_meta_data_iface_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType gmpc_provider_ht_backdrops_type_id;
		gmpc_provider_ht_backdrops_type_id = g_type_register_static (GMPC_PLUGIN_TYPE_BASE, "GmpcProviderHTBackdrops", &g_define_type_info, 0);
		g_type_add_interface_static (gmpc_provider_ht_backdrops_type_id, GMPC_PLUGIN_TYPE_META_DATA_IFACE, &gmpc_plugin_meta_data_iface_info);
		g_once_init_leave (&gmpc_provider_ht_backdrops_type_id__volatile, gmpc_provider_ht_backdrops_type_id);
	}
	return gmpc_provider_ht_backdrops_type_id__volatile;
}



