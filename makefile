P=maze
OBJECTS=
CFLAGS = `pkg-config --cflags glib-2.0` -g -Wall -O3 -ftest-coverage -std=c99
LDLIBS=`pkg-config --libs glib-2.0`
CC=clang

$(P): $(OBJECTS)

