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

    int N; cin>>N;
    V<int> A(N); cin>>A;

    V<int> cnt(4);
    rep(i,N) cnt[A[i]]++;
    EL(cnt)

    //dp[i][j][k]:=残り1,2,3個の皿がi,j,k個
    V<V<V<double>>> dp(N+1, V<V<double>>(N+1, V<double>(N+1)));
    V<V<V<bool>>> visited(N+1, V<V<bool>>(N+1, V<bool>(N+1)));

    auto dfs = [&](auto dfs)->void {
        EL(cnt)

        if(cnt[0]==N){
            dp[cnt[1]][cnt[2]][cnt[3]] = 0;
            return;
        }

        for(int i=1;i<=3;i++){
            if(cnt[i]==0) continue;
            if(!visited[cnt[1]-(i==1)+(i==2)][cnt[2]-(i==2)+(i==3)][cnt[3]-(i==3)]){
                cnt[i]--;
                cnt[i-1]++;
                dfs(dfs);
                cnt[i]++;
                cnt[i-1]--;
                visited[cnt[1]-(i==1)+(i==2)][cnt[2]-(i==2)+(i==3)][cnt[3]-(i==3)] = true;
            }
            dp[cnt[1]][cnt[2]][cnt[3]] += 1.0 * cnt[i] * (1.0 + dp[cnt[1]-(i==1)+(i==2)][cnt[2]-(i==2)+(i==3)][cnt[3]-(i==3)]);
            ES(i) EL(dp[cnt[1]][cnt[2]][cnt[3]])
        }
        dp[cnt[1]][cnt[2]][cnt[3]] += 1.0 * cnt[0];
        dp[cnt[1]][cnt[2]][cnt[3]] /= N;
        dp[cnt[1]][cnt[2]][cnt[3]] *= 1.0 * N / (N-cnt[0]);
        ES(cnt) EL(dp[cnt[1]][cnt[2]][cnt[3]])
    };

    dfs(dfs);

    PL(dp[cnt[1]][cnt[2]][cnt[3]]);

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
