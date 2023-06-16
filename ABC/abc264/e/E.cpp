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
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    int N,M; cin>>N>>M;
    int E; cin>>E;

    V<Pii> Edge(E);
    rep(i,E) cin>>Edge[i].fi>>Edge[i].se;
    rep(i,E) {Edge[i].fi--; Edge[i].se--;}

    int Q; cin>>Q;
    V<int> X(Q); cin>>X;
    rep(q,Q) X[q]--;
    V<bool> NG(E,false);
    rep(q,Q) NG[X[q]] = true;


    //クエリ先読み，終わりから処理．
    //電線が増えるたびに追加

    vector<vector<int>> G(N+M);
    for(int i=0;i<E;i++){
        if(NG[i]) continue;
        int u,v;
        u = Edge[i].fi;
        v = Edge[i].se;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    V<int> Ans;
    int cnt = 0;
    V<int> dist(N+M, INF);
    queue<int> que;
    for(int i=N;i<N+M;i++){
        dist[i] = 0;
        que.push(i);
    }
    EL(dist)
    while(!que.empty()){
        int p = que.front();
        que.pop();
        rep(i,G[p].size()){
            int to = G[p][i];
            if(dist[to]==INF){
                cnt++;
                dist[to]=0;
                que.push(to);
            }
        }
    }
    Ans.push_back(cnt);
    EL(dist)


    REVERSE(X);
    rep(i,X.size()){
        G[Edge[X[i]].fi].push_back(Edge[X[i]].se);
        G[Edge[X[i]].se].push_back(Edge[X[i]].fi);
        if(dist[Edge[X[i]].fi]!=INF || dist[Edge[X[i]].se]!=INF){
            if(dist[Edge[X[i]].fi]==INF) cnt++;
            if(dist[Edge[X[i]].se]==INF) cnt++;
            dist[Edge[X[i]].fi]=0;
            dist[Edge[X[i]].se]=0;
            que.push(Edge[X[i]].fi);
            que.push(Edge[X[i]].se);
        }


        while(!que.empty()){
            int p = que.front();
            que.pop();
            rep(j,G[p].size()){
                int to = G[p][j];
                if(dist[to]==INF){
                    cnt++;
                    dist[to]=0;
                    que.push(to);
                }
            }
        }
        Ans.push_back(cnt);
    }
    EL(dist)

    Ans.pop_back();
    REVERSE(Ans);
    repi(i,0,Ans.size()) PL(Ans[i])


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
