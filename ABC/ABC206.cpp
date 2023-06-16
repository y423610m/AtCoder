#include <bits/stdc++.h>
using namespace std;


void solveABC206A() {
	int n;
	cin >> n;
	n = 1.08 * n;

	if (n < 206)cout << "Yay!";
	else if (n == 206) cout << "so-so";
	else cout << ":(";
}

void solveABC206B() {

	int n;
	cin >> n;

	int money = 0;
	int day = 1;
	while (1) {
		money += day;
		if (money >= n) {
			cout << day;
			return 0;
		}
		day++;
	}
}
void solveABC206C() {

	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		m[tmp] = m[tmp] + 1;
	}


	long long int ret = 0;

	for (auto itr = m.begin(); itr != m.end(); itr++) {
		long long int i = itr->second;
		ret += i * (long long int)(n - i);

	}

	cout << ret / 2;

}

void solveABC206D() {


	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	vector<int> v1, v2;
	for (int i = 0; i < n / 2; i++) {
		v1.push_back(v[i]);
		v2.push_back(v[n - i - 1]);
	}
	//cout << v1[0] << v1[1] << endl;
	//cout << v2[0] << v2[1] << endl;[
	int ret = 0;
	while (v1 != v2) {
		int i = 0;//‰½”Ô–Ú‚ªˆá‚¤‚©
		while (v1[i] == v2[i]) {
			i++;
		}
		int i1 = v1[i];
		int i2 = v2[i];

		replace(v1.begin(), v1.end(), i1, i2);
		ret++;
	}
	cout << ret;
}