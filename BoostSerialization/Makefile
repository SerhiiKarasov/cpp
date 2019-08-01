OUTPUT := build/boost_serialization

SOURCES_CPP := $(wildcard *.cpp)

GCC := gcc
GCCFLAGS_COMPILE_STEP = -c

GPP := g++
GPPFLAGS_COMPILE_STEP = -c -std=c++17
GPPFLAGS_LINK_STEP = -o
LDFLIBS += -lboost_serialization


OBJS+=$(subst .cpp,.o,$(SOURCES_CPP))

.PHONY: all
all:$(OUTPUT)

$(OUTPUT):$(OBJS)
	$(GPP) $(GPPFLAGS_LINK_STEP) $(OUTPUT) $(OBJS) $(LDFLIBS) 

$(OBJS):
	$(GPP) $(GPPFLAGS_COMPILE_STEP) $(SOURCES_CPP)

.PHONY: clean
clean:
	rm $(wildcard *.o)
	rm $(OUTPUT)
