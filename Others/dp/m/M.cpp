#include <bits/stdc++.h>
using namespace std;

// const int MOD = 998'244'353;
const int MOD = 1000'000'007;

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

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}
#endif

void solve() {

    int N; cin>>N;
    int K; cin>>K;
    V<int> A(N); cin>>A;

    //dp[i][j]:=i人目まで配り終えて，残りの飴がjこの時の配り方
    V<V<mint>> dp(N+1, V<mint>(K+1));
    V<V<mint>> sum(N+1, V<mint>(K+2));
    V<V<bool>> visited(N+1, V<bool>(K+1));

    auto dfs = [&](auto dfs, int p, int k)-> void {
        if(p==N-1){
            if(k<=A[p]) dp[p][k] = 1;
            else dp[p][k] = 0;
            return;
        }

        for(int i=0;i<=k;i++){
            if(i>A[p]) break;
            if(!visited[p+1][k-i]){
                dfs(dfs, p+1, k-i);
                visited[p+1][k-i] = true;
            }
            dp[p][k] += dp[p+1][k-i];
        }
    };

    dfs(dfs, 0, K);
    PL(dp[0][K])

    return;
}

void solve2() {

    int N; cin>>N;
    int K; cin>>K;
    V<int> A(N); cin>>A;

    //dp[i][j]:=i人目まで配り終えて，残りの飴がjこの時の配り方
    V<V<mint>> dp(N+1, V<mint>(K+1));
    V<V<mint>> sum(N+1, V<mint>(K+2));
    V<V<bool>> visited(N+1, V<bool>(K+1));

    auto dfs = [&](auto dfs, int p, int k)-> void {
        if(p==N-1){
            if(k<=A[p]){
                dp[p][k] = 1;
                sum[p][k+1] = dp[p][k]+sum[p][k];
            }
            else dp[p][k] = 0;
            return;
        }

        if(!visited[p+1][k]){
            for(int i=K;i>=0;i--){
                if(i>A[p]) continue;;
                if(!visited[p+1][k-i]){
                    dfs(dfs, p+1, k-i);
                    visited[p+1][k-i] = true;
                }
                //dp[p][k] += dp[p+1][k-i];
            }
        }
        dp[p][k] += sum[p+1][k+1]-sum[p+1][max(0, k-A[p])];
        sum[p][k+1] = dp[p][k]+sum[p][k];
    };

    dfs(dfs, 0, K);
    PL(dp[0][K])

    rep(i,N+1) EL(dp[i])
    rep(i,N+1) EL(sum[i])

    return;
}

void solve3(){
    int N,K; cin>>N>>K;
    V<int> A(N); cin>>A;

    //dp[i][j]:=i番目の人まで配って，残りk個の時の通り数
    V<V<mint>> dp(N+1,V<mint>(K+1));
    V<V<mint>> sum(N+1,V<mint>(K+2));

    //rep(k,K+1) dp[0][k] = 1;
    dp[0][0] = 1;
    rep(k,K+1) sum[0][k+1] = sum[0][k] + dp[0][k];

    rep(i,N){
        rep(k,K+1){
            dp[i+1][k] = sum[i][k+1]-sum[i][max(0, k-A[i])];
        }

        rep(k,K+1){
            sum[i+1][k+1] = sum[i+1][k] + dp[i+1][k];
        }
    }

    PL(dp[N][K])
    
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
