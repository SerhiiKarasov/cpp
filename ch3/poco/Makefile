
GCC := g++

OUTPUT := ch01_mt_example
SOURCES := $(wildcard *.cpp)
CCFLAGS := -std=c++11 -pthread -lPocoFoundation

all: $(OUTPUT)
	
$(OUTPUT):
	$(GCC) -o $(OUTPUT) $(CCFLAGS) $(SOURCES)
	
clean:
	rm $(OUTPUT)
	
.PHONY: all