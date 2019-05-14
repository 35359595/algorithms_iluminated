#include "int_multiply.h"
#include <list>
#include <stdlib.h>
#include <memory>
#include <tuple>
#include <math.h>
#include <numeric>
#include <algorithm>

using namespace std;

// Splits integer into two returning tuple of all numbers in input except last one,
// last one returned as second tuple member.
// input: 1234 | output: tuple<123, 4>
auto split_as_int (int input) -> tuple<int, int> {
    double param = static_cast<double>(input) / 10;
    double fract_part, int_part;
    fract_part = modf(param, &int_part);
	auto whole = static_cast<int>(int_part);
	auto fract = static_cast<int>(fract_part * 10);
    return make_tuple(whole, fract);
}

auto ten_to_power_n (int input, int n) -> int {
	while (n-- > 0)
		input *= 10;
	return input;
}

auto recourse_grade_school_multiply (int input, int multiplyed, short step) noexcept -> int {
	if (input <= 0 || multiplyed <=0)
		return 0;
	if (input < 10)
		return step > 1 ? ten_to_power_n(input * multiplyed, step) : input * multiplyed;
	auto split = split_as_int(input);
	auto x = get<0>(split);
	auto y = get<1>(split);
	auto current = step > 1 ? ten_to_power_n(x * multiplyed, step) : x * multiplyed;
	return current + recourse_grade_school_multiply(y, multiplyed, ++step);
}

auto grade_school_multiply (int x, int y) noexcept -> int {
	if (x <= 0 || y <= 0)
		return 0;
    if (y < 10)
        return x * y;
	auto intermidiate_products = unique_ptr<list<int>>(new list<int>());
    int run = 0;
    while (y > 10) {
        auto result = split_as_int(y);
        y = get<0>(result); // Set y to reduced value
        if (run == 0)
            intermidiate_products->push_back(x * get<1>(result)); // Store product of
        else
            intermidiate_products->push_back(ten_to_power_n(x * get<1>(result), run));
        run++;
    }
	// Last one to multiply
	intermidiate_products->push_back(ten_to_power_n(x * y, run));

	return accumulate(intermidiate_products->begin(), intermidiate_products->end(), 0);
}
