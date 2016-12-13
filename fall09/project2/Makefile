# Eric Lima
# Makefile

APPNAME='p3'

# Construct list of .cc files and their corresponding .o files
sources := $(wildcard *.cpp)
objects := $(sources:.cpp=.o)

all: ${APPNAME}

${APPNAME}: ${objects}
	g++ -Wall -g -o $@ $^

%.o: %.cpp
	g++ -Wall -c -g -o $@ $^

clean:
	rm -f *.o ${APPNAME}

nice:
	rm -f *.o
