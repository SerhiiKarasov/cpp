
GCC := g++

OUTPUT := thread_demo
SOURCES := $(wildcard *.cpp)
CCFLAGS := -std=c++11 -pthread -g3

all: $(OUTPUT)
	
$(OUTPUT):
	$(GCC) -o $(OUTPUT) $(CCFLAGS) $(SOURCES)
	
clean:
	rm $(OUTPUT)
	
.PHONY: all
