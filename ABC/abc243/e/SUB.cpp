#line 1 "E.cpp"
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;
// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define endl "\n"
//#define ONLINE_JUDGE 1
#ifdef ONLINE_JUDGE
    #define ES(a) while(0){}
    #define EL(a) while(0){}
#else
    #define NAME(a) #a
    #define ES(a) cerr<<NAME(a)<<": "<<(a)<<" ";
    #define EL(a) cerr<<NAME(a)<<": "<<(a)<<endl;
#endif
#define END(a) {PL(a) return;}
#define RES(a) cerr<<"\r"<<NAME(a)<<": "<<(a)<<"   ";
#define fi first
#define se second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

#line 2 "/mnt/c/Users/y4236/CPP/kyopro_library/graph/mst/kruskal.hpp"

#line 2 "/mnt/c/Users/y4236/CPP/kyopro_library/graph/graph_template.hpp"

/*
struct Edge;
edges = vectpr<Edge>;
readE()
Graph G;

TO DO: find_path, find_edges
*/


//////////////////Graph Template
template<typename T=int>//cost type
struct Edge{
    int from, to;
    T cost;
    int id, used;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int id = -1, int used = false)
    : from(from)
    , to(to)
    , cost(cost)
    , id(id)
    , used(used){}

    operator int() const { return to; }
};

// bool operator<(Edge a, Edge b){
//     return a.cost<b.cost;
// }

template <typename T = int>
using Edges = vector< Edge< T > >;

template<typename T>
vector< Edge< T > > readE(int M, int padding = -1, bool weighted = false){
    vector< Edge< T > > E;
    E.reserve(M);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        u += padding;
        v += padding;

        T w = 1;
        if(weighted) cin>>w;

        E.emplace_back(u,v,w,i,0);
    }
    return E;
}




template <typename T = int>//cost type
struct Graph{
    vector< vector< Edge< T > > > g;
    int id;

    Graph() = default;

    explicit Graph(int n):g(n), id(0){}

    Graph(int n, const Edges<T>& E, bool directed = false):g(n), id(0){
        for(const auto& e: E){
            g[e.from].emplace_back(e);
            if(!directed) g[e.to].emplace_back(e.to, e.from, e.cost, e.id, e.used);
        }
    }

    size_t size()const{return g.size();}

    void add_directed_edge(int from, int to, T cost = 1){
        g[from].emplace_back(from, to, cost, id++, 0);
    }

    void add_edge(int from, int to, T cost = 1){
        g[from].emplace_back(from, to, cost, id, 0);
        g[to].emplace_back(to, from, cost, id++, 0);
    }

    void read(int M, int padding = -1, bool weighted = false, bool directed = false){
        for(int i=0;i<M;i++){
            int u,v; cin>>u>>v;
            u += padding; v += padding;

            T w = 1;
            if(weighted) cin>>w;

            if(directed) add_directed_edge(u,v,w);
            else add_edge(u,v,w);
        }
    }

    inline vector< Edge< T > > &operator[](const int& k){return g[k];}
    inline const vector< Edge< T > > &operator[](const int& k)const{return g[k];}

};

/*
    int N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, true);//weighted?
    Graph<int> G(N, E, true);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);
*/

#line 4 "/mnt/c/Users/y4236/CPP/kyopro_library/graph/mst/kruskal.hpp"

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
using namespace atcoder;
#endif

template<typename T>
struct Kruskal{
	int N;
	T total;
	vector<int> used;//edge id

	Kruskal(int N)
	:N(N)
	,total(0)
	{used.reserve(N);}

	void solve(Edges<T>& E){
		sort(E.begin(), E.end(), [](const Edge<T>& a, const Edge<T>& b){
			return a.cost<b.cost;
		});

		dsu tree(N);
		for(auto& e:E){
			if(!tree.same(e.from, e.to)){
				tree.merge(e.from, e.to);
				used.push_back(e.id);
				total += e.cost;
				e.used = 1;
			}
		}
	}
};
#line 49 "E.cpp"


void solve() {

    int N; cin>>N;
    int M; cin>>M;

    Edges<ll> E = readE<ll>(M, -1, true);
    Graph<ll> G(N, E, false);

    Kruskal<ll> kr(N);
    kr.solve(E);

    int ans = 0;
    rep(i,M) if(!E[i].used) ans++;
    PL(ans)

    EL(kr.total)

    return;
}

#line 2 "/mnt/c/Users/y4236/CPP/kyopro_library/graph/mst/prim.hpp"


#line 5 "/mnt/c/Users/y4236/CPP/kyopro_library/graph/mst/prim.hpp"

/*
ダイクストラ風に小さな辺から選ぶ
*/

template<typename T = int>
struct Prim{
	
	int N;
	T total;
	vector<T> dist;
	vector<bool> used;
	vector<int> froms;
	vector<int> ids;

	Prim(int N, T initDist)
	:N(N)
	,total(0)
	,dist(N, initDist)
	,used(N,false)
	,froms(N,-1)
	,ids(N,-1)//edge_ids
	{}

	void solve(const Graph<T>& G, int s = 0){
		using P = pair<T,int>;//dist, pos
		priority_queue<P,vector<P>,greater<P>> que;
		que.push({0,s});//頂点0からスタート
		dist[s] = 0;
		while(!que.empty()){
			P p = que.top();
			que.pop();
			if(used[p.second]) continue;
			used[p.second] = true;
			total += p.first;
			for(const auto& e:G[p.second]){
				if(dist[e.to]<=e.cost) continue;
				if(used[e.to]) continue;
				dist[e.to] = e.cost;
				que.push({e.cost, e.to});
				froms[e.to] = e.from;
				ids[e.to] = e.id;
			}
		}
	}
};

/* 無向グラフのみ！！！
    int N; cin>>N;
    int M; cin>>M;
    int s = 0;

    Edges<ll> E = readE<ll>(M, 0, true);
    Graph<ll> G(N, E, false);

    Prim<ll> prim(N, INF);
    prim.solve(G, s);

    PL(prim.total)

	retuen;
*/
#line 72 "E.cpp"
/*
    int N; cin>>N;
    int M; cin>>M;
    int s = 0;

    Edges<ll> E = readE<ll>(M, 0, true);
    Graph<ll> G(N, E, false);

    Prim<ll> prim(N, INF);
    prim.solve(G, s);
    PL(prim.total)
*/

void solve2(){
    int N; cin>>N;
    int M; cin>>M;
    int s = 0;

    Edges<ll> E = readE<ll>(M, -1, true);
    Graph<ll> G(N, E, false);

    Prim<ll> prim(N, INF);
    prim.solve(G, s);
    PL(prim.total)
}

void solve3(){
    int N; cin>>N;
    int M; cin>>M;

    Edges<ll> E = readE<ll>(M, -1, true);
    Graph<ll> G(N, E, false);

    sort(ALL(E));

    V<V<ll>> dist(N,V<ll>(N, LINF));
    for(const auto& e:E){
        dist[e.from][e.to] = e.cost;
        dist[e.to][e.from] = e.cost;
    }

    rep(k,N) rep(i,N) rep(j,N) chmin(dist[i][j], dist[i][k]+dist[k][j]);

    int ans = 0;
    for(const auto& e:E){
        bool used = true;
        rep(i,N) if(dist[e.from][i]+dist[i][e.to]<=e.cost) used = false;
        if(!used) ans++;
    }
    PL(ans)

}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve3();
   return 0;
}
