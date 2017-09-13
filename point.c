#include "point.h"
#include <stdio.h>
#include <glib.h>

typedef struct _PointPrivate PointPrivate;

/* Below macro performs the following:
 * 1. Register our type in the type system
 * 2. Creates the point_get_type() function
 * 3. Creates prototypes for class and instance initialization
 * 4. Creates a static variable named point_parent_class
 * Syntax of arguments: 
 * 1. Name of new type in camel case
 * 2. Name of new type in lower case with words separated by '_'
 * 3. GType of the parent type
*/
G_DEFINE_TYPE (Point, point, G_TYPE_OBJECT);

struct _PointPrivate{
	int x, y;
};

/* Generic defines for quick retrieval */

/* obtain the actual class structure (which can be a subclass of Point)
 * from an object (class instance)
 */
#define POINT_GET_CLASS(object) (G_TYPE_INSTANCE_GET_CLASS((object), POINT_TYPE, PointClass))
#define POINT_GET_PRIVATE(object) (G_TYPE_INSTANCE_GET_PRIVATE((object), POINT_TYPE, PointPrivate))

void point_private_set_value(Point *self, int x, int y){
	PointPrivate *priv = POINT_GET_PRIVATE(self);
	priv->x = x;
	priv->y = y;
}

int point_private_get_x(Point *self){
	PointPrivate *priv = POINT_GET_PRIVATE(self);
	return priv->x;
}

int point_private_get_y(Point *self){
	PointPrivate *priv = POINT_GET_PRIVATE(self);
	return priv->y;
}

/* Implement the initialization functions */
static void point_class_init(PointClass *kclass){
	// Add your private properties to Class
	g_type_class_add_private(kclass, sizeof(PointPrivate));
	kclass->set_value = point_private_set_value;
	kclass->get_x = point_private_get_x;
	kclass->get_y = point_private_get_y;
}

static void point_init(Point *self){}

Point *new_point(void){
	/*
	 * When creating a new object using g_object_new() function,
	 * there is a certain sequence of steps executed. The sequence is:
	 * _class_init()
	 * constructor()
	 * constructed()
	 * _init()
	 * Of those four, the first and fourth, are mandatory and have to be defined
	 * in the source. The second and third steps are optional and you define them 
	 * in class constructor (_class_init()) by assigning appropriate pointers to 
	 * the class interface.
	
	 * Note that g_object_new() accepts an object type that should be created and 
	 * a sequence of attribute-value pairs terminated with a single NULL. 
	 * Those attribute-value pairs are used to set properties of an object but 
	 * only after object constructor finishes
	 */
	return g_object_new(POINT_TYPE, NULL);
}

/* define the declared public functions of the Point instance */
void point_set_value(Point *self, int x, int y){
	PointClass *klass = _POINT_GET_CLASS(self);
	klass->set_value(self, x, y);
}

int point_get_x(Point *self){
	PointClass *klass = _POINT_GET_CLASS(self);
	return klass->get_x(self);
}

int point_get_y(Point *self){
	PointClass *klass = _POINT_GET_CLASS(self);
	return klass->get_y(self);
}

