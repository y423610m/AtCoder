#include <bits/stdc++.h>
using namespace std;

void solveARC124A() {
	int n, k;
	cin >> n >> k;

	vector<int> vi;
	vector<string> vs;
	rep(i, k) {
		string s;
		int tmp;
		cin >> s >> tmp;
		vs.push_back(s);
		vi.push_back(tmp - 1);
	}

	vector<ll> vll(n);
	rep(i, vi.size()) {//1Ç∏Ç¬ë´Ç∑
		if (vs[i] == "L") for (int j = vi[i]; j < vll.size(); j++)  vll[j]++;
		else if (vs[i] == "R") for (int j = 0; j < vi[i]; j++)  vll[j]++;
	}
	//cout << "aaaa" << endl;
	rep(i, vi.size()) {//-10000ñÑÇﬂÇÈ
		ll tmp = vi[i];
		//cout << "tmp" << tmp << endl;
		if (vll[tmp] < 0) {
			cout << 0;// << " out";
			return 0;
		}
		else vll[tmp] = -10000;
	}

	//rep(i, vll.size()) cout << vll[i] << " ";
	//cout << endl;

	//cout << "bbbb" << endl;
	ll ret = 1;
	rep(i, vll.size()) {
		//cout << ret << endl;
		if (vll[i] > 0) {
			ret *= vll[i];
			ret %= MOD;
		}
	}

	cout << ret;
}

void solveARC124B() {

	int c = 2;
	int d = 0;
	int i = 1;
	cout << ((d << i) and (c << i)) << std::endl;
	cout << ((not c) and d or c and (not d)) << std::endl;
	cout << (c || d) << endl;

	int n;  cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];

	//0ÇÃèÍçá
	int cnta = 0, cntb = 0;
	rep(i, n) if (a[i] % 2 == 0) cnta++;
	rep(i, n) if (b[i] % 2 == 1) cntb++;
	if (cnta == cntb) cout << 0; return 0;

	int x = max(*max_element(a.begin(), a.end()), *max_element(b.begin(), b.end()));
	rep(i, n) {//ï¿Ç—ïœÇ¶
		rep(j, n) {//nî‘ñ⁄
			rep(k, 30)//bit
		}

	}
}

void solveARC124C() {

	///////////////////////////// hand02 ÇÃÇ›ïsê≥âÅ@Ç»Ç∫

	int n; cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];

	ll X = a[0], Y = b[0];
	rep(i, n) {
		if (ll(gcd(X, a[i])) * gcd(Y, b[i]) > ll(gcd(X, b[i])) * gcd(Y, a[i])) {
			X = gcd(X, a[i]);
			Y = gcd(Y, b[i]);
		}
		else {
			X = gcd(X, b[i]);
			Y = gcd(Y, a[i]);
		}
	}
	cout << X << "  " << Y << endl;
	cout << ll(X) * ll(Y) / ll(gcd(X, Y)) << endl;
}