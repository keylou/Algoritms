#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<pair<int, int>> v;

int cmp(pair<int, int> a, pair<int, int> b)
{
	int mm = min(min(a.first, a.second), min(b.first, b.second));
	if ((mm == a.first) || (mm == b.second)) return 0;
	return 1;
}

void sort()
{
	int i, j;
	for (i = 0; i < v.size(); i++)
		for (j = i + 1; j < v.size(); j++)
			if (cmp(v[i], v[j])) swap(v[i], v[j]);
}

int main()
{
	int n,a,b,sum;
	cin >> n;
	int* up = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		up[i] = a;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b;
		v.push_back(make_pair(up[i], b));
	}
	sort();
	sum = v[0].first + v[0].second;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1].second < v[i].first)
			sum += v[i].first - v[i - 1].second;
		sum += v[i].second;
	}
	cout << "\n" << sum;
}