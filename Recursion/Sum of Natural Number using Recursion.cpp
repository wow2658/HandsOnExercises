#include <iostream>
// Sum of N natural numbers 
int sum(int n)	    // 재귀함수로 나타냈을때 가장 많은 메모리 공간을 사용한다.
{				    // 시간복잡도는 O(n)
	if (n == 0)
		return 0;
	return sum(n - 1) + n;
}
int Isum(int n)	    // 재귀함수를 for문으로 치환해서 나타낸 것이다.
{					// 시간복잡도는 똑같이 O(n)인데 메모리는 적게쓴다.
					// 이래서 꼬리재귀나 웬만한 재귀함수는 for문으로 표현하는 것이 메모리 사용측면에서 이득이라고 하는 것 같다.
	int s = 0, i;
	for (i = 1; i <= n; i++)
		s = s + i;

	return s;
}
int Mathsum(int n)  // 마지막으로는 수학공식으로 나타낸 것이다.
				    // 시간복잡도는 O(1)으로 수학을 왜 공부해야하는지 보여주는 무시무시한 예이다.
{
	return n * (n + 1) / 2;
}
int main()
{
	int r1 = sum(5);
	int r2 = Isum(5);
	int r3 = Mathsum(5);
	printf("%d ", r1);
	printf("%d ", r2);
	printf("%d ", r3);
	return 0;
}
