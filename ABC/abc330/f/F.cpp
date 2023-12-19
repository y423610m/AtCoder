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


//mint


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
template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream&, const std::tuple<T...>&){}
template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream& os, const std::tuple<T...>& tup){if (n != 0){os << " ";} os << std::get<n>(tup); print_tuple<n+1>(os, tup);}
template <typename... T> std::ostream& operator<<(std::ostream& os, const std::tuple<T...>& tup) {print_tuple<0>(os, tup); return os;}
template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type input_tuple(std::istream& is, std::tuple<T...>&){}
template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type input_tuple(std::istream& is, std::tuple<T...>& tup){is>> std::get<n>(tup); input_tuple<n+1>(is, tup);}
template <typename... T> std::istream& operator>>(std::istream& is, std::tuple<T...>& tup) {input_tuple<0>(is, tup); return is;}
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

#if __has_include(<atcoder/segtree>)
#include <atcoder/segtree>
using namespace atcoder;
template<typename T> T opMax(T a, T b){return max(a,b);}
template<typename T> T opMin(T a, T b){return min(a,b);}
template<typename T> T opSum(T a, T b){return a+b;}
template<typename T> T e0(){return T(0);}
template<typename T> T e_LINF(){return -LINF;}
template<typename T> T eLINF(){return LINF;}

template<typename T=ll> using RMQ = segtree<T, opMax<T>, e_LINF<T>>;//Range Max Query
template<typename T=ll> using RmQ = segtree<T, opMin<T>, eLINF<T>>;// RmQ tree(vec); tree.prod(l,r)
template<typename T=ll> using RSQ = segtree<T, opSum<T>, e0<T>>;

ll seg_target;
bool f(ll vi){return vi<seg_target;}//seg.max_right<f>(x-1)
bool f2(ll vi){return vi>=seg_target;}//seg.max_right<f>(x-1)
//max_right<f>(l):=>[l:N)でfを満たす右端．
//min_left<f>(r):=>[0:r)でfを満たす左端．
//f(e)=trueでなければならない
//RMQ<ll> tree(N);
//tree.set(i,0);
//tree.get(i);
//tree.prod(l,r);//半開区間
#endif

template<typename T, typename F>
T binSearch(T ok, T ng, F check){
   while(abs(ok-ng)>1){
       T mid = (ok+ng)/2;
       if(check(mid)) ok=mid;
       else ng=mid;
   }
   return ok;
}



#define endl "\n"

void solve() {

   ll N,K; cin>>N>>K;
   V<Pll> XY(N); cin>>XY;
   V<ll> X(N), Y(N);
   rep(i,N) X[i]=XY[i].fi;
   rep(i,N) Y[i]=XY[i].se;
   sort(ALL(X));
   sort(ALL(Y));
   V<ll> revX(N), revY(N);
   rep(i,N) revX[i]=INF-X[i];
   rep(i,N) revY[i]=INF-Y[i];
   sort(ALL(revX));
   sort(ALL(revY));
   // multiset<ll> stX,stY;
   // rep(i,N){
   //    stX.insert(XY[i].fi);
   //    stY.insert(XY[i].se);
   // }

   // RSQ<ll> segX(N);
   // RSQ<ll> segY(N);
   // rep(i,N) segX.set(i, X[i]);
   // rep(i,N) segY.set(i, Y[i]);
   // RSQ<ll> revsegX(N);
   // RSQ<ll> revsegY(N);
   // rep(i,N) revsegX.set(i, revX[i]);
   // rep(i,N) revsegY.set(i, revY[i]);

   V<ll> acX(N+1), acY(N+1);
   rep(i,N) acX[i+1] = acX[i]+X[i];
   rep(i,N) acY[i+1] = acY[i]+Y[i];
   V<ll> acrevX(N+1), acrevY(N+1);
   rep(i,N) acrevX[i+1] = acrevX[i]+revX[i];
   rep(i,N) acrevY[i+1] = acrevY[i]+revY[i];

   V<ll> LN(N), RN(N);



   if(N==1) END(0);


   auto check = [&](auto l){
      V<ll> cnt(2, LINF);
      rep(isRev, 2) rep(isY,2){
         V<ll>& Z = isRev?( isY? revY : revX ): isY? Y : X;
         // RSQ<ll>& seg = isRev?( isY? revsegY : revsegX ): isY? segY : segX;
         V<ll>& ac = isRev?( isY? acrevY : acrevX ): isY? acY : acX;
         rep(i,N){
            ll cand = 0;

            //costL
            auto ln = lower_bound(ALL(Z), Z[i]) - Z.begin();
            cand += ln*Z[i] - (ac[ln]-ac[0]);

            //costR
            auto rn = upper_bound(ALL(Z), Z[i]+l) - Z.begin();
            cand += (ac[N]-ac[rn]) - (N-rn)*(Z[i]+l);

            chmin(cnt[isY], cand);
         }
      }

      if(cnt[0]+cnt[1]<=K) return true;
      return false;
   };

   auto ans = binSearch(INF, -1LL, check);
   PL(ans)

   return;
}


void solve1() {

   ll N,K; cin>>N>>K;
   V<Pll> XY(N); cin>>XY;
   V<ll> X(N), Y(N);
   rep(i,N) X[i]=XY[i].fi;
   rep(i,N) Y[i]=XY[i].se;
   sort(ALL(X));
   sort(ALL(Y));
   V<ll> revX(N), revY(N);
   rep(i,N) revX[i]=INF-X[i];
   rep(i,N) revY[i]=INF-Y[i];
   sort(ALL(revX));
   sort(ALL(revY));
   // multiset<ll> stX,stY;
   // rep(i,N){
   //    stX.insert(XY[i].fi);
   //    stY.insert(XY[i].se);
   // }

   // RSQ<ll> segX(N);
   // RSQ<ll> segY(N);
   // rep(i,N) segX.set(i, X[i]);
   // rep(i,N) segY.set(i, Y[i]);
   // RSQ<ll> revsegX(N);
   // RSQ<ll> revsegY(N);
   // rep(i,N) revsegX.set(i, revX[i]);
   // rep(i,N) revsegY.set(i, revY[i]);

   V<ll> acX(N+1), acY(N+1);
   rep(i,N) acX[i+1] = acX[i]+X[i];
   rep(i,N) acY[i+1] = acY[i]+Y[i];
   V<ll> acrevX(N+1), acrevY(N+1);
   rep(i,N) acrevX[i+1] = acrevX[i]+revX[i];
   rep(i,N) acrevY[i+1] = acrevY[i]+revY[i];

   if(N==1) END(0);


   auto check = [&](auto l){
      V<ll> cnt(2, LINF);
      rep(isRev, 2) rep(isY,2){
         V<ll>& Z = isRev?( isY? revY : revX ): isY? Y : X;
         // RSQ<ll>& seg = isRev?( isY? revsegY : revsegX ): isY? segY : segX;
         V<ll>& ac = isRev?( isY? acrevY : acrevX ): isY? acY : acX;
         rep(i,N){
            ll cand = 0;

            //costL
            auto ln = lower_bound(ALL(Z), Z[i]) - Z.begin();
            // cand += ln*Z[i] - seg.prod(0, ln);
            cand += ln*Z[i] - (ac[ln]-ac[0]);

            //costR
            auto rn = upper_bound(ALL(Z), Z[i]+l) - Z.begin();
            cand += (ac[N]-ac[rn]) - (N-rn)*(Z[i]+l);
            // cand += seg.prod(rn, N) - (N-rn)*(Z[i]+l);

            chmin(cnt[isY], cand);
            // ES(l) ES(isY) ES(cand) EL("")
         }
      }

      if(cnt[0]+cnt[1]<=K) return true;
      return false;
   };

   auto ans = binSearch(INF, -1LL, check);
   PL(ans)

   return;
}


void solve2() {

   ll N,K; cin>>N>>K;
   V<Pll> XY(N); cin>>XY;
   V<ll> X(N), Y(N);
   rep(i,N) X[i]=XY[i].fi;
   rep(i,N) Y[i]=XY[i].se;
   sort(ALL(X));
   sort(ALL(Y));
   V<ll> revX(N), revY(N);
   rep(i,N) revX[i]=INF-X[i];
   rep(i,N) revY[i]=INF-Y[i];
   sort(ALL(revX));
   sort(ALL(revY));
   multiset<ll> stX,stY;
   rep(i,N){
      stX.insert(XY[i].fi);
      stY.insert(XY[i].se);
   }

   RSQ<ll> segX(N);
   RSQ<ll> segY(N);
   rep(i,N) segX.set(i, X[i]);
   rep(i,N) segY.set(i, Y[i]);
   RSQ<ll> revsegX(N);
   RSQ<ll> revsegY(N);
   rep(i,N) revsegX.set(i, revX[i]);
   rep(i,N) revsegY.set(i, revY[i]);

   if(N==1) END(0);


   auto check = [&](auto l){
      V<ll> cnt(2, LINF);
      rep(isRev, 2) rep(isY,2){
         V<ll>& Z = isRev?( isY? revY : revX ): isY? Y : X;
         RSQ<ll>& seg = isRev?( isY? revsegY : revsegX ): isY? segY : segX;

         rep(i,N){
            ll cand = 0;

            //costL
            auto ln = lower_bound(ALL(Z), Z[i]) - Z.begin();
            cand += ln*Z[i] - seg.prod(0, ln);

            //costR
            auto rn = upper_bound(ALL(Z), Z[i]+l) - Z.begin();
            cand += seg.prod(rn, N) - (N-rn)*(Z[i]+l);

            chmin(cnt[isY], cand);
            ES(l) ES(isY) ES(cand) EL("")
         }
      }

      if(cnt[0]+cnt[1]<=K) return true;
      return false;
   };

   auto ans = binSearch(INF, -1LL, check);
   PL(ans)

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
ABC330 6完
A for
B clamp
C x,y<=1e7程度まで列挙して二分探索．
D 各行列のoを数えて，交差してるマスを全探索
E 答えは必ずN以下．Minセグ木をN+1以上確保．セグ木のi番目に±N+2で更新した．
F 辺の長さLで二分探索．左端or右端を固定して，必要な操作回数確認．セグ木だとTLEだったので累積和でAC.
O(Nlog(N)log(L))
*/