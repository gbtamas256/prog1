#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try{
	cout << "sizeof:\n";
	cout << "char\t" << sizeof(char) << '\n';
	cout << "short\t" << sizeof(short) << '\n';
	cout << "int\t" << sizeof(int) << '\n';
	cout << "long\t" << sizeof(long) << '\n';
	cout << "float\t" << sizeof(float) << '\n';
	cout << "double\t" << sizeof(double) << '\n';
	cout << "int*\t" << sizeof(int*) << '\n';
	cout << "double*\t" << sizeof(double*) << '\n';
	
	cout << "\nMatrix sizes:\n";
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);
	cout << "1D int, 10 elem\t\t" << sizeof(a) << '\n';
	cout << "1D int, 100 elem\t" << sizeof(b) << '\n';
	cout << "1D double, 10 elem\t" << sizeof(c) << '\n';
	cout << "2D int, 10x10 elem\t" << sizeof(d) << '\n';
	cout << "3D int, 10x10x10 elem\t" << sizeof(e) << '\n';
	
	cout << "\nNumber of elements:\n";
	cout << "a:\t" << a.size() << '\n';
	cout << "b:\t" << b.size() << '\n';
	cout << "c:\t" << c.size() << '\n';
	cout << "d:\t" << d.size() << '\n';
	cout << "e:\t" << e.size() << '\n';
	
	int i;
	cout << "\nEnter ints:";
	while(cin >> i) {
		errno = 0;
		double d = sqrt(i);
		if (errno == EDOM)
			cout << "no square root\n";
		else
			cout << "sqrt(" << i << ") = " << d << '\n';
	}
	
	cin.clear();
	cin.ignore();
	cout << "\nEnter 10 floats: ";
	Matrix<double> mx(10);
	double d2;
	for(int i=0; i<mx.size(); i++) {
		cin >> d2;
		if(!cin) throw runtime_error("Error while reading from cin!");
		mx[i] = d2;
	}
	
	cout << "Matrix:\n" << mx << '\n';
	
	int n;
	int m;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter m: ";
	cin >> m;
	Matrix<int,2> mx2(n,m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			mx2(i,j) = (i+1)*(j+1);
			cout << setw(5) << mx2(i,j);
		}
		cout << '\n';
	}
	
	Matrix<complex<double>> mx3(10);
	cout << "Enter 10 complex numbers (Re, Im): ";
	complex<double> comp;
	for(int i=0; i<10; i++) {
		cin >> comp;
		if(!cin) throw runtime_error("Problem reading complex number!");
		mx3[i] = comp;
	}
	complex<double> sum;
	for(Index i = 0; i<mx3.size(); i++) {
		sum += mx3[i];
	}
	cout << "Sum: " << sum << '\n';
	
	Matrix<int,2> mx4(2,3);
	cout << "\nEnter 6 integers: ";
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> mx2(i,j);
			cout << mx2(i,j) << '\t';
		}
		cout << '\n';
	}
	
} catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
} catch (...) {
	cerr << "Unknown exception: " << '\n';
}
