#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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
#define fi first
#define se second

template<typename T> istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/geometry/geometries/linestring.hpp>


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
    PL(ans)

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
