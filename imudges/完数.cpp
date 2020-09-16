#include<iostream>
using namespace std;
void lfh(int a)
{
	int  i;
	for (i = 1; i < a; i++)
	{
		if (a % i == 0) cout << i << " ";
	}
}
int main()
{
	int p[100];
	int i, m = 0, a = 2, sum = 0, N, j=0, d;
	cin >> N;
	if (N >=6)
	{
		while (a <= N)
		{
			if (a != 1)
			{
				for (i = 1; i < a; i++)
				{
					if (a % i == 0) sum += i;
				}
				if (sum == a)
				{
					p[j] = a;
					j++;											
				}
				sum = 0;
			}
			a++;
		}
		
		for (d = 0; d <= j-1; d++)
		{
	     	cout << p[d] << " its factors are ";
			lfh(p[d]);
			cout << endl;
		}
	}
}




#include<iostream>
using namespace std;
void lfh(int a)
{
	int  i;
	for (i = 2; i < a; i++)
	{
		if (a % i == 0) cout << "+" << i;
	}
}
int main()
{
	int p[100];
	int i, m = 0, a = 2, sum = 0, N, j = 0, d;
	N = 1000;
	if (N >= 6)
	{
		while (a <= N)
		{
			if (a != 1)
			{
				for (i = 1; i < a; i++)
				{
					if (a % i == 0) sum += i;
				}
				if (sum == a)
				{
					p[j] = a;
					j++;
				}
				sum = 0;
			}
			a++;
		}
		cout << "1=1" << endl;
		for (d = 0; d <= j - 1; d++)
		{
			cout << p[d] << "=1";
			lfh(p[d]);
			cout << endl;
		}
	}
}