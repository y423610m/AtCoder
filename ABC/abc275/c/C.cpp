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

    int N = 9;
    V<string> S(N); cin>>S;

    auto dist = [&](int x1, int y1, int x2, int y2)->int {
        int ret = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        return ret;
    };

    auto outer = [&](int x1, int y1, int x2, int y2)->int {
        int ret = x1*x2+y1*y2;
        return ret;
    };


    // //平行
    // int ans = 0;
    // rep(i,N) rep(j,N) repi(len,1,N){
    //     if(i+len>=N) continue;
    //     if(j+len>=N) continue;
    //     bool ok = true;
    //     if(S[i][j]=='.') continue;
    //     if(S[i][j+len]=='.') continue;
    //     if(S[i+len][j]=='.') continue;
    //     if(S[i+len][j+len]=='.') continue;
    //     ans++;
    // }

    int ans2 = 0;
    V<pair<Pii,Pii>> ANS;
    V<int> d(4);
    V<Pii> Points(4);
    rep(x0,N){
        rep(y0,N){
            if(S[x0][y0]=='.') continue;
            rep(x1,N){
                rep(y1,N){//横横縦縦
                    if(S[x1][y1]=='.') continue;
                    rep(x2,N){
                        rep(y2,N){
                            if(S[x2][y2]=='.') continue;
                            rep(x3,N){
                                rep(y3,N){
                                    if(S[x3][y3]=='.') continue;

                                    if((x0==x1)&&(y0==y1)) continue;
                                    if((x1==x2)&&(y1==y2)) continue;
                                    if((x2==x3)&&(y2==y3)) continue;
                                    if((x3==x0)&&(y3==y0)) continue;
                                    if((x0==x2)&&(y0==y2)) continue;
                                    if((x1==x3)&&(y1==y3)) continue;

                                    if(outer(x1-x2, y1-y2, x3-x2, y3-y2)!=0) continue;

                                    d[0] = dist(x0,y0,x1,y1);
                                    d[1] = dist(x1,y1,x2,y2);
                                    d[2] = dist(x2,y2,x3,y3);
                                    d[3] = dist(x3,y3,x0,y0);

                                    bool ok = true;
                                    if(d[0]==0) ok = false;
                                    rep(i,4) if(d[0]!=d[i]) ok = false;
                                    if(ok) ans2++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    EL(ans2)
    PL(ans2/8)

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
