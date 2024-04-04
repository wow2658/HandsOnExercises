// https://www.hackerrank.com/challenges/count-triplets-1/problem

long countTriplets(vector<long> arr, long r) {

	unordered_map<long, long> right, left;

	for (auto x : arr)
	{
		right[x]++;
		left[x] = 0;

	}

	long ans = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		right[arr[i]]--;

		if (arr[i] % r == 0)
		{
			long b = arr[i];
			long a = arr[i] / r;
			long c = arr[i] * r;

			ans += left[a] * right[c];
		}
		left[arr[i]]++;

	}
	return ans;
}