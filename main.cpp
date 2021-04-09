#include<iostream>
#include<vector>
#include<cmath>
#include<random>
#include<cstdlib>
#include<ctime>



using namespace std;
double sigmoid(double x) {
	return 1 / (1 + (exp(-x)));
}
template<class A>
long double derivative(A(*funct)(double), A x) {
	long double h = 0.0000000001;
	return (funct(x + h) - funct(x)) / h;

}


template<class A,class B>
long double integral(B(*funct)(A),A left,A right,long long n) {
	
	long double sum = 0;
	double len = right - left;
	for (long double i = left+(len/n); i <=right; i+=(len/n)) {
		sum += funct(i);
		//cout << "i is::" << i << endl;
	}
	//sum += funct(len);
	return sum*len/n;
}

inline double myfunc(double x) {
	return -pow(x, 3) + 3 * pow(x, 2) - 2 * x - 2;
}

double newtons_method(double(*funct)(double),double start) {
	double x = start;
	double temp = 0;
	while (true) {
		temp = x;
		x = x - funct(x) / derivative(funct, x);
		
		if (float(temp) == float(x))break;
	}
	return x;

}

double my_sqrt(double num) {
	double x = 0.5;
	double temp = 0;
	while (true) {
		temp = x;
		x = x - (x*x - num) / (2*x);
		if (float(temp) ==float( x))break;
	}
	return x;
}
int main() {
	long double integ = integral<double,double>(sin, 1, 2,1000000);
	cout << "integral of my funct at given interval is ::" << integ<< endl;
	cout.precision(14);
	cout << "newton approximation of funct is::" << newtons_method(myfunc, -1)<<endl;
	cout << "sqrt of the num with newton approx. is::" << my_sqrt(231231232455) << endl;
	
}