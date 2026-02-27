CC = gcc -Wall -pedantic

main: element linked_list
	$(CC) -o build/main main.c build/element.o build/linked_list.o

build:
	mkdir -p build

element: build
	$(CC) -c -o build/element.o element.c

linked_list: element
	$(CC) -c -o build/linked_list.o linked_list.c

clean:
	rm -rf build

run: main
	./build/main
