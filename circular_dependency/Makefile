GCC := g++

OUTPUT := circular_dependency
SOURCES := $(wildcard *cpp)
CCFLAGS := -std=c++11 -g3

all: $(OUTPUT)

$(OUTPUT):
	$(GCC) -o $(OUTPUT) $(CCFLAGS) $(SOURCES)

clean: 
	rm $(OUTPUT)


.PHONY: all