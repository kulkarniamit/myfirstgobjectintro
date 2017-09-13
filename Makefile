CC = gcc
CFLAGS = -Wall -ggdb3 `pkg-config --libs --cflags glib-2.0 gobject-2.0`
SRC = main.c point.c point.h

main: $(SRC)
	$(CC) -o $@ $(SRC) $(CFLAGS)

clean:
	rm -rf main
