#include <queue>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <fstream>
#include <climits>
#include <ctime>

using namespace std;

const int MaxN = (int)(1e6);

int z[MaxN];
string s, t;

void getZ () {
	int n = s.size();
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[z[i] + i])
			++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> s >> t;
	reverse (t.begin(), t.end());
	s += "#" + t;
	getZ();
	// cout << s << endl;
	/*for (int i = 0; i < s.size(); ++i)
		cout << z[i];
	cout << endl; */
	for (int j = 0, i = t.size() + 1; i < s.size(); ++j, ++i) {
		// cout << z[i] << " ";
		if (j + z[i] == t.size()) {
			cout << "Yes\n" << j;
			return 0;
		}
	}
	cout << "No";
	return 0;
}
