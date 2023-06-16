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

//DRUL  SENW
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};



void solve() {

    int H,W; cin>>H>>W;
    ll x,y; cin>>x>>y; x--,y--;

    // auto inGrid = [&](int nx, int ny){
    //     if(0<=nx&&nx<H&&0<=ny&&ny<W) return true;
    //     return false;
    // };

    int N; cin>>N;

    map<int,V<ll>> mpH, mpW;
    rep(i,N){
        int r,c; cin>>r>>c; r--, c--;
        mpH[r].push_back(c);
        mpW[c].push_back(r);
    }

    for(auto& p:mpH) sort(ALL(p.se));
    for(auto& p:mpW) sort(ALL(p.se));


    int dir[256];
    dir['D'] = 0;
    dir['R'] = 1;
    dir['U'] = 2;
    dir['L'] = 3;

    EL("begin Q")

    int Q; cin>>Q;
    rep(q,Q){
        char d; cin>>d;
        ll l; cin>>l;
        
        if(d=='D'){//下向き
            auto& mp = mpW[y];
            auto it = upper_bound(ALL(mp),x);
            if(it==mp.end()){
                x += l;
            }
            else{
                x = min(x+l, (*it)-1);
            }
            chmin(x, H-1);
        }
        else if(d=='R'){//右
            auto& mp = mpH[x];
            auto it = upper_bound(ALL(mp),y);
            if(it==mp.end()){
                y += l;
            }
            else{
                y = min(y+l, (*it)-1);
            }
            chmin(y, W-1);
        }
        else if(d=='U'){//上
            auto& mp = mpW[y];
            auto it = lower_bound(ALL(mp),x);
            if(it==mp.begin()){
                x = x-l;
            }
            else{
                it = prev(it);
                x = max(x-l, (*it)+1);
            }
            chmax(x, 0);
        }
        else if(d=='L'){//左
            auto& mp = mpH[x];
            auto it = lower_bound(ALL(mp),y);
            if(it==mp.begin()){
                y = y-l;
            }
            else{
                it = prev(it);
                y = max(y-l, (*it)+1);
            }
            chmax(y, 0);
        }
        PS(x+1) PL(y+1)
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
