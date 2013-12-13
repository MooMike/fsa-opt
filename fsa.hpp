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
		double Tmax = 100000.0;
		long kstart = 1000;
		std::mt19937_64 rnd_gen = std::mt19937_64();
		std::uniform_real_distribution<double> rnd_dist = std::uniform_real_distribution<double>(1, Tmax);
		inline bool accept(long old_cost, long new_cost, long k, double Tmax);
		inline double T(long k);
		inline double r();
		inline void sr(long seed);
	};
}

