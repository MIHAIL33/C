/*
 * RSA.h
 *
 *  Created on: 19 нояб. 2017 г.
 *      Author: Михаил
 */

#ifndef RSA_H_
#define RSA_H_

#include <iostream>
#include "DiffieHellman.h"
#include "fastpow.h"
#include "Evclid.h"

using namespace std;

//p=3, q=11, e=7
//m=1,2,3;

void RSA() {
	int p, q;
	bool flag = true;
	while (flag) {
		cout << "Enter the parametr p:" << endl;
		cin >> p;
		flag = verForSimple(p);
	}
	flag = true;
	while (flag) {
		cout << "Enter the parametr q:" << endl;
		cin >> q;
		flag = verForSimple(q);
	}

	long int n = p * q;
	long int f = (p - 1)*(q - 1);
	int e, d, v;
	cout << "Enter the parametr e:" << endl;
	cin >> e;
	v = ReverseElement(e, f, d);
	cout << "Public key: " << e << ", " << n << endl;
	cout << "Private key: " << d << ", " << n << endl;
	cout << "Forwarding public key..." << endl;

	int m;
	cout << "Enter the encrypted message." << endl;
	cin >> m;

	long int c = fastpow(m, e, n);
	cout << "The encrypted message: " << c << endl;

	int m_dec = fastpow(c, d, n);
	cout << "Message decrypted: " << m_dec << endl;

	cout << "Signature RSA..." << endl;
	int s = fastpow(m, d, n);
	cout << "Forwarding signature: " << m << ", " << s << endl;
	int m_s = fastpow(s, e, n);
	cout << "Signature: " << m_s << endl;
}

#endif /* RSA_H_ */
