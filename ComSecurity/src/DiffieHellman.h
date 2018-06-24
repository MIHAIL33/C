/*
 * DiffieHellman.h
 *
 *  Created on: 18 нояб. 2017 г.
 *      Author: Михаил
 */

#ifndef DIFFIEHELLMAN_H_
#define DIFFIEHELLMAN_H_

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "fastpow.h"

using namespace std;

bool verForSimpleSecurity(int p) {
	for (int i = 2; i <= sqrt(p); i++) {
		if (p % i == 0) {
			return false;
		} else {
			return true;
		}
	}
}

bool verForSimple(int p) {
	for (int i = 2; i <= sqrt(p); i++) {
		if (p % i == 0) {
			cout << "The parametr is not simple." << endl;
			return true;
		} else {
			cout << "The parametr is simple." << endl;
			if (verForSimpleSecurity((p - 1)/2)) {
				cout << "Increased reliability!" << endl;
			}
			return false;
		}
	}
}

void DiffiHallman() {
	srand(time(0));
	int a, b;
	int p, g;
	cout << "Enter the first private key:" << endl;
	cin >> a;
	cout << "Enter the second private key:" << endl;
	cin >> b;
	bool flag = true;
	while (flag) {
		cout << "Enter the parametr p:" << endl;
		cin >> p;
		flag = verForSimple(p);
	}
	flag = true;
	while (flag) {
		cout << "Enter the parametr g:" << endl;
		cin >> g;
		flag = verForSimple(g);
	}

	double A_par = fastpow(g, a, p);
	double B_par = fastpow(g, b, p);
	cout << "First key: " << fastpow(B_par, a, p) << endl;
	cout << "Second key: " << fastpow(A_par, b, p) << endl;
}


#endif /* DIFFIEHELLMAN_H_ */
