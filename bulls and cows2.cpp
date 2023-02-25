// bulls and cows2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;


#define N 4


void print_ar(char ar[], int n)
{
	for (int i = 0; i < n; i++)
		cout << ar[i];
}


void Move2Array(int value, char ar[], int n)
{
	for (int i = N - 1; i >= 0; i--)
	{
		ar[i] = '0' + value % 10;
		value = value / 10;
	}
}

void rand_4(char ar[], int n)
{
	Move2Array(rand() % 9999, ar, n);
}


bool SameDigits(char ar[], int n)
{
	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			if (ar[i] == ar[j])
				count++;
		}

	return (count != 0);
}


int main()
{
	setlocale(0, "");

	char mech[N];
	char ours[N];

	int raz = 0;

	
	srand(time(NULL));
	for (int i = 1; i < 15; i++)
		rand();
	
	do {
		rand_4(mech, N);
	} while (SameDigits(mech, N));

	/*print_ar(mech, N);
	cout <<"\n";*/

	int nOurs;	

	int bools = 0;	
	int cows = 0;	


	do {

		
		cout << "Введите число из " << N << " цифр ";
		cin >> nOurs;
		if (nOurs == 0)
		{
			cout << "Вам надоело играть!";
			break;
		}
		if (nOurs > 9876)
		{
			cout << "вы ввели слишком большое число \n";
			continue;
		}
		if (nOurs < 123)
		{
			cout << "вы ввели слишком маленькое число \n";
			continue;
		}

		
		Move2Array(nOurs, ours, N);

		if (SameDigits(ours, N))
		{
			cout << "Нельзя вводить одинаковые цифры! \n";
			continue;
		}

		
		raz++; 

		
		bools = 0; 
		cows = 0;  
		for (int i = 0; i < N; i++)
		{
			if (mech[i] == ours[i])
				bools++;
			for (int j = 0; j < N; j++)
				if (mech[i] == ours[j])
					cows++;
		}
		cows -= bools;

		cout << "Попытка №" << raz << ": Быков " << bools << "; Коров " << cows << endl;


		
	} while (bools != 4);
}