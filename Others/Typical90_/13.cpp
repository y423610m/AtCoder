#include <bits/stdc++.h>
using namespace std;

const int MOD = 998'244'353;
//const int MOD = 1000'000'007;

const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
#define FI first
#define SE second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using P = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}


struct dijkstra{

	int N;
	int s;
	vector<ll> dist;
	vector<vector<P>> G;
	vector<int> path;
	vector<ll> cnt; 

	dijkstra(int n_, vector<vector<P>>& G_){
		N = n_;
		G = G_;
	}
	
	void set_graph(const vector<vector<P>>& G_){
		G = G_;
	}

	vector<ll> solve(int s_, int g=-1){
		s = s_;

		dist = vector<ll>(N, LINF);
		cnt.resize(N);
		for(auto& c:cnt) c=0;

		dist[s] = 0;
		cnt[s] = 1;
		priority_queue<P,vector<P>,greater<P>> que;//dist, to
		que.push({0,s});

		while(!que.empty()){
			ll d = que.top().first;
			ll now = que.top().second;
			que.pop();
			if(d>dist[now]) continue;
			if(g>=0 && d>dist[g]) continue;
			for(int i=0;i<G[now].size();i++){
				int to = G[now][i].first;
				int w = G[now][i].second;
				if(dist[now]+w<dist[to]){
					dist[to] = dist[now] + w;
					que.push({dist[to], to});
					cnt[to] = cnt[now];
				}
				else if(dist[now]+w==dist[to]){
					cnt[to] += cnt[now];
					cnt[to] %= MOD;
				}
			}
		}

		return dist;
	}


	vector<int> find_path(int g){
		if(dist[g]==LINF) path;
		int p = g;
		if(path.size()>0) path.clear();
		path.push_back(p);
		while(p!=s){
			for(auto [to,w]:G[p]){
				if(dist[to]+w==dist[p]){
					path.push_back(to);
					p = to;
					break;
				}
			}
		}
		reverse(path.begin(), path.end());
		return path;
	}
};


void solve() {


	int n,m;
	cin>>n;
	cin>>m;
	int s = 0;
	int g = n-1;

	vector<vector<P>> G(n);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v;
		u--,v--;
		w = 1;
		cin>>w;
		//経路復元はu,v逆!!!
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}

	dijkstra di(n, G);
	auto dist1 = di.solve(0);
	//for(auto d:dist) cout<< d <<" "; cout<<endl;
	auto dist2 = di.solve(n-1);

    //PL(dist1)
    //PL(dist2)

    rep(i,n) PL(dist1[i]+dist2[i])


    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
