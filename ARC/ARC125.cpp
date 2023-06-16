#include <bits/stdc++.h>
using namespace std;

void solveA() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> t(m);
	rep(i, m) cin >> t[i];

	//‚»‚à‚»‚à‰Â”\ ?
	if (find(a.begin(), a.end(), 0) == a.end() && find(t.begin(), t.end(), 0) != t.end()) {
		cout << -1 << endl;
		return;
	}
	if (find(a.begin(), a.end(), 1) == a.end() && find(t.begin(), t.end(), 1) != t.end()) {
		cout << -1 << endl;
		return;
	}

	//Œð‘ã‰ñ”
	int cnt = 0;
	rep(i, m - 1) if (t[i] != t[i + 1]) ++cnt;


	//Å‰‚Ì“ü‚ê‘Ö‚¦‰ñ”
	int inv = 1 - a[0];
	auto itf = find(a.begin(), a.end(), inv);
	int init = int(itf - a.begin()) - 1;
	reverse(a.begin(), a.end());
	auto itb = find(a.begin(), a.end(), inv);
	init = min(init, int(itb - a.begin()));
	reverse(a.begin(), a.end());

	// T‚Í0‚Ì‚Ýor1‚Ì‚Ý@‚©‚Â@Å‰“¯‚¶
	if (cnt == 0) {
		if (a[0] == t[0]) {
			cout << m << endl;
			return;
		}
		else {
			cout << m + init + 1 << endl;
			return;
		}
	}

	//cout << "init "<<init << endl;
	if (a[0] == t[0])cout << m + cnt + init << endl;
	else cout << m + cnt + init + 1 << endl;

	return;
}

void solveB() {
	ll n;
	cin >> n;

	ll X = ll(sqrt(n));
	while ((X + 1) * (X + 1) - X * X <= n) ++X;
	cout << X << endl;

	ll ret = 0;


	for (ll i = 1; i <= X; ++i) {
		if (i * i <= n) {
			ret += i;
		}
		else {
			ll a = 1;
			while (a <= X) {
				if (i * i - a * a <= n && i * i - a * a > 0) {
					ret++;
				}
				a++;
			}
		}
		//ret %= MOD;
		//cout << i << " " << ret << endl;
	}

	cout << ret << endl;
}