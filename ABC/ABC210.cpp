#include <bits/stdc++.h>
using namespace std;

void solveABC210A() {
	int n, a, x, y;

	cin >> n >> a >> x >> y;

	if (n <= a) cout << n * x;
	else cout << a * x + (n - a) * y;
}


void solveABC210B() {


	string s;

	cin >> n;
	cin >> s;

	if (s.find('1') % 2 == 0) cout << "Takahashi";
	else cout << "Aoki";
}

void solveABC210C() {

	int n, k;
	vector<int> v;
	set <int> s;
	map<int, int> m;
	cin >> n >> k;


	rep(i, n) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		if (i < k) {
			s.insert(tmp);
			m[tmp]++;
		}
	}


	int ret = 0;
	int len = (int)s.size();
	ret = max(ret, (int)m.size());

	for (int i = 0; i < n - k; i++) {
		//left
		m[v[i]]--;
		if (m[v[i]] <= 0) m.erase(v[i]);
		//right
		m[v[i + k]]++;
		//cout << "   len   " << len << "   ret   " << ret << endl;
		ret = max(ret, (int)m.size());
	}

	cout << ret << endl;
}

void solveABC210D() {


	int h, w, c;

	cin >> h >> w >> c;
	vector<vector<ll>> a(h, vector<ll>(w));
	rep(i, h)rep(j, w) {
		cin >> a[i][j];
	}

	vector<vector<ll>> dp(h, vector<ll>(w));

}
