#include <bits/stdc++.h>
using namespace std;

void solveABC207A() {
	vector<int> v;
	for (int i = 0; i < 3; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	cout << v[1] + v[2] << endl;
}

void solveABC207B() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	if (B >= C * D) {
		cout << -1;
		return 0;
	}

	for (long long int i = 0; i < LONG_MAX; i++) {
		long long int n_b = A + B * i;
		long long int n_r = C * i;
		if (n_b <= n_r * D) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}

void solveABC207C() {

	///////////////////////////////ˆê•”•s³‰ð
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		int l, r;
		cin >> l >> r;
		if (t == 1)		v.push_back(make_pair(2 * l, 2 * r));
		if (t == 2)		v.push_back(make_pair(2 * l, 2 * r - 1));
		if (t == 3)		v.push_back(make_pair(2 * l + 1, 2 * r));
		if (t == 4)		v.push_back(make_pair(2 * l + 1, 2 * r - 1));
	}
	int ret = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i].second < v[j].first) {
				//cout << i << j << endl;
			}
			else if (v[j].second < v[i].first) {
				//cout << i << j<<endl;
			}
			else {
				ret++;
			}
		}
	}

	cout << ret;
}
void solveABC207D() {
	int n;
	cin >> n;

	vector<int> ax, ay;
	vector<int> bx, by;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ax.push_back(x);
		ay.push_back(y);
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		bx.push_back(x);
		by.push_back(y);
	}

	int ax_range = *max_element(ax.begin(), ax.end()) - *max_element(ax.begin(), ax.end());
	int ay_range = *max_element(ay.begin(), ay.end()) - *max_element(ay.begin(), ay.end());
	int ax_range = *max_element(ax.begin(), ax.end()) - *max_element(ax.begin(), ax.end());
	int ax_range = *max_element(ax.begin(), ax.end()) - *max_element(ax.begin(), ax.end());




	double ax_ave = accumulate(ax.begin(), ax.end(), 0.0);
	double ay_ave = accumulate(ay.begin(), ay.end(), 0.0);
	double bx_ave = accumulate(bx.begin(), bx.end(), 0.0);
	double by_ave = accumulate(by.begin(), by.end(), 0.0);

	for (int i = 0; i < n; i++) {
		ax[i] -= ax_ave;
		ay[i] -= ay_ave;
		bx[i] -= bx_ave;
		by[i] -= by_ave;
	}
}
