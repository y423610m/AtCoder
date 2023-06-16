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
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    int A,B,C; cin>>A>>B>>C;

    const int N = 200;
    V<V<V<double>>> dp(N+1, V<V<double>>(N+1, V<double>(N+1, -1.0)));
    //array<array<array<double,N+1>,N+1>,N+1> dp;
    //rep(i,N+1) rep(j,N+1) dp[i][j].fill(-1.0);

    auto dfs = [&](auto dfs, int a, int b, int c)->void{
        if(a>=N||b>=N||c>=N){
            dp[a][b][c] = 0;
            return;
        }

        dp[a][b][c] = 0.0;
        if(dp[a+1][b][c]<0) dfs(dfs, a+1, b, c); 
        if(dp[a][b+1][c]<0) dfs(dfs, a, b+1, c); 
        if(dp[a][b][c+1]<0) dfs(dfs, a, b, c+1); 

        dp[a][b][c] += dp[a+1][b][c]*(a)/(a+b+c);
        dp[a][b][c] += dp[a][b+1][c]*(b)/(a+b+c);
        dp[a][b][c] += dp[a][b][c+1]*(c)/(a+b+c);

        //dp[a][b][c] /= 3;
        dp[a][b][c] += 1;
        ES(a) ES(b) ES(c) EL(dp[a][b][c])
    };

    dfs(dfs, A,B,C);

    PL(dp[A][B][C])

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
