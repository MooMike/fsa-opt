.PHONY: build test

CLANG_FLAGS=-std=c++11

libfsa.a: fsa.o
	ar r $@ $^

fsa.o: fsa.cpp
	clang++ $(CLANG_FLAGS) -c -o $@ $^	

test: test.cpp
	clang++ $(CLANG_FLAGS) -o $@ -L. -lfsa $^
	./test
