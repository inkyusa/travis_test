CXXFLAGS = -g -Wall -Wfatal-errors -std=c++14

ALL = example

all: $(ALL)

example: example.cpp Makefile
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp

clean:
	$(RM) $(ALL) *.o

test: all
	bash test