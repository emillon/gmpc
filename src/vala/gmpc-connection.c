/* gmpc-connection.c generated by valac 0.12.0, the Vala compiler
 * generated from gmpc-connection.vala, do not modify */

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
#include <libmpd/libmpd.h>



static gpointer gmpc_connection_parent_class = NULL;

enum  {
	GMPC_CONNECTION_DUMMY_PROPERTY
};
static void g_cclosure_user_marshal_VOID__POINTER_INT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);


GmpcConnection* gmpc_connection_construct (GType object_type) {
	GmpcConnection * self = NULL;
	self = (GmpcConnection*) g_object_new (object_type, NULL);
	return self;
}


GmpcConnection* gmpc_connection_new (void) {
	return gmpc_connection_construct (GMPC_TYPE_CONNECTION);
}


static void g_cclosure_user_marshal_VOID__POINTER_INT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__POINTER_INT) (gpointer data1, gpointer arg_1, gint arg_2, gpointer data2);
	register GMarshalFunc_VOID__POINTER_INT callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__POINTER_INT) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_pointer (param_values + 1), g_value_get_int (param_values + 2), data2);
}


static void gmpc_connection_class_init (GmpcConnectionClass * klass) {
	gmpc_connection_parent_class = g_type_class_peek_parent (klass);
	g_signal_new ("connection_changed", GMPC_TYPE_CONNECTION, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__POINTER_INT, G_TYPE_NONE, 2, G_TYPE_POINTER, G_TYPE_INT);
	g_signal_new ("status_changed", GMPC_TYPE_CONNECTION, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__POINTER_INT, G_TYPE_NONE, 2, G_TYPE_POINTER, G_TYPE_INT);
}


static void gmpc_connection_instance_init (GmpcConnection * self) {
}


GType gmpc_connection_get_type (void) {
	static volatile gsize gmpc_connection_type_id__volatile = 0;
	if (g_once_init_enter (&gmpc_connection_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GmpcConnectionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gmpc_connection_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GmpcConnection), 0, (GInstanceInitFunc) gmpc_connection_instance_init, NULL };
		GType gmpc_connection_type_id;
		gmpc_connection_type_id = g_type_register_static (G_TYPE_OBJECT, "GmpcConnection", &g_define_type_info, 0);
		g_once_init_leave (&gmpc_connection_type_id__volatile, gmpc_connection_type_id);
	}
	return gmpc_connection_type_id__volatile;
}



