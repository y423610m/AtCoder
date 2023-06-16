#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
//__uint128_t
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;

//#define _GLIBCXX_DEQUE_BUF_SIZE 512

// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
// #define endl "\n"
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
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template<typename T> using V = vector<T>;
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
template<typename T, unsigned long int sz> ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz> istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/geometry/geometries/linestring.hpp>
/*
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
*/

void solve() {

    namespace bg = boost::geometry;

    typedef bg::model::d2::point_xy<double> point;
    typedef bg::model::polygon<point> polygon;

    ll N; cin>>N;
    vector<pair<double, double>> XY(N); cin>>XY;
    pair<double,double> s,t; cin>>s>>t;



    polygon poly;
    rep(i,N){
        poly.outer().push_back({XY[i].fi, XY[i].se});
    }
    poly.outer().push_back({XY[0].fi, XY[0].se});

    // {//接触部あるか判定
    //     bg::model::linestring<point> linest{{s.fi, s.se}, {t.fi,t.se}};
    //     bool cross = false;
    //     rep(i,N){
    //         bg::model::linestring<point> line{{XY[i].fi, XY[i].se}, {XY[(i+1)%N].fi, XY[(i+1)%N].se}};
    //         if(bg::intersects(linest, line)){
    //             cross = true;
    //         }
    //     }
    //     if(!cross) END(hypot(s.fi-t.fi, s.se-t.se))
    // }

    {//接触部あるか判定
        bg::model::linestring<point> linest{{s.fi, s.se}, {t.fi,t.se}};
        bool cross = false;
        if(!bg::intersects(linest, poly.outer())){
            END(hypot(s.fi-t.fi, s.se-t.se))
        }
    }

    poly.outer().push_back({s.fi, s.se});
    poly.outer().push_back({t.fi, t.se});
    polygon hull;
    bg::convex_hull(poly, hull);

    ll ids = 0;
    ll idt = 0;
    point sp(s.fi, s.se);
    point tp(t.fi, t.se);

    auto h = hull.outer();
    ll M = h.size();
    rep(i, M){
        if(h[i].x()==sp.x()&&h[i].y()==sp.y()) ids = i;
        if(h[i].x()==tp.x()&&h[i].y()==tp.y()) idt = i;
    }

    double ans = 1e18;
    double cand1 = 0;
    for(ll i = ids; i!=idt; i++, i%=M){
        cand1 += hypot(h[i].x()-h[(i+1)%M].x(), h[i].y()-h[(i+1)%M].y());
    }

    double cand2 = 0;
    for(ll i = idt; i!=ids; i++, i%=M){
        cand2 += hypot(h[i].x()-h[(i+1)%M].x(), h[i].y()-h[(i+1)%M].y());
    }

    chmin(ans, cand1);
    chmin(ans, cand2);
    EL(cand1)
    EL(cand2)
    PL(ans)

    return;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);//小数点以下
    // std::cout << std::setprecision(3);//全体有効数字
    // std::cout << std::defaultfloat;//設定戻す(6桁)
    // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
    // stoll(s,nullptr,base);
    int TT = 1;
    //cin>>TT;
    for(int tt = 0; tt<TT; tt++) solve();
    return 0;
}
