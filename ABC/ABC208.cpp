#include <bits/stdc++.h>
using namespace std;

void solveABC208A() {

	int A, B;
	cin >> A >> B;

	if (B < A) {
		cout << "No" << endl;
		return 0;
	}
	else if (B > 6 * A) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
}

void solveABC208B() {

	int kaijo(int n) {
		if (n == 1)return 1;

		return n * kaijo(n - 1);
	}

	vector<int> coin;
	for (int i = 1; i <= 10; i++) {
		coin.push_back(kaijo(i));
	}

	reverse(coin.begin(), coin.end());

	int P;
	cin >> P;

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		int cnt = 0;
		while (cnt < 100 && P >= coin[i]) {
			P -= coin[i];
			cnt++;
		}
		sum += cnt;
	}
	cout << sum << endl;
}

void solveABC208C() {
	int N;
	long long int K;
	cin >> N >> K;

	vector<pair<int, int>> v;
	vector<long long int>  snack(N);

	for (int i = 0; i < N; i++) {
		int id;
		cin >> id;
		v.push_back(make_pair(id, i));
	}

	//Nà»è„
	long long int common = K / N;
	K %= N;

	//cout << "common" << common << endl;

	//NÇÊÇËè≠Ç»Ç¢
	sort(v.begin(), v.end());

	int i = 0;
	while (K > 0) {
		snack[v[i].second]++;
		K--;
		i++;
	}


	for (int i = 0; i < N; i++) {
		cout << common + snack[i] << endl;
	}
}

void solveABC208D() {


	int done[410][410];
	vector<vector<int>> bridge;
	long long int go(int s, int t, int k, long long int time = 0, long long int ret = 1000000000000000000) {
		if (s == t) return time;

		for (int i = 1; i < k + 1; i++) {
			if (bridge[s][i] != 0) {
				time += bridge[s][i];
				ret = min(ret, go(i, t, k, time, ret));
				time -= bridge[s][i];
			}
		}

		return time;
	}
	int N, M;
	cin >> N >> M;
	bridge = vector<vector<int>>(N + 1, vector<int>(N + 1));
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		bridge[A][B] = C;
	}

	long long int ret = 0;
	for (int s = 1; s < N; s++) {
		for (int t = 1; t < N + 1; t++) {
			for (int k = 1; k < N + 1; k++) {

				ret += go(s, t, k);

			}
		}
	}

	cout << ret << endl;
}