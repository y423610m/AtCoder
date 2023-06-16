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
#define NAME(a) #a
#define ES(a) cerr<<NAME(a)<<": "<<(a)<<" ";
#define EL(a) cerr<<NAME(a)<<": "<<(a)<<endl;
#define END(a) {PL(a) return;}
#define RES(a) cerr<<"\r"<<NAME(a)<<": "<<(a)<<"   ";
#define FI first
#define SE second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using P = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}
#endif

void solve() {

    int n; cin>>n;
    int m; cin>>m;
    int k; cin>>k;

    V<mint> dp(m, 1);
    rep(i,n-1){
        V<mint> nxt(m, 0);
        
        V<mint> Lsum(1,dp[0]);
        repi(j,1,m){Lsum.push_back(Lsum.back()+dp[j]);}
        V<mint> Rsum(1,dp.back());
        for(int j=m-2; j>=0; j--){Rsum.push_back(Rsum.back()+dp[j]);}
        REVERSE(Rsum)
        // // ES(Rsum.size())
        // // ES(Lsum.size())
    //    EL(Lsum)
    //    EL(Rsum)

        if(k!=0){
            rep(j,m){
                if(j-k>=0) nxt[j] += Lsum[j-k];
                if(j+k<m) nxt[j] += Rsum[j+k];
            }
        }
        else{
            rep(j,m){
                if(j-k>=0) nxt[j] += Lsum[j-k];
                if(j+k<m) nxt[j] += Rsum[j+k];
                nxt[j] -= dp[j];

            }            
        }

    //    EL(nxt)

        dp = nxt;
    }
    mint ans = 0;
    rep(i,m) ans += dp[i];
    PL(ans)

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
