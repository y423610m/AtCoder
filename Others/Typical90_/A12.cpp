#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

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

	int h,w; cin>>h>>w;
	vector<vector<int> > HW(h, vector<int>(w,0));
	int Q; cin>>Q;

	dsu DSU(h*w);
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,-1,0,1};
	
	rep(i,Q){
		//PS("nnn")PL(i)
		int t; cin>>t;
		if(t==1){
			int r,c;
			cin>>r>>c;
			r--; c--;
			HW[r][c]=1;
			rep(j,4) if(0<=r+dx[j]&&r+dx[j]<h&&0<=c+dy[j]&&c+dy[j]<w&&HW[r+dx[j]][c+dy[j]]==1) DSU.merge(r*w+c, (r+dx[j])*w+(c+dy[j]));
		}
		else{
			int ra,ca, rb,cb;
			cin>>ra>>ca>>rb>>cb;
			ra--; ca--; rb--; cb--;
			if(HW[ra][ca]==1&&HW[rb][cb]==1&&DSU.same(ra*w+ca,rb*w+cb)){
				PL("Yes")
			}
			else{
				PL("No")
			}
		}
	}

	return;
}

int main() {
	solve();
	return 0;
}
