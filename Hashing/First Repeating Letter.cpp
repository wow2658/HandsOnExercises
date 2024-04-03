#if 0
First Repeating Letter!
Given a string, 
find the first repeating letter in a string in a single scan of the string.
Return '\0' if no such character exists.

Input : codingminutes
Output : i

Hint : Since we are practicing hashing, 
instead of using a simple frequency array, 
try solving this problem using an unordered_set or unordered_map.
#endif

#include<bits/stdc++.h>
using namespace std;

char firstRepeatChar(string input)
{
	unordered_map<char, bool> m;

	for (char s : input)
	{
		if (m.count(s) == 0)
		{
			m[s] = 1;
		}
		else
		{
			return s;
		}
	}
	return '\0';
}