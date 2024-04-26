#include <algorithm>
#include <cmath>
#include <complex>
#include <numbers>
#include <vector>

extern "C" void dft(size_t num, const std::complex<double>* x, std::complex<double>* y) {
    double phi = -2 * std::numbers::pi / static_cast<double>(num);
    for (size_t k = 0; k < num; ++k) {
        auto sum = std::complex{0.0};
        for (size_t n = 0; n < num; ++n)
            sum += x[n] * std::polar(1.0, phi * n * k);

        y[k] = sum / std::sqrt(num);
    }
}

extern "C" void fft_conv(size_t num0, const std::complex<double>* in0, size_t num1, const std::complex<double>* in1,
    std::complex<double>* out) {
    auto size = 2 * std::max(num0, num1);
    std::vector<std::complex<double>> x(size);
    std::vector<std::complex<double>> y(size);
    std::vector<std::complex<double>> c(size);

    std::copy_n(in0, num0, x.begin());
    std::copy_n(in1, num1, y.begin());
    // fft, for, ...
    std::copy_n(c.begin(), num0 + num1, out);
}
