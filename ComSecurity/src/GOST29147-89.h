/*
 * GOST29147-89.h
 *
 *  Created on: 24 дек. 2017 г.
 *      Author: Михаил
 */

#ifndef GOST29147_89_H_
#define GOST29147_89_H_

#include "fastpow.h"
#include <iostream>
#include <cstring>
#include <string>

//N = 0x0102030405060708
//K = 'as28zw37q8397342ui238e2twqm2ewp1'

#define Count 8

using namespace std;

void GOST() {
	int L = 0x01020304;
	int R = 0x05060708;

	int *k = new int[Count];
	k[0] = 'as28';
	k[1] = 'zw37';
	k[2] = 'q839';
	k[3] = '7342';
	k[4] = 'ui23';
	k[5] = '8e2t';
	k[6] = 'wqm2';
	k[7] = 'ewp1';

	int smod = 0;
	  asm ( "add %1, %0" : "=r" (smod) : "r" (k[0]), "0" (R) ); //66793940

	cout << dec << smod << " dec" << endl;
	cout << hex << smod << " hex" << endl;
	cin >> smod;

	char *s = new char[Count+ 10];
	int i = 0;
	while (smod!=0)
	{
	s[i] = smod % 10 + '0';
	smod = smod/10;
	i++;
	}

	for (int i = 0; i < Count; i++) {
		cout << s[i] << " ";
	}
	cout << endl;

	int *sim = new int[Count];
	for (int i = 0; i < Count; i++) {
		sim[i] = static_cast<int>(s[Count - 1 - i]) - 48;
		cout << sim[i] << " ";
	}
	cout << endl;

	int templ[Count][16] = { {0x5, 0x9, 0x2, 0x4, 0x8, 0x7, 0x3, 0x10, 0x15, 0x1, 0x13, 0x11, 0x6, 0x14, 0x0, 0x12},
						 	 {0x7, 0x13, 0x5, 0x12, 0x2, 0x14, 0x4, 0x3, 0x0, 0x8, 0x10, 0x9, 0x1, 0x6, 0x11, 0x14},
							 {0x12, 0x9, 0x11, 0x4, 0x15, 0x5, 0x10, 0x1, 0x14, 0x3, 0x7, 0x13, 0x8, 0x6, 0x0, 0x2},
							 {0x10, 0x8, 0x4, 0x0, 0x6, 0x15, 0x11, 0x3, 0x12, 0x13, 0x2, 0x1, 0x7, 0x5, 0x9, 0x14},
							 {0x8, 0x10, 0x15, 0x6, 0x9, 0x11, 0x4, 0x12, 0x7, 0x1, 0x14, 0x3, 0x5, 0x0, 0x2, 0x13},
							 {0x13, 0x1, 0x10, 0x0, 0x5, 0x8, 0x2, 0x14, 0x7, 0x15, 0x9, 0x12, 0x11, 0x3, 0x6, 0x4},
							 {0x15, 0x7, 0x6, 0x10, 0x12, 0x4, 0x1, 0x11, 0x14, 0x9, 0x8, 0x0, 0x2, 0x5, 0x13, 0x3},
							 {0x15, 0x7, 0x6, 0x10, 0x12, 0x4, 0x1, 0x11, 0x14, 0x9, 0x8, 0x0, 0x2, 0x5, 0x13, 0x3}};

	int preobraz[Count];
	for (int i = 0; i < Count; i++) {
		preobraz[i] = templ[i][sim[Count - 1 - i]];
	}

	for (int i = 0; i < Count; i++) {
		cout << preobraz[i] << " ";
	}
	cout << endl;

	char pre[Count];
	string str = "0x";
	for (int i = 0; i < Count; i++) {
		if (preobraz[i] == 10) {
			pre[i] = 'a';
		} else if (preobraz[i] == 11) {
			pre[i] = 'b';
		} else if (preobraz[i] == 12) {
			pre[i] = 'c';
		} else if (preobraz[i] == 13) {
			pre[i] = 'd';
		} else if (preobraz[i] == 14) {
			pre[i] = 'e';
		} else if (preobraz[i] == 15) {
			pre[i] = 'f';
		} else {
			if (preobraz[i] >= 10) { preobraz[i]++; }
			pre[i] = preobraz[i] + '0';
		}
	}

	for (int i = 0; i < Count; i++) {
		str += pre[Count - 1 - i];
	}
	int simple;
	cout << str << endl;
	cin >> hex >> simple;
	cout << simple << endl;
	int roll = 0, sdvig = 11;
	simple = (simple << sdvig) | (simple >> (32 - sdvig));
	cout << simple << endl;
	int LL = 0;
	asm ( "xor %1, %0" : "=r" (LL) : "r" (L), "0" (simple) );
	int RR = L;

	cout << "Answer:" << endl;
	cout << "L = ";
	cout << hex << LL << endl;
	cout << "R = ";
	cout << hex << RR << endl;
}




#endif /* GOST29147_89_H_ */
