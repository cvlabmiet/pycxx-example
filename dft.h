#pragma once

#include <complex>
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

void dft(size_t num, const std::complex<double>* input, std::complex<double>* output);

void fft(size_t num, const std::complex<double>* input, std::complex<double>* output);
void fft_permut(size_t num, std::complex<double>* inoout);

void conv(size_t num0, const std::complex<double>* in0, size_t num1, const std::complex<double>* in1,
    std::complex<double>* out);

void fft_conv(size_t num0, const std::complex<double>* in0, size_t num1, const std::complex<double>* in1,
    std::complex<double>* out);

#ifdef __cplusplus
}
#endif
