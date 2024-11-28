// kolokwiuem  termin 1 grupa 1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class K1 {
	string * p1;
public:
	K1() : p1(new string[2]) { 
		p1[0] = " ";
		p1[1] = " ";
	}// konstruktor domyślny w zmiennych klasowych nie mamy zapisanej tablicy wiec musimy zawsze ją zrobić
	K1( string& w1,  string& w2) : p1(new string[2]) {
		p1[0] = w1;
		p1[1] = w2;
	}
	K1(const K1& k) : p1(new string[2]) {
		p1[0] = k.p1[0];
		p1[1] = k.p1[1];


	}//konstruktor kopiujacy
	~K1() {delete[] p1; }// destruktor

	K1& operator =(const K1& ob) {
		p1[0] = ob.p1[0];
		p1[1] = ob.p1[1];
		return *this;
	}//operator przeciążania zmiennej = - przyrownania

	string operator [](size_t roz) const  {
		return p1[roz];
	}//operator przeciążania adresowania, zmiana statik na air

};
class K2 {
	K1 w1;
	double w2;
public:
	K2(): w1(), w2(0) {}//konstruktor domyślny
	K2( string e1,  string e2, double e3): w1(e1,e2), w2(e3) {}
	K2(const K2& kopia): w1(kopia.w1), w2(kopia.w2) {}//konstruktor kopiujacy
	
	K2& operator =(const K2& ob) {
		w1 = ob.w1;
		w2 = ob.w2;
		return *this;
	}
	
	K2 operator -(const double a) {
		return K2(w1[0], w1[1], w2 - a);
	}
	K2 operator +=(const double liczba) {
		w2 += liczba;
		return *this;
	}
	friend ostream& operator <<(ostream& lewa, const K2& prawa);
};
ostream& operator <<(ostream& lewa, const K2& prawa) {
	 lewa << prawa.w1[0]<<prawa.w1[1] << prawa.w2 << endl;
	 return lewa;
}
int main()
{
	K2 ob1, ob2;
	const K2 * wsk1 = new K2("cos", "cos2", 4.8);
	const K2 ob3(*wsk1);
	delete wsk1;
	wsk1 = 0;
	const K2 *wsk2 = new K2(ob3);
	ob2 = *wsk2;
	cout << ob1 << *wsk2 << endl;
	delete wsk2;
	wsk2 = 0;
	cout << ob2 << endl;
	cout << ob2 - 1.25;
	//---3---
	K2 tab[4];
	ifstream myfile;
	myfile.open("example.txt");
	if (myfile.is_open())
	{
		for (int i = 0; i < 4; i++) {
			string one;
			string two;
			double three;
			myfile >> one >> two >> three;
			tab[i] = K2(one, two, three);
		}
		for (int i = 0; i < 4; i++) {
			tab[i] += 1;
			cout << tab[i];
		}

		myfile.close();
	}
	//---4---

	cin.get();
	return 0;
}
