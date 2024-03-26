#include <iostream>
using namespace std;

int Q1(int n)
{
	static int i = 1;
	if (n >= 5)return n;
	n = n + i;
	i++;
	return Q1(n);
}

void Q2(int n, int sum)
{
	int k = 0, j = 0;
	if (n == 0) return;
	k = n % 10;
	j = n / 10;
	sum = sum + k;
	Q2(j, sum);
	printf("%d ", k);
}

int Q3(int& x, int c)
{
	c = c - 1;
	if (c == 0) return 1;
	x = x + 1;
	return Q3(x, c) * x;
}

int Q4(int n)
{
	int x = 1, k;
	if (n == 1) return x;
	for (k = 1; k < n; ++k)
		x = x + Q4(k) * Q4(n - k);
	return x;
}

void Q5(int n)
{
	static int d = 1;
	printf("%d ", n);
	printf("%d ", d);
	d++;
	if (n > 1) Q5(n - 1);
	printf("%d ", d);
}

int main()
{
	cout << Q1(1) << endl;

	int a = 2048, sum = 0;
	Q2(a, sum);
	printf("%d\n", sum);

	int p = 5;
	cout << Q3(p, p) << endl;

	cout << Q4(5) << endl;

	Q5(3);

	return 0;
}