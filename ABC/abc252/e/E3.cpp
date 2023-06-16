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

struct Edge{
	int from, to, cost, id, used;
};

struct bellman_ford{
	int N;
	int s;
	bool _has_minus_loop = false;
	vector<ll> dist;
	vector<Edge> edges;
	vector<int> idx;
	vector<int> froms;

	bellman_ford(int n_, vector<Edge>& edges_){
		N = n_;
		edges = edges_;
	}

	void set_graph(vector<Edge>& edges_){
		edges = edges_;
	}

	bool solve(int s_){
		s = s_;
		dist = vector<ll>(N,LINF);
		idx = vector<int>(N,-1);
		froms = vector<int>(N,-1);
		dist[s] = 0;

		int cnt_loop = 0;
		while(true){
			bool updated = false;
			for(int i=0;i<(int)edges.size();i++){
				int from = edges[i].from;
				int to = edges[i].to;
				int cost = edges[i].cost;
				int id = edges[i].id;
				if(dist[from]+cost<dist[to]){
					dist[to] = dist[from]+cost;
					froms[to] = from;
					idx[to] = id;
					updated = true;
				}
			}
			if(!updated) break;
			cnt_loop++;
			if(cnt_loop>(int)edges.size()){
				cout<<"minus closed"<<endl;
				_has_minus_loop = true;
				break;
			}
		}
		//return dist;
		return true;
	}
	
	vector<int> find_path(int g){
		vector<int> path;
		if(dist[g]==LINF) return path;
		int p = g;
		while(p!=s){
			path.push_back(p);
			p = froms[p];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		return path;
	}

	vector<int> find_path_idx(int g){
		vector<int> path_idx;
		if(dist[g]==LINF) return path_idx;
		int p = g;
		while(p!=s){
			path_idx.push_back(idx[p]);
			p = froms[p];
		}
		reverse(path_idx.begin(), path_idx.end());
		return path_idx;
	}
};


void solve() {

	int n,m;
	cin>>n>>m;
	int s = 0;
	int g = n-1;

	vector<Edge> edges;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v;
		u--; v--;
		w=1;
		cin>>w;
		edges.push_back({u,v,w,i,0});
		edges.push_back({v,u,w,i,0});
	}
	
	bellman_ford bf(n, edges);
	auto dist = bf.solve(s);

    auto idx = bf.idx;
    repi(i,1,idx.size()) PS(idx[i]+1) PL("")

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
