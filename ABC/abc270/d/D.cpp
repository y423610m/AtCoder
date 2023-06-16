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

    int N; cin>>N;
    int K; cin>>K;
    V<int> A(K); cin>>A;

    V<V<int>> memo(N+1, V<int>(2,-1));
    //return:高橋君が取れる石の最大値
    auto dfs = [&](auto dfs, int n, int turn)->int{
        //ES(n) ES(turn) EL(tak)
        if(n==0){
            return 0;
        }
        int ret;
        if(turn==0) ret = -INF;
        else ret = INF;
        rep(k,K){
            if(n<A[k]) break;
            int result;
            if(memo[n-A[k]][1-turn]!=-1) result = memo[n-A[k]][1-turn];
            else{
                result = dfs(dfs, n-A[k], 1-turn);
                memo[n-A[k]][1-turn] = result;
            }
            if(turn==0) chmax(ret, A[k]+result);
            else chmin(ret, result);
        }
        ES(n) ES(turn) EL(ret)
        return ret;
    };

    int ans = dfs(dfs, N, 0);

    PL(ans)

    return;
}

void solve2(){
    int N,K; cin>>N>>K;
    V<int> A(K); cin>>A;
    V<int> memo(N+1,-1);
    //return:残りn個のとき，自分がとれる最大個数
    auto dfs = [&](auto dfs, int n){
        if(n==0) return 0;
        int ret = -INF;
        rep(k,K){
            if(n<A[k]) break;
            int result;
            if(memo[n-A[k]==-1]){
                result = dfs(dfs, n-A[k]);
                memo[n-A[k]] = result;
            }
            else result = memo[n-A[k]];
            chmax(ret, n-result);
        }
        return ret;
    };

    int ans = dfs(dfs, N);
    PL(ans)
}

void solve3(){
    int N,K; cin>>N>>K;
    V<int> A(K); cin>>A;

    //dp[i]:=のこりの石がi個の時にとれる最大個数
    V<int> dp(N+1, -INF);
    dp[0] = 0;
    rep(i,N+1){
        rep(k,K){
            if(i-A[k]<0) break;
            chmax(dp[i], i-dp[i-A[k]]);
        }
    }
    PL(dp[N])
}

void solve4(){
    int N,K; cin>>N>>K;
    V<int> A(K); cin>>A;

    //dp[i][j]:=石残りi個でjの番の時に取れる最大個数
    V<V<int>> dp(N+1,V<int>(2,-INF));
    dp[0][0] = 0;
    dp[0][1] = 0;
    repi(i,1,N+1){
        rep(j,2){
            rep(k,K){
                if(i-A[k]<0) break;
                chmax(dp[i][j], i-dp[i-A[k]][1-j]);
            }
        }
    }
    PL(dp[N][0])
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve4();
   return 0;
}
