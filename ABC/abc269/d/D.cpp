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
int dx[6] = {1, 0, 1, -1,  0, -1};
int dy[6] = {0, 1, 1,  0, -1, -1};

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
using namespace atcoder;
//dsu DSU(n);
//DSU.merge(a,b);
//if(DSU.same(a,b)){}
#endif

void solve() {

    int N; cin>>N;

    V<Pii> P(N);
    cin>>P;
    rep(i,N){
        P[i].fi+=1010;
        P[i].se+=1010;
    }

    set<Pii> st;

    int D = 2011;
    dsu tree(D*2010+2010+10);

    rep(i,N){
        auto [x,y] = P[i];
        rep(d,6){
            auto [nx,ny] = P[i];
            nx += dx[d];
            ny += dy[d];
            tree.merge(D*x+y, D*nx+ny);
        }
    }

    int ans = 1;
    auto [x,y] = P[0];
    rep(i,N){
        auto [nx, ny] = P[i];
        if(!tree.same(D*x+y, D*nx+ny)){
            tree.merge(D*x+y, D*nx+ny);
            ans++;
            EL(i)
        }
    }

    PL(ans)


    return;
}

void solve2(){
    int N; cin>>N;
    V<Pii> P(N); cin>>P;

    set<Pii> st;
    rep(i,N) st.insert(P[i]);

    dsu tree(N);

    map<Pii,int> id;
    rep(i,N){
        id[P[i]] = i;
    }

    rep(i,N){
        rep(d,6){
            auto [nx,ny] = P[i];
            nx += dx[d];
            ny += dy[d];
            if(st.find(Pii(nx, ny))!=st.end()){
                tree.merge(i, id[Pii(nx, ny)]);
            }
        }
    }

    int ans = 1;
    rep(i,N){
        if(!tree.same(0,i)){
            tree.merge(0,i);
            ans++;
        }
    }

    PL(ans)
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
