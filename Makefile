#Makefile for table_top.cpp

CC     = g++
CFLAGS = -Wall -Wextra -g
LIBS   += -lSDL2 -lSDL2main -lSDL2_ttf

SRC    = SDL_Utils.cpp pieces.cpp
OBJS   = SDL_Utils.o   pieces.o

all: table_top

table_top: table_top.cpp $(OBJS)
	$(CC) $(CFLAGS) -o table_top table_top.cpp $(OBJS) $(LIBS)

%.o: %.c *.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f table_top *.o
