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
	vector<vector<int> > G(n);
	rep(i,n-1){
		int u,v;
		cin>>u>>v;
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	vector<int> dist(n,INF);
	dist[0]=0;

	priority_queue<int, vector<int>, greater<int> > que;
	que.push(0);

	while(!que.empty()){
		int p = que.top(); que.pop();
		rep(i,G[p].size()){
			int next = G[p][i];
			if(dist[p]+1<dist[next]){
				dist[next]=dist[p]+1;
				que.push(next);
			}
		}
	}

	int farest = int(max_element(ALL(dist))-dist.begin());
	rep(i,n) dist[i]=INF;
	dist[farest]=0;
	que.push(farest);

	while(!que.empty()){
		int p = que.top(); que.pop();
		rep(i,G[p].size()){
			int next = G[p][i];
			if(dist[p]+1<dist[next]){
				dist[next]=dist[p]+1;
				que.push(next);
			}
		}
	}

	PL(1+*max_element(ALL(dist)))
	

	return;
}

int main() {
	solve();
	return 0;
}
