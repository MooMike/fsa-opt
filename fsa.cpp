#include "fsa.hpp"

#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

static const long NUM_INTERVALS = 10;

namespace fsa {
	void problem::solve() {
		sr(1);

		long cost = evaluate_function();

		std::cout << "Start cost: " << cost << endl;

		vector<long> intervals(NUM_INTERVALS+1);
		for (long i = 0; i < NUM_INTERVALS; ++i) {
			intervals[i] = Tstart - i * (Tstart/NUM_INTERVALS);
		}
		intervals[NUM_INTERVALS] = 0L;

		for (long i = 0; i < NUM_INTERVALS; i++) {
			long T = intervals[i];
			long Tmin = intervals[i+1];

			std::cout << "Calculating interval " << T << " -> " << Tmin << endl;
			for (; T > Tmin; --T) {
				make_move();
	
				long new_cost = evaluate_function();

				if (new_cost > cost && r() > T) {	
					reject_move();
					new_cost = cost;
				}

				cost = new_cost;
			}
		
			std::cout << "Intermediate cost @" << T << ": " << cost << endl;
		}

		std::cout << "End cost: " << cost << endl;
	}

	void problem::sr(long seed) {
		rnd_gen.seed(seed);
	}

	long problem::r() {
		// Generate a number between 1 and Tmax
		return rnd_dist(rnd_gen);
	}
}

