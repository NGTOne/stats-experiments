CPPC = g++
CPPFLAGS = -c -g -std=gnu++0x -fPIC -Wall

SHELL := /bin/bash
PLATFORM := $(shell uname -s)

ifeq ($(PLATFORM), Linux)
EIGENINCLUDE = -I/usr/include/eigen3
else ifeq ($(PLATFORM), Darwin)
EIGENINCLUDE = -I/usr/local/include/eigen3
endif

INCLUDE = -Iinclude -I/usr/local/include $(EIGENINCLUDE)

ifeq ($(PLATFORM), Linux)
SHAREDLIB = -lHierGA
else ifeq ($(PLATFORM), Darwin)
SHAREDLIB = -L/usr/local/lib -lHierGA
endif

all: obj-dir objectives

obj-dir:
	./compile-scripts/make-obj-dir.sh

objectives:
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/ExperimentObjective.cpp -o obj/objectives/ExperimentObjective.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/ContinuousObjective.cpp -o obj/objectives/continuous/ContinuousObjective.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/n-d/SphereFunction.cpp -o obj/objectives/continuous/n-d/SphereFunction.o

clean:
	find obj -name *.o | xargs rm -f
