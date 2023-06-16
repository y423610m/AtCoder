#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long int;
using ld = long double;
// __uint128_t
constexpr ll MOD = 998'244'353;
// constexpr ll MOD = 1000'000'007;

constexpr ll INF = (1LL<<30)-1;
constexpr ll LINF = (1LL<<62)-1;
constexpr char Yes[] = "Yes";
constexpr char No[] = "No";

// #define _GLIBCXX_DEQUE_BUF_SIZE 512

// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
// #define ONLINE_JUDGE 1
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
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template<typename T> using V = vector<T>;
template<typename T> using max_heap = priority_queue<T>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T, unsigned long int sz> using Ar = array< T , sz >;
template<typename T> ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T> istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T> void operator--(vector<T>& A){for(auto& a:A) a--;}//pre
template<typename T> void operator--(vector<T>& A, int){for(auto& a:A) a--;}//post
template<typename T> void operator++(vector<T>& A){for(auto& a:A) a++;}//pre
template<typename T> void operator++(vector<T>& A, int){for(auto& a:A) a++;}//post
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, typename U> void operator--(pair<T, U>& p){p.first--, p.second--;}//pre
template<typename T, typename U> void operator--(pair<T, U>& p, int){p.first--, p.second--;}//post
template<typename T, typename U> void operator++(pair<T, U>& p){p.first--, p.second--;}//pre
template<typename T, typename U> void operator++(pair<T, U>& p, int){p.first--, p.second--;}//post
template<class T,class U> struct std::hash<std::pair<T,U>>{size_t operator()(const std::pair<T,U> &p) const noexcept {return (std::hash<T>()(p.first)+1) ^ (std::hash<U>()(p.second)>>2);}};
template<typename T, unsigned long int sz> ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz> istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A){for(auto& a:A){a--;}}//pre
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A, int){for(auto& a:A){a--;}}//post
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A){for(auto& a:A){a++;}}//pre
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A, int){for(auto& a:A){a++;}}//post
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/linestring.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
namespace bg = boost::geometry;
typedef bg::model::d2::point_xy<ll> point;

#include <boost/geometry/geometries/linestring.hpp>
/*
namespace bg = boost::geometry;
typedef bg::model::d2::point_xy<double> point;
bg::model::linestring<point> linest{{s.fi, s.se}, {t.fi,t.se}};
bool cross = false;
if(!bg::intersects(linest, poly.outer())){
    END(hypot(s.fi-t.fi, s.se-t.se))
}
*/
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/assign/list_of.hpp>
typedef bg::model::polygon<point> polygon;



// #define endl "\n"

void solve() {

   ll N; cin>>N;
   V<Pll> XY(N); cin>>XY;
   ll Q; cin>>Q;
   V<Pll> AB(Q); cin>>AB;

   bg::model::linestring<point> line;
   polygon poly;
   rep(i,N){
      line.push_back({XY[i].fi, XY[i].se});
      poly.outer().push_back({XY[N-1-i].fi, XY[N-1-i].se});
   }

   rep(q,Q){
      point p{AB[q].fi, AB[q].se};
      bool on = bg::intersects(line, p);
      if(on){
         PL("ON")
         continue;
      }
      //bool in = bg::within(line, p);
      bool in = bg::disjoint(poly, p);
      if(!in){
         PL("IN")
         continue;
      }

      PL("OUT")
   }


   return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);//小数点以下
   // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
   // stoll(s,nullptr,base);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}



/*
    https://boostjp.github.io/tips/geometry.html
    pair型としてソートして最小の頂点から開始．必ずxy座標にて時計回り
    複数回呼ぶとclearされずにpush_backされ続けるので，polygon.clear()を呼ぶ
    namespace bg = boost::geometry;

    typedef bg::model::d2::point_xy<double> point;
    typedef bg::model::polygon<point> polygon;
    //入力
    polygon poly;
    poly.outer().push_back({0,0});
    poly.outer().push_back({0,1});
    poly.outer().push_back({1,0});
    poly.outer().push_back({1,1});
    poly.outer().push_back({0.5,1.5});
    // poly.outer().push_back({0,0});

    //出力先.
    polygon hull;
    bg::convex_hull(poly, hull);

    //デバッグ
    EL(bg::dsv(poly))
    EL(bg::dsv(hull))

    auto h = hull.outer();
    EL(h.size())
    EL(h[0].x())
    for(auto p:hull.outer()){
        ES(p.x()) EL(p.y())
    }

 接触判定．
bg::model::linestring<point> linest{{s.fi, s.se}, {t.fi,t.se}};
bool cross = false;
if(!bg::intersects(linest, poly.outer())){
END(hypot(s.fi-t.fi, s.se-t.se))
}
*/