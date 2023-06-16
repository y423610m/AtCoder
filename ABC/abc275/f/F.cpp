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

    int N,M;
    cin>>N>>M;
    V<int> A(N); cin>>A;


    //dp[i][j]:=i番目まで見て，和がjで，最後使った？
    V<V<V<int>>> dp(N+1, V<V<int>>(M+1, V<int>(2, INF)));
    dp[0][0][1] = 0;
    rep(i,N){
        //dp[i+1] = dp[i];
        rep(j,M)if(j+A[i]<=M){
            chmin(dp[i+1][j+A[i]][1], dp[i][j][0]);
            chmin(dp[i+1][j+A[i]][1], dp[i][j][1]);
        }
        rep(j,M+1){
            chmin(dp[i+1][j][0], dp[i][j][0]);
            chmin(dp[i+1][j][0], dp[i][j][1]+1);
        }
    }



    repi(i,1,M+1){
        if(dp[N][i][0]==INF&&dp[N][i][1]==INF) PL("-1")
        else PL(min(dp[N][i][0],dp[N][i][1]))
    }


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

/*
ABC275 ABDE4完
A:やる
B:modint
C:解けず．ひし形を含んでしまってた．．．orz
D:メモ化再起．
E:期待値はmodintでメモ化再起．
F:dp[i][j][k]:=i番目までで和がjで，i-1番目の要素を使った場合の最小操作回数．


*/