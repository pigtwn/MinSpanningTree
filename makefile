SOURCE_NAME = main
OUTPUT_NAME = MinSpanningTree

.PHONY:all
all:build

.PHONY:clean
clean:
	rm -rf bin

build:$(SOURCE_NAME).cpp bin
	g++ -std=c++11 -Wall $(SOURCE_NAME).cpp -o bin/$(OUTPUT_NAME).exe

bin:
	mkdir bin

run:bin/$(OUTPUT_NAME).exe
	bin/$(OUTPUT_NAME).exe

debug:$(SOURCE_NAME).cpp
	g++ -g -std=c++11 -Wall $(SOURCE_NAME).cpp -o bin/$(OUTPUT_NAME)-debug.exe
	gdb bin/$(OUTPUT_NAME)-debug.exe
