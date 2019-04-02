
#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 26;
int fiveMedian(int T[N], int a, int b)
{
	sort(T+a,T+b+1);
	if ((b - a + 1) % 2 == 1)
	{
		return (T[a + (b - a + 1) / 2]);
	}
	else
	{
		return (T[a + (b - a) / 2]);// + T[(a + (b - a + 1) / 2) + 1]);
	}
}
int magicFives(int T[N], int a, int b)
{
	if ((b - a + 1) <= 5)
	{
		return fiveMedian(T, a, b);
	}
		int i = 0;
		while (a < b)
		{
			T[i] = magicFives(T, a, a + 4);
			a += 5;
			i++;
		}
		if (a == b)
		{
			T[i] = T[a];
		}
		else
		{
			T[i] = magicFives(T, b, a);
		}
		return magicFives(T, 0, i);
	}
int main()
{
	int T[N] = { 1,15,2,3,4,7,2,3,5,8,2,17,16,3,5,2,1,11,12,10,27,25,22,10,8,3 };
	cout << magicFives(T, 0, 25);
}
