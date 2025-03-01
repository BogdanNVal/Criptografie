#include <iostream>
#include <string.h>

using namespace std;



string schimbare_baza(char nr[], int b1, int b2)
{
	int n = 0, p = 1, i = strlen(nr);
	string numar;

	//trecerea de la baza b1 la baza 10

	if (b1 == 26)

		while (i>0)
		{	
			n = n+ (int(nr[i - 1])-65) * p;
			i--;
			p = p * b1;
		}
	else
	{
		while (i > 0)
		{	if(int(nr[i - 1])>64)
				n = n + (int(nr[i - 1])-55) * p;
			else
				n = n + (int(nr[i - 1]) - 48) * p;
			i--;
			p = p * b1;
		}

	}


	//trecerea de la baza 10 la baza b2


	if (b2 == 26)
		while(n>0)
		{
			numar = char(n % b2+65)+numar;
			n = n / b2;
			i++;

		}
	else 
		while (n > 0)
		{
			if (n % b2 >= 10)
				numar = char(n % b2 + 55)+numar;
			else
				numar = char(n % b2+48)+numar;
			n = n / b2;
			i++;

		}



		return numar;
}

int main()
{

	char nr[100] = "AAB0";

	cout << schimbare_baza(nr, 16, 26);
	
	
	return 0;
}

