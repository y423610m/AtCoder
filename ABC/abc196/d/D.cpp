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



void solve() {

    int H,W; cin>>H>>W;
    int a,b; cin>>a>>b;

    int ans = 0;
    int HW = H*W;
    V<int> memo(HW, -1);

    rep(i, (1<<HW)){
        int bitN = __builtin_popcount(i);
        if(bitN!=2*a) continue;

        auto dfs = [&](auto dfs, int p)->void{
            //ES(i) EL(p)
            if(p==HW){
                ans++;
                // PL(i)
                // PL(__builtin_popcount(i))
                // rep(j, HW) PS(i&(1<<j))
                // PL("")
                // rep(h,H){
                //     rep(w,W){
                //         PS(memo[h*W+w])
                //     }
                //     PL("")
                // }
                // PL("")
                return;
            }

            if(memo[p]!=-1){
                dfs(dfs, p+1);
            }
            else if(i&(1<<p)){//2枚
                //右
                if(1+p%W<W && i&(1<<(p+1)) && memo[p+1]==-1){
                    memo[p] = p;
                    memo[p+1] = p;
                    dfs(dfs, p+1);
                    memo[p] = -1;
                    memo[p+1] = -1;
                }
                //下
                if(1+p/W<H && i&(1<<(p+W)) && memo[p+W]==-1){
                    memo[p] = p;
                    memo[p+W] = p;
                    dfs(dfs, p+1);
                    memo[p] = -1;
                    memo[p+W] = -1;
                }
                return;
            }
            else{//1枚
                memo[p] = p;
                dfs(dfs, p+1);
                memo[p] = -1;
            }
        };

        dfs(dfs, 0);

    }
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
