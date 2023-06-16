#include <bits/stdc++.h>
using namespace std;

void solveABC213A() {

	int a, b;
	cin >> a >> b;
	int ret = 0;
	int i = 0;
	while (a > 0 || b > 0) {
		if ((a % 2) != (b % 2)) ret += pow(2, i);
		a /= 2;
		b /= 2;
		i++;
	}
	cout << ret << endl;
}

void solveABC213B() {

	int n; cin >> n;
	vector<pair<int, int>> v;
	rep(i, n) {
		int tmp;
		cin >> tmp;
		v.push_back(mp(tmp, i + 1));
	}
	sort(v.begin(), v.end());
	cout << v[n - 2].second << endl;
}

void solveABC213C() {


	int h, w, n; cin >> h >> w >> n;
	vector<pair<int, int>> vx;
	vector<pair<int, int>> vy;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		vx.push_back(mp(a - 1, i));
		vy.push_back(mp(b - 1, i));
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	vector<pair<int, pair<int, int>>> ret(n);//num i j
	int last = vx[0].first;
	int x = 0;
	rep(i, n) {
		if (last < vx[i].first) {
			x++;
			last = vx[i].first;
		}
		ret[vx[i].second].second.first = x;
	}
	last = vy[0].first;
	int y = 0;
	rep(i, n) {
		if (last < vy[i].first) {
			y++;
			last = vy[i].first;
		}
		ret[vy[i].second].second.second = y;
	}
	rep(i, n) cout << ret[i].second.first + 1 << " " << ret[i].second.second + 1 << endl;
}

void solveABC213D() {

	int n; cin >> n;
	vector<vector<int>> v(n);
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int now = 1;
	int cnt = 1;
	stack<int> q;
	vector<int> ret;
	ret.push_back(now);
	q.push(now);

	while (cnt < n || q.size()>0) {
		if (v[now].size() > 0) {
			int tmp = now;
			now = v[now][0];
			ret.push_back(now);
			swap(v[tmp][0], v[tmp].back());
			v[tmp].pop_back();
			cnt++;
		}
		else {
			now = q.top();
			q.pop();
			ret.push_back(now);
		}
	}

	rep(i, ret.size()) cout << ret[i] << " ";
}