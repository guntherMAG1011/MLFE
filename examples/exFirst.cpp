#include <iostream>
#include <vector>

#include "lafe/structure.hpp"

int main() {
	int array[4] = { 1, 2, 3, 4 };
	std::cout << array << '\n';
	int* ptr = array + 5;
	std::cout << *ptr << '\n';
	std::vector<int> v = { 1, 2, 3, 4 };
	std::cout << v.data() << '\n';
	LAFECPP::Vector<int> vec1(v);
	std::cout << "Dimension of the vector: " << vec1.getDimension() << '\n';
	std::cout << "Magnitude of the vector: " << vec1.getMagnitude() << '\n';
	return 0;
}