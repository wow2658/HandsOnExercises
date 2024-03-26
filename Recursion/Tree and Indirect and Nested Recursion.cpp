#if 1
// Tree Recursion
#include <stdio.h>
void fun(int n)
{
	if (n > 0)
	{
		printf("%d ", n);
		fun(n - 1);
		fun(n - 1);
	}
}
int main() 
{
	fun(3);
	return 0;
}
#endif
#if 0
// Indirect Recursion 
#include <stdio.h>
void funB(int n); // 미리 선언해놔야 funA에서 사용가능
void funA(int n)
{
	if (n > 0)
	{
		printf("%d ", n);
		funB(n - 1);
	}
}
void funB(int n)
{
	if (n > 1)
	{
		printf("%d ", n);
		funA(n / 2);
	}
}

int main()
{
	funA(20);
	return 0;
}
#endif
#if 0
// Nested Recursion
#include <stdio.h>
int fun(int n)
{
	if (n > 100)
		return n - 10;
	return fun(fun(n + 11));
}
int main()
{
	int r;
	r = fun(95);
	printf("%d\n", r);
	return 0;
}
#endif