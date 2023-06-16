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

    int H,W; cin>>H>>W;
    V<string> A(H); cin>>A;


    V<V<int>> dp(H,V<int>(W, -INF));

    auto dfs = [&](auto dfs, int h, int w)->void{
        int turn = (h+w)%2;

        if(h+w==H+W-2){
            dp[h][w] = 0;
            return;
        }

        if(turn==0){
            dp[h][w] = -INF;
            if(h+1<H){
                if(dp[h+1][w]==-INF) dfs(dfs, h+1,w);
                chmax(dp[h][w], dp[h+1][w]-1+2*int(A[h+1][w]=='+'));
            }
            if(w+1<W){
                if(dp[h][w+1]==-INF) dfs(dfs, h,w+1);
                chmax(dp[h][w], dp[h][w+1]-1+2*int(A[h][w+1]=='+'));
            }
        }
        else{
            dp[h][w] = INF;
            if(h+1<H){
                if(dp[h+1][w]==-INF) dfs(dfs, h+1,w);
                chmin(dp[h][w], dp[h+1][w]+1-2*int(A[h+1][w]=='+'));
            }
            if(w+1<W){
                if(dp[h][w+1]==-INF) dfs(dfs, h,w+1);
                chmin(dp[h][w], dp[h][w+1]+1-2*int(A[h][w+1]=='+'));
            }
        }
    };

    dfs(dfs, 0, 0);
    int result = dp[0][0];
    if(result>0) PL("Takahashi")
    else if(result<0) PL("Aoki")
    else PL("Draw")

    //rep(h,H) PL(dp[h])

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
