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

const int MAX_N = 200000;

int par[MAX_N], Rank[MAX_N];
void init(int n){
	rep(i,n){
		par[i]=i;
		Rank[i]=0;
	}
}

int find(int x){
	if(par[x]==x){ return x;}
	else{ return par[x]=find(par[x]);}
}

void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x==y) return;
	
	if(Rank[x]<Rank[y]) par[x]=y;
	else{
		par[y]=x;
		if(Rank[x]==Rank[y]) Rank[x]++;
	}
}

bool same(int x, int y){
	return find(x)==find(y);
}

void solve() {

	int n,m;
	cin>>n>>m;

	vector<vector<int> > G(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[min(a,b)].push_back(max(a,b));
	}

	vector<int> ret;
	ret.push_back(0);

	init(n);
	int ans = 0;
	rep(i,n){
		ans++;
		int I = n-1-i;
		rep(j,G[I].size()){
			if(!same(I,G[I][j])){
				ans--;
			}
			unite(I,G[I][j]);
			
		}
		ret.push_back(ans);
//		PL(ans)
	}

	reverse(ALL(ret));
	repi(i,1,ret.size()){
		PL(ret[i])
	}


	return;
}

int main() {
	solve();
	return 0;
}
