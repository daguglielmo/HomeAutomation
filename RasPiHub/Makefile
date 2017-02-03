CFLAGS=-Wall -ggdb -I/usr/include/
LDFLAGS=-lmosquittopp -lrf24-bcm -lrf24network -lrf24mesh

.PHONY: all clean

all : Hub

Hub : Main.o MyMqtt.o Verification.o MeshNet.o
	${CXX} $^ -o $@ ${LDFLAGS}

Main.o : Main.cpp
	${CXX} -c $^ -o $@ ${CFLAGS}

MyMqtt.o : MyMqtt.cpp
	${CXX} -c $^ -o $@ ${CFLAGS}

Verification.o : Verification.cpp
	${CXX} -c $^ -o $@ ${CFLAGS}

MeshNet.o : MeshNet.cpp
	${CXX} -c $^ -o $@ ${CFLAGS}

clean :
	-rm -f *.o Hub
