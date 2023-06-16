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



void solve() {

    int N; cin>>N;
    ll K; cin>>K;
    V<int> P(N); cin>>P;
    V<ll> C(N); cin>>C;

    rep(i,N) P[i]--;

    ll ans = -LINF;
    rep(i,N) chmax(ans, C[i]);
    if(ans<0) END(ans)

    int D = 32;
    V<V<int>> Pos(D, V<int>(N));
    V<V<ll>> Score(D, V<ll>(N));
    rep(i,N) Pos[0][i] = P[i];
    rep(i,N) Score[0][i] = C[P[i]];

    rep(d,D-1){
        rep(i,N){
            Pos[d+1][i] = Pos[d][Pos[d][i]];
            int p = Pos[d][i];
            Score[d+1][i] = Score[d][p] + Score[d][i];
        }
    }

    V<ll> bi(1,1);
    rep(i,D+3) bi.emplace_back(bi.back()*2);
    EL(bi)

    V<V<unordered_map<ll,ll>>> dp(N,V<unordered_map<ll,ll>>(D+1));
    auto dfs = [&](auto dfs, int p, ll score, ll k, int i)->ll {
        ES(p) ES(score) ES(k) EL(i)

        ll ret = -LINF; 
        ll dk = bi[i];
        if(k+dk<=K){
            if(dp[p][i].find(K-k)==dp[p][i].end()) dp[p][i][K-k] = dfs(dfs, p, score, k, i+1);
            chmax(ret, dp[p][i][K-k]);

            if(dp[p][i].find(K-k-dk)==dp[p][i].end()){
                int to = Pos[i][p];
                ll dScore = Score[i][p];
                //chmax(ans, score+dScore);
                dp[p][i][K-k-dk] = dfs(dfs, to, score+dScore, k+dk, i+1);
            }
            chmax(ret, Score[i][p]+dp[p][i][K-k-dk]);
        }

        if(ret==-LINF) return  0;
        return ret;
    };
    rep(s,N){
        EL(s)
        ll cand =  dfs(dfs, s, 0LL, 0LL, 0);
        chmax(ans, cand);
        EL(cand)
    }


    PL(ans)

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
