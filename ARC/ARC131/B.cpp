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

	int h,w;
	cin>>h>>w;

	vector<string> vs(h);
	rep(i,h) cin>>vs[i];

	int dx[4]={1,0,-1,0};
	int dy[4]={0,-1,0,1};



	rep(i,h){
		rep(j,w){
			if(vs[i][j]!='.') continue;
			set<int> S;
			rep(i,5) S.insert(i+1);
			
			if(0<i&&vs[i-1][j]!='.') S.erase(int(vs[i-1][j]-'0'));
			if(i+1<h&&vs[i+1][j]!='.') S.erase(int(vs[i+1][j]-'0'));
			if(0<j&&vs[i][j-1]!='.') S.erase(int(vs[i][j-1]-'0'));
			if(j+1<w&&vs[i][j+1]!='.') S.erase(int(vs[i][j+1]-'0'));
			vs[i][j]=char('0'+*(S.begin()));
		}
	}

	rep(i,h) PL(vs[i])


	return;
}

int main() {
	solve();
	return 0;
}
