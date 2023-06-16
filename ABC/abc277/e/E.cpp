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
// #define endl "\n"
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

#include "graph/graph_template.hpp"
/*
    int N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, true);//weighted?
    Graph<int> G(N, E, true);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);
*/

void solve() {
    EL(0)

    ll N,M,K; cin>>N>>M>>K;
    Edges<int> E = readE<int>(M, -1, true);//weighted?
    Graph<int> G(N, E, false);//directed?
    EL(1)

    V<int> S(K); cin>>S;
    V<bool> hasSwitch(N);
    rep(i,K) hasSwitch[S[i]-1] = true;
    EL(2)

    V<V<int>> dist(2, V<int>(N,INF));
    //dist, available, pos
    using arr = array<int,3>;
    priority_queue<arr, V<arr>, greater<arr>> que;
    dist[1][0] = 0;
    que.push({0, 1, 0});
    EL(3)

    while(!que.empty()){
        auto [d, avai, p] = que.top(); que.pop();
        ES(d) ES(avai) EL(p)
        if(d<=dist[avai][p]){
            //ここではスイッチ押さない
            for(const auto& e:G[p])if(e.cost==avai){
                if(dist[avai][e.to]>d+1){
                    dist[avai][e.to]=d+1;
                    que.push({dist[avai][e.to], avai, e.to});
                }
            }
        }

        //スイッチある？
        if(!hasSwitch[p]) continue;
        //スイッチ押す
        avai = 1-avai;
        //d++;
        if(dist[avai][p]<=d) continue;
        dist[avai][p] = d;
        for(const auto& e:G[p])if(e.cost==avai){
            if(dist[avai][e.to]>d+1){
                dist[avai][e.to]=d+1;
                que.push({dist[avai][e.to], avai, e.to});
            }
        }
    }

    EL(dist[0])
    EL(dist[1])

    int ans = INF;
    chmin(ans, dist[0][N-1]);
    chmin(ans, dist[1][N-1]);

    if(ans==INF) END(-1)
    else END(ans)

    return;
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
