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

objectives: objectives-base n-d-objectives 2d-objectives binary-objectives

objectives-base:
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/ExperimentObjective.cpp -o obj/objectives/ExperimentObjective.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/ContinuousObjective.cpp -o obj/objectives/continuous/ContinuousObjective.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/discrete/binary/BinaryObjective.cpp -o obj/objectives/discrete/binary/BinaryObjective.o

n-d-objectives:
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/n-d/SphereFunction.cpp -o obj/objectives/continuous/n-d/SphereFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/n-d/RosenbrockFunction.cpp -o obj/objectives/continuous/n-d/RosenbrockFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/n-d/StyblinskiTangFunction.cpp -o obj/objectives/continuous/n-d/StyblinskiTangFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/n-d/RastriginFunction.cpp -o obj/objectives/continuous/n-d/RastriginFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/n-d/GriewankFunction.cpp -o obj/objectives/continuous/n-d/GriewankFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/n-d/F8F2Function.cpp -o obj/objectives/continuous/n-d/F8F2Function.o

2d-objectives:
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/2d/AckleyFunction.cpp -o obj/objectives/continuous/2d/AckleyFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/2d/BealesFunction.cpp -o obj/objectives/continuous/2d/BealesFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/2d/GoldsteinPriceFunction.cpp -o obj/objectives/continuous/2d/GoldsteinPriceFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/2d/BoothsFunction.cpp -o obj/objectives/continuous/2d/BoothsFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/2d/BukinNo6Function.cpp -o obj/objectives/continuous/2d/BukinNo6Function.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/2d/MatyasFunction.cpp -o obj/objectives/continuous/2d/MatyasFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/2d/LeviNo13Function.cpp -o obj/objectives/continuous/2d/LeviNo13Function.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/2d/ThreeHumpCamelFunction.cpp -o obj/objectives/continuous/2d/ThreeHumpCamelFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/continuous/2d/EasomFunction.cpp -o obj/objectives/continuous/2d/EasomFunction.o

binary-objectives:
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/discrete/binary/1maxFunction.cpp -o obj/objectives/discrete/binary/1maxFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/discrete/binary/LongestFragmentFunction.cpp -o obj/objectives/discrete/binary/LongestFragmentFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/discrete/binary/AverageFragmentFunction.cpp -o obj/objectives/discrete/binary/AverageFragmentFunction.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/objectives/discrete/binary/H_IFFFunction.cpp -o obj/objectives/discrete/binary/H_IFFFunction.o

clean:
	find obj -name *.o | xargs rm -f
