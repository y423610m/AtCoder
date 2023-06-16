#include <bits/stdc++.h>
using namespace std;

void solveARC121A() {
	int N;
	cin >> N;

	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	vector<int> distance;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int x1, y1;
			int x2, y2;
			x1 = v[i].first;
			y1 = v[i].second;
			x2 = v[j].first;
			y2 = v[j].second;
			int d = max(abs(x1 - x2), abs(y1 - y2));
			distance.push_back(d);
		}
	}
	sort(distance.begin(), distance.end(), [](int x, int y) {return x > y; });

	cout << distance[1] << endl;
}

void solveARC121A_() {
	int N;
	cin >> N;

	vector<int> X;
	vector<int> Y;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		X.push_back(x);
		Y.push_back(y);
	}

	vector<int> distance;

	auto xmin = min_element(X.begin(), X.end());
	auto xmax = max_element(X.begin(), X.end());
	auto ymin = min_element(Y.begin(), Y.end());
	auto ymax = max_element(Y.begin(), Y.end());



	int d = 0;
	for (int i = 0; i < N; i++) {
		if (i != int(xmin - X.begin())) { d = max(d, *xmax - X[i]); }
		if (i != int(xmax - X.begin())) { d = max(d, X[i] - *xmin); }
		if (i != int(ymin - Y.begin())) { d = max(d, *ymax - Y[i]); }
		if (i != int(ymax - Y.begin())) { d = max(d, Y[i] - *ymin); }
	}


	int dx = *xmax - *xmin;
	int dy = *ymax - *ymin;
	int d2 = min(dx, dy);

	if ((int(xmax - X.begin()) == int(ymax - Y.begin()) && int(xmin - X.begin()) == int(ymin - Y.begin()))
		|| (int(xmax - X.begin()) == int(ymin - Y.begin()) && int(xmin - X.begin()) == int(ymax - Y.begin())))
	{

	}
	else {
		d = max(d2, d);
	}

	cout << d << endl;
}

void solveARC121B() {
	vector<pair<int, char>> R;
	vector<pair<int, char>> G;
	vector<pair<int, char>> B;

	int N;
	cin >> N;

	for (int i = 0; i < 2 * N; i++) {
		int c;
		char s;
		cin >> c >> s;

		if (s == 'R') R.push_back({ c,s });
		if (s == 'G') G.push_back({ c,s });
		if (s == 'B') B.push_back({ c,s });
	}

	sort(R.begin(), R.end());
	sort(G.begin(), G.end());
	sort(B.begin(), B.end());

	vector<pair<int, char>> v;

	if (R.size() % 2 == 1) {
		v.push_back(R[0]);
	}
	if (G.size() % 2 == 1) {
		v.push_back(G[0]);
	}
	if (B.size() % 2 == 1) {
		v.push_back(B[0]);
	}

	if (v.size() == 0) cout << 0 << endl;
	else {
		cout << abs(v[0].first - v[1].first) << endl;
	}
}