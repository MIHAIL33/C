/*
 * AttackViner.h
 *
 *  Created on: 19 нояб. 2017 г.
 *      Author: Михаил
 */

#ifndef ATTACKVINER_H_
#define ATTACKVINER_H_

#include <iostream>
#include "Evclid.h"
#include "DiffieHellman.h"

using namespace std;

void AttackViner() {
	bool flag;
	int p, q;
	while (true) {
		flag = true;
		while (flag) {
			cout << "Enter the parametr p: " << endl;
			cin >> p;
			flag = verForSimple(p);
		}
		flag = true;
		while (flag) {
			cout << "Enter the parametr q: " << endl;
			cin >> q;
			flag = verForSimple(q);
		}
		if (q < p) {
			break;
		} else {
			cout << "Error p < q!!!" <<endl;
		}
	}

	int e;
	cout << "Enter the parametr e:" << endl;
	cin >> e;

	//d < (1/3)*pow(n, (1/4));
	int d;
	int v = ReverseElement(e, ((p - 1)*(q - 1)), d);
	cout << "Private key d = " << d << endl;
}

#endif /* ATTACKVINER_H_ */
