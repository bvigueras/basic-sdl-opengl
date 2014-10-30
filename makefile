CFLAGS := -c -Wall
LDFLAGS := `sdl-config --cflags --libs` -lSDL -lGL
LDLIBS := -lSDL -lGL
CC := gcc

all: basic_sdl_opengl

basic_sdl_opengl: basic_sdl_opengl.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

basic_sdl_opengl.o: basic_sdl_opengl.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	@echo Cleaning up...
	rm -f *~ *.o basic_sdl_opengl
	@echo Done.

vclean: clean
