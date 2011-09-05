/* GmpcVolume.c generated by valac 0.12.0, the Vala compiler
 * generated from GmpcVolume.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include "gmpc-extras.h"
#include <stdlib.h>
#include <string.h>
#include <config.h>
#include <float.h>
#include <math.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo.h>
#include <glib/gi18n-lib.h>

#define _cairo_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_destroy (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _GmpcWidgetsVolumePrivate {
	gint num_blocks;
};


static gpointer gmpc_widgets_volume_parent_class = NULL;

#define GMPC_WIDGETS_VOLUME_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), GMPC_WIDGETS_TYPE_VOLUME, GmpcWidgetsVolumePrivate))
enum  {
	GMPC_WIDGETS_VOLUME_DUMMY_PROPERTY,
	GMPC_WIDGETS_VOLUME_VOLUME_LEVEL
};
#define GMPC_WIDGETS_VOLUME_some_unique_name VERSION
#define GMPC_WIDGETS_VOLUME_BORDER_WIDTH 1
#define GMPC_WIDGETS_VOLUME_DEFAULT_HEIGHT 32
#define GMPC_WIDGETS_VOLUME_DEFAULT_WIDTH 24
#define GMPC_WIDGETS_VOLUME_BLOCK_SPACING ((gdouble) 2)
#define GMPC_WIDGETS_VOLUME_mute_size 1
static void gmpc_widgets_volume_set_volume_level_from_y_pos (GmpcWidgetsVolume* self, gdouble y);
static gboolean gmpc_widgets_volume_b_scroll_event (GmpcWidgetsVolume* self, GdkEventScroll* event);
static gboolean gmpc_widgets_volume_real_button_press_event (GtkWidget* base, GdkEventButton* event);
static gboolean gmpc_widgets_volume_real_button_release_event (GtkWidget* base, GdkEventButton* event);
static gboolean gmpc_widgets_volume_real_motion_notify_event (GtkWidget* base, GdkEventMotion* event);
static void gmpc_widgets_volume_real_size_request (GtkWidget* base, GtkRequisition* requisition);
static void gmpc_widgets_volume_real_size_allocate (GtkWidget* base, GdkRectangle* allocation);
static gboolean gmpc_widgets_volume_real_expose_event (GtkWidget* base, GdkEventExpose* event);
static void g_cclosure_user_marshal_BOOLEAN__INT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);
static GObject * gmpc_widgets_volume_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static gboolean _lambda2_ (GtkWidget* source, GdkEventScroll* event, GmpcWidgetsVolume* self);
static gboolean __lambda2__gtk_widget_scroll_event (GtkWidget* _sender, GdkEventScroll* event, gpointer self);
static void gmpc_widgets_volume_finalize (GObject* obj);
static void _vala_gmpc_widgets_volume_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_gmpc_widgets_volume_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


GmpcWidgetsVolume* gmpc_widgets_volume_construct (GType object_type) {
	GmpcWidgetsVolume * self = NULL;
	self = (GmpcWidgetsVolume*) g_object_new (object_type, NULL);
	return self;
}


GmpcWidgetsVolume* gmpc_widgets_volume_new (void) {
	return gmpc_widgets_volume_construct (GMPC_WIDGETS_TYPE_VOLUME);
}


static void gmpc_widgets_volume_set_volume_level_from_y_pos (GmpcWidgetsVolume* self, gdouble y) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	if (y > GMPC_WIDGETS_VOLUME_BORDER_WIDTH) {
		_tmp0_ = y < (((GtkWidget*) self)->allocation.height - GMPC_WIDGETS_VOLUME_BORDER_WIDTH);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		gdouble _tmp1_;
		gdouble block_height;
		gdouble tvolume_level;
		_tmp1_ = floor ((((GtkWidget*) self)->allocation.height - (GMPC_WIDGETS_VOLUME_BORDER_WIDTH * 2)) / ((gdouble) self->priv->num_blocks));
		block_height = _tmp1_;
		tvolume_level = 1 - (((y - GMPC_WIDGETS_VOLUME_BORDER_WIDTH) - (block_height * 0.5)) / (block_height * (self->priv->num_blocks - 1)));
		gmpc_widgets_volume_set_volume_level (self, (gint) (tvolume_level * 100.0));
	}
}


static gboolean gmpc_widgets_volume_b_scroll_event (GmpcWidgetsVolume* self, GdkEventScroll* event) {
	gboolean result = FALSE;
	gint tvolume_level;
	g_return_val_if_fail (self != NULL, FALSE);
	tvolume_level = self->_volume_level;
	if ((*event).direction == GDK_SCROLL_UP) {
		gmpc_widgets_volume_set_volume_level (self, tvolume_level + 5);
	} else {
		if ((*event).direction == GDK_SCROLL_DOWN) {
			gmpc_widgets_volume_set_volume_level (self, tvolume_level - 5);
		}
	}
	result = FALSE;
	return result;
}


static gboolean gmpc_widgets_volume_real_button_press_event (GtkWidget* base, GdkEventButton* event) {
	GmpcWidgetsVolume * self;
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	self = (GmpcWidgetsVolume*) base;
	if ((*event).x > GMPC_WIDGETS_VOLUME_BORDER_WIDTH) {
		_tmp0_ = (*event).x < (((GtkWidget*) self)->allocation.width - GMPC_WIDGETS_VOLUME_BORDER_WIDTH);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		gmpc_widgets_volume_set_volume_level_from_y_pos (self, (*event).y);
	}
	result = FALSE;
	return result;
}


static gboolean gmpc_widgets_volume_real_button_release_event (GtkWidget* base, GdkEventButton* event) {
	GmpcWidgetsVolume * self;
	gboolean result = FALSE;
	self = (GmpcWidgetsVolume*) base;
	result = FALSE;
	return result;
}


static gboolean gmpc_widgets_volume_real_motion_notify_event (GtkWidget* base, GdkEventMotion* event) {
	GmpcWidgetsVolume * self;
	gboolean result = FALSE;
	self = (GmpcWidgetsVolume*) base;
	if (((*event).state & GDK_BUTTON1_MASK) == GDK_BUTTON1_MASK) {
		gmpc_widgets_volume_set_volume_level_from_y_pos (self, (*event).y);
	}
	result = FALSE;
	return result;
}


static void gmpc_widgets_volume_real_size_request (GtkWidget* base, GtkRequisition* requisition) {
	GmpcWidgetsVolume * self;
	GtkRequisition _requisition = {0};
	self = (GmpcWidgetsVolume*) base;
	_requisition.width = (GMPC_WIDGETS_VOLUME_BORDER_WIDTH * 2) + GMPC_WIDGETS_VOLUME_DEFAULT_WIDTH;
	_requisition.height = (GMPC_WIDGETS_VOLUME_BORDER_WIDTH * 2) + GMPC_WIDGETS_VOLUME_DEFAULT_HEIGHT;
	if (requisition) {
		*requisition = _requisition;
	}
}


static void gmpc_widgets_volume_real_size_allocate (GtkWidget* base, GdkRectangle* allocation) {
	GmpcWidgetsVolume * self;
	gdouble _tmp0_;
	gint _tmp1_;
	self = (GmpcWidgetsVolume*) base;
	GTK_WIDGET_CLASS (gmpc_widgets_volume_parent_class)->size_allocate ((GtkWidget*) GTK_EVENT_BOX (self), allocation);
	_tmp0_ = ceil ((*allocation).height / 8.0);
	_tmp1_ = MAX ((gint) _tmp0_, 4);
	self->priv->num_blocks = _tmp1_;
}


static gboolean gmpc_widgets_volume_real_expose_event (GtkWidget* base, GdkEventExpose* event) {
	GmpcWidgetsVolume * self;
	gboolean result = FALSE;
	cairo_t* _tmp0_ = NULL;
	cairo_t* cr;
	GtkStyle* _tmp1_ = NULL;
	GdkColor _tmp2_;
	gint _tmp3_;
	gdouble svol;
	gdouble _tmp4_;
	gdouble block_height;
	gdouble block_width;
	gint _tmp9_;
	self = (GmpcWidgetsVolume*) base;
	_tmp0_ = gdk_cairo_create ((GdkDrawable*) ((GtkWidget*) self)->window);
	cr = _tmp0_;
	cairo_set_line_width (cr, 1.0);
	cairo_set_line_join (cr, CAIRO_LINE_JOIN_ROUND);
	_tmp1_ = gtk_widget_get_style ((GtkWidget*) self);
	_tmp2_ = _tmp1_->fg[((GtkWidget*) self)->state];
	gdk_cairo_set_source_color (cr, &_tmp2_);
	_tmp3_ = gmpc_widgets_volume_get_volume_level (self);
	svol = _tmp3_ / 100.0;
	_tmp4_ = floor ((((GtkWidget*) self)->allocation.height - (GMPC_WIDGETS_VOLUME_BORDER_WIDTH * 2)) / ((gdouble) self->priv->num_blocks));
	block_height = _tmp4_;
	block_width = (((GtkWidget*) self)->allocation.width - (2 * GMPC_WIDGETS_VOLUME_BORDER_WIDTH)) - GMPC_WIDGETS_VOLUME_BLOCK_SPACING;
	{
		gint i;
		i = 0;
		{
			gboolean _tmp5_;
			_tmp5_ = TRUE;
			while (TRUE) {
				gdouble bvolume_level;
				gint bw;
				gdouble _tmp6_;
				gboolean _tmp7_ = FALSE;
				gint _tmp8_;
				if (!_tmp5_) {
					i++;
				}
				_tmp5_ = FALSE;
				if (!(i < self->priv->num_blocks)) {
					break;
				}
				bvolume_level = 1.0 - (i / ((gdouble) self->priv->num_blocks));
				bw = (gint) ((block_width * bvolume_level) + GMPC_WIDGETS_VOLUME_BLOCK_SPACING);
				_tmp6_ = ceil (GMPC_WIDGETS_VOLUME_BORDER_WIDTH + (block_height * i));
				cairo_rectangle (cr, (((((GtkWidget*) self)->allocation.x + ((GtkWidget*) self)->allocation.width) - GMPC_WIDGETS_VOLUME_BORDER_WIDTH) - bw) + 0.5, ((((GtkWidget*) self)->allocation.y + _tmp6_) + 0.5) + GMPC_WIDGETS_VOLUME_BLOCK_SPACING, (gdouble) bw, block_height - (2 * GMPC_WIDGETS_VOLUME_BLOCK_SPACING));
				_tmp8_ = gmpc_widgets_volume_get_volume_level (self);
				if (_tmp8_ > 0) {
					_tmp7_ = (bvolume_level - (1 / (1.0 * self->priv->num_blocks))) <= svol;
				} else {
					_tmp7_ = FALSE;
				}
				if (_tmp7_) {
					cairo_fill_preserve (cr);
				}
				cairo_stroke (cr);
			}
		}
	}
	_tmp9_ = gmpc_widgets_volume_get_volume_level (self);
	if (_tmp9_ == 0) {
		GtkStyle* _tmp10_ = NULL;
		GdkColor _tmp11_;
		cairo_arc (cr, (((((GtkWidget*) self)->allocation.x + 0.5) + GMPC_WIDGETS_VOLUME_BORDER_WIDTH) + (GMPC_WIDGETS_VOLUME_mute_size * block_height)) + 4, ((((((GtkWidget*) self)->allocation.y + 0.5) + ((GtkWidget*) self)->allocation.height) - GMPC_WIDGETS_VOLUME_BORDER_WIDTH) - (GMPC_WIDGETS_VOLUME_mute_size * block_height)) - 4, GMPC_WIDGETS_VOLUME_mute_size * block_height, (gdouble) 0, 2 * G_PI);
		cairo_set_line_width (cr, 3.5);
		cairo_stroke_preserve (cr);
		cairo_set_line_width (cr, 2.0);
		cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);
		cairo_stroke_preserve (cr);
		cairo_clip (cr);
		_tmp10_ = gtk_widget_get_style ((GtkWidget*) self);
		_tmp11_ = _tmp10_->fg[((GtkWidget*) self)->state];
		gdk_cairo_set_source_color (cr, &_tmp11_);
		cairo_new_path (cr);
		cairo_move_to (cr, (gdouble) ((((GtkWidget*) self)->allocation.x + GMPC_WIDGETS_VOLUME_BORDER_WIDTH) + 4), (gdouble) (((((GtkWidget*) self)->allocation.y + ((GtkWidget*) self)->allocation.height) - GMPC_WIDGETS_VOLUME_BORDER_WIDTH) - 3));
		cairo_line_to (cr, ((((GtkWidget*) self)->allocation.x + GMPC_WIDGETS_VOLUME_BORDER_WIDTH) + ((2 * GMPC_WIDGETS_VOLUME_mute_size) * block_height)) + 4, (((((GtkWidget*) self)->allocation.y + ((GtkWidget*) self)->allocation.height) - GMPC_WIDGETS_VOLUME_BORDER_WIDTH) - ((2 * GMPC_WIDGETS_VOLUME_mute_size) * block_height)) - 3);
		cairo_set_line_width (cr, 3.5);
		cairo_stroke_preserve (cr);
		cairo_set_line_width (cr, 2.0);
		cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);
		cairo_stroke (cr);
	}
	result = TRUE;
	_cairo_destroy0 (cr);
	return result;
}


gint gmpc_widgets_volume_get_volume_level (GmpcWidgetsVolume* self) {
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->_volume_level;
	return result;
}


void gmpc_widgets_volume_set_volume_level (GmpcWidgetsVolume* self, gint value) {
	gint _tmp0_ = 0;
	gint temp;
	g_return_if_fail (self != NULL);
	if (value > 100) {
		_tmp0_ = 100;
	} else {
		gint _tmp1_ = 0;
		if (value < 0) {
			_tmp1_ = 0;
		} else {
			_tmp1_ = value;
		}
		_tmp0_ = _tmp1_;
	}
	temp = _tmp0_;
	if (temp != self->_volume_level) {
		gboolean _tmp2_;
		gboolean _tmp3_;
		g_signal_emit_by_name (self, "value-changed", temp, &_tmp2_);
		_tmp3_ = _tmp2_;
		if (!_tmp3_) {
			self->_volume_level = temp;
			if (temp > 0) {
				const gchar* _tmp4_ = NULL;
				gchar* _tmp5_ = NULL;
				gchar* _tmp6_;
				_tmp4_ = _ ("Volume");
				_tmp5_ = g_strdup_printf ("%s: %i%%", _tmp4_, temp);
				_tmp6_ = _tmp5_;
				gtk_widget_set_tooltip_text ((GtkWidget*) self, _tmp6_);
				_g_free0 (_tmp6_);
			} else {
				const gchar* _tmp7_ = NULL;
				const gchar* _tmp8_ = NULL;
				gchar* _tmp9_ = NULL;
				gchar* _tmp10_;
				_tmp7_ = _ ("Volume");
				_tmp8_ = _ ("Muted");
				_tmp9_ = g_strdup_printf ("%s: %s", _tmp7_, _tmp8_);
				_tmp10_ = _tmp9_;
				gtk_widget_set_tooltip_text ((GtkWidget*) self, _tmp10_);
				_g_free0 (_tmp10_);
			}
			gtk_widget_queue_draw ((GtkWidget*) self);
		}
	}
	g_object_notify ((GObject *) self, "volume-level");
}


static void g_cclosure_user_marshal_BOOLEAN__INT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef gboolean (*GMarshalFunc_BOOLEAN__INT) (gpointer data1, gint arg_1, gpointer data2);
	register GMarshalFunc_BOOLEAN__INT callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	gboolean v_return;
	cc = (GCClosure *) closure;
	g_return_if_fail (return_value != NULL);
	g_return_if_fail (n_param_values == 2);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_BOOLEAN__INT) (marshal_data ? marshal_data : cc->callback);
	v_return = callback (data1, g_value_get_int (param_values + 1), data2);
	g_value_set_boolean (return_value, v_return);
}


static gboolean _lambda2_ (GtkWidget* source, GdkEventScroll* event, GmpcWidgetsVolume* self) {
	gboolean result = FALSE;
	gboolean _tmp0_;
	g_return_val_if_fail (source != NULL, FALSE);
	_tmp0_ = gmpc_widgets_volume_b_scroll_event (self, event);
	result = _tmp0_;
	return result;
}


static gboolean __lambda2__gtk_widget_scroll_event (GtkWidget* _sender, GdkEventScroll* event, gpointer self) {
	gboolean result;
	result = _lambda2_ (_sender, event, self);
	return result;
}


static GObject * gmpc_widgets_volume_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	GmpcWidgetsVolume * self;
	parent_class = G_OBJECT_CLASS (gmpc_widgets_volume_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = GMPC_WIDGETS_VOLUME (obj);
	gtk_widget_set_app_paintable ((GtkWidget*) self, TRUE);
	gtk_widget_set_has_window ((GtkWidget*) self, FALSE);
	gtk_widget_add_events ((GtkWidget*) self, (gint) (((GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK) | GDK_POINTER_MOTION_MASK) | GDK_SCROLL_MASK));
	g_signal_connect_object ((GtkWidget*) self, "scroll-event", (GCallback) __lambda2__gtk_widget_scroll_event, self, 0);
	return obj;
}


static void gmpc_widgets_volume_class_init (GmpcWidgetsVolumeClass * klass) {
	gmpc_widgets_volume_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (GmpcWidgetsVolumePrivate));
	GTK_WIDGET_CLASS (klass)->button_press_event = gmpc_widgets_volume_real_button_press_event;
	GTK_WIDGET_CLASS (klass)->button_release_event = gmpc_widgets_volume_real_button_release_event;
	GTK_WIDGET_CLASS (klass)->motion_notify_event = gmpc_widgets_volume_real_motion_notify_event;
	GTK_WIDGET_CLASS (klass)->size_request = gmpc_widgets_volume_real_size_request;
	GTK_WIDGET_CLASS (klass)->size_allocate = gmpc_widgets_volume_real_size_allocate;
	GTK_WIDGET_CLASS (klass)->expose_event = gmpc_widgets_volume_real_expose_event;
	G_OBJECT_CLASS (klass)->get_property = _vala_gmpc_widgets_volume_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_gmpc_widgets_volume_set_property;
	G_OBJECT_CLASS (klass)->constructor = gmpc_widgets_volume_constructor;
	G_OBJECT_CLASS (klass)->finalize = gmpc_widgets_volume_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), GMPC_WIDGETS_VOLUME_VOLUME_LEVEL, g_param_spec_int ("volume-level", "volume-level", "volume-level", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_signal_new ("value_changed", GMPC_WIDGETS_TYPE_VOLUME, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_BOOLEAN__INT, G_TYPE_BOOLEAN, 1, G_TYPE_INT);
}


static void gmpc_widgets_volume_instance_init (GmpcWidgetsVolume * self) {
	self->priv = GMPC_WIDGETS_VOLUME_GET_PRIVATE (self);
	self->priv->num_blocks = 8;
	self->_volume_level = 0;
}


static void gmpc_widgets_volume_finalize (GObject* obj) {
	GmpcWidgetsVolume * self;
	self = GMPC_WIDGETS_VOLUME (obj);
	G_OBJECT_CLASS (gmpc_widgets_volume_parent_class)->finalize (obj);
}


GType gmpc_widgets_volume_get_type (void) {
	static volatile gsize gmpc_widgets_volume_type_id__volatile = 0;
	if (g_once_init_enter (&gmpc_widgets_volume_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GmpcWidgetsVolumeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gmpc_widgets_volume_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GmpcWidgetsVolume), 0, (GInstanceInitFunc) gmpc_widgets_volume_instance_init, NULL };
		GType gmpc_widgets_volume_type_id;
		gmpc_widgets_volume_type_id = g_type_register_static (GTK_TYPE_EVENT_BOX, "GmpcWidgetsVolume", &g_define_type_info, 0);
		g_once_init_leave (&gmpc_widgets_volume_type_id__volatile, gmpc_widgets_volume_type_id);
	}
	return gmpc_widgets_volume_type_id__volatile;
}


static void _vala_gmpc_widgets_volume_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	GmpcWidgetsVolume * self;
	self = GMPC_WIDGETS_VOLUME (object);
	switch (property_id) {
		case GMPC_WIDGETS_VOLUME_VOLUME_LEVEL:
		g_value_set_int (value, gmpc_widgets_volume_get_volume_level (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_gmpc_widgets_volume_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	GmpcWidgetsVolume * self;
	self = GMPC_WIDGETS_VOLUME (object);
	switch (property_id) {
		case GMPC_WIDGETS_VOLUME_VOLUME_LEVEL:
		gmpc_widgets_volume_set_volume_level (self, g_value_get_int (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



