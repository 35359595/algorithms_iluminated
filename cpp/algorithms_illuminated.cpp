// algorithms_illuminated.cpp : Defines the entry point for the application.
//
#include "algorithms_illuminated.h"

using namespace std;

int main()
{
    cout << "Grade school manual [1234 * 5678]: " << grade_school_multiply(1234, 5678) << endl;
	cout << "Recoursive grade school [1234 * 5678]: " << recourse_grade_school_multiply(1234, 5678) << endl;
	cout << "Karatsuba initial implementation [1234 * 5678]: " << karatsuba_multiplication(1234, 5678) << endl;
	return 0;
}
