#include <bits/stdc++.h>
using namespace std;

void solveABC211A() {
	int a, b;
	cin >> a >> b;

	float c = float(a - b) / 3.0 + float(b);

	cout << c;
}

void solveABC211B() {

	vector<string> v(4);
	rep(i, 4) cin >> v[i];

	sort(v.begin(), v.end());

	bool ok = true;
	rep(i, 3) {
		if (v[i] == v[i + 1]) ok = false;
	}

	if (ok) cout << "Yes";
	else cout << "No";
}


void solveABC211C() {


	string s;
	string ta = "chokudai";

	cin >> s;
	vector<ll> v(s.size());

	rep(i, v.size()) if (s[i] == 'c') v[i] = 1;

	rep(k, ta.size() - 1) {
		char last = ta[k];
		char now = ta[k + 1];
		ll cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == last) {
				cnt += v[i];
				cnt %= MOD;
				v[i] = 0;
			}
			if (s[i] == now) {
				v[i] = cnt;
				v[i] %= MOD;
			}
		}

	}

	ll ret = 0;
	for (int i = 0; i < v.size(); i++) {
		ret += v[i];
		ret %= MOD;
	}
	cout << ret;
}

void solveABC211D() {

	int n, m;
	cin >> n >> m;
	vector<vector<int>> dist(n, vector<int>(n));
	rep(i, n) rep(j, n) dist[i][j] = INF;
	rep(i, n) dist[i][i] = 0;
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		dist[a - 1][b - 1] = 1;
		dist[b - 1][a - 1] = 1;
	}

	queue<int> q;
	q.push(1);


	//ダイクストラ風
	/*
	int ret = 0;
	rep(i, n) {//goal
		rep(j, n) {//mid
			if (i = n - 1) {
				if (dist[0][i] > dist[0][j] + dist[j][i]) {
					dist[0][i] = dist[0][j] + dist[j][i];
					ret = 0;
				}
				else if (dist[0][i] == dist[0][j] + dist[j][i]) ret++;
				else ret = 0;
			}
			else {
				dist[0][i] = min(dist[0][i], dist[0][j] + dist[j][i]);
			}
		}
	}
	cout << ret+1 << endl;
	*/
}