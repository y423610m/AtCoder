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
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

#include "graph/graph_template.hpp"
/*
    int N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, true);//weighted?
    Graph<int> G(N, E, true);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);
*/

#include "graph/shortest_path/dijkstra.hpp"
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
    EL(di.cnt)
*/

void solve() {

    int N,M; cin>>N>>M;
    ll P; cin>>P;

    Edges<ll> E;
    E.reserve(M);
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--, b--;
        E.push_back({a,b,c});
    }
    Graph<ll> G(N, E, true);

    ll ans = -LINF;

    //pos, t, coin
    struct State{
        int p;
        ll t;
        ll coin;
        State(int p, ll t, ll coin):
        p(p), t(t), coin(coin){}
    };
    queue<State> que;
    V<ll> score(N, -LINF);// coin-t*p
    score[0] = 0;
    que.push(State(0,0,0));
    while(!que.empty()){
        int p = que.front().p;
        ll t = que.front().t;
        ll coin = que.front().coin;
        que.pop();
        ES(p) ES(t) EL(coin)

        for(const auto& e:G[p]){
            ll nxtCoin = coin+e.cost-(t+1)*P;
            if(score[e.to]<nxtCoin){
                score[e.to] = nxtCoin;
                que.push(State(e.to, t+1, nxtCoin));
            }
        }
    }

    if(score[N-1]==-LINF) PL(-1)
    else PL(max(0LL, score[N-1]))

    return;
}

void solve2(){
    int N,M; cin>>N>>M;
    ll P; cin>>P;

    Edges<ll> E;
    E.reserve(M);
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--, b--;
        c -= P;
        E.push_back({a,b,-c});
    }

    //N-1に到達しない辺を除去したい
    //辺を逆向きにしてダイクストラ
    auto F = E;
    rep(i,F.size()){
        swap(F[i].from, F[i].to);
        F[i].cost = 1;
    }
    Graph<ll> G(N,F,true);
    Dijkstra<ll> di(N, INF);
    di.solve(G, N-1);
    V<bool> used(N, false);
    rep(i,N) if(di.dist[i]!=INF) used[i] = true;
    EL(used)

    V<V<ll>> score(M+3, V<ll>(N, LINF/100));
    score[0][0] = 0;
    rep(i,M+2){
        score[i+1] = score[i];
        EL(i)
        bool updated = false;
        for(const auto&e:E){
            if(score[i][e.from]!=LINF/100&&used[e.from]&&used[e.to]&&score[i+1][e.to]>score[i][e.from]+e.cost){
                score[i+1][e.to] = score[i][e.from]+e.cost;
                ES(e.from) ES(e.to) EL(score[i+1][e.to])
                updated = true;
            }
        }
        if(!updated){
            break;
        }
        if(i==M+1) END(-1)
    }

    ll ans = 0;
    rep(i,M+3){
        chmax(ans, -score[i][N-1]);
    }
    PL(ans)

}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
