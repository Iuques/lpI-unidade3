build: bin/main.o bin/autocompletar.o bin/termo.o include/listaordenada.h
	g++ -o bin/main src/termo.cpp src/autocompletar.cpp src/main.cpp -I./include

all: bin/main.o bin/autocompletar.o bin/termo.o include/listaordenada.h
	g++ -o main listaordenada.o termo.o autocompletar.o main.o -I./include

bin/main.o: bin/autocompletar.o bin/termo.o include/listaordenada.h
	g++ -o bin/main.o -c src/main.cpp -I./include

bin/autocompletar.o: bin/termo.o src/autocompletar.cpp include/autocompletar.h include/listaordenada.h
	g++ -o bin/autocompletar.o -c src/autocompletar.cpp -I./include

bin/termo.o: src/termo.cpp include/termo.h
	g++ -o bin/termo.o -c src/termo.cpp -I./include

clean: 
	rm -f *.o *.out bin/*