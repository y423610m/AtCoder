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
#define FI first
#define SE second
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

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
using namespace atcoder;
//dsu DSU(n);
//DSU.merge(a,b);
//if(DSU.same(a,b)){}
#endif

struct EN{
    ll x, y, r;
};

bool areContact(const EN& A, const EN& B){

    //same en
    if(A.x==B.x && A.y==B.y && A.r==B.r) return true;

    //2point contact 一方の円の中に他方の円ない
    ll d2 = (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
    ll rr2 = (A.r+B.r)*(A.r+B.r);

    //明らかに遠すぎる
    if(d2>rr2) return false;

    //完全に内包している
    ll dAB2 = (abs(A.x-B.x)+B.r)*(abs(A.x-B.x)+B.r) + (abs(A.y-B.y)+B.r)*(abs(A.y-B.y)+B.r);
    ll dBA2 = (abs(A.x-B.x)+A.r)*(abs(A.x-B.x)+A.r) + (abs(A.y-B.y)+A.r)*(abs(A.y-B.y)+A.r);
    if(dAB2<A.r*A.r || dBA2<B.r*B.r) return false;

    return true;
}

bool onEN(const EN& E, ll x, ll y){
    ll d2 = (E.x-x)*(E.x-x) + (E.y-y)*(E.y-y);
    if(d2 == E.r*E.r) return true;
    return false;
}

void solve() {

    int n; cin>>n;
    ll sx, sy, tx, ty;
    cin>>sx>>sy>>tx>>ty;
    V<EN> Es(n);
    rep(i,n) cin>>Es[i].x>>Es[i].y>>Es[i].r;

    dsu tree(n+2);

    rep(i,n){
        repi(j,i+1, n){
            if(areContact(Es[i], Es[j])){
                ES("same") ES(i) EL(j)
                tree.merge(i,j);
            }
        }
    }
    //s
    rep(i,n){
        if(onEN(Es[i], sx, sy)){
            tree.merge(i, n); 
            ES("s") EL(i)
        }
    }
    //t
    rep(i,n){
        if(onEN(Es[i], tx, ty)){
            tree.merge(i, n+1); 
            ES("t") EL(i)
        }
    }

    if(tree.same(n, n+1)) PL("Yes")
    else PL("No")


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
