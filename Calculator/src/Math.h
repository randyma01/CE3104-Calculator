/*
 * Math.h
 *
 *  Created on: 20 feb. 2017
 *      Author: randy
 */

#ifndef MATH_H_
#define MATH_H_

#include <iostream>
#include <string>

using namespace std;

class Math {
	public:
		Math(); /*Constructor*/
		virtual ~Math(); /*Destroyer*/

	private:
		/*Attributes*/
		string variables;
		int numerals;

		/*Methods*/
		string sum(string exp1, string exp2);
		void checkNumeral(string exp);
		void checkVariable(string exp);

};

#endif /* MATH_H_ */
