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
    V<V<int>> Pos(N, V<int>(3));
    cin>>Pos;

    //dp[行った町][最後に訪れた町]
    V<V<int>> dp(1<<N, V<int>(N, INF));
    dp[1][0]=0;
    rep(i,N){
        auto nxt = dp;
        rep(j,1<<N){//from
            rep(k,N){//last
                if(dp[j][k]==INF) continue;
                rep(l,N){
                    if(j&(1<<l)) continue;
                    int cost = 0;
                    cost += abs(Pos[k][0]-Pos[l][0]);
                    cost += abs(Pos[k][1]-Pos[l][1]);
                    cost += max(0, Pos[l][2]-Pos[k][2]);
                    chmin(nxt[j|(1<<l)][l], dp[j][k]+cost);
                }
            }
        }
        swap(dp, nxt);
    }

    int ans = INF;
    rep(i,N){
        if(dp[(1<<N)-1][i]==INF) continue;
        int cost = 0;
        cost += abs(Pos[0][0]-Pos[i][0]);
        cost += abs(Pos[0][1]-Pos[i][1]);
        cost += max(0, Pos[0][2]-Pos[i][2]);
        chmin(ans, dp[(1<<N)-1][i]+cost);
    }
    PL(ans)


    return;
}


void solve2() {

    int N; cin>>N;
    V<V<int>> Pos(N, V<int>(3));
    cin>>Pos;

    //dp[行った町][最後に訪れた町]
    V<V<int>> dp(N, V<int>(1<<N, INF));
    dp[0][1]=0;
    rep(i,N){
        rep(k,N){//last
        auto nxt = dp;
            rep(j,1<<N){//from
                if(dp[k][j]==INF) continue;
                rep(l,N){
                    if(j&(1<<l)) continue;
                    int cost = 0;
                    cost += abs(Pos[k][0]-Pos[l][0]);
                    cost += abs(Pos[k][1]-Pos[l][1]);
                    cost += max(0, Pos[l][2]-Pos[k][2]);
                    chmin(nxt[l][j|(1<<l)], dp[k][j]+cost);
                }
            }
        swap(dp, nxt);
        }
    }

    int ans = INF;
    rep(i,N){
        if(dp[i][(1<<N)-1]==INF) continue;
        int cost = 0;
        cost += abs(Pos[0][0]-Pos[i][0]);
        cost += abs(Pos[0][1]-Pos[i][1]);
        cost += max(0, Pos[0][2]-Pos[i][2]);
        chmin(ans, dp[i][(1<<N)-1]+cost);
    }
    PL(ans)


    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
