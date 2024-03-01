CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -O0

PROG ?= Main
OBJS = Book.o MoveAll.o Main.o

all: $(PROG)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(EXEC) *.o *.out Main 

rebuild: clean all
