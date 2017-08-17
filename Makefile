.SUFFIXES: .c .o .cpp .cc .cxx .C

UNAME = $(shell uname)
PLATFORM = $(shell uname -p)

CC = g++
COPTS = -g -Wall

INCDIR =
LIBDIR =

ifeq ("$(shell uname)", "Linux")
INC = \
  -I/usr/lib/glut-3.7/include
LIBDIR = \
  -L/usr/lib -L/usr/X11R6/lib -L/usr/lib/glut-3.7/lib/glut
LIBS = \
  -lglut -lGLU -lGL -lXmu -lXi -lXext -lX11 -lm
else
ifeq ("$(shell uname)", "Darwin")
LIBS = \
  -framework OpenGL -framework GLUT -framework Foundation -lstdc++
endif
endif

.c.o:
	$(CC) -c $(INCDIR) $(COPTS) -o $@ $<

.cpp.o:
	$(CC) -c $(INCDIR) $(COPTS) -o $@ $<

all : simple

OBJECTS = \
face.o camera.o aw.o vertex.o

simple: $(OBJECTS) simple.o
	$(CC) -o $@ $(INCDIR) $(COPTS) $(OBJECTS) $@.o $(LIBDIR) $(LIBS)

face.o: face.h face.cpp

camera.o: camera.h camera.cpp

aw.o: aw.h aw.cpp

vertex.o: vertex.h vertex.cpp

clean :
	rm -f *.o
	rm -f *~
	rm -rf simple
