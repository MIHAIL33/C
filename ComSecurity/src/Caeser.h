/*
 * Caeser.h
 *
 *  Created on: 19 нояб. 2017 г.
 *      Author: Михаил
 */

#ifndef CAESER_H_
#define CAESER_H_

#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

void Caeser() {

	int size;
	cout << "Enter the size message:" << endl;
	cin >> size;

	char* buf = new char[size];
	int step;

	cout << "Enter the message:" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(buf, size);
	cout << "Enter the step:" << endl;
	cin >> step;

	for(int i = 0; i < strlen(buf); i++) {
		buf[i] += step;
	}
	cout << "Encrypted: " << buf << endl;

	int count;
	cout << "Enter the count cycles" << endl;
	cin >> count;

	cout << "Decode..." << endl;
	for (int j = 0; j < count; j++) {
		for(int i = 0; i < strlen(buf); i++) {
			buf[i] -= 1;
		}
		cout << buf << endl;
	}
}

#endif /* CAESER_H_ */
