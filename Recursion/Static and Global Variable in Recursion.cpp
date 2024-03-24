#if 0
int func(int n)
{
	Static int x = 0; // static variables in recursion
	if (n > 0)
	{
		x++;
		return func(n - 1) + x;
	}
	return 0;

}
int main(void)
{
	int a = 5;
	printf("%d", func(a));

}
#endif

#if 1
#include <iostream>
int x = 0; // global variable in recursion
int func(int n)
{
	if (n > 0)
	{
		x++;
		return func(n - 1) + x;
	}
	return 0;

}
int main(void)
{
	int a = 5;
	printf("%d", func(a));

}
#endif