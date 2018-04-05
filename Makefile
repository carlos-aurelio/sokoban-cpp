CC  ?= gcc
CXX ?= g++
AR  ?= ar
RM  := rm -rf
MD  := mkdir -p
CP  := cp

WFLAGS := -Wall -Wextra -Wchar-subscripts -Wdouble-promotion -Wformat \
		 -Wfloat-equal -Wundef -Wcast-qual \
		 -Wwrite-strings -Wconversion -Wlogical-op \
		 -Wredundant-decls
CPPFLAGS += -std=c++11 $(WFLAGS) -I src
CPPFLAGS += $(shell pkg-config ncursesw --cflags)
LDFLAGS  += $(shell pkg-config ncursesw --libs)
.PHONY: clean

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst %.cpp,%.o,$(SRC))

sokoban-cpp: $(OBJ)
	$(CXX) -o $@  $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $(CPPFLAGS) $^ -o $@

clean:
	$(RM) sokoban-cpp $(OBJ)
