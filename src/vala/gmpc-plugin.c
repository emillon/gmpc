/* gmpc-plugin.c generated by valac 0.12.0, the Vala compiler
 * generated from gmpc-plugin.vala, do not modify */

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
#include "gmpc-extras.h"
#include <stdlib.h>
#include <string.h>
#include <plugin.h>
#include <config1.h>
#include <gtk/gtk.h>
#include <libmpd/libmpdclient.h>
#include <libmpd/libmpd.h>
#include <misc.h>
#include <metadata.h>

#define _g_free0(var) (var = (g_free (var), NULL))


static gpointer gmpc_plugin_base_parent_class = NULL;

enum  {
	GMPC_PLUGIN_BASE_DUMMY_PROPERTY
};
static gint* gmpc_plugin_base_real_get_version (GmpcPluginBase* self, int* result_length1);
static const gchar* gmpc_plugin_base_real_get_name (GmpcPluginBase* self);
static void gmpc_plugin_base_real_save_yourself (GmpcPluginBase* self);
static gboolean gmpc_plugin_base_real_get_enabled (GmpcPluginBase* self);
static void gmpc_plugin_base_real_set_enabled (GmpcPluginBase* self, gboolean state);
static void gmpc_plugin_base_finalize (GObject* obj);
static gint gmpc_plugin_browser_iface_real_browser_option_menu (GmpcPluginBrowserIface* self, GtkMenu* menu);
static gint gmpc_plugin_browser_iface_real_browser_add_go_menu (GmpcPluginBrowserIface* self, GtkMenu* menu);
static gboolean gmpc_plugin_integrate_search_iface_real_field_supported (GmpcPluginIntegrateSearchIface* self, mpd_TagItems tag);


/**
             * Function should return the version of the plugin
             */
static gint* gmpc_plugin_base_real_get_version (GmpcPluginBase* self, int* result_length1) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `gmpc_plugin_base_get_version'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


gint* gmpc_plugin_base_get_version (GmpcPluginBase* self, int* result_length1) {
	return GMPC_PLUGIN_BASE_GET_CLASS (self)->get_version (self, result_length1);
}


/**
             * Return the name of the plugin
             */
static const gchar* gmpc_plugin_base_real_get_name (GmpcPluginBase* self) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `gmpc_plugin_base_get_name'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


const gchar* gmpc_plugin_base_get_name (GmpcPluginBase* self) {
	return GMPC_PLUGIN_BASE_GET_CLASS (self)->get_name (self);
}


/**
             * This is called before the plugin is destroyed. Plugins should save it state here.
             *
             * A Browser plugin should store the position in the side-tree here.
             * Optional function. 
             */
static void gmpc_plugin_base_real_save_yourself (GmpcPluginBase* self) {
	g_return_if_fail (self != NULL);
}


void gmpc_plugin_base_save_yourself (GmpcPluginBase* self) {
	GMPC_PLUGIN_BASE_GET_CLASS (self)->save_yourself (self);
}


/**
             * Function used by gmpc to check if the plugin is enabled.
             * By default it is stored in the get_name() category under the enabled key.
             * 
             * @return The state (true or false)
             */
static gboolean gmpc_plugin_base_real_get_enabled (GmpcPluginBase* self) {
	gboolean result = FALSE;
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	gint _tmp2_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = gmpc_plugin_base_get_name (self);
	if (_tmp0_ == NULL) {
		result = FALSE;
		return result;
	}
	_tmp1_ = gmpc_plugin_base_get_name (self);
	_tmp2_ = cfg_get_single_value_as_int_with_default (config, _tmp1_, "enabled", 1);
	result = (gboolean) _tmp2_;
	return result;
}


gboolean gmpc_plugin_base_get_enabled (GmpcPluginBase* self) {
	return GMPC_PLUGIN_BASE_GET_CLASS (self)->get_enabled (self);
}


/**
             * Function to enable/disable the plugin
             * @param state the enable state to set the plugin in. (true or false)
             * 
             * Function used by gmpc to enable/disable the plugin. 
             * By default it is stored in the get_name() category under the enabled key.
             * If something needs to be done on enable/disable override this function.
             */
static void gmpc_plugin_base_real_set_enabled (GmpcPluginBase* self, gboolean state) {
	const gchar* _tmp0_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = gmpc_plugin_base_get_name (self);
	if (_tmp0_ != NULL) {
		const gchar* _tmp1_ = NULL;
		_tmp1_ = gmpc_plugin_base_get_name (self);
		cfg_set_single_value_as_int (config, _tmp1_, "enabled", (gint) state);
	}
}


void gmpc_plugin_base_set_enabled (GmpcPluginBase* self, gboolean state) {
	GMPC_PLUGIN_BASE_GET_CLASS (self)->set_enabled (self, state);
}


GmpcPluginBase* gmpc_plugin_base_construct (GType object_type) {
	GmpcPluginBase * self = NULL;
	self = (GmpcPluginBase*) g_object_new (object_type, NULL);
	return self;
}


static void gmpc_plugin_base_class_init (GmpcPluginBaseClass * klass) {
	gmpc_plugin_base_parent_class = g_type_class_peek_parent (klass);
	GMPC_PLUGIN_BASE_CLASS (klass)->get_version = gmpc_plugin_base_real_get_version;
	GMPC_PLUGIN_BASE_CLASS (klass)->get_name = gmpc_plugin_base_real_get_name;
	GMPC_PLUGIN_BASE_CLASS (klass)->save_yourself = gmpc_plugin_base_real_save_yourself;
	GMPC_PLUGIN_BASE_CLASS (klass)->get_enabled = gmpc_plugin_base_real_get_enabled;
	GMPC_PLUGIN_BASE_CLASS (klass)->set_enabled = gmpc_plugin_base_real_set_enabled;
	G_OBJECT_CLASS (klass)->finalize = gmpc_plugin_base_finalize;
}


static void gmpc_plugin_base_instance_init (GmpcPluginBase * self) {
	self->translation_domain = NULL;
	self->plugin_type = 1;
}


static void gmpc_plugin_base_finalize (GObject* obj) {
	GmpcPluginBase * self;
	self = GMPC_PLUGIN_BASE (obj);
	_g_free0 (self->path);
	G_OBJECT_CLASS (gmpc_plugin_base_parent_class)->finalize (obj);
}


/**
         * This is the base class that a plugin should inherit from.
         *
         */
GType gmpc_plugin_base_get_type (void) {
	static volatile gsize gmpc_plugin_base_type_id__volatile = 0;
	if (g_once_init_enter (&gmpc_plugin_base_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GmpcPluginBaseClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gmpc_plugin_base_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GmpcPluginBase), 0, (GInstanceInitFunc) gmpc_plugin_base_instance_init, NULL };
		GType gmpc_plugin_base_type_id;
		gmpc_plugin_base_type_id = g_type_register_static (G_TYPE_OBJECT, "GmpcPluginBase", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&gmpc_plugin_base_type_id__volatile, gmpc_plugin_base_type_id);
	}
	return gmpc_plugin_base_type_id__volatile;
}


gint gmpc_plugin_tool_menu_iface_tool_menu_integration (GmpcPluginToolMenuIface* self, GtkMenu* menu) {
	return GMPC_PLUGIN_TOOL_MENU_IFACE_GET_INTERFACE (self)->tool_menu_integration (self, menu);
}


static void gmpc_plugin_tool_menu_iface_base_init (GmpcPluginToolMenuIfaceIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


/**
         * This interface allows the plugin to add one, or more, entries in the Tools menu.
         * If need to remove or undate an entry call pl3_tool_menu_update(). This will tell gmpc
         * To clear the menu, and call this function again on every plugin.
         */
GType gmpc_plugin_tool_menu_iface_get_type (void) {
	static volatile gsize gmpc_plugin_tool_menu_iface_type_id__volatile = 0;
	if (g_once_init_enter (&gmpc_plugin_tool_menu_iface_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GmpcPluginToolMenuIfaceIface), (GBaseInitFunc) gmpc_plugin_tool_menu_iface_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType gmpc_plugin_tool_menu_iface_type_id;
		gmpc_plugin_tool_menu_iface_type_id = g_type_register_static (G_TYPE_INTERFACE, "GmpcPluginToolMenuIface", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (gmpc_plugin_tool_menu_iface_type_id, GMPC_PLUGIN_TYPE_BASE);
		g_once_init_leave (&gmpc_plugin_tool_menu_iface_type_id__volatile, gmpc_plugin_tool_menu_iface_type_id);
	}
	return gmpc_plugin_tool_menu_iface_type_id__volatile;
}


void gmpc_plugin_meta_data_iface_get_metadata (GmpcPluginMetaDataIface* self, const mpd_Song* song, MetaDataType type, GmpcPluginMetaDataCallback callback, void* callback_target) {
	GMPC_PLUGIN_META_DATA_IFACE_GET_INTERFACE (self)->get_metadata (self, song, type, callback, callback_target);
}


gint gmpc_plugin_meta_data_iface_get_priority (GmpcPluginMetaDataIface* self) {
	return GMPC_PLUGIN_META_DATA_IFACE_GET_INTERFACE (self)->get_priority (self);
}


void gmpc_plugin_meta_data_iface_set_priority (GmpcPluginMetaDataIface* self, gint priority) {
	GMPC_PLUGIN_META_DATA_IFACE_GET_INTERFACE (self)->set_priority (self, priority);
}


static void gmpc_plugin_meta_data_iface_base_init (GmpcPluginMetaDataIfaceIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType gmpc_plugin_meta_data_iface_get_type (void) {
	static volatile gsize gmpc_plugin_meta_data_iface_type_id__volatile = 0;
	if (g_once_init_enter (&gmpc_plugin_meta_data_iface_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GmpcPluginMetaDataIfaceIface), (GBaseInitFunc) gmpc_plugin_meta_data_iface_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType gmpc_plugin_meta_data_iface_type_id;
		gmpc_plugin_meta_data_iface_type_id = g_type_register_static (G_TYPE_INTERFACE, "GmpcPluginMetaDataIface", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (gmpc_plugin_meta_data_iface_type_id, GMPC_PLUGIN_TYPE_BASE);
		g_once_init_leave (&gmpc_plugin_meta_data_iface_type_id__volatile, gmpc_plugin_meta_data_iface_type_id);
	}
	return gmpc_plugin_meta_data_iface_type_id__volatile;
}


void gmpc_plugin_browser_iface_browser_add (GmpcPluginBrowserIface* self, GtkWidget* category_tree) {
	GMPC_PLUGIN_BROWSER_IFACE_GET_INTERFACE (self)->browser_add (self, category_tree);
}


void gmpc_plugin_browser_iface_browser_selected (GmpcPluginBrowserIface* self, GtkContainer* container) {
	GMPC_PLUGIN_BROWSER_IFACE_GET_INTERFACE (self)->browser_selected (self, container);
}


void gmpc_plugin_browser_iface_browser_unselected (GmpcPluginBrowserIface* self, GtkContainer* container) {
	GMPC_PLUGIN_BROWSER_IFACE_GET_INTERFACE (self)->browser_unselected (self, container);
}


static gint gmpc_plugin_browser_iface_real_browser_option_menu (GmpcPluginBrowserIface* self, GtkMenu* menu) {
	gint result = 0;
	g_return_val_if_fail (menu != NULL, 0);
	result = 0;
	return result;
}


gint gmpc_plugin_browser_iface_browser_option_menu (GmpcPluginBrowserIface* self, GtkMenu* menu) {
	return GMPC_PLUGIN_BROWSER_IFACE_GET_INTERFACE (self)->browser_option_menu (self, menu);
}


static gint gmpc_plugin_browser_iface_real_browser_add_go_menu (GmpcPluginBrowserIface* self, GtkMenu* menu) {
	gint result = 0;
	g_return_val_if_fail (menu != NULL, 0);
	result = 0;
	return result;
}


gint gmpc_plugin_browser_iface_browser_add_go_menu (GmpcPluginBrowserIface* self, GtkMenu* menu) {
	return GMPC_PLUGIN_BROWSER_IFACE_GET_INTERFACE (self)->browser_add_go_menu (self, menu);
}


static void gmpc_plugin_browser_iface_base_init (GmpcPluginBrowserIfaceIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
		iface->browser_option_menu = gmpc_plugin_browser_iface_real_browser_option_menu;
		iface->browser_add_go_menu = gmpc_plugin_browser_iface_real_browser_add_go_menu;
	}
}


GType gmpc_plugin_browser_iface_get_type (void) {
	static volatile gsize gmpc_plugin_browser_iface_type_id__volatile = 0;
	if (g_once_init_enter (&gmpc_plugin_browser_iface_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GmpcPluginBrowserIfaceIface), (GBaseInitFunc) gmpc_plugin_browser_iface_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType gmpc_plugin_browser_iface_type_id;
		gmpc_plugin_browser_iface_type_id = g_type_register_static (G_TYPE_INTERFACE, "GmpcPluginBrowserIface", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (gmpc_plugin_browser_iface_type_id, GMPC_PLUGIN_TYPE_BASE);
		g_once_init_leave (&gmpc_plugin_browser_iface_type_id__volatile, gmpc_plugin_browser_iface_type_id);
	}
	return gmpc_plugin_browser_iface_type_id__volatile;
}


static gboolean gmpc_plugin_integrate_search_iface_real_field_supported (GmpcPluginIntegrateSearchIface* self, mpd_TagItems tag) {
	gboolean result = FALSE;
	result = TRUE;
	return result;
}


gboolean gmpc_plugin_integrate_search_iface_field_supported (GmpcPluginIntegrateSearchIface* self, mpd_TagItems tag) {
	return GMPC_PLUGIN_INTEGRATE_SEARCH_IFACE_GET_INTERFACE (self)->field_supported (self, tag);
}


MpdData* gmpc_plugin_integrate_search_iface_search (GmpcPluginIntegrateSearchIface* self, mpd_TagItems tag, const gchar* search_query) {
	return GMPC_PLUGIN_INTEGRATE_SEARCH_IFACE_GET_INTERFACE (self)->search (self, tag, search_query);
}


static void gmpc_plugin_integrate_search_iface_base_init (GmpcPluginIntegrateSearchIfaceIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
		iface->field_supported = gmpc_plugin_integrate_search_iface_real_field_supported;
	}
}


GType gmpc_plugin_integrate_search_iface_get_type (void) {
	static volatile gsize gmpc_plugin_integrate_search_iface_type_id__volatile = 0;
	if (g_once_init_enter (&gmpc_plugin_integrate_search_iface_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GmpcPluginIntegrateSearchIfaceIface), (GBaseInitFunc) gmpc_plugin_integrate_search_iface_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType gmpc_plugin_integrate_search_iface_type_id;
		gmpc_plugin_integrate_search_iface_type_id = g_type_register_static (G_TYPE_INTERFACE, "GmpcPluginIntegrateSearchIface", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (gmpc_plugin_integrate_search_iface_type_id, GMPC_PLUGIN_TYPE_BASE);
		g_once_init_leave (&gmpc_plugin_integrate_search_iface_type_id__volatile, gmpc_plugin_integrate_search_iface_type_id);
	}
	return gmpc_plugin_integrate_search_iface_type_id__volatile;
}


void gmpc_plugin_preferences_iface_preferences_pane_construct (GmpcPluginPreferencesIface* self, GtkContainer* container) {
	GMPC_PLUGIN_PREFERENCES_IFACE_GET_INTERFACE (self)->preferences_pane_construct (self, container);
}


void gmpc_plugin_preferences_iface_preferences_pane_destroy (GmpcPluginPreferencesIface* self, GtkContainer* container) {
	GMPC_PLUGIN_PREFERENCES_IFACE_GET_INTERFACE (self)->preferences_pane_destroy (self, container);
}


static void gmpc_plugin_preferences_iface_base_init (GmpcPluginPreferencesIfaceIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType gmpc_plugin_preferences_iface_get_type (void) {
	static volatile gsize gmpc_plugin_preferences_iface_type_id__volatile = 0;
	if (g_once_init_enter (&gmpc_plugin_preferences_iface_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GmpcPluginPreferencesIfaceIface), (GBaseInitFunc) gmpc_plugin_preferences_iface_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType gmpc_plugin_preferences_iface_type_id;
		gmpc_plugin_preferences_iface_type_id = g_type_register_static (G_TYPE_INTERFACE, "GmpcPluginPreferencesIface", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (gmpc_plugin_preferences_iface_type_id, GMPC_PLUGIN_TYPE_BASE);
		g_once_init_leave (&gmpc_plugin_preferences_iface_type_id__volatile, gmpc_plugin_preferences_iface_type_id);
	}
	return gmpc_plugin_preferences_iface_type_id__volatile;
}


gint gmpc_plugin_song_list_iface_song_list (GmpcPluginSongListIface* self, GtkWidget* tree, GtkMenu* menu) {
	return GMPC_PLUGIN_SONG_LIST_IFACE_GET_INTERFACE (self)->song_list (self, tree, menu);
}


static void gmpc_plugin_song_list_iface_base_init (GmpcPluginSongListIfaceIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType gmpc_plugin_song_list_iface_get_type (void) {
	static volatile gsize gmpc_plugin_song_list_iface_type_id__volatile = 0;
	if (g_once_init_enter (&gmpc_plugin_song_list_iface_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GmpcPluginSongListIfaceIface), (GBaseInitFunc) gmpc_plugin_song_list_iface_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType gmpc_plugin_song_list_iface_type_id;
		gmpc_plugin_song_list_iface_type_id = g_type_register_static (G_TYPE_INTERFACE, "GmpcPluginSongListIface", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (gmpc_plugin_song_list_iface_type_id, GMPC_PLUGIN_TYPE_BASE);
		g_once_init_leave (&gmpc_plugin_song_list_iface_type_id__volatile, gmpc_plugin_song_list_iface_type_id);
	}
	return gmpc_plugin_song_list_iface_type_id__volatile;
}



