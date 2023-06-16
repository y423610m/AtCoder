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

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
using namespace atcoder;
//dsu DSU(n);
//DSU.merge(a,b);
//if(DSU.same(a,b)){}
#endif





void solve() {

    int N; cin>>N;

    V<double> dp(N+1);
    dp[1] = 3.5;
    for(int i=2;i<=N;i++){
        for(int x=1;x<=6;x++){
            dp[i] += max(double(x), dp[i-1]);
        }
        dp[i]/=6.0;
    }
    PL(dp[N])
    

    return;
}

void solve2(){
    int N; cin>>N;
    //dp[i][j]:=i回振って最大がjである通り
    V<V<ll>> dp(N+1, V<ll>(7));
    dp[0][0] = 1;

    rep(i,N){
        for(int j=0;j<=6;j++){
            for(int x = 1;x<=6;x++){
                dp[i+1][max(x,j)] += dp[i][j];
            }
        }
        EL(dp[i+1])
    }

    ll sum = 0;
    ll cnt = 0;
    repi(j,1,7){
        sum += dp[N][j]*j;
        cnt += dp[N][j];
    }
    PL((double)sum/cnt)
}

void solve3(){
    int N; cin>>N;
    V<double> dp(N);
    dp.back() = 3.5;
    for(int i=N-2;i>=0;i--){
        for(int x=1;x<=6;x++){
            if(x>=dp[i+1]) dp[i] += (double)x/6;
            else dp[i] += dp[i+1]/6.0;
        }
    }
    PL(dp[0])
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve3();
   return 0;
}


