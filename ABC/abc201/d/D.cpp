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

    V<V<int>> dp(H,V<int>(W,0));

    rep(h,H){
        rep(w,W){
            if(h+w==0) continue;
            int isPlus = (A[h][w]=='+');
            if((h+w)%2==1){
                dp[h][w] = -INF;
                if(0<h) chmax(dp[h][w], dp[h-1][w]-1+2*isPlus);
                if(0<w) chmax(dp[h][w], dp[h][w-1]-1+2*isPlus);
            }
            else{
                dp[h][w] = INF;
                if(0<h) chmin(dp[h][w], dp[h-1][w]+1-2*isPlus);
                if(0<w) chmin(dp[h][w], dp[h][w-1]+1-2*isPlus);
            }
        }
        EL(dp[h])
    }

    if(dp[H-1][W-1]>0) PL("Takahashi")
    else if(dp[H-1][W-1]<0) PL("Aoki")
    else PL("Draw")

    return;
}

void solve2(){
    int H,W; cin>>H>>W;
    V<string> A(H); cin>>A;

    V<V<int>> dp(H+1,V<int>(W+1));
    for(int h=H-1;h>=0;h--){
        for(int w=W-1;w>=0;w--){
            //+なら1,-なら-1
            int tmp = -1+2*int(A[h][w]=='+');
            if((h+w)%2==1){
                dp[h][w] = max(dp[h+1][w], dp[h][w+1]);
                dp[h][w] += tmp;
            }
            else{
                dp[h][w] = min(dp[h+1][w], dp[h][w+1]);
                dp[h][w] -= tmp;                
            }
        }
    }
    rep(i,H+1) EL(dp[i])
    if(dp[0][0]>0) PL("Takahashi")
    else if(dp[0][0]<0) PL("Aoki")
    else PL("Draw")

}

void solve3(){
    int H,W; cin>>H>>W;
    V<string> A(H); cin>>A;
    V<V<int>> dp(H, V<int>(W));
    for(int h=H-1;h>=0;h--){
        for(int w=W-1;w>=0;w--){
            int turn = (h+w)%2;
            int val = -1 + 2*int(A[h][w]=='+');
            if(h+w==0){
                dp[h][w] = -INF;
                if(h+1<H) chmax(dp[h][w], dp[h+1][w]);
                if(w+1<W) chmax(dp[h][w], dp[h][w+1]);
                if(dp[h][w]==-INF) dp[h][w] = 0;
                continue;
            }
            if(h+w==H+W-2){
                dp[h][w] = 0;
                if(turn==1) dp[h][w] = val;
                else dp[h][w] = -val;
                continue;
            }
            if(turn==0){
                dp[h][w] = -INF;
                if(h+1<H) chmax(dp[h][w], dp[h+1][w]);
                if(w+1<W) chmax(dp[h][w], dp[h][w+1]);
                dp[h][w] -= val;
            }
            else{
                dp[h][w] = INF;
                if(h+1<H) chmin(dp[h][w], dp[h+1][w]);
                if(w+1<W) chmin(dp[h][w], dp[h][w+1]);
                dp[h][w] += val;
            }
        }
    }
    if(dp[0][0]>0) PL("Takahashi")
    else if(dp[0][0]<0) PL("Aoki")
    else PL("Draw")

}



int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve3();
   return 0;
}
