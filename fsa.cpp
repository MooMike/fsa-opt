#include "fsa.hpp"

#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

namespace fsa {
	void problem::solve() {
		this->sr(1);

		long cost = this->evaluate_function();

		std::cout << "Start cost: " << cost << endl;

		vector<long> intervals(10);
		for (long i = 0; i < 10; ++i) {
			intervals[i] = this->Tstart - i * (this->Tstart/10);
		}

		for (long i = 0; i < intervals.size(); i++) {
			long T = intervals[i];
			long Tmin = 0;
			if (i < intervals.size())
				Tmin = intervals[i+1];

			std::cout << "Calculating interval " << T << " -> " << Tmin << endl;
			for (; T > Tmin; --T) {
				this->make_move();
	
				long new_cost = this->evaluate_function();

				if (new_cost > cost && this->r() > T) {	
					this->reject_move();
					new_cost = cost;
				}

				cost = new_cost;
			}
		
			std::cout << "Intermediate cost @" << T << ": " << cost << endl;
		}

		std::cout << "End cost: " << cost << endl;
	}

	void problem::sr(long seed) {
		srand(seed);
	}

	long problem::r() {
		// Generate a number between 0 and Tmax
		long r = rand();
		return r % Tmax;
	}
}

