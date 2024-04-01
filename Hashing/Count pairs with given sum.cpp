#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
int getPairsCount_unordered_map(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.find(k - arr[i]) != m.end())
        {
            count += m[k - arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
}

int getPairsCount_sort(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int x = 0, c = 0, y, z;
    for (int i = 0; i < n - 1; i++)
    {
        x = k - arr[i];

        int y = lower_bound(arr + i + 1, arr + n, x) - arr;
        int z = upper_bound(arr + i + 1, arr + n, x) - arr;
        c = c + z - y;
    }
    return c;
}

int getPairsCount_for2(int arr[], int n, int K)
{
    int count = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == K)
                count++;

    return count;
}

int main()
{
    int arr[] = { 1, 5, 7, -1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;

    cout << "Count of pairs is "
        << getPairsCount_unordered_map(arr, n, sum);
    return 0;
}
