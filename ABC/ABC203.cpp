#include <bits/stdc++.h>
using namespace std;

void solveABC203A() {
	int a, b, c;

	cin >> a >> b >> c;


	if (a == b) {
		cout << c;
	}
	else if (b == c) {
		cout << a;
	}
	else if (c == a) {
		cout << b;
	}
	else {
		cout << 0;
	}
}

void solveABC203B() {
	int N, K;
	cin >> N >> K;

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			sum += 100 * i + j;
		}
	}

	cout << sum << endl;
}

void solveABC203C() {
	int N;
	long long K;
	cin >> N >> K;

	vector<pair<long long, long long>> v;
	//machi  , money 
	for (int i = 0; i < N; i++) {
		long long city;
		long long money;
		cin >> city >> money;
		v.push_back({ city,money });
		//cout << money << endl;
	}

	sort(v.begin(), v.end());

	long long city = 0;
	long long money = K;
	int ids = 0;
	for(int i = 0; i < N; i++) {

		if (money - (v[i].first - city) < 0) break;
		else {
			money -= v[i].first - city;
			money += v[i].second;
			city = v[i].first;
			//money += fre_money[i];
		}
	}

	cout << city + money << endl;
}
void solveABC203D_ori() {
	int N, K;
	cin >> N >> K;

	//pre defined
	/*
	vector<vector<string>> A(N,vector<string>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			string s;
			cin >> s;
			A[i][j] = s;
			cout << A[i][j] << endl;
		}
	}*/

	//undefined
	vector<vector<string>> A;
	for (int i = 0; i < N; i++) {
		A.push_back(vector<string>());
		for (int j = 0; j < N; j++) {
			string s;
			cin >> s;
			A[i].push_back(s);
		}
		cout << A[i][0] << endl;
	}

	//cout << "input finish" << endl;
	string med;
	for (int i = 0; i < N - K + 1; i++) {//y start
		for (int j = 0; j < N - K + 1; j++) {//x start

			vector<string> KK;
			for (int k = 0; k < K; k++) {//kk y
				for (int l = 0; l < K; l++) {//kk x
					//cout<< i+k <<"  "<< j+l <<endl;
					//K*K matrix
					//cout << A[i + k][j + l] << endl;
					KK.push_back(A[i + k][j + l]);
					//cout << "loop 1" << endl;

				}
			}
			//sort KK

			sort(KK.begin(), KK.end(), [](string& a, string& b) {
				if (int(a.size()) != int(b.size())) {
					//cout << a.size() << "  size !=  " << b.size()<<endl;
					return a.size() < b.size();
				}
				else if (a == b) {
					//cout << a << "  ==  " << b;
					return true;
				}
				else {
					int m = 0;
					while (a[m] == b[m]) {
						m++;
					}
					return bool(char(a[m]) < char(b[m]));
				}

				return true;
				});

			//cout << "loop 2" << endl;

			//update med
			string tmp;
			int id = int(K * K / 2) - 1;
			//cout << KK.size() << "KK" << id << endl;
			tmp = KK[id];
			cout << tmp << endl;
			//cout << "loop 3" << endl;

			if (med == "") med == tmp;
			else if (med.size() < tmp.size()) med = min(med, tmp);
			else if (med.size() == tmp.size()) {

			}
		}
	}

	cout << "answer" << med << endl;
}

void ABC203D() {
	auto string_comp = [](string& a, string& b) {
		if (int(a.size()) != int(b.size())) { return a.size() < b.size(); }
		else if (a == b) { return true; }
		else {
			int keta = 0;
			while (a[keta] == b[keta]) keta++;
			return bool(char(a[keta]) < char(b[keta]));
		}
		return true;
	};

	int N, K;
	cin >> N >> K;

	//undefined
	vector<vector<int>> A;
	for (int i = 0; i < N; i++) {
		A.push_back(vector<int>());
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			A[i].push_back(a);
		}
	}

	//cout << "input finish" << endl;

	vector<int> med;
	for (int i = 0; i < N - K + 1; i++) {//y start
		for (int j = 0; j < N - K + 1; j++) {//x start

			vector<int> KK;
			for (int k = 0; k < K; k++) {//kk y
				for (int l = 0; l < K; l++) {//kk x
					//K*K matrix
					KK.push_back(A[i + k][j + l]);
				}
			}

			//sort KK
			sort(KK.begin(), KK.end());

			//update med
			int id = int(K * K / 2) - 1;
			med.push_back(KK[id]);

		}
	}

	cout << "answer" << *min_element(med.begin(), med.end()) << endl;
}