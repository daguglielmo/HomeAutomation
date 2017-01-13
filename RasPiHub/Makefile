CFLAGS=-Wall -ggdb -I/usr/include/
LDFLAGS=-lmosquittopp

.PHONY: all clean

all : Hub

Hub : Main.o MyMqtt.o
	${CXX} $^ -o $@ ${LDFLAGS}

Main.o : Main.cpp
	${CXX} -c $^ -o $@ ${CFLAGS}

MyMqtt.o : MyMqtt.cpp
	${CXX} -c $^ -o $@ ${CFLAGS}

clean :
	-rm -f *.o Hub
