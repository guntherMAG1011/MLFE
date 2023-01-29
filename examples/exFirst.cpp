#include <iostream>
#include <vector>

#include "lafe/structure.hpp"

int main() {
	std::vector<int> v = { 1, 2, 3, 4 };
	LAFECPP::Vector<int> vec1(v);
	std::cout << "Dimension of the vector: " << vec1.getDimension() << '\n';
	std::cout << "Magnitude of the vector: " << vec1.getMagnitude() << '\n';
	return 0;
}