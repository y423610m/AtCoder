#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define rrep(i, a, n) for (int i = (int)(a); i > (int)(n); i--)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define rrepll(i, a, n) for (ll i = (ll)(a); i > (ll)(n); i--)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define ALL(a)  (a).begin(),(a).end()

const int MAX_N = 100;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

const int MAX_V = 100;

void solve() {

	int n; cin>>n;
	int x,y; cin>>x>>y;
	vector<pair<int,int> > vp(n);
	rep(i,n)cin>>vp[i].first>>vp[i].second;
	
	//可能?
	ll sx=0, sy = 0;
	rep(i,n){
		sx+=vp[i].first;
		sy+=vp[i].second;
	}
	if( sx<x || sy<y){
		cout<<-1<<endl;
		return;
	}

	//x = sx - x;
	//y = sy - y;
	int dpx[301][301];
	int dpy[301][301];
	int num[301][301];
	rep(i,n){
		rep(j,x+1){
			dpx[i+1][j] = dpx[i][j];
			dpy[i+1][j] = dpy[i][j];
			if(j-vp[i].first>=0){
				if(dpx[i][j]>dpx[i][j-1]+vp[i].first){
					dpx[i+1][j] = dpx[i][j];
					dpy[i+1][j] = dpy[i][j];
					num[i+1][j] = num[i][j];
				}
				else{
					dpx[i+1][j] = dpx[i][j-vp[i].first]+1;
					dpy[i+1][j] = dpy[i][j-vp[i].first]+vp[i].second;
					num[i+1][j] = num[i][j-vp[i].first]+1;
				}
			}
		}
	}

	int ret=INF;
	rep(i,n){
		rep(j,x+1){
			if(dpy[i+1][j]<=y) ret = min(ret, dpx[i+1][j]);
		}
	}

	cout<< ret <<endl;

	return;
}

int main() {
	solve();
	return 0;
}
