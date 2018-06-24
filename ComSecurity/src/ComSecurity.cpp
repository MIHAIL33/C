//============================================================================
// Name        : ComSecurity.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "fastpow.h"
#include "Evclid.h"
#include "DiffieHellman.h"
#include "ElHamal.h"
#include "Shamir.h"
#include "RSA.h"
#include "AttackFerma.h"
#include "AttackViner.h"
#include "Caeser.h"
#include "GOST29147-89.h"
using namespace std;

int main() {

	cout << "Welcome to Computer Security!!!" << endl;
	cout << "1. Rapid exponentiation." << endl;
	cout << "2. Euclidean algorithm." << endl;
	cout << "3. Diffi-Hellman algorithm." << endl;
	cout << "4. El Hamal algorithm." << endl;
	cout << "5. Shamir algorithm." << endl;
	cout << "6. RSA algorithm and signature." << endl;
	cout << "7. Attack by theorem Ferma." << endl;
	cout << "8. Attack by theorem Viner." << endl;
	cout << "9. Cipher of Ceaser." << endl;
	cout << "10. GOST29147-89." << endl;

	int number;
	cin >>  number;

	switch (number) {
	case 1:
		rapidExpon();
		break;
	case 2:
		algorEvclid();
		break;
	case 3:
		DiffiHallman();
		break;
	case 4:
		ElHaml();
		break;
	case 5:
		Shamir();
		break;
	case 6:
		RSA();
		break;
	case 7:
		AttackFerma();
		break;
	case 8:
		AttackViner();
		break;
	case 9:
		Caeser();
		break;
	case 10:
		GOST();
		break;
	};

	return 0;
}
