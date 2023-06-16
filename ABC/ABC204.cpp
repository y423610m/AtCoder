#include <bits/stdc++.h>
using namespace std;

void solveABC204() {
	int x, y;
	cin >> x >> y;

	if (x == y) cout << x;
	else {
		cout << 3 - (x + y);
	}
}

void solveABC204B() {
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > 10) sum += tmp - 10;
	}

	cout << sum;
}
