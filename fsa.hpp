#include <string>

namespace fsa {
	class problem {
		public:
		void solve();

		protected:
		virtual void make_move() = 0;
		virtual long evaluate_function() = 0;
		virtual void reject_move() = 0;

		private:
		long Tmax = 1000000000;
		long Tstart = Tmax;
		long dT = 1;
		long r();
		void sr(long seed);
	};
}

