/*
 * Shamir.h
 *
 *  Created on: 18 нояб. 2017 г.
 *      Author: Михаил
 */

#ifndef SHAMIR_H_
#define SHAMIR_H_

#include <iostream>
#include <cmath>
#include "Evclid.h"
#include "fastpow.h"
#include "DiffieHellman.h"

using namespace std;

bool testMod(int p, int C, int d) {
	if (fmod(C*d, p-1) == 1) {
		return false;
	} else {
		return true;
	}
}

void Shamir() {
	int M; //message
	double p; //parametr
	cout << "Enter the encrypted message." << endl;
	cin >> M;
	bool flag = true;
	while (flag) {
		cout << "Enter the parametr p:" << endl;
		cin >> p;
		flag = verForSimple(p);
	}

	int CA, CB, dA, dB;
	int v;
	flag = true;
	while (flag) {
		cout << "Enter the parametr CA:" << endl;
		cin >> CA;
		v = ReverseElement(CA, p - 1, dA);
		cout << "The parametr dA: " << dA << endl;
		flag = testMod(p, CA, dA);
		if (flag) {
			cout << "Incorrect CA and dA! (CA*dA mod p - 1 = 1)" << endl;
		}
	}
	flag = true;
	while (flag) {
		cout << "Enter the parametr CB:" << endl;
		cin >> CB;
		v = ReverseElement(CB, p - 1, dB);
		cout << "The parametr dB: " << dB << endl;
		flag = testMod(p, CB, dB);
		if (flag) {
			cout << "Incorrect CB and dB! (CB*dB mod p - 1 = 1)" << endl;
		}
	}

	double x1 = fastpow(M, CA, p);
	cout << "Step 1: " << x1 << endl;
	cout << "Forwading..." << endl;
	double x2 = fastpow(x1, CB, p);
	cout << "Step 2: " << x2 << endl;
	cout << "Forwading..." << endl;
	double x3 = fastpow(x2, dA, p);
	cout << "Step 3: " << x3 << endl;
	cout << "Forwading..." << endl;
	double x4 = fastpow(x3, dB, p);
	cout << "Encrypted message: " << x4 << endl;
}


#endif /* SHAMIR_H_ */
