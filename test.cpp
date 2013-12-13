#include "fsa.hpp"

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <cstdint>

using namespace std;
using namespace fsa;

class simple : public problem {
	public:
	long x = rand(), prev_x = 0;
	long y = rand(), prev_y = 0;
	long z = rand(), prev_z = 0;

	virtual long evaluate_function() {
		return (x + y) - z;
	};

	protected:
	virtual void make_move() {
		prev_x = x;
		prev_y = y;
		prev_z = z;

		switch(rand() % 3) {
			case 0: x = rand(); break;
			case 1: y = rand(); break;
			case 2: z = rand(); break;
		}
	};
	virtual void reject_move() {
		x = prev_x;
		y = prev_y;
		z = prev_z;
	};
};

int main(void) {
	simple s;
	cout << "Start = (" << s.x << ", " << s.y << ", " << s.z << ")" << endl; 
	s.solve();
	cout << "Final = (" << s.x << ", " << s.y << ", " << s.z << ")" << endl;

	long target = -(1<<30);
	long actual = s.evaluate_function();
	if (target < actual) {
		cerr << "Test failed (target was " << target << ", acheived " << actual << ")" << endl;
		return 1;
	}

	cout << "Test passed (target was " << target << ", acheived " << actual << ")" << endl;
	return 0;
}

