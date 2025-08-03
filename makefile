all: programa

programa: main.o grafo.o dijkstra.o
	gcc -o programa main.o grafo.o dijkstra.o

main.o: main.c grafo.h dijkstra.h
	gcc -c main.c

grafo.o: grafo.c grafo.h
	gcc -c grafo.c

dijkstra.o: dijkstra.c dijkstra.h
	gcc -c dijkstra.c

clean:
	rm -f *.o programa
