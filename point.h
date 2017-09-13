#include <glib-object.h>
#include <glib.h>

/* 	
 *	Returns a value corresponding to the type of our class
 *	The syntax is <classname_with_underscores>_get_type()
 *  The name can be anything: POINT_TYPE or TREX_POINT
 *   For example: MyObject class would have it as 
 *	my_object_get_type()
*/
#define POINT_TYPE (point_get_type())

/* Boilerplate defines
 * NOTE: It is not mandatory to write these defines unless required by your code 
 * Your Thrift code MAY require some of these, so just be aware of this stuff
 */
/* up-cast an instance (object) of a subclass to the Point type */
#define POINT(obj)                   (G_TYPE_CHECK_INSTANCE_CAST ((obj), POINT_TYPE, POINT))

/* To test whether an object is an instance of the Point class */ 
#define IS_POINT(obj)                (G_TYPE_CHECK_INSTANCE_TYPE ((obj), POINT_TYPE))

/* up-cast a subclass to the Point class */ 
#define POINT_CLASS(_class)          (G_TYPE_CHECK_CLASS_CAST ((_class), POINT_TYPE, PointClass))

/* This macro acts like the instanceof function in Java. 
 * To test if a given class is a subclass of Point 
 */ 
#define IS_POINT_CLASS(_class)       (G_TYPE_CHECK_CLASS_TYPE ((_class), POINT_TYPE))

/* obtain the actual class structure (which can be a subclass of Point) 
 * from an object (class instance)
 */
#define POINT_GET_CLASS(obj)         (G_TYPE_INSTANCE_GET_CLASS ((obj), POINT_TYPE, PointClass))
/* End of Boilerplate defines */

/* To declare derivable class, macro G_DECLARE_DERIVABLE_TYPE is used */
/*
ModuleObjName	The name of the new type, in camel case (like GtkWidget)
module_obj_name	The name of the new type in lowercase, with words separated by '_' (like 'gtk_widget')
MODULE	The name of the module, in all caps (like 'GTK')
OBJ_NAME	The bare name of the type, in all caps (like 'WIDGET')
ParentName	the name of the parent type, in camel case (like GtkWidget)

This also performs the following:
Point struct is created with GObject as the first and only item. 
*/
G_DECLARE_DERIVABLE_TYPE(Point, point, ,POINT, GObject)

typedef struct _PointClass{
	/* Name of the parent class can be anything */
//	GObjectClass parent_class;
	GObjectClass appa_amma_class;
	void (*set_value) (Point *self, int x, int y);
	int (*get_x) (Point *self);
	int (*get_y) (Point *self);
}PointClass;

Point *new_point(void);

void point_set_value(Point *self, int x, int y);
int point_get_x(Point *self);
int point_get_y(Point *self);
