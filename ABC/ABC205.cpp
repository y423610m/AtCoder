#include <bits/stdc++.h>
using namespace std;

void solveABC205A() {
	int a, b;
	cin >> a >> b;
	cout << float(a * b) / 100.0;

}

void solveABC205A() {

	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 1; i <= n; i++) {

		if (find(v.begin(), v.end(), i) == v.end()) {
			cout << "No" << endl;
			return 0;
		}

	}

	cout << "Yes";
}
void solveABC205C() {

	//‰½‚ª‚¾‚ß‚¾‚Á‚½‚Ì‚©...
	int a, b, c;
	cin >> a >> b >> c;

	if (c % 2 == 0) {
		if (abs(a) > abs(b)) cout << ">";
		if (abs(a) < abs(b)) cout << "<";
		if (abs(a) == abs(b)) cout << "=";
	}
	else {
		if (a > b) cout << ">";
		if (a < b) cout << "<";
		if (a == b) cout << "=";
	}

}
void solveABC205D_TLE() {

	//D TLE


	int n, q;
	cin >> n >> q;

	vector<long long int> v;
	for (int i = 0; i < n; i++) {
		long long int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	vector<long long int> vq;
	for (int i = 0; i < q; i++) {
		long long int tmp;
		cin >> tmp;
		vq.push_back(tmp);
	}


	for (int k = 0; k < q; k++) {
		long long int i = vq[k];
		long long int j = 0;
		while (j < n && v[j] - (j + 1) < i) {
			//cout << v.size() << "  " << j << endl;
			j++;
		}
		j--;
		cout << i + j + 1 << endl;
	}

}
void solveABC205D() {

	//D AC
	int n, q;
	cin >> n >> q;

	vector<long long int> v;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		long long int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	v.push_back(1e18 + 10);

	vector<long long int> vs;
	for (int i = 0; i < n + 2; i++) {
		vs.push_back(v[i] - i);
		//cout << vs[i] << "  ";
	}
	//cout << endl;

	vector<long long int> vq;
	for (int i = 0; i < q; i++) {
		long long int tmp;
		cin >> tmp;
		vq.push_back(tmp);
	}

	for (int i = 0; i < q; i++) {
		long long int t = vq[i];
		int bottom = 0, top = n + 1;
		int med;
		while (bottom + 1 < top) {
			med = (bottom + top) / 2;
			if (vs[med] < t) bottom = med;
			else top = med;
			//cout << bottom << "    " << top << endl;
		}
		//cout<< v[bottom]<<"    "<<t <<"    "<< -vs[bottom] << endl;
		cout << v[bottom] + t - vs[bottom] << endl;

	}
}