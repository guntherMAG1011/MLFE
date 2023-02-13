#include <iostream>
#include <vector>
#include <blaze/Blaze.h>

using namespace blaze;

int main() {
	setNumThreads(4);
    const size_t N(100UL);
    const size_t iterations(10UL);

    const size_t NN(N * N);

    blaze::CompressedMatrix<double, rowMajor> A(NN, NN);
    blaze::DynamicVector<double, columnVector> x(NN, 1.0), b(NN, 0.0), r(NN), p(NN), Ap(NN);
    double alpha, beta, delta;

    // ... Initializing the sparse matrix A

    // Performing the CG algorithm
    r = b - A * x;
    p = r;
    delta = (r, r);

    for (size_t iteration = 0UL; iteration < iterations; ++iteration)
    {
        Ap = A * p;
        alpha = delta / (p, Ap);
        x += alpha * p;
        r -= alpha * Ap;
        beta = (r, r);
        if (std::sqrt(beta) < 1E-8) break;
        p = r + (beta / delta) * p;
        delta = beta;
    }
	std::cout << getNumThreads() << '\n';
	return 0;
}