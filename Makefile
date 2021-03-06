#
# Makefile to make the file libclientserver.a, containing
# connection.o and server.o
#
# Define the compiler. g++ can be
# changed to clang++.
CXX = g++
CC  = g++

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of libstdc++.
CPPFLAGS =  -std=c++11
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g

LDFLAGS += -L.
LDFLAGS += -L eventlib
LDLIBS = -ljsoncpp -levents -lboost_filesystem -lboost_system
#CXXFLAGS =  -stdlib=libc++
#CPPFLAGS =  -stdlib=libc++
#CXXFLAGS += -stdlib=libc++

PROGS = simulation_agedist_2pops simulation_basepop simulation_agedist_1pop simulation_input simulation_2pops_input run_simulation

all: $(PROGS)

# Create the library; ranlib is for Darwin (OS X) and maybe other systems.
# Doesn't seem to do any damage on other systems.

#simulation_2_pops: population.o simulation.o simulation_2_pops.o constants_runspec.o

simulation_agedist_2pops: population.o simulation.o constants_runspec.o

simulation_basepop: population.o simulation.o constants_runspec.o

simulation_agedist_1pop: population.o simulation.o constants_runspec.o

simulation_input: population.o simulation.o constants_runspec.o

simulation_2pops_input: population.o simulation.o constants_runspec.o

run_simulation: population.o simulation.o constants_runspec.o events_wrapper.o
# Phony targets
.PHONY: all clean install

# Standard clean
clean:
	rm -f *.o $(PROGS)

# Generate dependencies in *.d files
%.d: %.cc
	@set -e; rm -f $@; \
         $(CPP) -MM $(CPPFLAGS) $< > $@.$$$$; \
         sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
         rm -f $@.$$$$

# Include the *.d files
SRC = $(wildcard *.cc)
include $(SRC:.cc=.d)
