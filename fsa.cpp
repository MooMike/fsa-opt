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
		intervals[0] = 0L;
		for (long i = 1; i <= NUM_INTERVALS; ++i) {
			long j = NUM_INTERVALS - i;
			intervals[i] = kstart - j * (kstart/NUM_INTERVALS);
		}

		for (long i = 0; i < NUM_INTERVALS; i++) {
			long k = intervals[i];
			long kmax = intervals[i+1];

			std::cout << "Calculating interval " << k << " -> " << kmax << endl;
			for (; k < kmax; ++k) {
				make_move();
	
				long new_cost = evaluate_function();

				if (!accept(cost, new_cost, k, Tmax)) {
					reject_move();
					new_cost = cost;
				}

				cost = new_cost;
			}
		
			std::cout << "Intermediate cost @" << k << ": " << cost << endl;
		}

		std::cout << "End cost: " << cost << endl;
	}

	inline
	bool problem::accept(long old_cost, long new_cost, long k, double Tmax) {
		if (new_cost < old_cost)
			return true;

		return r() <= exp(-(new_cost - old_cost) * T(k));
	}

	inline
	double problem::T(long k) {
		return Tmax / log(k);
	}

	inline
	void problem::sr(long seed) {
		rnd_gen.seed(seed);
	}

	inline
	double problem::r() {
		// Generate a number between 1 and Tmax
		return rnd_dist(rnd_gen);
	}
}

