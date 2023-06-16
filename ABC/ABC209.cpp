#include <bits/stdc++.h>
using namespace std;

void solveABC209A() {
	int a, b;
	if (a <= b) {
		cout << b - a + 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
}

void solveABC209B() {
	int n, x;
	cin >> n >> x;
	vector<int> v;


	repi(i, 1, n + 1) {
		int tmp;
		cin >> tmp;
		if (i % 2 == 0) tmp--;
		v.push_back(tmp);
	}

	if (x >= accumulate(v.begin(), v.end(), 0)) cout << "Yes";
	else cout << "No";
}

void solveABC209C() {

	int n;
	cin >> n;
	rep(i, n) {
		ll tmp;
		cin >> tmp;
		c.push_back(tmp);
	}

	sort(c.begin(), c.end());

	ll ret = 1;
	for (ll i = 0; i < ll(n); i++) {
		ret *= c[i] - i;
		ret %= MOD;
		//cout << ret << endl;
	}
	cout << endl;
	cout << ret << endl;
}

void solveABC209D() {

	//////////////////////////////D RE and TLE
	int n, q;
	vector<pair<int, int>> way;
	vector<int> vc;
	vector<int> vd;
	vector<string> ans;

	cin >> n >> q;
	vector<vector<int>> dist(n + 1, vector<int>(n + 1));
	rep(i, n)rep(j, n) dist[i][j] = INF;
	rep(i, n) dist[i][i] = 0;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		dist[a - 1][b - 1] = 1;
		dist[b - 1][a - 1] = 1;
	}
	rep(i, q) {
		int c, d;
		cin >> c >> d;
		vc.push_back(c - 1);
		vd.push_back(d - 1);
	}

	//ダイクストラ
	rep(i, q) {
		vector<int> d(n + 1, INF);
		vector<bool> used(n + 1, false);
		d[vc[i]] = 0;
		while (1) {
			int v = -1;
			rep(u, n) if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
			if (v == -1) break;
			used[v] = true;
			rep(u, n) d[u] = min(d[u], d[v] + dist[v][u]);
		}

		if (d[vd[i]] % 2 == 0) cout << "Town" << endl;
		else cout << "Road" << endl;
	}
	return 0;


	/*
	rep(i, q) {
		//cout << c[i] << "  " << d[i] << endl;
		if (dist[c[i]][d[i]] % 2 == 0) cout << "Town" << endl;
		else cout << "Road" << endl;
	}
	*/
	//ベルマン
	/*
	rep(k, n) {
		rep(i, n) {
			rep(j, n) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	*/
}