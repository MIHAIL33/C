/*
 * Evclid.h
 *
 *  Created on: 18 нояб. 2017 г.
 *      Author: Михаил
 */

#ifndef EVCLID_H_
#define EVCLID_H_

#include <iostream>
#include "fastpow.h"

using namespace std;

int gcdex(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
    	y = 0;
    	return a;
	}
	int x1, y1;
	int d1 = gcdex(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return d1;
}

int ReverseElement(int a, int N, int &result) {
	int x, y, d;
	d = gcdex(a, N, x, y);
	if (d != 1) {
		return 1;
	} else {
		if (x > 0) {
			result = x;
	  } else {
		  result = x + N;
	  }
    return 0;
	}
}

int Evclid(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return Evclid(b, a % b);
	}
}

void algorEvclid() {
	int a, b;
	cout << "Enter the first number:" << endl;
	cin >> a;
	cout << "Enter the second number:" << endl;
	cin >> b;
	int res, v;
	v = ReverseElement(a, b, res);
	cout << "Result: " << res << endl;
}

#endif /* EVCLID_H_ */
