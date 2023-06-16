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

	int n,m; cin>>n>>m;
	vector<vector<pair<int,ll> > > G(n);//to, cost
	rep(i,m){
		ll a,b,c;
		cin>>a>>b>>c;
		a--; b--;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}

	//PL("a")

	vector<ll> dist1(n, LINF);
	dist1[0]=0;
	priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > que; //dist, place
	que.push({0,0});
	while(!que.empty()){
		int d = que.top().first; 
		int now = que.top().second;
		que.pop();
		//if(dist1[now]<=d) continue;
		//dist1[now]=d;
		rep(i,G[now].size()){
			if(dist1[now]+G[now][i].second<dist1[G[now][i].first]){
				dist1[G[now][i].first]=dist1[now]+G[now][i].second;
				que.push({dist1[now]+G[now][i].second,G[now][i].first});
			}
		}
	}

	//PL("aa")

	vector<ll> dist2(n, LINF);
	dist2[n-1]=0;
	que.push({0, n-1});
	while(!que.empty()){
		int d = que.top().first;
		int now = que.top().second;
		que.pop();
		//if(dist2[now]<=d) continue;
		//dist2[now]=d;
		rep(i,G[now].size()){
			if(dist2[now]+G[now][i].second<dist2[G[now][i].first]){
				dist2[G[now][i].first]=dist2[now]+G[now][i].second;
				que.push({dist2[now]+G[now][i].second,G[now][i].first});
			}
		}
	}

	//PL("bbb")

	rep(i,n){
		PL(dist1[i]+dist2[i])
	}



	return;
}

int main() {
	solve();
	return 0;
}
