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

/* Template */

#define ll long long
#define foreach(it, S) for(__typeof (S.begin()) it = S.begin(); it != S.end(); it++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MN(a, b) a = min (a, b)
#define MX(a, b) a = max (a, b)
#define endl '\n'

#define fname ""

#define nxtnt getNext <int>()
#define nxtll getNext <ll>()

template <typename T> inline T getNext () { T s = 1, x = 0, c = getc(stdin); while (c <= 32) c = getc(stdin); if (c == '-')	s = -1, c = getc(stdin); while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getc(stdin); return x * s; }
const double eps = 1e-9;

bool Equals (double x, double y) { return abs (x - y) < eps; }
bool Less (double x, double y) { return (x) < y - eps; }
bool LessOrEqual (double x, double y) { return (x) < y + eps; }

const int MaxN = int (1e5) + 256;

int a[5], b[5];
int res;

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif
	
	for (int i = 0; i < 3; ++i) a[i] = nxtnt;
	for (int i = 0; i < 3; ++i) b[i] = nxtnt;
	
	sort (a, a + 3);
	sort (b, b + 3);
	
	for (int i = 0; i < 3; ++i)
		res += a[i] * b[i];
	
	cout << res;
	
	return 0;
}

