#include <bits/stdc++.h>

using namespace std;

typedef long double ldb;
typedef long long ll;

const ldb eps = 1e-6;

template <typename T> T sqr(T a) {
	return a * a;
}

struct point {
	ll x, y;
	point read() {
		cin >> x >> y;
		return *this;
	} 
};

inline ldb distance(const point &a, const point &b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

struct Vector {
	ll x, y;
	Vector(point a, point b) {
		x = (b.x - a.x);
		y = (b.y - a.y);
	}
};

inline int dotProd(const Vector &a, const Vector &b) {
	return a.x * b.x + a.y * b.y;
}

inline int crossProd(const Vector &a, const Vector &b) {
	return a.x * b.y - a.y * b.x;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t; cin >> t;
	int res = 0;
	
	while (t--) {
		point pt = point().read();
		vector <point> v;
		for (int i = 0; i < 4; ++i)
			v.push_back(point().read());
		
		ldb cnt = 0;
		
		for (int i = 0; i < 4; ++i) {
			Vector v1 = Vector(pt, v[i]);
			Vector v2 = Vector(pt, v[(i + 1) % 4]);
			cnt += atan2(crossProd(v1, v2), dotProd(v1, v2));
			// cnt += atan2(dotProd(v1, v2), crossProd(v1, v2));
		}
		
		/* for (int i = 0; i < 4; ++i) {
			cerr << v[i].x << " " << v[i].y << endl;
			cnt += distance(pt, v[i]);
		} */
		
		// cerr << cnt << endl;
		
		res += fabs(cnt) > eps;
	}
	
	cout << res;
	
	return 0;
}

