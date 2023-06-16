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
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
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

int dx1[2] = {1, -1};
int dy1[2] = {0, 0};

int dx2[2] = {0, 0};
int dy2[2] = {1, -1};

void solve() {

    int h,w,n,m; cin>>h>>w>>n>>m;
    V<string> S1(h, string(w,' '));
    V<string> S2(h, string(w,' '));

    V<P> L(n);
    rep(i,n) cin>>L[i].first>>L[i].second;
    
    rep(i,m){
        int x,y; cin>>x>>y;
        x--, y--;
        S1[x][y] = '#';
        S2[x][y] = '#';
    }

    //1
    rep(i,n){
        int x = L[i].first;
        int y = L[i].second;
        x--, y--;
        if(S1[x][y]=='.') continue;
        S1[x][y]='.';
        rep(j,2){
            int nx = x;
            int ny = y;
            nx += dx1[j];
            ny += dy1[j];
            while(0<=nx && nx<h && 0<=ny && ny<w && S1[nx][ny]==' '){
                S1[nx][ny] = '.';
                nx += dx1[j];
                ny += dy1[j];
            }
        }
    }

    rep(i,n){
        int x = L[i].first;
        int y = L[i].second;
        x--, y--;
        if(S2[x][y]=='.') continue;
        S2[x][y]='.';
        rep(j,2){
            int nx = x;
            int ny = y;
            nx += dx2[j];
            ny += dy2[j];
            while(0<=nx && nx<h && 0<=ny && ny<w && S2[nx][ny]==' '){
                S2[nx][ny] = '.';
                nx += dx2[j];
                ny += dy2[j];
            }
        }
    }


    int ans = 0;
    rep(i,h) rep(j,w) if(S1[i][j]=='.' || S2[i][j]=='.') ans++;
    PL(ans)

    return;
}

// void solve2() {

//     int h,w,n,m; cin>>h>>w>>n>>m;
//     V<string> S(h, string(w,' '));

//     V<P> L(n);
//     rep(i,n) cin>>L[i].first>>L[i].second;
    
//     rep(i,m){
//         int x,y; cin>>x>>y;
//         x--, y--;
//         S[x][y] = '#';
//     }
//     EL("a")

//     rep(j,n){
//         int x = L[j].first;
//         int y = L[j].second;
//         x--, y--;
//         S[x][y]='.';
//         rep(i,4){
//             int nx = x;
//             int ny = y;
//             while(0<=nx && nx<h && 0<=ny && ny<w && S[nx][ny]!='#'){
//                 S[nx][ny] = '.';
//                 nx += dx[i];
//                 ny += dy[i];
//             }
//         }
//     }
//     EL("b")

//     int ans = 0;
//     rep(i,h) rep(j,w) if(S[i][j]=='.') ans++;
//     PL(ans)

//     return;
// }

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
