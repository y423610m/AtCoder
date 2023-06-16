#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
//__uint128_t
// const ll MOD = 998'244'353;
const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;

//#define _GLIBCXX_DEQUE_BUF_SIZE 512

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
template<typename T> using V = vector<T>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqr = priority_queue<T, vector<T>, greater<T>>;
template<typename T> ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T> istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T> void operator--(vector<T>& A){for(auto& a:A) a--;}//pre
template<typename T> void operator--(vector<T>& A, int){for(auto& a:A) a--;}//post
template<typename T> void operator++(vector<T>& A){for(auto& a:A) a++;}//pre
template<typename T> void operator++(vector<T>& A, int){for(auto& a:A) a++;}//post
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, typename U> void operator--(pair<T, U>& p){p.first--, p.second--;}//pre
template<typename T, typename U> void operator--(pair<T, U>& p, int){p.first--, p.second--;}//post
template<typename T, typename U> void operator++(pair<T, U>& p){p.first--, p.second--;}//pre
template<typename T, typename U> void operator++(pair<T, U>& p, int){p.first--, p.second--;}//post
template<typename T, unsigned long int sz> ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz> istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A){for(auto& a:A){a--;}}//pre
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A, int){for(auto& a:A){a--;}}//post
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A){for(auto& a:A){a++;}}//pre
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A, int){for(auto& a:A){a++;}}//post
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp



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


template<typename T = int, typename U = int>//cost type
struct Dijkstra{

	int N;
	vector< T > dist;
	vector< U > cnt;
	vector< int > ids;
	vector< int > froms;
	using P = pair< T, int >;//dist, id

	Dijkstra(int N, T initDist)
	: N(N)
	, dist(N, initDist)
	, cnt(N,0)
	, ids(N,-1)
	, froms(N,-1)
	{}

	Dijkstra() = default;

	void solve(const Graph< T >& G, int s, int g=-1, bool count = false){
		dist[s] = 0;
		cnt[s] = 1;
		priority_queue< P, vector< P >, greater< P > > que;//dist, to
		que.push({0,s});

		while(!que.empty()){
			T d = que.top().first;
			int p = que.top().second;
			que.pop();
			if(d>dist[p]) continue;
			if(g>=0 && d>dist[g]) continue;

			for(const auto& e:G[p]){
				if(dist[e.to]>dist[p]+e.cost){
					dist[e.to] = dist[p] + e.cost;
					que.push({dist[e.to], e.to});
					ids[e.to] = e.id;
					froms[e.to] = e.from;
					if(count) cnt[e.to] = cnt[p];
				}
				else if(count && dist[e.to] == dist[p]+e.cost){
					cnt[e.to] += cnt[p];
					// cnt[to] %= MOD;
				}	
			}
		}
	}

	//頂点id
	vector<int> find_path(int g){
		vector<int> path;
		if(froms[g]==-1) return path;
		int p = g;
		while(froms[p]!=-1){
			path.push_back(p);
			p = froms[p];
		}
		path.push_back(p);
		reverse(path.begin(), path.end());
		return path;
	}
	//Edge id
	vector<int> find_edges(int g){
		vector<int> edge_ids;
		if(ids[g]==-1) return edge_ids;
		int p = g;
		while(ids[p]!=-1){
			edge_ids.push_back(ids[p]);
			p = froms[p];
		}
		reverse(edge_ids.begin(), edge_ids.end());
		return edge_ids;
	}
};

/*
    int N; cin>>N;
    int M; cin>>M;

    Edges<int> E = readE<int>(M, -1, false);//辺数，index, weight
    Graph<int> G(N, E, false);//頂点数，Edges, 有向

    Dijkstra<int> di(N, INF);//頂点数，初期距離
    di.solve(G, 0, 0, false);//G, start, goal, 通り数える

    EL(di.dist)
    EL(di.find_path(N-1))
    EL(di.find_edges(N-1))
*/


/*
    ll N; cin>>N;
    ll M; cin>>M;

    Edges<int> E = readE<int>(M, -1, false);//辺数，index, weight
    Graph<int> G(N, E, false);//頂点数，Edges, 有向

    Dijkstra<int> di(N, INF);//頂点数，初期距離
    di.solve(G, 0, 0, false);//G, start, goal, 通り数える

    EL(di.dist)
    EL(di.find_path(N-1))
    EL(di.find_edges(N-1))
    EL(di.cnt)
*/

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
// using mint = atcoder::modint;
// mint::set_mod(MOD);
//制約: a/b -> gcd(b,mod)==1
template<int m> ostream &operator<<(ostream &os, const atcoder::static_modint<m> x) {os<<x.val();return os;}
template<int m> istream &operator>>(istream &is, atcoder::static_modint<m>& x){ll val; is >> val; x = val; return is;}
ostream &operator<<(ostream &os, const atcoder::modint x) {os<<x.val();return os;}
istream &operator>>(istream &is, atcoder::modint& x){ll val; is >> val; x = val; return is;}
#endif

void solve() {

    ll N; cin>>N;
    ll M; cin>>M;

    Edges<int> E = readE<int>(M, -1, false);//辺数，index, weight
    Graph<int> G(N, E, false);//頂点数，Edges, 有向

    Dijkstra<int, mint> di(N, INF);//頂点数，初期距離
    di.solve(G, 0, -1, true);//G, start, goal, 通り数える

    PL(di.cnt[N-1])

    return;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);//小数点以下
    // std::cout << std::setprecision(3);//全体有効数字
    // std::cout << std::defaultfloat;//設定戻す(6桁)
    // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
    // stoll(s,nullptr,base);
    int TT = 1;
    //cin>>TT;
    for(int tt = 0; tt<TT; tt++) solve();
    return 0;
}
