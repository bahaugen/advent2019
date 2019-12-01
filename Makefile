CPP = g++
CFLAGS = -Wall -Wextra -std=c++11 -o3

EXES = day1

all: $(EXES)

day1: day1.cpp
	$(CPP) $(CFLAGS) -o day1 day1.cpp

.PHONY: clean

clean:
	rm -f $(EXES) *.o