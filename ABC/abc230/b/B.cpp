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

	string s;
	cin>>s;

	if(s=="x"||s=="xx"){
		PL("Yes")
		return;
	}

	int firstO = 0;
	while(s[firstO]!='o'&&firstO+1<s.size()) firstO++;
	if(firstO>2){
		PL("No")
		return;
	}

	int cntX=2;

	for(int i=firstO; i<s.size();i++){
		if(s[i]=='o'){
			if(cntX!=2){
				PL("No")
				return;
			}
			cntX=0;
		}
		else{
			cntX++;
		}
	}

	if(cntX>2){
		PL("No")
		return;
	}

	PL("Yes")

	return;
}

int main() {
	solve();
	return 0;
}
