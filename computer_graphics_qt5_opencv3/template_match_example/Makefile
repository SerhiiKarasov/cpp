OUTPUT := template_match_opencv2
SOURCES_CPP := $(wildcard *.cpp)

GPP := g++
GPPFLAGS_COMPILE_STEP = -c -std=c++11
GPPFLAGS_LINK_STEP = -o

OBJS=$(subst .cpp,.o,$(SOURCES_CPP))
LDFLIBS := -L/usr/local/lib -lopencv_world 

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


.PHONY: test
test:
	./$(OUTPUT)