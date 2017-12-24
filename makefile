SOURCE_NAME = main
OUTPUT_NAME = KruskalAlgorithm

.PHONY:all
all:clean build run

.PHONY:clean
clean:
	rm -rf bin

build:$(SOURCE_NAME).cpp
	mkdir bin
	g++ -std=c++11 -Wall $(SOURCE_NAME).cpp -o bin/$(OUTPUT_NAME).exe

run:bin/$(OUTPUT_NAME).exe
	bin/$(OUTPUT_NAME).exe

debug:$(SOURCE_NAME).cpp
	g++ -g -std=c++11 -Wall $(SOURCE_NAME).cpp -o bin/$(OUTPUT_NAME)-debug.exe
	gdb bin/$(OUTPUT_NAME)-debug.exe
