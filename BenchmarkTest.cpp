#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

template<class Resolution = std::chrono::milliseconds>
class ExecutionTimer {
public:
	using Clock = std::conditional_t<std::chrono::high_resolution_clock::is_steady,
		std::chrono::high_resolution_clock,
		std::chrono::steady_clock>;
	ExecutionTimer() = default;

	~ExecutionTimer() {
		std::cout
			<< "Elapsed: "
			<< std::chrono::duration_cast<Resolution>(Clock::now() - mStart).count()
			<< std::endl;
	}
private:
	Clock::time_point mStart = Clock::now();
};

int main() {
	ExecutionTimer<> timer;

	std::vector<int> v(50000000);
	std::sort(std::begin(v), std::end(v));
	return 0;
}