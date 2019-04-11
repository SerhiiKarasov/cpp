
GCC := g++

OUTPUT := thread_demo
SOURCES := $(wildcard *.cpp)
CCFLAGS := -std=c++14 -g3 -pthread

all: $(OUTPUT)
	
$(OUTPUT):
	$(GCC) -o $(OUTPUT) $(CCFLAGS) $(SOURCES)
	
clean:
	rm $(OUTPUT)
	
.PHONY: all
