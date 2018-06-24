/*
 * fastpow.h
 *
 *  Created on: 18 нояб. 2017 г.
 *      Author: Михаил
 */

#ifndef FASTPOW_H_
#define FASTPOW_H_

#include <iostream>

using namespace std;

int fastpow(int a, int n, int p) {
	if (n == 0) return 1;
	int b = fastpow(a, n/2, p);
	if (n % 2 == 0)	{
		return (b*b) % p;
	} else {
		return (a*b*b) % p;
	}
}

void rapidExpon() {
	int a, n, p;
	int b;
	cout << "Enter the number:" << endl;
	cin >> a;
	cout << "Enter the degree:" << endl;
	cin >> n;
	cout << "Enter the parametr p:" << endl;
	b = fastpow(a, n, p);
	cout << "Result: " << b << endl;
}

#endif /* FASTPOW_H_ */
