# sythetiseur_vhdl
TARGET=bin/Main
SRCDIR=src
INCDIR=lib
INCLUDE=-I$(INCDIR)
CFLAGS=-g $(INCLUDE)
SRC=$(wildcard $(SRCDIR)/*.cc)
OBJ=$(SRC:.c=obj:.o)

all : main

#main :  Main.o Node.o
#	g++ -o Main.exe $^ $(LDFLAGS)

main   : $(OBJ)
	g++ $^ -o $(TARGET)

%.o : %.cc
	g++ $< $(CFLAGS) -c $(basename $<).o

#%.o:%.cc
#	g++ $(CFLAGS) -c -g $^

clean:
	rm -f *.o *~ bin/Main

