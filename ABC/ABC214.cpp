#include <bits/stdc++.h>
using namespace std;

void solveABC214B() {

	int s, t;
	cin >> s >> t;

	int ret = 0;
	rep(i, 101) {
		rep(j, 101 - i) {
			rep(k, 101 - i - j) {
				if (i + j + k <= s && i * j * k <= t) ret++;
			}
		}
	}

	cout << ret << endl;
}

void solveABC214C() {

	int n; cin >> n;
	vector<int> s(n);
	vector<int> t(n);
	rep(i, n)cin >> s[i];
	rep(i, n)cin >> t[i];

	vector<ll> ret(n);
	rep(i, n) ret[i] = t[i];

	rep(i, n - 1) ret[i + 1] = min(ret[i] + s[i], ret[i + 1]);
	ret[0] = min(ret[0], ret[n - 1] + s[n - 1]);
	rep(i, n - 1) ret[i + 1] = min(ret[i] + s[i], ret[i + 1]);
	rep(i, n) cout << ret[i] << endl;
}

void solveABC214D() {

	///////////////////////// d runtime error
	int n; cin >> n;
	vector<vector<int>> dist(n, vector<int>(n, INF));
	rep(i, n) dist[i][i] = 0;
	vector<vector<int>> w(n, vector<int>(n));
	rep(i, n - 1) {
		int u, v, w_;
		cin >> u >> v >> w_;
		w[u - 1][v - 1] = w_;
		w[v - 1][u - 1] = w_;
		dist[u - 1][v - 1] = 1;
		dist[v - 1][u - 1] = 1;
	}

	rep(s, n - 1) {
		repi(g, s + 1, n) {
			rep(m, n) {
				if (dist[s][m] + dist[m][g] <= dist[s][g]) {
					dist[s][g] = dist[s][m] + dist[m][g];
					dist[g][s] = dist[s][m] + dist[m][g];
					int tmp = max(w[s][m], w[m][g]);
					w[s][g] = max(w[s][g], tmp);
					w[g][s] = max(w[s][g], tmp);
				}
			}
		}
	}

	ll ans = 0;
	rep(i, n - 1) repi(j, i + 1, n) ans += w[i][j];
	cout << ans << endl;
}