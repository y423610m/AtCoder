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
template <class T> using V = vector<T>;
template<typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, unsigned long int sz > ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz > istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<class T, class U > void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U > void chmax(T& t, const U& u) {if (t < u) t = u;}

#include "graph/graph_template.hpp"
/*
    int N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, true);//weighted?
    Graph<int> G(N, E, true);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);
*/

struct State{
    ll d,val;
    State(ll d, ll val):d(d),val(val){}
};

bool operator<(const State a, const State b){
    if(a.d!=b.d) return a.d<b.d;
    return a.val>b.val;
}

void solve() {

    ll N; cin>>N;
    V<ll> A(N); cin>>A;
    V<string> S(N); cin>>S;

    Edges<int> E;
    rep(i,N) rep(j,N) if(i!=j){
        if(S[i][j]=='Y') E.push_back({i,j});
    }
    Graph<int> G(N, E, true);//directed?

    ll Q; cin>>Q;
    using P = pair<State, ll>;//{dist, val}, pos
    // priority_queue<P,V<P>,greater<P>> que;
    queue<P> que;
    V<State> dist(N,State(LINF, -LINF));
    rep(q,Q){
        EL(q)
        rep(i,N) dist[i] = {LINF, -LINF};
        ll s,t; cin>>s>>t;
        s--,t--;
        dist[s] = {0,A[s]};
        que.push({State(0,A[s]),s});

        while(!que.empty()){
            ll d = que.front().first.d;
            ll val = que.front().first.val;
            ll p = que.front().second;
            que.pop();
            if(dist[p]<State(d,val)) continue;
            ES(p) ES(d) EL(val)

            for(const auto& e:G[p]){
                //距離更新
                bool ok = false;
                State tmp = State(d+1,val+A[e.to]);
                if(tmp<dist[e.to]){
                    dist[e.to] = tmp;
                    que.push({tmp,e.to});
                }
            }
        }
        if(dist[t].d==LINF) PL("Impossible")
        else{
            PS(dist[t].d) PL(dist[t].val)
        }
    }

    return;
}

void solve2(){
        ll N; cin>>N;
    V<ll> A(N); cin>>A;
    V<string> S(N); cin>>S;

    Edges<int> E;
    rep(i,N) rep(j,N) if(i!=j){
        if(S[i][j]=='Y') E.push_back({i,j});
    }
    // Graph<int> G(N, E, true);//directed?

    V<V<State>> dist(N, V<State>(N, State(LINF,-LINF)));
    rep(i,N){
        rep(j,N)if(S[i][j]=='Y'){
            dist[i][j] = State(1,A[j]);
        }
    }

    State tmp(0,0);
    rep(k,N){
        rep(i,N){
            rep(j,N){
                //chmin(d[i][j], d[i][k]+d[k][j]);
                tmp.d = dist[i][k].d+dist[k][j].d;
                tmp.val = dist[i][k].val+dist[k][j].val;
                if(tmp<dist[i][j]) dist[i][j] = tmp;
            }
        }
    }

    // rep(i,N){
    //     rep(j,N){
    //         PS(dist[i][j].d)
    //     }
    //     PL("")
    // }

    // rep(i,N){
    //     rep(j,N){
    //         PS(dist[i][j].val)
    //     }
    //     PL("")
    // }

    ll Q; cin>>Q;
    rep(q,Q){
        ll u,v; cin>>u>>v; u--,v--;
        if(dist[u][v].d==LINF) PL("Impossible")
        else{
            PS(dist[u][v].d) PL(dist[u][v].val+A[u])
        }
    }
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
