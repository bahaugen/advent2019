CPP = g++
CFLAGS = -Wall -Wextra -std=c++11 -o3

EXES = day1 day2 day3

all: $(EXES)

day1: day1.cpp
	$(CPP) $(CFLAGS) -o day1 day1.cpp

day2: day2.cpp
	$(CPP) $(CFLAGS) -o day2 day2.cpp

day3: day3.cpp
	$(CPP) $(CFLAGS) -o day3 day3.cpp

.PHONY: clean

clean:
	rm -f $(EXES) *.o