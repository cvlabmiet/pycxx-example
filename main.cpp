#include <algorithm>
#include <complex>
#include <iostream>
#include <random>
#include <ranges>
#include <vector>

#include "dft.h"

namespace rng = std::ranges;
namespace vw = std::ranges::views;

std::ostream& operator<<(std::ostream& os, std::vector<std::complex<double>>& v) {
    auto tr = [](auto x) {
        return "(" + std::to_string(x.real()) + ";" + std::to_string(x.imag()) + ")";
    };

    os << "[";
    // __cpp_lib_ranges_to_container
    // os << (v | vw::transform(tr) | vw::join_with(',') | rng::to<std::string>());
    rng::copy(v | vw::transform(tr) | vw::join_with(','), std::ostream_iterator<char>(os));
    return os << "]";
}

int main() {
    std::default_random_engine eng(21);
    std::uniform_real_distribution<> distr(-1000, 1000);

    std::vector<std::complex<double>> vec(10);
    rng::generate(vec, [&eng, &distr]() {
        return std::complex{distr(eng), distr(eng)};
    });

    std::cout << "X=" << vec << "\n";

    std::vector<std::complex<double>> out(vec.size());
    dft(vec.size(), vec.data(), out.data());
    std::cout << "DFT(X)=" << out << "\n";
}
