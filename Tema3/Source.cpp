#include<iostream>
#include<math.h>


using namespace std;

//Din laboratorul 3
int** factor(unsigned int n, int& nr)
{
	int** descompunere = new int* [2];
	descompunere[0] = new int[n];
	descompunere[1] = new int[n];
	for (unsigned long long i = 0; i < n; i++)
		descompunere[0][i] = descompunere[1][i] = 0;
	if (n % 2 == 0)
	{
		descompunere[0][0] = 2;
		nr++;
		while (n % 2 == 0)
		{
			descompunere[1][0]++;
			n /= 2;
		}
	}
	for (unsigned long long i = 3; i <= n; i += 2)
	{
		if (n % i == 0)
		{
			descompunere[0][nr] = i;
			while (n % i == 0)
			{
				descompunere[1][nr]++;
				n /= i;
			}
			nr++;
		}
	}
	return descompunere;
}

//Din laboratorul 1
int modulo(int k, int n) {
	if (k < 0)k = n - (-k) % n;
	if (k >= n) return k % n;
	return k;
}

//k la puterea p mod n
int modulo(int k, int p, int n)
{
	int temp=1;
	k=modulo(k, n);
	while (p > 1) {
		if (!(p % 2))
		{
			k = modulo(k * k, n);
			p /= 2;
		}
		else
		{
			temp = modulo(temp*k, n);
			p--;
		}

	}
	k = modulo(temp * k, n);
	return k;
}


//Simbolul Jacobi
int jacobi(int n, int b) {
	int simb=1,temp;
	int nr = 0;

	int** a = factor(n, nr);
	for (int i = 0; i < nr; i++)
	{
		if (!modulo(b, a[0][i]))
			return 0;
		temp = modulo(b,a[0][i]);
		if (sqrt((double)temp) * sqrt((double)temp) != temp)
			if (a[1][i] % 2)
				simb = -1 * simb;

		
	}
	return simb;
}

//Algoritmul Solovay–Strassen
bool  Solovay_Strassen(int n, int b)
{
	int a = (n - 1) / 2;
	int ss = modulo(b, a, n);
	int j=jacobi(n, b);
	j = modulo(j, n);
	if (ss == j)
		return 1;
	
	return 0;
}


int main() {
	//n numar impar
	int n=17, b=20;

	
	//cout << jacobi(n, b)<<endl;
	//cout << Solovay_Strassen(n,b)<<endl;
	if (Solovay_Strassen(n, b)) cout << "Este prim"<<endl;
	else cout << "Nu este prim"<<endl;
	//cout << modulo(2, 100, 71)<<endl;

	return 0;
}