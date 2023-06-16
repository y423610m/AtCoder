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

	ll n,a,b;
	cin>>n>>a>>b;

	ll p,q,r,s;
	cin>>p>>q>>r>>s;

	string t;
	rep(i,s-r+1) t += ".";
	vector<string> vs(q-p+1, t);

	ll l1 = max(1-a, 1-b);
	ll r1 = min(n-a, n-b);

	ll l2 = max(1-a, b-n);
	ll r2 = min(n-a, b-1);

	PS(l1)PL(r1)
	PS(l2)PL(r2)

	//a--; b--;
	//p--; q--; r--; s--;


	repill(i,0, q-p+1){
		repill(j, 0,s-r+1){
			if(i+p-a==j+q-b){
				ll k = i+p-1-a;
				//if(l1<=k&&k<=r1) vs[i][j]='#';
				cout<<"#";
			} 
			else if(i+p-a==b-j-q){
				ll k = i+p-1-a;
				//if(l2<=k&&k<=r2) 	vs[i][j]='#';
				cout<<"#";
			}
			else{
				cout<<".";
			}
		}
		cout<<endl;
	}
	

	repill(i,p,q+1){
		repill(j,r,s+1){
			if(i-a==j-b) cout<<"#";
			else if(i-a==b-j) cout<<"#";
			else cout<<".";
		}
		PL("")
	}


	rep(i, q-p+1){
		PL(vs[i])
	}

	return;
}

int main() {
	solve();
	return 0;
}
