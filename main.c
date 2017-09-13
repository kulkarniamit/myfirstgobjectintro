#include <stdio.h>
#include "point.h"

int main(int argc, char *argv[]){
	Point *point = new_point();
	point_set_value(point, 10, 12);
	printf("So the new values (x, y) are (%d, %d)\n",point_get_x(point), point_get_y(point));
	return 0;
}
