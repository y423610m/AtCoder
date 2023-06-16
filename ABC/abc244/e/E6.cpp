#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
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
template<class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

#include "graph/graph_template.hpp"
/*
    int N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, true);//weighted?
    Graph<int> G(N, E, true);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);
*/

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}
istream &operator>>(istream &is, mint& x){ll val; is >> val; x = val; return is;}
#endif

void solve() {

    ll N,M,K,S,T,X;
    cin>>N>>M>>K>>S>>T>>X;
    S--,T--,X--;
    V<Pii> E(M); cin>>E;
    for(auto& e:E){e.fi--, e.se--;}
    //dp[i][j][k]:=i回移動してjにいて，Xをk回通った通り数
    V<V<V<ll>>> dp(K+1, V<V<ll>>(N, V<ll>(2)));
    // V<V<V<bool>>> visited(K+1,V(N,V(2,false)));
    dp[0][S][0] = 1;
    rep(i,K){
        // rep(j,N){
        //     for(const auto& e:G[j]){
        //         rep(k,2){
        //             if(j==X){
        //                 dp[i+1][j][k] += dp[i][e.to][1-k];
        //             }
        //             else{
        //                 dp[i+1][j][k] += dp[i][e.to][k];
        //             }
        //         }
        //     }
        // }
        // rep(j,N) EL(dp[i+1][j])
        for(const auto& e:E){
            if(e.se==X){
                rep(k,2){
                    dp[i+1][e.se][k]+=dp[i][e.fi][1-k];
                    if(dp[i+1][e.se][k]>MOD) dp[i+1][e.se][k]%=MOD;
                }
            }
            else{
                rep(k,2){
                    dp[i+1][e.se][k]+=dp[i][e.fi][k];
                    if(dp[i+1][e.se][k]>MOD) dp[i+1][e.se][k]%=MOD;
                }
            }

            if(e.fi==X){
                rep(k,2){
                    dp[i+1][e.fi][k]+=dp[i][e.se][1-k];
                    if(dp[i+1][e.fi][k]>MOD) dp[i+1][e.fi][k]%=MOD;
                }            
            }
            else{
                rep(k,2){
                    dp[i+1][e.fi][k]+=dp[i][e.se][k];
                    if(dp[i+1][e.fi][k]>MOD) dp[i+1][e.fi][k]%=MOD;
                }   
            }
        }
    }
    PL(dp[K][T][0])

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
