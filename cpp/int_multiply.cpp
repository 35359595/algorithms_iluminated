#include "int_multiply.h"
#include <list>
#include <stdlib.h>
#include <memory>
#include <tuple>
#include <math.h>
#include <numeric>
#include <algorithm>

using namespace std;

auto ten_to_power_n (int input, int n) -> int {
	while (n-- > 0)
		input *= 10;
	return input;
}

// Splits integer into two returning tuple of all numbers in input except last one,
// last one returned as second tuple member.
// input: 1234 | output: tuple<123, 4>
auto split_pop_smallest_as_int (int input) -> tuple<int, int> {
    double param = static_cast<double>(input) / 10;
    double fract_part, int_part;
    fract_part = modf(param, &int_part);
	auto whole = static_cast<int>(int_part);
	auto fract = static_cast<int>(round(fract_part * 10));
    return make_tuple(whole, fract);
}

// Splits integer into two returning tuple of two [almost]same sized ints
// input: 1234 | output: tuple<12, 34>
auto split_half_as_int(int input) noexcept -> tuple<int, int, int> {
	if (input < 10)
		return make_tuple(0, input, 1);
	auto size = static_cast<int>(log10(input) + 1);
	double fract_part, int_part;
	auto multiplyer = ten_to_power_n(1, (size / 2));
	fract_part = modf(static_cast<double>(input) / multiplyer, &int_part);
	return make_tuple(static_cast<int>(int_part), static_cast<int>(round(fract_part * multiplyer)), size);
}

auto recourse_grade_school_multiply(int input, int multiplyed, short step) noexcept -> int {
	if (input <= 0 || multiplyed <= 0)
		return 0;
	if (input < 10)
		return step > 0 ? ten_to_power_n(input * multiplyed, step) : input * multiplyed;
	auto split = split_pop_smallest_as_int(input);
	auto x = get<0>(split);
	auto y = get<1>(split);
	auto current = step > 0 ? ten_to_power_n(y * multiplyed, step) : y * multiplyed;
	step++; // This always gets incrimented at this point
	return current + recourse_grade_school_multiply(x, multiplyed, step);
}

auto grade_school_multiply (int x, int y) noexcept -> int {
	if (x <= 0 || y <= 0)
		return 0;
    if (y < 10)
        return x * y;
	auto intermidiate_products = unique_ptr<list<int>>(new list<int>());
    int run = 0;
    while (y > 10) {
        auto result = split_pop_smallest_as_int(y);
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

auto karatsuba_multiplication(int x, int y) noexcept -> int {
	// Some edge case scenarios
	if (x <= 0 || y <= 0)
		return 0;
	if (x < 10 || y < 10)
		return x * y;

	// Creating a, b, c and d for Karatsuba algorithm
	int a, b, c, d, n;
	auto a_and_b = split_half_as_int(x);
	auto c_and_d = split_half_as_int(y);
	n = get<2>(a_and_b);
	a = get<0>(a_and_b);
	b = get<1>(a_and_b);
	c = get<0>(c_and_d);
	d = get<1>(c_and_d);

	// Karatsuba implementation
	auto p = a + b;
	auto q = c + d;
	auto ac = a * c;
	auto bd = b * d;
	auto pq = p * q;
	auto adbc = pq - ac - bd;

	auto power_ac = ten_to_power_n(ac, n);
	auto power_adbc = ten_to_power_n(adbc, n / 2);
	auto result = power_ac + power_adbc + bd;
	return result;
}
