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

	int n; cin>>n;

	int ans=0;
	rep(i,1<<n){
		//候補作成
		string s;
		for(int j=n-1;j>=0;j--){
			if( (i&(1<<j))==0 ) s+="(";
			else s+=")";
		}
		
		//判定
		int cnt=0;
		bool ok = true;
		rep(j,n){
			if(s[j]=='(') cnt++;
			else cnt--;

			if(cnt<0) ok = false;
		}
		if(cnt==0&&ok) {
			PL(s)
			ans++;
		}
	}

	PL(ans)

	return;
}

int main() {
	solve();
	return 0;
}
