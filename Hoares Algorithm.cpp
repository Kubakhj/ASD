//Algorithm finds k-th largest element in n-sized array using Hoare's Algorithm
#include <pch.h>
#include <iostream>
using namespace std;
const int N = 9;
void printOutArray(int T[N])
{
	for (int i = 0; i < N; i++)
	{
		cout << T[i] << " ";
	}
}
int partition(int T[N],int a,int b) // decomposes an array in relation to pivot and returns pivot's index
{
	int pivot = T[b];
	int y = a;
	while (a < b)
	{
		if (T[a] < pivot)
		{
			if (a != y)
			{
				swap(T[a], T[y]);
			}
				y++;
		}
		a++;
	}
	swap(T[a], T[y]);
	return y;
}
int Hoare(int T[N], int a, int b, int k) // returns an index of k-th biggest element
{
	if (a == b) return a;
	int y = partition(T, a, b);
	if (y == k - 1) return y;
	if (k - 1 > y)
	{
		return Hoare(T, y+1, b, k - y - 1);
	}
	else
	{
		return Hoare(T, a, y - 1, k);
	}
}
int main()
{
	int T[N] = { 1,1,3,2,68,98,7,9,8 };
	cout << T[Hoare(T, 0, N - 1, 4)];
	return 0;
}


