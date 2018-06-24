/*
 * AttackFerma.h
 *
 *  Created on: 19 нояб. 2017 г.
 *      Author: Михаил
 */

#ifndef ATTACKFERMA_H_
#define ATTACKFERMA_H_

#include <iostream>
#include <cmath>

using namespace std;

void AttackFerma() {
	int n;
	cout << "Enter the number n:" << endl;
	cin >> n;
	int s = round(sqrt(n));
	cout << "Sqrt(n) (round): " << s << endl;
	int k = 1;
	double y;
	double sqrt_y;
	while (true) {
		y = pow(s + k, 2) - n;
		sqrt_y = sqrt(y);
		cout << "k = " << k << ", y = " << y << ", sqrt(y) = " << sqrt_y << endl;
		if (sqrt_y - round(sqrt_y) == 0) {
			break;
		}
		k++;
	}

	int a = s + k + sqrt_y;
	int b = s + k - sqrt_y;

	cout << "Answer : " << a << ", " << b << endl;

}



#endif /* ATTACKFERMA_H_ */
