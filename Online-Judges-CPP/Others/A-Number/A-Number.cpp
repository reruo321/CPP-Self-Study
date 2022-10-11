#include <iostream>

using namespace std;

/*
	A-Number
	F(1) = 1 (1*1 = '1')
	F(2) = 0 (2*2 = 4)
	F(3) = 0 (3*3 = 9)
	F(10) = 0 (10*10 = 100)
	F(625) = 1 (625*625 = 390'625')

	Problem: Find the biggest n that x < n, F(x) = 1
	(0 < n < INT_MAX)

	My apporach:
		1. n must be ended with specific numbers: 0, 1, 5, 6
		2. Compare between n and the result, from the lowest digit -> discard F(x) = 0 as soon as possible
		3. Find the biggest n, descending from INT_MAX - 1
*/

int aNumber() {
	long long n = INT_MAX-1;
	int last_digit;
	long long x;
	long long pow_result;
	bool isAnswer = false;
	while (!isAnswer) {
		x = n - 1;
		last_digit = x % 10;
		switch (last_digit) {
			// Only work for one of these four kinds of last digit
			case 0:
			case 1:
			case 5:
			case 6:
				pow_result = x * x;
				while(1) {
					// Compare the last digit of x, pow_result
					// IF different, escape
					if ((x % 10) != (pow_result % 10))
						break;

					x /= 10;
					pow_result /= 10;

					// until a loop escape OR both quotient becomes zero.
					if (x == 0) {
						isAnswer = true;
						break;
					}
				}
				break;
			default:
				break;
		}
		if(!isAnswer)
			--n;
	}
	return n;
}

int main() {

	int anumber = aNumber();
	cout << "The Biggest A-Number is: " << anumber << endl;
	cout << anumber-1 << " * " << anumber-1 << " = " << pow(anumber - 1, 2);
	return 0;
}