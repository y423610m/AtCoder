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
using P = pair<ll, ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

struct dijkstra{

	using P = pair<ll, ll>;
	int N_;
	int s;
	vector<ll> dist;
	vector<vector<P>> G;
	vector<int> path;
	vector<ll> cnt; 

	dijkstra(int n_){
		N_ = n_;
		G.resize(N_);
	}

	void set_graph(int m, bool cinW = false){
		if(cinW) cerr<<"cin>>w enabled"<<endl;
		else cerr<<"cin>>w not enabled"<<endl;

		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v;
			u--,v--;
			w = 1;
			if(cinW) cin>>w;
			//経路復元はu,v逆!!!
			G[u].push_back({v,w});
			G[v].push_back({u,w});
		}
	}
	
	void set_graph(const vector<vector<P>>& G_){
		G = G_;
	}

	void reset_dist(){
		dist.resize(N_, INF);
	}

	void solve(int s_){
		s = s_;

		dist.resize(N_, LINF);
		cnt.resize(N_);
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
	}


	void find_path(int g){
		if(dist[g]==INF) return;
		int p = g;
		path.clear();
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
	}
	

};

void solve() {

    int n; cin>>n;
    V<ll> A(n);
    rep(i,n) cin>>A[i];
    A.push_back(A.back());
    ll ans = LINF;

    V<V<P>> G(n+2);
    repi(i,0,n){
        G[i].push_back({i+1,A[i]});
        G[i].push_back({i+2,A[i+1]});
    }
    EL("aaa")
	dijkstra di1(n+2);
	di1.set_graph(G);
	di1.solve(0);
    chmin(ans, di1.dist[n]);
    EL(di1.dist)

    G[n].push_back({n+1, A[n]});
	di1.set_graph(G);
	di1.solve(1);
    chmin(ans, di1.dist[n+1]);
    EL(di1.dist)


	PL(ans)




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
