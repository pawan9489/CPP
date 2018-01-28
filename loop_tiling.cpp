#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <limits>
#include <random>

#define p(a) std::cout << a << std::endl

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

static std::vector<int> generate_data(size_t size)
{
    using value_type = int;
    // We use static in order to instantiate the random engine
    // and the distribution once only.
    // It may provoke some thread-safety issues.
    static std::uniform_int_distribution<value_type> distribution(
        std::numeric_limits<value_type>::min(),
        std::numeric_limits<value_type>::max());
    static std::default_random_engine generator;

    std::vector<value_type> data(size);
    std::generate(data.begin(), data.end(), []() { return distribution(generator); });
    return data;
}

int main(){
    ExecutionTimer<> timer;

    int len = 1000000000;

    std::vector<int> v1 = generate_data(len);
    std::vector<int> v2 = generate_data(len);
    // for (auto v: v1)
    // {
    //     std::cout << v << ",";
    // }
    // std::cout << std::endl;
    // for (auto v: v2)
    // {
    //     std::cout << v << ",";
    // }
    int tiling_length = 4096;
    for(int i = 0; i < len; i+= tiling_length) {
        for(int j = i; j < std::min(i+tiling_length, len); j++) {
            v1[j] += v2[j];
        }
    }

    return 0;
}

