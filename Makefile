gobjectrun:	main.c point.c point.h
#	gcc -Wall -ggdb3 -o gobjectrun `pkg-config --libs --cflags glib-2.0 gobject-2.0` main.c point.c
	gcc -Wall -ggdb3 -o gobjectrun main.c point.c `pkg-config --libs --cflags glib-2.0 gobject-2.0`

clean:
	rm -rf gobjectrun
