#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
//__uint128_t
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

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

/*
    ll N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, true);//weighted?
    Graph<int> G(N, E, true);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);
*/



template <typename T>
struct TreeDiameter{
    int N;
    vector<T> dist0;//0からの距離
    vector<T> distl;//lからの距離
    vector<T> distr;//rからの距離
    int l, r;//両端．先にl,　そのあとr求める
    T Diameter;

    TreeDiameter(int N, const Graph<T>& G, T initDist = INF, bool calcDistR = false):
    N(N)
    {
        vector<T> dist(N, initDist);
        dist[0] = 0;
        int FarestNode = 0;
        T MaxDist = 0;
        auto dfs = [&](auto dfs, int p)->void {
            for(const auto& e:G[p]){
                if(dist[e.to]>dist[p]+e.cost){
                    dist[e.to] = dist[p]+e.cost;
                    if(MaxDist<dist[e.to]){
                        MaxDist = dist[e.to];
                        FarestNode = e.to;
                    }
                    dfs(dfs, e.to);
                }
            }
        };
        dfs(dfs, 0);
        swap(dist, dist0);
        l = FarestNode;

        dist = vector<T>(N, initDist);
        dist[l] = 0;
        FarestNode = l;
        MaxDist = 0;
        dfs(dfs, l);
        swap(dist, distl);
        r = FarestNode;
        Diameter = MaxDist;

        if(calcDistR){
            dist = V<T>(N, initDist);
            dist[r] = 0;
            dfs(dfs, r);
            swap(dist, distr);
        }
    }

/*
    int N; cin>>N;
    Edges<int> E = readE<int>(N-1, -1, false);
    Graph<int> G(N, E, false, false);

    TreeDiameter tree(N, G, INF, false);//needDistFromR?
    ES(tree.l) EL(tree.r)
    EL(tree.Diameter)
*/

};
/*
    ll N; cin>>N;
    Edges<int> E = readE<int>(N-1, -1, false);
    Graph<int> G(N, E, false);
    TreeDiameter tree(N, G, INF, false);//needDistFromR?
    ES(tree.l) EL(tree.r)
    EL(tree.Diameter)
*/


template<typename T>
struct RootedTree{
    int N;
    vector<int> depth;
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> numOfDescendants;
    vector<T> dist;
    V<int> farestDescendant;

    RootedTree(int N, const Graph<T>& G, int root)
    :N(N)
    ,depth(N,-1)
    ,parent(N,-1)
    ,children(N)
    ,numOfDescendants(N, 0)
    ,dist(N, -1)
    ,farestDescendant(N)
    {
        parent[root] = root;
        dist[root] = 0;
        auto dfs = [&](auto dfs, int v, int d)->void {
            depth[v] = d;
            farestDescendant[v] = v;
            for(const auto& e:G[v]) if(depth[e.to]==-1){
                parent[e.to] = v;
                dist[e.to] = dist[v] + e.cost;
                children[v].emplace_back(e.to);
                dfs(dfs, e.to, d+1);
                numOfDescendants[v] += numOfDescendants[e.to]+1;
                if(depth[farestDescendant[v]]<depth[farestDescendant[e.to]]) farestDescendant[v] = farestDescendant[e.to];
            }
            return;
        };
        dfs(dfs, root, 0);
    }
};

/*
    int N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, false);//weighted?
    Graph<int> G(N, E, false);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);

    RootedTree rt(N, G, 0);//2nd arg:root

    EL(rt.depth)
    EL(rt.parent)
    EL(rt.numOfDescendants)
    rep(i,N) EL(rt.children[i])
    EL(rt.farestDescendant)
    //Edgeは親->子が含まれていれば,有向でも無向でもOK
    rootの親はroot自身
*/
/*
    ll N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, false);//weighted?
    Graph<int> G(N, E, false);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);

    RootedTree rt(N, G, 0);

    EL(rt.depth)
    EL(rt.parent)
    EL(rt.numOfDescendants)
    rep(i,N) EL(rt.children[i])
    EL(rt.farestDescendant)
    parent[root]=root
    //Edgeは親->子が含まれていれば,有向でも無向でもOK
*/

void solve() {

    ll N; cin>>N;
    Edges<int> E = readE<int>(N-1, -1, false);//weighted?
    Graph<int> G(N, E, false);//directed?

    set<int> Pid;
    rep(i,N) Pid.insert(i);

    TreeDiameter<int> dia(N, G, INF, false);//needDistFromR?
    EL(dia.dist0)
    EL(dia.distl)

    RootedTree rt(N, G, dia.l);
    EL(dia.l)
    EL(dia.r)

    V<ll> P(N, -1);
    V<bool> used(N, false);

    queue<int> que;
    que.push(dia.l);
    while(!que.empty()){
        ll p = que.front(); que.pop();
        if(used[p]) continue;
        used[p] = true;
        ll q = rt.farestDescendant[p];
        used[q] = true;
        V<ll> A;
        while(q!=p){
            used[q] = true;
            ES(p) EL(q)
            A.push_back(q);
            q = rt.parent[q];
            for(const auto& e:G[q])if(!used[e.to]&&rt.parent[q]!=e.to){
                // used[e.to] = true;
                que.push(e.to);
                ES(p) ES(q) EL(e.to)
            }
        }
        A.push_back(q);
        ll l = 0, r = A.size()-1;
        while(l<=r){
            P[A[r]] = A[l];
            P[A[l]] = A[r];
            Pid.erase(l);
            Pid.erase(r);
            l++, r--;
        }
        EL(A)
        EL(P)
    }


    // V<bool> done(N);
    // auto dfs = [&](auto dfs, ll p)->void {
    //     for(const auto& e:G[p]) if(!done[e.to]){
    //         done[e.to] = true;
    //         dfs(dfs, e.to);
    //     }
    // };

    P++;
    EL(P)
    PL(P)


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

/*
木の直径について，順番が逆になるようなPをひとまず考えてみた．特に意味はない．
残った部分木についても繰り返せばできる？
*/
