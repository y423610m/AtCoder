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

ll dp[2005][2005][2][2];

void solve() {

    ll H,W; cin>>H>>W;
    V<ll> R(H), C(W); cin>>R>>C;
    V<string> A(H); cin>>A;

    rep(h,H+1) rep(w,W+1) rep(i,2) rep(j,2) dp[h][w][i][j] = LINF;
    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = C[0];
    dp[0][0][1][0] = R[0];
    dp[0][0][1][1] = R[0]+C[0];

    rep(h,H) rep(w,W){
        //更新
        // rep(i,2) rep(j,2){
        //     rep(i2,2) rep(j2,2){
        //         ll c = 0;
        //         if(i!=i2) c += R[h];
        //         if(j!=j2) c += C[w];
        //         //chmin(dp[h][w][i][j], dp[h][w][i2][j2]+c);
        //     }
        // }
        if(h+1<H){//下に行く
            rep(i,2) rep(j,2){//今のマスの状態
                rep(i2,2){//r,cを変更する？
                    ll c = 0;
                    ll d = 0;
                    if(A[h][w]!=A[h+1][w]) d++;
                    if(i) d++;
                    // if(j) d++;
                    if(i2) d++, c+=R[h+1];
                    if(d%2==0) chmin(dp[h+1][w][i2][j], dp[h][w][i][j]+c);
                }
            }
        }
        if(w+1<W){
            rep(i,2) rep(j,2){//今のマスの状態
                rep(j2,2){//r,cを変更する？
                    ll c = 0;
                    ll d = 0;
                    if(A[h][w]!=A[h][w+1]) d++;
                    // if(i) d++;
                    if(j) d++;
                    if(j2) d++, c+=C[w+1];
                    if(d%2==0) chmin(dp[h][w+1][i][j2], dp[h][w][i][j]+c);
                }
            }
        }
    }

    ll ans = LINF;
    rep(i,2) rep(j,2) chmin(ans,dp[H-1][W-1][i][j]);
    PL(ans)
    return;
    rep(i,2) rep(j,2){
        ES(i) EL(j)
        rep(h,H){
            rep(w,W) PS(dp[h][w][i][j])
            PL("")
        }
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
