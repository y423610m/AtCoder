#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long int;
using ld = long double;
using ull = unsigned long long;
using lll = __int128_t;
using ulll = __uint128_t;
constexpr ll MOD = 998'244'353;
// constexpr ll MOD = 1000'000'007;
// #define _GLIBCXX_DEQUE_BUF_SIZE 512
// #pragma comment(linker, "/stack:1000000000")

// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]
constexpr ll INF = (1LL<<30)-1;
constexpr ll LINF = (1LL<<62)-1;
string Yes = "Yes";
string No = "No";

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
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, typename U> void operator--(pair<T, U>& p){p.first--, p.second--;}//pre
template<typename T, typename U> void operator--(pair<T, U>& p, int){p.first--, p.second--;}//post
template<typename T, typename U> void operator++(pair<T, U>& p){p.first++, p.second++;}//pre
template<typename T, typename U> void operator++(pair<T, U>& p, int){p.first++, p.second++;}//post
template<class T,class U> struct std::hash<std::pair<T,U>>{size_t operator()(const std::pair<T,U> &p) const noexcept {return (std::hash<T>()(p.first)+1) ^ (std::hash<U>()(p.second)>>2);}};
template<typename T, unsigned long int sz> ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz> istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A){for(auto& a:A){a--;}}//pre
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A, int){for(auto& a:A){a--;}}//post
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A){for(auto& a:A){a++;}}//pre
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A, int){for(auto& a:A){a++;}}//post
template<typename T> ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T> istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T> void operator--(vector<T>& A){for(auto& a:A) a--;}//pre
template<typename T> void operator--(vector<T>& A, int){for(auto& a:A) a--;}//post
template<typename T> void operator++(vector<T>& A){for(auto& a:A) a++;}//pre
template<typename T> void operator++(vector<T>& A, int){for(auto& a:A) a++;}//post
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp

template <typename T>
struct Vec2T{
    vector<T> v;

    Vec2T():v(vector<T>(2)){}

    Vec2T(T x, T y):v(vector<T>(2)){
        v[0]=x; v[1]=y;
    }

    size_t size(){
        return v.size();
    }

    inline const T &operator[](int k) const{
        return (v[k]);
    }

    inline T &operator[](int k){
        return (v[k]);
    }

    ///行列同士の演算
    Vec2T &operator+=(const Vec2T& A){
        this->v[0] += A.v[0];
        this->v[1] += A.v[1];
        return (*this);
    }
    Vec2T operator+(const Vec2T& A){
        return (Vec2T(*this)+=A);
    }
    Vec2T &operator-=(const Vec2T& A){
        this->v[0] -= A.v[0];
        this->v[1] -= A.v[1];
        return (*this);
    }
    Vec2T operator-(const Vec2T& A){
        return (Vec2T(*this)-=A);
    }
    T outer_product(const Vec2T& A){
        return T(this->v[0]*A.v[1] - this->v[1]*A.v[0]);
    }
    T inner_product(const Vec2T& A){
        return T(this->v[0]*A.v[0] + this->v[1]*A.v[1]);
    }

    ///行列とスカラーの演算
    Vec2T &operator+=(const T& a){
        this->v[0] += a;
        this->v[1] += a;
        return (*this);
    }
    Vec2T operator+(const T& a){
        return (Vec2T(*this)+=a);
    }
    Vec2T &operator-=(const T& a){
        this->v[0] -= a;
        this->v[1] -= a;
        return (*this);
    }
    Vec2T operator-(const T& a){
        return (Vec2T(*this)-=a);
    }
    Vec2T &operator*=(const T& a){
        this->v[0] *= a;
        this->v[1] *= a;
        return (*this);
    }
    Vec2T operator*(const T& a){
        return (Vec2T(*this)*=a);
    }
    Vec2T &operator/=(const T& a){
        this->v[0] /= a;
        this->v[1] /= a;
        return (*this);
    }
    Vec2T operator/(const T& a){
        return (Vec2T(*this)/=a);
    }


    ///回転演算
    Vec2T rotate_rad(const T& a){
        return Vec2T(
            this->v[0]*cos(a) - this->v[1]*sin(a),
            this->v[0]*sin(a) + this->v[1]*cos(a)
        );
    }
    Vec2T rotate_deg(T a){
        a = a * M_PI / 180;
        return Vec2T(
            this->v[0]*cos(a) - this->v[1]*sin(a),
            this->v[0]*sin(a) + this->v[1]*cos(a)
        );
    }

    //ノルム
    double norm(){
        return sqrt(v[0]*v[0]+v[1]*v[1]);
    }

    //角度
    double angle_rad(Vec2T& A){
        return asin((double)((*this).outer_product(A))/(*this).norm()/A.norm());
    }

    double angle_deg(Vec2T& A){
        return asin((double)((*this).outer_product(A))/(*this).norm()/A.norm())*180/M_PI;
    }

    ///比較演算
    bool operator<(const Vec2T& A){
        if(this->v[0]!=A.v[0]) return (this->v[0]<A.v[0]);
        return (this->v[1]<A.v[1]);
    }
    bool operator==(const Vec2T& A){
        if(this->v[0]!=A.v[0]) return false;
        if(this->v[1]!=A.v[1]) return false;        
        return true;
    }

    //入出力
    friend istream &operator>>(istream &is, Vec2T<T> &vec) {
        is>>vec.v[0]>>vec.v[1];
        return is;
    }
    friend ostream &operator<<(ostream &os,const Vec2T<T> &vec) {
        os<<vec.v[0]<<" "<<vec.v[1];
        return os;
    }

    ///2点間直線の唯一性評価用 dx,dy
    vector<T> info(){
        T dx = this->v[0];
        T dy = this->v[1];

        if(dx==0 && dy==0){}
        else if(dx==0) dy = 1;
        else if(dy==0) dx = 1;
        else{
            T GCD = gcd(dx, dy);
            dx /= GCD;
            dy /= GCD;
        }

        vector<T> ret(2);//dx, dy
        ret[0] = dx;
        ret[1] = dy;
        return ret;
    }


    //直線A->Bへの垂線ベクトル
    //    A + s*AB = C + t*P
    //<=> s*AB - t*p = A-C
    Vec2T<double> perpend(Vec2T& A, Vec2T& B){
        Vec2T AB = B-A;
        Vec2T p = AB;
        swap(p.v[0], p.v[1]);
        p.v[1] *= -1;

        Vec2T R = A-(*this);
        double det = -(AB[0]*p[0]) + AB[1]*p[1];
        if(det==0) return Vec2T<double>(0,0);


        double t;
        t = (-p[0]*R[0] + p[1]*R[1])/det;

        Vec2T<double> tP(p[0]*t, p[1]*t);

        return tP;
    }
};

// Vec2T<int> A(0,0);
// Vec2T<int> B(5,0);
// Vec2T<int> O(0,0);

// auto C = A+B;
// EL(C)
// EL(A.outer_product(B))//外積，面積
// EL(A.inner_product(B))//内積
// EL((A-O).outer_product(B-O))//外積，面積
// EL((A-O).info())
// EL(A.norm())
// EL(A.angle_deg(B))
// EL(B.angle_deg(A))
// auto p = O.perpend(A, B);
// EL(p.v)
// EL(O.perpend(A,B).v)




// Vec2T<double> a; cin>>a;
// Vec2T<double> e(1., 0.);//x方向 単位ベクトル
// Vec2T<double> f = e.rotate_rad(M_PI/4);//45度回転
// Vec2T<double> g = e.rotate_deg(90);////90度回転
// EL(f)
// EL(g)
// EL(e==a)

#define endl "\n"

void solve() {

   ld A,B; cin>>A>>B;
   ld H,M; cin>>H>>M;
   Vec2T<ld> L(0., 1.);
   Vec2T<ld> S(0., 1.);

   L *= B;
   S *= A;

   EL(S.rotate_deg(90))

   L = L.rotate_deg(-360. * (M / 60.));
   S = S.rotate_deg(-360. * (H / 12. + M/60/12));

   EL(L)
   EL(S)

   EL(L.norm())
   EL(S.norm())

   EL((L-S))

   //EL((hypot(L.norm(), S.norm())))

   PL((L-S).norm())

   EL((L+S).norm())
   EL(L)
   EL(S)

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
