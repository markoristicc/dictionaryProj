CXX=clang++
# CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

CXXFLAGS = -std=c++11

# Change to this before final submission:

#CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES = project2_first project2_second

all: ${BINARIES}

project2_first: project2_first.o Dictionary.o hash24.o 
	${CXX} $^ -o $@

project2_second: project2_second.o Dictionary.o hash24.o
	${CXX} $^ -o $@


tests: ${BINARIES}
	./project2_first.out
	./project2_second.out

clean:
	/bin/rm -f ${BINARIES} *.o
