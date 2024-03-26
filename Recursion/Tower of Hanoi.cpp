// Tower of Hanoi
enum { A = 1, B, C };
#include <stdio.h>
static void TOH(int n, int From, int Using, int Dest)
{
	int A = From;
	int B = Using;
	int C = Dest;
	if (n > 0)
	{
		TOH(n - 1, A, C, B);
		printf("(%d,%d)\n", A, C);
		TOH(n - 1, B, A, C);
	}
}
int main()
{
	TOH(4, A, B, C);
	return 0;
}