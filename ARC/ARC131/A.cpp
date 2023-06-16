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

	int a,b; cin>>a>>b;
	string s1 = to_string(a);
	string s2 = to_string(b/2);

	string ans;
	if(b==1){
		ans += "5";
		ans += s1;
	}
	else if(b%2==0){
		ans += s2;
		ans += "0";
	}
	else{
		ans += s2;
		ans += "5";
	}

	ans += s1;

	PL(ans)



	return;
}

int main() {
	solve();
	return 0;
}
