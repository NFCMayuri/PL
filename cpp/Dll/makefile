CXX := g++
CXXFLAGS := -Wall -std=c++11

SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
DLL := libSortComponent.so
EXEC := main

LIBDIR := .
LDFLAGS :=  -L$(LIBDIR) -lSortComponent

all: $(DLL) $(EXEC)

$(DLL): SortComponent.o
	$(CXX) -shared -o $@ $^

$(EXEC): main.o
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(DLL) $(EXEC)

run: $(EXEC)
	LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH ./$(EXEC)

.PHONY: all clean test
