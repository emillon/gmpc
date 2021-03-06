/* RenderCover.c generated by valac 0.12.0, the Vala compiler
 * generated from RenderCover.vala, do not modify */

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
#include <cairo.h>
#include <gdk-pixbuf/gdk-pixdata.h>
#include <gdk/gdk.h>
#include <float.h>
#include <math.h>
#include <pango/pangocairo.h>
#include <pango/pango.h>

typedef struct _Block36Data Block36Data;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _cairo_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_destroy (var), NULL)))
#define _cairo_surface_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_surface_destroy (var), NULL)))
#define _cairo_pattern_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_pattern_destroy (var), NULL)))
#define _pango_font_description_free0(var) ((var == NULL) ? NULL : (var = (pango_font_description_free (var), NULL)))
#define __g_list_free__meta_data_free0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__meta_data_free0_ (var), NULL)))
#define _meta_data_free0(var) ((var == NULL) ? NULL : (var = (meta_data_free (var), NULL)))

struct _Block36Data {
	int _ref_count_;
	GmpcProviderRenderCover * self;
	void* data;
	guint len;
};


static gpointer gmpc_provider_render_cover_parent_class = NULL;
static GmpcPluginMetaDataIfaceIface* gmpc_provider_render_cover_gmpc_plugin_meta_data_iface_parent_iface = NULL;

#define use_transition_prc TRUE
#define some_unique_name_prc VERSION
#define log_domain_prc "Gmpc.Provider.RenderCover"
enum  {
	GMPC_PROVIDER_RENDER_COVER_DUMMY_PROPERTY
};
static gint* gmpc_provider_render_cover_real_get_version (GmpcPluginBase* base, int* result_length1);
static const gchar* gmpc_provider_render_cover_real_get_name (GmpcPluginBase* base);
static void gmpc_provider_render_cover_real_set_priority (GmpcPluginMetaDataIface* base, gint priority);
static gint gmpc_provider_render_cover_real_get_priority (GmpcPluginMetaDataIface* base);
static void gmpc_provider_render_cover_real_get_metadata (GmpcPluginMetaDataIface* base, const mpd_Song* song, MetaDataType type, GmpcPluginMetaDataCallback callback, void* callback_target);
static void gmpc_provider_render_cover_get_album_art (GmpcProviderRenderCover* self, const mpd_Song* song, GmpcPluginMetaDataCallback callback, void* callback_target);
static Block36Data* block36_data_ref (Block36Data* _data36_);
static void block36_data_unref (Block36Data* _data36_);
static cairo_status_t _lambda93_ (Block36Data* _data36_, guchar* imgdata, int imgdata_length1);
static cairo_status_t __lambda93__cairo_write_func (gpointer self, guchar* data, int data_length1);
static void _meta_data_free0_ (gpointer var);
static void _g_list_free__meta_data_free0_ (GList* self);
static GObject * gmpc_provider_render_cover_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);

static const gint GMPC_PROVIDER_RENDER_COVER_version[3] = {0, 0, 2};

static gint* gmpc_provider_render_cover_real_get_version (GmpcPluginBase* base, int* result_length1) {
	GmpcProviderRenderCover * self;
	gint* result = NULL;
	gint* _tmp0_;
	self = (GmpcProviderRenderCover*) base;
	_tmp0_ = GMPC_PROVIDER_RENDER_COVER_version;
	*result_length1 = G_N_ELEMENTS (GMPC_PROVIDER_RENDER_COVER_version);
	result = _tmp0_;
	return result;
}


static const gchar* gmpc_provider_render_cover_real_get_name (GmpcPluginBase* base) {
	GmpcProviderRenderCover * self;
	const gchar* result = NULL;
	self = (GmpcProviderRenderCover*) base;
	result = "Backdrop Renderer";
	return result;
}


static void gmpc_provider_render_cover_real_set_priority (GmpcPluginMetaDataIface* base, gint priority) {
	GmpcProviderRenderCover * self;
	const gchar* _tmp0_ = NULL;
	self = (GmpcProviderRenderCover*) base;
	_tmp0_ = gmpc_plugin_base_get_name ((GmpcPluginBase*) self);
	cfg_set_single_value_as_int (config, _tmp0_, "priority", priority);
}


static gint gmpc_provider_render_cover_real_get_priority (GmpcPluginMetaDataIface* base) {
	GmpcProviderRenderCover * self;
	gint result = 0;
	const gchar* _tmp0_ = NULL;
	gint _tmp1_;
	self = (GmpcProviderRenderCover*) base;
	_tmp0_ = gmpc_plugin_base_get_name ((GmpcPluginBase*) self);
	_tmp1_ = cfg_get_single_value_as_int_with_default (config, _tmp0_, "priority", 100);
	result = _tmp1_;
	return result;
}


static void gmpc_provider_render_cover_real_get_metadata (GmpcPluginMetaDataIface* base, const mpd_Song* song, MetaDataType type, GmpcPluginMetaDataCallback callback, void* callback_target) {
	GmpcProviderRenderCover * self;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	self = (GmpcProviderRenderCover*) base;
	g_return_if_fail (song != NULL);
	if (song == NULL) {
		_tmp1_ = TRUE;
	} else {
		_tmp1_ = song->artist == NULL;
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = song->album == NULL;
	}
	if (_tmp0_) {
		g_log (log_domain_prc, G_LOG_LEVEL_DEBUG, "RenderCover.vala:64: Insufficient information. doing nothing");
		callback (NULL, callback_target);
		return;
	}
	switch (type) {
		case META_ALBUM_ART:
		{
			gmpc_provider_render_cover_get_album_art (self, song, callback, callback_target);
			return;
		}
		default:
		case META_ARTIST_TXT:
		case META_ARTIST_SIMILAR:
		case META_ARTIST_ART:
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


static Block36Data* block36_data_ref (Block36Data* _data36_) {
	g_atomic_int_inc (&_data36_->_ref_count_);
	return _data36_;
}


static void block36_data_unref (Block36Data* _data36_) {
	if (g_atomic_int_dec_and_test (&_data36_->_ref_count_)) {
		_g_object_unref0 (_data36_->self);
		g_slice_free (Block36Data, _data36_);
	}
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static cairo_status_t _lambda93_ (Block36Data* _data36_, guchar* imgdata, int imgdata_length1) {
	GmpcProviderRenderCover * self;
	cairo_status_t result = 0;
	void* _tmp0_ = NULL;
	self = _data36_->self;
	_tmp0_ = g_realloc (_data36_->data, (gsize) (_data36_->len + imgdata_length1));
	_data36_->data = _tmp0_;
	memcpy (&_data36_->data[_data36_->len], imgdata, (gsize) imgdata_length1);
	_data36_->len = _data36_->len + ((guint) imgdata_length1);
	result = CAIRO_STATUS_SUCCESS;
	return result;
}


static cairo_status_t __lambda93__cairo_write_func (gpointer self, guchar* data, int data_length1) {
	cairo_status_t result;
	result = _lambda93_ (self, data, data_length1);
	return result;
}


static void _meta_data_free0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (meta_data_free (var), NULL));
}


static void _g_list_free__meta_data_free0_ (GList* self) {
	g_list_foreach (self, (GFunc) _meta_data_free0_, NULL);
	g_list_free (self);
}


static void gmpc_provider_render_cover_get_album_art (GmpcProviderRenderCover* self, const mpd_Song* song, GmpcPluginMetaDataCallback callback, void* callback_target) {
	Block36Data* _data36_;
	cairo_pattern_t* p = NULL;
	cairo_surface_t* _tmp0_ = NULL;
	cairo_surface_t* surf;
	cairo_t* _tmp1_ = NULL;
	cairo_t* ct;
	guint _tmp2_;
	guint hash;
	guint _tmp3_;
	GtkIconTheme* _tmp4_ = NULL;
	GtkIconTheme* _tmp5_;
	GtkIconTheme* it;
	GdkPixbuf* _tmp6_ = NULL;
	GdkPixbuf* pb;
	gint _tmp7_;
	gint _tmp8_;
	cairo_pattern_t* _tmp9_ = NULL;
	cairo_pattern_t* _tmp10_ = NULL;
	PangoLayout* _tmp11_ = NULL;
	PangoLayout* layout;
	PangoFontDescription* _tmp12_ = NULL;
	PangoFontDescription* fd;
	gint aheight;
	gint awidth;
	gint _tmp13_;
	gint _tmp14_;
	PangoFontDescription* _tmp16_ = NULL;
	gint bheight;
	gint bwidth;
	gint _tmp17_;
	gint _tmp18_;
	MetaData* _tmp20_ = NULL;
	MetaData* pitem;
	const gchar* _tmp21_ = NULL;
	GList* list;
	MetaData* _tmp22_;
	GList* _tmp23_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (song != NULL);
	_data36_ = g_slice_new0 (Block36Data);
	_data36_->_ref_count_ = 1;
	_data36_->self = g_object_ref (self);
	_tmp0_ = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, GMPC_PROVIDER_RENDER_COVER_album_size, GMPC_PROVIDER_RENDER_COVER_album_size);
	surf = _tmp0_;
	_tmp1_ = cairo_create (surf);
	ct = _tmp1_;
	_tmp2_ = g_str_hash (song->album);
	hash = _tmp2_ / 2;
	_tmp3_ = g_str_hash (song->artist);
	hash = hash + (_tmp3_ / 2);
	cairo_set_source_rgb (ct, (hash & 255) / 255.0, ((hash >> 8) & 255) / 255.0, ((hash >> 16) & 255) / 255.0);
	cairo_paint (ct);
	_tmp4_ = gtk_icon_theme_get_default ();
	_tmp5_ = _g_object_ref0 (_tmp4_);
	it = _tmp5_;
	_tmp6_ = gtk_icon_theme_load_icon (it, "gmpc", 256, 0, &_inner_error_);
	pb = _tmp6_;
	if (_inner_error_ != NULL) {
		goto __catch23_g_error;
	}
	decolor_pixbuf (pb, pb);
	_tmp7_ = gdk_pixbuf_get_width (pb);
	_tmp8_ = gdk_pixbuf_get_height (pb);
	gdk_cairo_set_source_pixbuf (ct, pb, (gdouble) (200 - (_tmp7_ / 2)), (gdouble) (390 - _tmp8_));
	cairo_paint_with_alpha (ct, 0.6);
	_g_object_unref0 (pb);
	goto __finally23;
	__catch23_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		_g_error_free0 (e);
	}
	__finally23:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (it);
		_cairo_destroy0 (ct);
		_cairo_surface_destroy0 (surf);
		_cairo_pattern_destroy0 (p);
		block36_data_unref (_data36_);
		_data36_ = NULL;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp9_ = cairo_pattern_create_linear ((gdouble) 0, (gdouble) 0, (gdouble) GMPC_PROVIDER_RENDER_COVER_album_size, (gdouble) 0);
	_cairo_pattern_destroy0 (p);
	p = _tmp9_;
	cairo_pattern_add_color_stop_rgb (p, (gdouble) 0, 0.8, 0.8, 0.8);
	cairo_pattern_add_color_stop_rgb (p, (gdouble) 1, 0.5, 0.5, 0.5);
	cairo_set_source (ct, p);
	cairo_rectangle (ct, 0.0, 0.0, (gdouble) GMPC_PROVIDER_RENDER_COVER_album_size, (gdouble) (GMPC_PROVIDER_RENDER_COVER_album_size / 3));
	cairo_fill (ct);
	_tmp10_ = cairo_pattern_create_linear ((gdouble) 0, (gdouble) 0, (gdouble) GMPC_PROVIDER_RENDER_COVER_album_size, (gdouble) 0);
	_cairo_pattern_destroy0 (p);
	p = _tmp10_;
	cairo_pattern_add_color_stop_rgba (p, (gdouble) 0, (gdouble) 0, (gdouble) 0, (gdouble) 0, 0.1);
	cairo_pattern_add_color_stop_rgba (p, 0.5, (gdouble) 0, (gdouble) 0, (gdouble) 0, 0.9);
	cairo_pattern_add_color_stop_rgba (p, (gdouble) 1, (gdouble) 0, (gdouble) 0, (gdouble) 0, 0.1);
	cairo_set_source (ct, p);
	cairo_rectangle (ct, 0.0, (gdouble) ((GMPC_PROVIDER_RENDER_COVER_album_size / 3) - 6), (gdouble) GMPC_PROVIDER_RENDER_COVER_album_size, 12.0);
	cairo_fill (ct);
	cairo_set_source_rgb (ct, 0.0, 0.0, 0.0);
	_tmp11_ = pango_cairo_create_layout (ct);
	layout = _tmp11_;
	_tmp12_ = pango_font_description_from_string ("Serif bold 32");
	fd = _tmp12_;
	pango_layout_set_font_description (layout, fd);
	pango_layout_set_text (layout, song->album, -1);
	aheight = 0;
	awidth = 0;
	pango_layout_get_pixel_size (layout, &_tmp13_, &_tmp14_);
	awidth = _tmp13_;
	aheight = _tmp14_;
	if (awidth >= (GMPC_PROVIDER_RENDER_COVER_album_size - 50)) {
		cairo_pattern_t* _tmp15_ = NULL;
		_tmp15_ = cairo_pattern_create_linear ((gdouble) 0, (gdouble) 0, (gdouble) (GMPC_PROVIDER_RENDER_COVER_album_size - 25), (gdouble) 0);
		_cairo_pattern_destroy0 (p);
		p = _tmp15_;
		cairo_pattern_add_color_stop_rgba (p, (gdouble) 0, (gdouble) 0, (gdouble) 0, (gdouble) 0, (gdouble) 1);
		cairo_pattern_add_color_stop_rgba (p, (GMPC_PROVIDER_RENDER_COVER_album_size - 50) / ((gdouble) GMPC_PROVIDER_RENDER_COVER_album_size), (gdouble) 0, (gdouble) 0, (gdouble) 0, (gdouble) 1);
		cairo_pattern_add_color_stop_rgba (p, (gdouble) 1, (gdouble) 0, (gdouble) 0, (gdouble) 0, 0.0);
		cairo_set_source (ct, p);
	} else {
		cairo_set_source_rgb (ct, 0.0, 0.0, 0.0);
	}
	cairo_move_to (ct, (gdouble) 25, (gdouble) 25);
	pango_cairo_layout_path (ct, layout);
	cairo_fill (ct);
	_tmp16_ = pango_font_description_from_string ("Sans bold 18");
	_pango_font_description_free0 (fd);
	fd = _tmp16_;
	pango_layout_set_font_description (layout, fd);
	pango_layout_set_text (layout, song->artist, -1);
	bheight = 0;
	bwidth = 0;
	pango_layout_get_pixel_size (layout, &_tmp17_, &_tmp18_);
	bwidth = _tmp17_;
	bheight = _tmp18_;
	if (bwidth >= (GMPC_PROVIDER_RENDER_COVER_album_size - 50)) {
		cairo_pattern_t* _tmp19_ = NULL;
		cairo_move_to (ct, (gdouble) 25, (gdouble) ((aheight + 25) + 5));
		_tmp19_ = cairo_pattern_create_linear ((gdouble) 0, (gdouble) 0, (gdouble) (GMPC_PROVIDER_RENDER_COVER_album_size - 25), (gdouble) 0);
		_cairo_pattern_destroy0 (p);
		p = _tmp19_;
		cairo_pattern_add_color_stop_rgba (p, (gdouble) 0, (gdouble) 1, (gdouble) 1, (gdouble) 1, (gdouble) 1);
		cairo_pattern_add_color_stop_rgba (p, (GMPC_PROVIDER_RENDER_COVER_album_size - 50) / ((gdouble) GMPC_PROVIDER_RENDER_COVER_album_size), (gdouble) 1, (gdouble) 1, (gdouble) 1, (gdouble) 1);
		cairo_pattern_add_color_stop_rgba (p, (gdouble) 1, (gdouble) 1, (gdouble) 1, (gdouble) 1, 0.0);
		cairo_set_source (ct, p);
	} else {
		cairo_move_to (ct, (gdouble) ((GMPC_PROVIDER_RENDER_COVER_album_size - 25) - bwidth), (gdouble) ((aheight + 25) + 5));
		cairo_set_source_rgb (ct, (gdouble) 1, (gdouble) 1, (gdouble) 1);
	}
	pango_cairo_layout_path (ct, layout);
	cairo_fill (ct);
	_data36_->data = NULL;
	_data36_->len = (guint) 0;
	cairo_surface_write_to_png_stream (surf, __lambda93__cairo_write_func, _data36_);
	_tmp20_ = meta_data_new ();
	pitem = _tmp20_;
	pitem->type = META_ALBUM_ART;
	_tmp21_ = gmpc_plugin_base_get_name ((GmpcPluginBase*) self);
	pitem->plugin_name = _tmp21_;
	pitem->content_type = META_DATA_CONTENT_RAW;
	meta_data_set_raw_owned (pitem, &_data36_->data, &_data36_->len);
	g_free (_data36_->data);
	list = NULL;
	_tmp22_ = pitem;
	pitem = NULL;
	list = g_list_append (list, _tmp22_);
	_tmp23_ = list;
	list = NULL;
	callback (_tmp23_, callback_target);
	__g_list_free__meta_data_free0_0 (list);
	_meta_data_free0 (pitem);
	_pango_font_description_free0 (fd);
	_g_object_unref0 (layout);
	_g_object_unref0 (it);
	_cairo_destroy0 (ct);
	_cairo_surface_destroy0 (surf);
	_cairo_pattern_destroy0 (p);
	block36_data_unref (_data36_);
	_data36_ = NULL;
}


GmpcProviderRenderCover* gmpc_provider_render_cover_construct (GType object_type) {
	GmpcProviderRenderCover * self = NULL;
	self = (GmpcProviderRenderCover*) gmpc_plugin_base_construct (object_type);
	return self;
}


GmpcProviderRenderCover* gmpc_provider_render_cover_new (void) {
	return gmpc_provider_render_cover_construct (GMPC_PROVIDER_TYPE_RENDER_COVER);
}


static GObject * gmpc_provider_render_cover_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	GmpcProviderRenderCover * self;
	parent_class = G_OBJECT_CLASS (gmpc_provider_render_cover_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = GMPC_PROVIDER_RENDER_COVER (obj);
	((GmpcPluginBase*) self)->plugin_type = 8 + 32;
	return obj;
}


static void gmpc_provider_render_cover_class_init (GmpcProviderRenderCoverClass * klass) {
	gmpc_provider_render_cover_parent_class = g_type_class_peek_parent (klass);
	GMPC_PLUGIN_BASE_CLASS (klass)->get_version = gmpc_provider_render_cover_real_get_version;
	GMPC_PLUGIN_BASE_CLASS (klass)->get_name = gmpc_provider_render_cover_real_get_name;
	G_OBJECT_CLASS (klass)->constructor = gmpc_provider_render_cover_constructor;
}


static void gmpc_provider_render_cover_gmpc_plugin_meta_data_iface_interface_init (GmpcPluginMetaDataIfaceIface * iface) {
	gmpc_provider_render_cover_gmpc_plugin_meta_data_iface_parent_iface = g_type_interface_peek_parent (iface);
	iface->set_priority = (void (*)(GmpcPluginMetaDataIface* ,gint)) gmpc_provider_render_cover_real_set_priority;
	iface->get_priority = (gint (*)(GmpcPluginMetaDataIface*)) gmpc_provider_render_cover_real_get_priority;
	iface->get_metadata = (void (*)(GmpcPluginMetaDataIface* ,const mpd_Song* ,MetaDataType ,GmpcPluginMetaDataCallback ,void*)) gmpc_provider_render_cover_real_get_metadata;
}


static void gmpc_provider_render_cover_instance_init (GmpcProviderRenderCover * self) {
}


GType gmpc_provider_render_cover_get_type (void) {
	static volatile gsize gmpc_provider_render_cover_type_id__volatile = 0;
	if (g_once_init_enter (&gmpc_provider_render_cover_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GmpcProviderRenderCoverClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gmpc_provider_render_cover_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GmpcProviderRenderCover), 0, (GInstanceInitFunc) gmpc_provider_render_cover_instance_init, NULL };
		static const GInterfaceInfo gmpc_plugin_meta_data_iface_info = { (GInterfaceInitFunc) gmpc_provider_render_cover_gmpc_plugin_meta_data_iface_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType gmpc_provider_render_cover_type_id;
		gmpc_provider_render_cover_type_id = g_type_register_static (GMPC_PLUGIN_TYPE_BASE, "GmpcProviderRenderCover", &g_define_type_info, 0);
		g_type_add_interface_static (gmpc_provider_render_cover_type_id, GMPC_PLUGIN_TYPE_META_DATA_IFACE, &gmpc_plugin_meta_data_iface_info);
		g_once_init_leave (&gmpc_provider_render_cover_type_id__volatile, gmpc_provider_render_cover_type_id);
	}
	return gmpc_provider_render_cover_type_id__volatile;
}



