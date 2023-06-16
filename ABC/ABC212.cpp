#include <bits/stdc++.h>
using namespace std;

void solveABC212A() {
	int a, b;
	cin >> a >> b;

	if (a == 0) cout << "Silver";
	else if (b == 0) cout << "Gold";
	else cout << "Alloy";
}


void solveABC212B() {


	string s;
	cin >> s;
	//int x = std::stoi(s);
	int x1 = atoi(&s[0]) / 1000;
	int x2 = atoi(&s[1]) / 100;
	int x3 = atoi(&s[2]) / 10;
	int x4 = atoi(&s[3]) % 10;

	//cout << x1;

	if (x1 == x2 && x2 == x3 && x3 == x4) cout << "Weak";
	else if (x1 + 1 == x2 && x2 + 1 == x3 && x3 + 1 == x4)cout << "Weak";
	else if (x1 == 7 && x2 == 8 && x3 == 9 && x4 == 0) cout << "Weak";
	else if (x1 == 8 && x2 == 9 && x3 == 0 && x4 == 1) cout << "Weak";
	else if (x1 == 9 && x2 == 0 && x3 == 1 && x4 == 2) cout << "Weak";
	else if (x1 == 0 && x2 == 1 && x3 == 2 && x4 == 3) cout << "Weak";
	else cout << "Strong";
}

void solveABC212C() {

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> c;
	rep(i, n) {//0
		int tmp;
		cin >> tmp;
		c.push_back(mp(tmp, 0));
	}
	rep(i, m) {//0
		int tmp;
		cin >> tmp;
		c.push_back(mp(tmp, 1));
	}

	sort(c.begin(), c.end());

	int ret = INF;
	rep(i, n + m - 1) {
		if (c[i].second != c[i + 1].second) ret = min(ret, c[i + 1].first - c[i].first);
	}

	cout << ret;
}

void solveABC212D() {

	//////////////////////////////D tle

	
		vector<ll> ball;
	int cnt = 0;


	rep(i, n) {
		if (q[i].first == 1) ball.push_back(q[i].second);
		if (q[i].first == 2)
		rep(j, ball.size()) ball[j] += q[i].second;
		if (q[i].first == 3) {
			auto it = min_element(ball.begin(), ball.end());
			cout << *it << endl;
			*it = ball.back();
			ball.pop_back();
		}
	}
	


	/*
		rep(i, n) {
			if (q[i].first == 1) ball.push_back(q[i].second);
			if (q[i].first == 2) rep(j, ball.size()) ball[j] += q[i].second;
			if (q[i].first == 3) {
				sort(ball.begin(), ball.end());
				cout << ball[0] << endl;
				ball[0] = ball.back();
				ball.pop_back();
			}
		}
		*/

		/*
		ll ret = LINF;
		ll min2=;
		rep(i, n) {
			if (q[i].first == 1) ret = min(ret, q[i].second);
			if (q[i].first == 2) ret += q[i].second;
			if (q[i].first == 3) cout << ret << endl;
		}
		*/

}
