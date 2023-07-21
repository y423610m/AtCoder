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

template<typename T> 
vector<vector<double>> convert_double(vector<vector<T>>& A){
    vector<vector<double>> ret(A.size(), vector<double>(A[0].size()));
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A.size();j++)
            ret[i][j] = A[i][j];
    return ret;
}

template<typename T> 
vector<vector<int>> convert_int(vector<vector<T>>& A){
    vector<vector<int>> ret(A.size(), vector<double>(A[0].size()));
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A.size();j++)
            ret[i][j] = A[i][j]+0.1;
    return ret;
}


template <typename T>
vector<vector<T>> transpose(vector<vector<T>>& A){
    vector<vector<T>> B(A[0].size(), vector<T>(A.size()));
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A[0].size();j++)
            B[j][i] = A[i][j];
    return B;
}

template <typename T>
vector<vector<T>> prod(const vector<vector<T>>& A, const vector<vector<T>>& B){
    vector<vector<T>> C(A.size(), vector<T>(B[0].size()));
    for(int i=0;i<A.size();i++)
        for(int j=0;j<B[0].size();j++)
            for(int k=0;k<A[0].size();k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

template <typename T>
vector<T> prod(vector<vector<T>>& A, vector<T>& B){
    vector<T> C(A.size());
    for(int i=0;i<A.size();i++)
        for(int j=0;j<B.size();j++)
                C[i] += A[i][j] * B[j];
    return C;
}

template <typename T>
vector<vector<T>> I(int n){
    vector<vector<T>> retI(n, vector<T>(n));
    for(int i=0;i<n;i++) retI[i][i]=1;
    return retI;
}


template <typename T>
T det2T(vector<vector<T>>& A){
    if(A.size()!=2 || A[0].size()!=2){
        cerr<<"det2 size != 2"<<endl;
        return 0;
    }
    T d = 0;
    d += A[0][0]*A[1][1];
    d -= A[0][1]*A[1][0];
    return d;
}

template <typename T>
T det3T(vector<vector<T>>& A){
    if(A.size()!=3 || A[0].size()!=3){
        cerr<<"det3 size != 3"<<endl;
        return 0;
    }
    T d = 0;
    d += A[0][0]*A[1][1]*A[2][2];
    d += A[0][1]*A[1][2]*A[2][0];
    d += A[0][2]*A[1][0]*A[2][1];

    d -= A[0][0]*A[1][2]*A[2][1];
    d -= A[0][1]*A[1][0]*A[2][2];
    d -= A[0][2]*A[1][1]*A[2][0];

    return d;
}

template <typename T>
vector<vector<double>> inv2T(vector<vector<T>>& A){
    T det = det2T(A);
    if(det==0){
        cerr<<"inv2T: determinant==0"<<endl;
        return I<double>(2);
    }
    vector<vector<double>> inv = convert_double(A);

    swap(inv[0][0], inv[1][1]);
    inv[0][1] = -inv[0][1];
    inv[1][0] = -inv[1][0];
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A.size();j++)
            inv[i][j] /= det;
    return inv;
}

template <typename T>
vector<vector<double>> inv3T(vector<vector<T>>& A){
    T det = det3T(A);
    if(det==0){
        cerr<<"inv2T: determinant==0"<<endl;
        return I<double>(3);
    }
    vector<vector<double>> inv = convert_double(A);
    inv[0][0] =  A[1][1]*A[2][2] - A[1][2]*A[2][1];
    inv[0][1] = -A[0][1]*A[2][2] + A[0][2]*A[2][1];
    inv[0][2] =  A[0][1]*A[1][2] - A[0][2]*A[1][1];
    
    inv[1][0] = -A[1][0]*A[2][2] + A[1][2]*A[2][0];
    inv[1][1] =  A[0][0]*A[2][2] - A[0][2]*A[2][0];
    inv[1][2] = -A[0][0]*A[1][2] + A[0][2]*A[1][0];

    inv[2][0] =  A[1][0]*A[2][1] - A[1][1]*A[2][0];
    inv[2][1] = -A[0][0]*A[2][1] + A[0][1]*A[2][0];
    inv[2][2] =  A[0][0]*A[1][1] - A[0][1]*A[1][0];

    for(int i=0;i<A.size();i++)
        for(int j=0;j<A.size();j++)
            inv[i][j] /= det;
    return inv;
}

V<V<int>> A(2,V<int>(3));
//rep(i,2) rep(j,3) A[i][j] = i*3+j*5;
//
//rep(i,A.size()) EL(A[i])
//
//V<V<int>> B = transpose(A);
//rep(i,B.size()) EL(B[i])
//
//auto ans_seki = prod(A,B);
//rep(i,ans_seki.size()) EL(ans_seki[i])
//
//V<int> vec(3,1);
//vec[1] = 2; vec[2]=3;
//auto MatVec = prod(A, vec);
//rep(i,MatVec.size()) EL(MatVec[i])
//
//auto ans_seki_inv = inv2T(ans_seki);
//rep(i,ans_seki_inv.size()) EL(ans_seki_inv[i]) 
//auto AA = prod(convert_double(ans_seki), ans_seki_inv);
//rep(i,AA.size()) EL(AA[i])
//
//
//vector<vector<double>> A3 = {
//    {1,2,3},
//    {4,5,6},
//    {7,8,8}
//};
//auto A3A3 = prod(A3, inv3T(A3));
//rep(i,A3A3.size()) EL(A3A3[i])
//
//vector<vector<int>> test(3,vector<int>(3)); cin>>test;
//auto test_result = prod(convert_double(test), inv3T(test));
//test_result = inv3T(test);
//rep(i,test_result.size()) EL(test_result[i])


#define endl "\n"

void solve() {

   double x,y; cin>>x>>y;

   /*
      a+b=X
      2a+4b=Y
   */

   V<V<double>> A = {
      {1, 1},
      {2, 4}
   };

   if(det2T(A)==0) END(No)

   V<double> X = {x, y};

   auto invA = inv2T(A);
   vector<double> Y = prod(invA, X);
   if(Y[0]<0 || Y[1] < 0) END(No)

   PL(Yes)
   EL(Y)

   return;
}

void solve2(){
   ll X,Y; cin>>X>>Y;
   rep(a,101) rep(b,101){
      if(a+b==X && a*2+b*4==Y) END(Yes)
   }
   PL(No)
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);//小数点以下
   // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
   // stoll(s,nullptr,base);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
