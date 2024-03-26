#include <iostream>
// Factorial of N 
int fact(int n)
{
	if (n == 0)
		return 1;
	return fact(n - 1) * n;
}
int Ifact(int n)
{
	int f = 1, i;
	for (i = 1; i <= n; i++)
		f = f * i;

	return f;
}
int main()
{
	int r1 = fact(5);
	printf("%d ", r1);
	int r2 = Ifact(5);
	printf("%d ", r2);
	return 0;
}