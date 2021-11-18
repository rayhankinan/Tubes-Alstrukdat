CC=gcc
TARGET=main

all:
	$(CC) Tubes/*.c ADT/LinkedList/*.c ADT/ListDinamis/*.c ADT/ListStatis/*.c ADT/Matrix/*.c ADT/Mesin/*.c ADT/Point/*.c ADT/Queue/*.c ADT/Stack/*.c ADT/Lokasi/*.c ADT/Item/*.c ADT/Player/*.c ADT/PColor/*.c -o $(TARGET)

clean:
	rm $(TARGET).exe