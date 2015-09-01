CC=g++
FLAGS=-std=c++11 -mssse3 -mpopcnt -O2 -Wall -pedantic -Wextra

DEPS=popcnt-*.cpp config.h
ALL=speed verify

.PHONY: all

# OSX 10.9: g++ is really clang/llvm, but we really do want g++
# make -f Makefile gcc all
gcc:
	CC=/usr/local/bin/g++

# make -f Makefile clang all
clang:
	CC=g++

all: $(ALL)

speed: $(DEPS) speed.cpp
	$(CC) $(FLAGS) speed.cpp -o $@

verify: $(DEPS) verify.cpp
	$(CC) $(FLAGS) verify.cpp -o $@

run: speed
	sh run.sh speed

clean:
	rm -f $(ALL)
