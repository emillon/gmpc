/* gmpc-liststore-sort.c generated by valac, the Vala compiler
 * generated from gmpc-liststore-sort.vala, do not modify */

/* Gnome Music Player Client (GMPC)
 * Copyright (C) 2004-2010 Qball Cow <qball@sarine.nl>
 * Project homepage: http://gmpc.wikia.com/
 
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
#include <gtk/gtk.h>
#include <gtktransition.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _gtk_tree_path_free0(var) ((var == NULL) ? NULL : (var = (gtk_tree_path_free (var), NULL)))


static gpointer gmpc_liststore_sort_parent_class = NULL;
static GtkTreeDragSourceIface* gmpc_liststore_sort_gtk_tree_drag_source_parent_iface = NULL;
static GtkTreeDragDestIface* gmpc_liststore_sort_gtk_tree_drag_dest_parent_iface = NULL;

enum  {
	GMPC_LISTSTORE_SORT_DUMMY_PROPERTY
};
#define GMPC_LISTSTORE_SORT_use_transition TRUE
static gboolean gmpc_liststore_sort_real_row_draggable (GtkTreeDragSource* base, GtkTreePath* path);
static gboolean gmpc_liststore_sort_real_drag_data_get (GtkTreeDragSource* base, GtkTreePath* path, GtkSelectionData* selection_data);
static gboolean gmpc_liststore_sort_real_drag_data_delete (GtkTreeDragSource* base, GtkTreePath* path);
static gboolean gmpc_liststore_sort_real_drag_data_received (GtkTreeDragDest* base, GtkTreePath* dest, GtkSelectionData* selection_data);



static gboolean gmpc_liststore_sort_real_row_draggable (GtkTreeDragSource* base, GtkTreePath* path) {
	GmpcListstoreSort * self;
	gboolean result;
	self = (GmpcListstoreSort*) base;
	g_return_val_if_fail (path != NULL, FALSE);
	result = TRUE;
	return result;
}


static gboolean gmpc_liststore_sort_real_drag_data_get (GtkTreeDragSource* base, GtkTreePath* path, GtkSelectionData* selection_data) {
	GmpcListstoreSort * self;
	gboolean result;
	self = (GmpcListstoreSort*) base;
	g_return_val_if_fail (path != NULL, FALSE);
	g_return_val_if_fail (selection_data != NULL, FALSE);
	result = FALSE;
	return result;
}


static gboolean gmpc_liststore_sort_real_drag_data_delete (GtkTreeDragSource* base, GtkTreePath* path) {
	GmpcListstoreSort * self;
	gboolean result;
	self = (GmpcListstoreSort*) base;
	g_return_val_if_fail (path != NULL, FALSE);
	result = TRUE;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gpointer _gtk_tree_path_copy0 (gpointer self) {
	return self ? gtk_tree_path_copy (self) : NULL;
}


static gboolean gmpc_liststore_sort_real_drag_data_received (GtkTreeDragDest* base, GtkTreePath* dest, GtkSelectionData* selection_data) {
	GmpcListstoreSort * self;
	gboolean result;
	GtkTreeModel* model;
	GtkTreePath* path;
	GtkTreePath* _tmp5_;
	gboolean _tmp4_;
	GtkTreePath* _tmp3_ = NULL;
	GtkTreeModel* _tmp2_;
	gboolean _tmp1_;
	GtkTreeModel* _tmp0_ = NULL;
	self = (GmpcListstoreSort*) base;
	g_return_val_if_fail (dest != NULL, FALSE);
	g_return_val_if_fail (selection_data != NULL, FALSE);
	model = NULL;
	path = NULL;
	if (dest == NULL) {
		result = FALSE;
		_g_object_unref0 (model);
		_gtk_tree_path_free0 (path);
		return result;
	}
	if ((_tmp4_ = (_tmp1_ = gtk_tree_get_row_drag_data (selection_data, &_tmp0_, &_tmp3_), model = (_tmp2_ = _g_object_ref0 (_tmp0_), _g_object_unref0 (model), _tmp2_), _tmp1_), path = (_tmp5_ = _gtk_tree_path_copy0 (_tmp3_), _gtk_tree_path_free0 (path), _tmp5_), _tmp4_)) {
		GtkTreeIter dest_iter = {0};
		GtkTreeIter source_iter = {0};
		gboolean dest_v;
		gboolean source_v;
		dest_v = gtk_tree_model_get_iter (model, &dest_iter, dest);
		source_v = gtk_tree_model_get_iter (model, &source_iter, path);
		if (source_v) {
			if (dest_v) {
				gtk_list_store_move_before ((GtkListStore*) self, &source_iter, &dest_iter);
			} else {
				gtk_list_store_move_before ((GtkListStore*) self, &source_iter, NULL);
			}
		}
		result = TRUE;
		_g_object_unref0 (model);
		_gtk_tree_path_free0 (path);
		return result;
	}
	result = FALSE;
	_g_object_unref0 (model);
	_gtk_tree_path_free0 (path);
	return result;
}


GmpcListstoreSort* gmpc_liststore_sort_construct (GType object_type) {
	GmpcListstoreSort * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


GmpcListstoreSort* gmpc_liststore_sort_new (void) {
	return gmpc_liststore_sort_construct (GMPC_LISTSTORE_TYPE_SORT);
}


static void gmpc_liststore_sort_class_init (GmpcListstoreSortClass * klass) {
	gmpc_liststore_sort_parent_class = g_type_class_peek_parent (klass);
}


static void gmpc_liststore_sort_gtk_tree_drag_source_interface_init (GtkTreeDragSourceIface * iface) {
	gmpc_liststore_sort_gtk_tree_drag_source_parent_iface = g_type_interface_peek_parent (iface);
	iface->row_draggable = gmpc_liststore_sort_real_row_draggable;
	iface->drag_data_get = gmpc_liststore_sort_real_drag_data_get;
	iface->drag_data_delete = gmpc_liststore_sort_real_drag_data_delete;
}


static void gmpc_liststore_sort_gtk_tree_drag_dest_interface_init (GtkTreeDragDestIface * iface) {
	gmpc_liststore_sort_gtk_tree_drag_dest_parent_iface = g_type_interface_peek_parent (iface);
	iface->drag_data_received = gmpc_liststore_sort_real_drag_data_received;
}


static void gmpc_liststore_sort_instance_init (GmpcListstoreSort * self) {
}


GType gmpc_liststore_sort_get_type (void) {
	static GType gmpc_liststore_sort_type_id = 0;
	if (gmpc_liststore_sort_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (GmpcListstoreSortClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gmpc_liststore_sort_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GmpcListstoreSort), 0, (GInstanceInitFunc) gmpc_liststore_sort_instance_init, NULL };
		static const GInterfaceInfo gtk_tree_drag_source_info = { (GInterfaceInitFunc) gmpc_liststore_sort_gtk_tree_drag_source_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		static const GInterfaceInfo gtk_tree_drag_dest_info = { (GInterfaceInitFunc) gmpc_liststore_sort_gtk_tree_drag_dest_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		gmpc_liststore_sort_type_id = g_type_register_static (GTK_TYPE_LIST_STORE, "GmpcListstoreSort", &g_define_type_info, 0);
		g_type_add_interface_static (gmpc_liststore_sort_type_id, GTK_TYPE_TREE_DRAG_SOURCE, &gtk_tree_drag_source_info);
		g_type_add_interface_static (gmpc_liststore_sort_type_id, GTK_TYPE_TREE_DRAG_DEST, &gtk_tree_drag_dest_info);
	}
	return gmpc_liststore_sort_type_id;
}




