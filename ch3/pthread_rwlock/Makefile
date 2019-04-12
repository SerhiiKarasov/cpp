GCC := g++

OUTPUT := ch03_pthread_example
SOURCES := $(wildcard *cpp)
CCFLAGS := -std=c++11 -pthread -g3 -fno-permissive

all: $(OUTPUT)

$(OUTPUT):
	$(GCC) -o $(OUTPUT) $(CCFLAGS) $(SOURCES)

clean: 
	rm $(OUTPUT)


.PHONY: all