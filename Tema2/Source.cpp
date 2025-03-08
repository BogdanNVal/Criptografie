#include <iostream>

using namespace std;



int euler(long long nr)
{
	
	long long p = nr,d=3;
	 
	
	if (nr < 0) return -1;
	if (nr == 0) return 0;
	if (nr == 1) return 1;
	if (nr % 2 == 0) {
		p = p - p / 2;
		while (nr % 2 == 0) nr /= 2;
	}
		
	for (; d * d <= nr; d += 2) {
		if (nr % d == 0) {
			p -= p / d;
			while (nr % d == 0)
				nr /= d;
		}
	}

		if (nr > 1) p-=p / nr;


		
		
		
		

	return p;

}

int main()
{ 
	long long nr;
	cin >> nr;
	
	cout << euler(nr);


	return 0;
}