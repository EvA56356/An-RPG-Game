//#include <iostream>
//#include <cmath>
//#include <iomanip>
//using namespace std;
//class Fraction;
//class iFraction;
//
//class Fraction {
//	friend iFraction convertF(Fraction a);
//	
//private:
//	int top;
//	int bottom;
//
//public:
//	//Initialize the variables, top and bottom
//	Fraction() {
//		top = 0;
//		bottom = 1;
//	}
//
//	Fraction(int a, int b) {
//		top = a;
//		bottom = b;
//	}
//
//	// define the function
//	Fraction(int a) {
//		top = a;
//		bottom = 1;
//	}
//	Fraction add(Fraction a);
//	Fraction sub(Fraction a);
//	Fraction mul(Fraction a);
//	Fraction div(Fraction a);
//	Fraction com(Fraction a);
//	void input();
//	void output();
//	void fraToDec();
//	void decToFra(double a);
//	void simiplify();
//	void sign();
//};
//
//Fraction Fraction::add(Fraction a) {
//	Fraction output;
//	output.top = top * a.bottom + bottom * a.top;
//	output.bottom = bottom * a.bottom;
//
//	output.simiplify();
//	output.sign();
//	return output;
//}
//
//Fraction Fraction::sub(Fraction a) {
//	Fraction output;
//	output.top = top * a.bottom - bottom * a.top;
//	output.bottom = bottom * a.bottom;
//
//	output.simiplify();
//	output.sign();
//	return output;
//}
//
//Fraction Fraction::mul(Fraction a) {
//	Fraction output;
//	output.top = top * a.top;
//	output.bottom = bottom * a.bottom;
//
//	output.simiplify();
//	output.sign();
//	return output;
//}
//
//Fraction Fraction::div(Fraction a) {
//	Fraction output;
//	output.top = top * a.bottom;
//	output.bottom = bottom * a.top;
//
//	output.simiplify();
//	output.sign();
//	return output;
//}
//
//Fraction Fraction::com(Fraction a) {
//	// Let these two fractions subtract with each other and compare the result with 0
//	Fraction output;
//	output.top = top * a.bottom - bottom * a.top;
//	output.bottom = bottom * a.bottom;
//	if (output.top == 0) {
//		cout << "These two fractions are the same." << endl;
//	}
//	if ((output.top * output.bottom < 0)) {
//		cout << "The second one is greater." << endl;
//	}
//	if ((output.top * output.bottom > 0)) {
//		cout << "The first one is greater." << endl;
//	}
//	return output;
//}
//
//void Fraction::simiplify() {
//	// Temporarily store 
//	int temp1 = abs(top);
//	int temp2 = abs(bottom);
//	int x = 1; // Initialize the greatest common divisor
//
//	// the way to get the greatest common divisor
//	while (temp1 != temp2)
//	{
//		if (temp1 > temp2)temp1 = temp1 - temp2;
//		else temp2 = temp2 - temp1;
//		if (temp1 == 0) break;
//	}
//	x = temp2;
//	top = top / x;
//	bottom = bottom / x;
//}
//
//void Fraction::sign() {
//	// judge the top and the bottom whether they have the same sign
//	if (top >= 0 && bottom < 0) {
//		top = top * -1;
//		bottom = bottom * -1;
//	}
//	if (top <= 0 && bottom < 0) {
//		top = top * -1;
//		bottom = bottom * -1;
//	}
//}
//
//void Fraction::fraToDec() {
//	cout << setiosflags(ios::fixed) << setprecision(10); // set the number of decimal places
//	cout << "It is inverted into: " << (double)top / bottom << endl;
//}
//
//void Fraction::decToFra(double a) {
//	top = a * 1000000;
//	bottom = 1000000;
//	simiplify();
//	sign();
//	cout << "It is inverted into: " << top << "/" << bottom << endl;
//}
//
//void Fraction::input() {
//	// input the top and the bottom from the keyboard
//	cout << "Please input the numerator: ";
//	cin >> top;
//	cout << "Please input the denominator: ";
//	cin >> bottom;
//
//	simiplify();
//	sign();
//}
//
//void Fraction::output() {
//	simiplify();
//	sign();
//	// show the result 
//	cout << top << "/" << bottom << endl;
//
//}
//
//
//
//
//class iFraction : public Fraction {
//	friend iFraction convertF(Fraction a);
//
//private:
//	int top;
//	int bottom;
//	int front;
//
//public:
//	//Initialize the variables, top, bottom
//	iFraction() {
//		top = 0;
//		bottom = 0;
//		front = 0;
//	}
//	iFraction(int a, int b, int c) {
//		front = a;
//		top = b;
//		bottom = c;
//	}
//	iFraction add(iFraction a);
//	iFraction sub(iFraction a);
//	iFraction mul(iFraction a);
//	iFraction div(iFraction a);
//	iFraction com(iFraction a);
//
//	void simplify();
//	void output();
//};
//iFraction iFraction::add(iFraction a) {
//	iFraction output;
//	
//	top = top + bottom * front;
//	a.top = a.top + a.bottom * a.front;
//	
//	output.top = top * a.bottom + bottom * a.top;
//	output.bottom = bottom * a.bottom;		
//	output.front = 1;
//	
//	output.simplify();
//	return output;
//}
//
//iFraction iFraction::sub(iFraction a) {
//	iFraction output;
//	top = top + bottom * front;
//	a.top = a.top + a.bottom * a.front;
//	output.top = top * a.bottom - bottom * a.top;
//	output.bottom = bottom * a.bottom;
//	output.front = 1;
//	output.simplify();
//	return output;
//
//}
//
//iFraction iFraction::mul(iFraction a) {
//	iFraction output;
//	top = top + bottom * front;
//	a.top = a.top + a.bottom * a.front;
//	output.top = top * a.top;
//	output.bottom = bottom * a.bottom;
//	output.front = 1;
//
//	output.simplify();
//	return output;
//}
//
//iFraction iFraction::div(iFraction a) {
//	iFraction output;
//	top = top + bottom * front;
//	a.top = a.top + a.bottom * a.front;
//
//	output.top = top * a.bottom;
//	output.bottom = bottom * a.top;
//	output.front = 1;
//
//	output.simplify();
//	return output;
//}
//
//iFraction iFraction::com(iFraction a) {
//	iFraction output;
//
//	top = top + bottom * front;
//	a.top = a.top + a.bottom * a.front;
//	output.top = top * a.bottom - bottom * a.top;
//	output.bottom = bottom * a.bottom;
//	if (output.top==0) {
//		cout << "These two fractions are the same." << endl;
//	}
//	if (output.top* output.bottom < 0) {
//		cout << "The second one is greater." << endl;
//	}
//	if (output.top * output.bottom > 0) {
//		cout << "The first one is greater." << endl;
//	}
//	return output;
//}
//
//
//
//void iFraction::simplify() {
//	// Temporarily store 
//	int temp1 = abs(top);
//	int temp2 = abs(bottom);
//	int x = 1; // Initialize the greatest common divisor
//
//	// the way to get the greatest common divisor
//	while (temp1 != temp2)
//	{
//		if (temp1 > temp2)temp1 = temp1 - temp2;
//		else temp2 = temp2 - temp1;
//		if (temp1 == 0) break;
//	}
//	x = temp2;
//	top = top / x;
//	bottom = bottom / x;	
//	
//	if (front * top * bottom>=0) {
//		front = top / bottom;
//		top = top - front * bottom;
//	}
//	else {
//		top = top + bottom * abs(front);
//		front = top / bottom;
//		top = top - front * bottom;
//		front = -front;
//	}
//}
//
//void iFraction::output() {
//	
//	// show the result 
//	if (top ==0) {
//		cout  << front << endl;
//	}
//	else {
//		cout << front << "(" << top << "/" << bottom << ") " << endl;
//	}
//}
//
//iFraction convertF(Fraction a) {
//	iFraction output;
//	output.front = a.top / a.bottom;
//	output.bottom = a.bottom;
//	output.top = a.top - output.front * a.bottom;
//	return output;
//}
//
//void main() {
//
//	iFraction a1(1, 1, 2);
//	iFraction a2(1, 1, 2);
//	(a1.add(a2)).output();
//	cout << endl << endl;
//
//	iFraction a3(1, -1, 3);
//	iFraction a4(0, 1, 2);
//	(a3.add(a4)).output();
//	cout << endl << endl;
//
//
//	iFraction a5(2, 2, 4);
//	iFraction a6(1, 1, 2);
//	(a5.sub(a6)).output();
//	cout << endl << endl;
//
//	iFraction a7(2, 2, 5);
//	iFraction a8(0, 1, 2);
//	(a7.sub(a8)).output();
//	cout << endl << endl;
//
//	iFraction a9(2, 2, 5);
//	iFraction a10(0, 1, 2);
//	(a9.mul(a10)).output();
//	cout << endl << endl;
//
//	iFraction a11(0, 2, 5);
//	iFraction a12(0, 1, 2);
//	(a11.mul(a12)).output();
//	cout << endl << endl;
//
//
//	iFraction a13(0, 4, 5);
//	iFraction a14(0, 1, 2);
//	(a13.div(a14)).output();
//	cout << endl << endl;
//
//	iFraction a15(0, 1, 1);
//	iFraction a16(1, 1, 2);
//	(a15.div(a16)).output();
//	cout << endl << endl;
//
//	iFraction a17(0, 1, 2);
//	iFraction a18(1, 1, 2);
//	a17.com(a18);
//	cout << endl << endl;
//
//	iFraction a19(0, 2, 4);
//	iFraction a20(0, 1, 2);
//	a19.com(a20);
//	cout << endl << endl;
//
//	Fraction a21(13, 5);
//	(convertF(a21)).output();
//}