#include <string>
#include <random>

namespace fsa {
	class problem {
		public:
		void solve();
		virtual long evaluate_function() = 0;

		protected:
		virtual void make_move() = 0;
		virtual void reject_move() = 0;

		private:
		long Tmax = 1000000;
		long Tstart = Tmax / 2;
		long dT = 1;
		std::mt19937_64 rnd_gen = std::mt19937_64();
		std::uniform_int_distribution<long> rnd_dist = std::uniform_int_distribution<long>(1, Tmax);
		long r();
		void sr(long seed);
	};
}

