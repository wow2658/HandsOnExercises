#if 0
Given two vectors, your task is to find the common elements between them.

All elements in one vector are unique among themselves.

Input Format :

Function contains two integer vectors v1 and v2 as parameters.

Output Format :

Return a vector containing list of common elements in sorted order.

Constraints :

	1 <= v1.size() <= 10 ^ 6

	1 <= v2.size() <= 10 ^ 6

	1 <= v1[i], v2[i] <= 10 ^ 6

	Sample Testcase :

Input:

v1[] = { 1, 45, 54, 71, 76, 12 },

v2[] = { 1, 7, 5, 4, 6, 12 }

Output:

{1, 12}
#endif

#include<bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2)
{
    vector<int> v;
    unordered_map<int, bool> map;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (auto x : v1)
        map[x] = true;

    for (auto x : v2)
    {
        if (map[x] == true)
            v.push_back(x);
    }

    return v;
}