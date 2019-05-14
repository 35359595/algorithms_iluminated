// algorithms_illuminated.cpp : Defines the entry point for the application.
//
#include "algorithms_illuminated.h"

using namespace std;

int main()
{
    cout << "Grade school manual [123 * 456]:" << grade_school_multiply(123, 456) << endl;
	cout << "Recoursive grade school [123 * 456]:" << recourse_grade_school_multiply(123, 456, 1) << endl;
	return 0;
}
