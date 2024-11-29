#include "calculate.h"
#include "pch.h"


#include <cmath>
#include <stdexcept>

double calculate(double x, int n) {
    if (n <= 0) {
        throw std::invalid_argument("Parameter n must be greater than 0.");
    }

    if (x <= 0) {
        // Äëÿ x <= 0
        double product = 1.0;
        for (int i = 0; i < n; ++i) {
            product *= (i + i); // i + i = 2 * i
        }
        return product;
    }
    else {
        // Äëÿ x > 0
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += (x + j) / (i + j + 1);
            }
        }
        return sum;
    }
}