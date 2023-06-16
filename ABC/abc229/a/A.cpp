#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).begin(),(a).end()
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;

const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

ll Power(ll a, ll b){
	ll ret = 1;
	repll(i,b) ret *= a;
	return ret;
}

void solve() {

	vector<string> S(2);
	rep(i,2) cin>>S[i];

	bool ok = true;

	int cnt = 0;
	rep(i,2){
		rep(j,2){
			if(S[i][j]=='#'){
	 			cnt++;
				if(S[1-i][j]=='#'||S[i][1-j]=='#') {

				}
				else{
					ok = false;
				}

			}
		}
	}

	if(cnt>=3) {
		PL("Yes")
		return;
	}
	else if(cnt==2&&ok){
		PL("Yes")
		return;
	}
	else{
		PL("No")
	}

	return;
}

int main() {
	solve();
	return 0;
}
