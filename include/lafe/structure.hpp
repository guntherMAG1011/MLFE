#pragma once

#include <vector>
#include <cmath>

namespace LAFECPP {
	template <typename T>
	class Vector {
	private:
		std::vector<T> coordinates;
		size_t dimension;
		float magnitude;
	public:
		// Constructor
		Vector(std::vector<T> list) {
			magnitude = 0;
			for (int i = 0; i < list.size(); i++) {
				coordinates.push_back(list[i]);
				magnitude += list[i] * list[i];
			}
			magnitude = sqrt(magnitude);
			dimension = coordinates.size();
		}
		// return dimension of the vector
		size_t getDimension() {
			return dimension;
		}
		// return magnitude of the vector
		float getMagnitude() {
			return magnitude;
		}
	};
}