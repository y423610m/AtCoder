#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;
// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define endl "\n"
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
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

template <typename T> vector<T> CCompress(vector<T>& A){
   vector<T> B = A;
   sort(B.begin(), B.end());
   B.erase(unique(B.begin(), B.end()), B.end());
   for(int i=0;i<(int)A.size();i++){
      A[i] = (int)(lower_bound(B.begin(), B.end(), A[i]) - B.begin());
   }
   return B;
}
//vector<int> A = {1,100,5,5};
//auto B = CCompress(A);
//-> A={0,2,1,1}, B={1,5,100}

//重複を許さない座標圧縮．同じ数字は先出から割り振る
template<typename T>
void reorder(vector<T>& A){
    vector<T> B = A;
    sort(ALL(B));
    for(auto& a:A){
        auto it = lower_bound(B.begin(), B.end(), a);
        a = it - B.begin();
        (*it)--;
    }
}

//重複を許さない座標圧縮．同じ数字は後方から割り振る
template<typename T>
void reorder_rev(vector<T>& A){
    vector<T> B = A;
    sort(ALL(B));
    for(int i=A.size()-1;i>=0;i--){
        auto it = lower_bound(B.begin(), B.end(), A[i]);
        A[i] = it - B.begin();
        (*it)--;
    }
}

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
using namespace atcoder;
//dsu DSU(n);
//DSU.merge(a,b);
//if(DSU.same(a,b)){}
#endif

void solve() {

    ll N; cin>>N;

    V<Pll> AB(N); cin>>AB;

    V<ll> VAL;
    rep(i,N){
        VAL.push_back(AB[i].fi);
        VAL.push_back(AB[i].se);
    }
    VAL.push_back(1);
    VAL.push_back(1000000000);

    auto mp = CCompress(VAL);

    rep(i,N){
        AB[i].fi = VAL[i*2];
        AB[i].se = VAL[i*2+1];
    }

    int top = VAL.back();
    dsu tree(top+1);
    rep(i,N){
        tree.merge(AB[i].fi, AB[i].se);
    }

    int ans = 0;
    rep(i,top+1){
        if(tree.same(0,i)) ans = i;
    }

    PL(mp[ans])


    return;
}


void solve2(){
    ll N; cin>>N;
    V<Pll> AB(N); cin>>AB;


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
