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
#define NAME(a) #a
#define ES(a) cerr<<NAME(a)<<": "<<(a)<<" ";
#define EL(a) cerr<<NAME(a)<<": "<<(a)<<endl;
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
using P = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

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
    friend ostream &operator<<(ostream &os, Vec2T<T> &vec) {
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

// ostream &operator<<(ostream &os, Vec2T<T> &vec) {
//     os<<vec.v[0]<<" "<<vec.v[1];
//     return os;
// }

void solve() {

    int n; cin>>n;
    Vec2T<double> A; cin>>A;
    Vec2T<double> B; cin>>B;

    auto O = (A+B)/2;

    auto ans = O + (A-O).rotate_deg(360./n);
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
