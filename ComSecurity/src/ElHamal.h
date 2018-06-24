/*
 * ElHamal.h
 *
 *  Created on: 18 нояб. 2017 г.
 *      Author: Михаил
 */

#ifndef ELHAMAL_H_
#define ELHAMAL_H_

#include <iostream>
#include <cmath>
#include <cstring>
#include <limits>
#include "fastpow.h"
#include "DiffieHellman.h"

using namespace std;

bool testG(int g, int x, int p) {
	if (fastpow(g, x, p) == 1) {
		return true;
		cout << "Incorrect g!" << endl;;
	} else {
		return false;
	}
}

void ElHaml() {
	int M; //message
	int p, g; //parametrs
	int x, k;
	cout << "Enter the encrypted message." << endl;
	cin >> M;
	bool flag = true;
	while (flag) {
		cout << "Enter the parametr p:" << endl;
		cin >> p;
		flag = verForSimple(p);
	}
	label:
	flag = true;
	while (flag) {
		cout << "Enter the parametr g:" << endl;
		cin >> g;
		flag = verForSimple(g);
	}

	flag = true;
	while (flag) {
		cout << "Enter the parametr x:" << endl;
		cin >> x;
		if ((x > 1)&&(x < p)) {
			flag = false;;
		} else {
			cout << "Incorrect x! (1 < x < p)" << endl;
		}
	}

	bool l = testG(g , x, p);
	if (l) {
		goto label;
	}

	flag = true;
	while (flag) {
		cout << "Enter the parametr k:" << endl;
		cin >> k;
		if ((k > 1)&&(k < p - 1)) {
			flag = false;;
		} else {
			cout << "Incorrect k! (1 < k < p - 1)" << endl;
		}
	}

	double y = fastpow(g, x, p);
	cout << "Public key: g = " << g << " y = " << y << "  p = " << p << endl;

	double a = fastpow(g, k, p);
	double b = fmod(pow(y, k) * M, p);
	cout << "Ciphertext : a = " << a << " b = " << b << endl;

	double M_dec = fmod(b*pow(a, p - 1 - x), p);
	cout << "Encrypted message: " << M_dec << endl;

	//Signature

	cout << "Enter the hash sum:" << endl;
	int m;
	cin >> m;
	int r = fastpow(g, k, p);
	cout << "R: " << r << endl;
	//int s = fmod((m - x * r)*(1/k), p - 1);
	int s;
	int t = ReverseElement(k, p - 1, s);
	cout << s << endl;
	t = fastpow((m - x * r)*s, 1 , p - 1);
	if (t < 0) {
		t += p - 1; //r s
	}
	cout << "S: " << t << endl;
	cout << fastpow(y, r, p) << endl;
	cout << fastpow(r, t, p) << endl;
	cout << "Right: " << fmod(fastpow(y, r, p)*fastpow(r, t, p), p)  << endl;
	cout << "Left: " << fastpow(g, m, p) << endl;

}

#endif /* ELHAMAL_H_ */
