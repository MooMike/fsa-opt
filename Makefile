.PHONY: clean

CLANG_FLAGS=-std=c++11 -O2

test: test.cpp libfsa.a fsa.hpp
	clang++ $(CLANG_FLAGS) -o $@ $< -L. -lfsa
	./test

libfsa.a: fsa.o
	ar r $@ $^

fsa.o: fsa.cpp fsa.hpp
	clang++ $(CLANG_FLAGS) -c -o $@ $<	

clean:
	rm -f *.o libfsa.a test

