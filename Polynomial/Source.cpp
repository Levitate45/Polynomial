#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
class poly
{
private:
	int deg;
	int* coef;
public:
	poly(int gr = -1);
	poly(const poly&);
	~poly(void);
	void read(void); // it reads coefficients – can be changed with:
	// friend istream& operator >>(istream&, poly&);
	void print(void); // it prints on the screen the polynomial in
	// "classical" format can be changed with:
	// friend ostream& operator <<(ostream&, poly&);
	poly operator+(const poly&);
	poly& operator=(const poly&);
	int& operator[](int);
	operator double(); // it returns the value of polynomial for x=1
	friend poly operator -(const poly&, const poly&);
	friend poly operator *(const poly&, int);
	friend poly operator *(int, const poly&);
};
poly::poly(int gr)
{
	deg = gr;
	coef = new int[deg + 1]; //deg+1 coefficients
	int i;
	for (i = 0; i <= deg; i++)
		coef[i] = 0;
}
poly::poly(const poly& p)
{
	deg = p.deg;
	coef = new int[p.deg + 1]; //p.deg+1 coefficients
	for (int i = 0; i <= deg; i++)
		coef[i] = p.coef[i];
}
poly::~poly()
{
	delete[] coef;
}
void poly::read()
{
	cout << endl;
	for (int i = deg; i >= 0; i--)
	{
		cout << "coef[" << i << "]=";
		cin >> coef[i];
	}
}
void poly::print()
{
	int i;
	cout << endl;
	for (i = deg; i > 0; i--)
		cout << coef[i] << "*x^" << i << " + ";
	cout << coef[i];
}
poly& poly::operator=(const poly& p)
{
	if (this != &p)
	{
		deg = p.deg;
		int i;
		delete[] coef;
		coef = new int[deg + 1];
		for (i = 0; i <= deg; i++)
			coef[i] = p.coef[i];
	}
	return *this;
}
poly poly::operator+(const poly& p)
{
	int i;
	poly rez(deg > p.deg ? deg : p.deg);
	for (i = 0; i <= deg; i++)
		rez.coef[i] = coef[i];
	for (i = 0; i <= p.deg; i++)
		rez.coef[i] += p.coef[i];
	return rez;
}
poly operator-(const poly& p1, const poly& p2)
{
	int i;
	poly rez(p1.deg > p2.deg ? p1.deg : p2.deg);
	for (i = 0; i <= p1.deg; i++)
		rez.coef[i] = p1.coef[i];
	for (i = 0; i <= p2.deg; i++)
		rez.coef[i] -= p2.coef[i];
	return rez;
}
int& poly::operator[](int i)
{
	if (i <= deg)
		return coef[i];
	else
		exit(1);
}
poly::operator double()
{
	double pol = 0;
	for (int i = 0; i <= deg; i++)
		pol += coef[i];
	return pol;
}
poly operator*(const poly& p1, int q)
{
	poly rez(p1.deg);
	for (int i = 0; i <= p1.deg; i++)
		rez.coef[i] = p1.coef[i] * q;
	return rez;
}
poly operator*(int q, const poly& p1)
{
	poly rez(p1.deg);
	for (int i = 0; i <= p1.deg; i++)
		rez.coef[i] = p1.coef[i] * q;
	return rez;
}
int main(void)
{
	poly a(2);
	poly b(3);
	poly c;
	a.read(); // cin>>a;
	b.read(); // cin>>b;
	c = a + b;
	a.print(); // cout<<a;
	b.print(); // cout<<b;
	c.print(); // cout<<c;
	cout << "\nthe coefficient of term with exponent 1 is: " << c[1];
	b[2] = 111;
	b.print();  // cout<<b;
		cout << "\nValue of polynomial is (for x=1): " << (double)a;
	cout << "\na*3:";
	(a * 3).print(); // cout<<(a*3);
	cin.ignore(1);
	cin.get();
	return 0;
}