#include <iostream>
// Taylor Series using Static variables 
double e1(int x, int n) // 실질적으로는 e^x이고 n이 높아질수록 정확해진다.
{
	static double p = 1, f = 1;
	double r;

	if (n == 0)
		return 1;
	r = e1(x, n - 1);
	p = p * x;
	f = f * n;
	return r + p / f;
}

//Taylor Series Horner’s Rule
double e2(int x, int n)
{
	static double s;
	if (n == 0)
		return s;
	s = 1 + x * s / n;
	return e2(x, n - 1);

}

//Taylor Serie Iterative
double e3(int x, int n)
{
	double s = 1;
	int i;
	double num = 1;
	double den = 1;

	for (i = 1; i <= n; i++)
	{
		num *= x;
		den *= i;
		s += num / den;
	}
	return s;
}
int main()
{
	printf("%lf \n", e1(1, 10));
	printf("%lf \n", e2(1, 10));
	printf("%lf \n", e3(1, 10));
	return 0;
}
