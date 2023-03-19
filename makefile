CFLAGS=-lm

all: run

build:
	gcc header.h tema1-sda.c lista.c stiva.c coada.c -o tema1-sda -lm -Wall
	touch tema1-sda.out

clean:
	rm *.out tema1-sda

run:
	make build
	./tema1-sda
	rm tema1-sda
