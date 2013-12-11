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
	long x = 134, prev_x = 0;
	long y = 21, prev_y = 0;
	long z = 3412, prev_z = 0;

	protected:
	virtual void make_move() {
		this->prev_x = this->x;
		this->prev_y = this->y;
		this->prev_z = this->z;

		switch(rand() % 3) {
			case 0: this->x = rand(); break;
			case 1: this->y = rand(); break;
			case 2: this->z = rand(); break;
		}
	};
	virtual long evaluate_function() {
		return (this->x + this->y) - this->z;
	};
	virtual void reject_move() {
		this->x = this->prev_x;
		this->y = this->prev_y;
		this->z = this->prev_z;
	};
};

int main(void) {
	simple s;
	cout << "Start = (" << s.x << ", " << s.y << ", " << s.z << ")" << endl; 
	s.solve();
	cout << "Final = (" << s.x << ", " << s.y << ", " << s.z << ")" << endl; 
	return s.x != 0 | s.y != 0;
}

