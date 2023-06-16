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
	int n,k; cin>>n>>k;
	string s; cin>>s;
	vector<vector<int> > vvi(n+1, vector<int>(26));
	rep(i,26) vvi[n][i]=n;
	rep(i,n){
		int I = n-1-i;
		rep(j,26){
			vvi[I][j]=vvi[I+1][j];
		}
		vvi[I][(s[I]-'a')]=I;
	}

	string ans;
	int pos = 0;
	rep(i,k){
		rep(j,26){
			int next = vvi[pos][j];
			int length = n-1-next+i+1;
			if(length>=k){
				ans += char(j+'a');
				pos = next+1;
				break;
			}
		}
	}

	PL(ans)

	return;
}

int main() {
	solve();
	return 0;
}
