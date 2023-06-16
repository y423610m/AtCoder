#line 1 "C.cpp"
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
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
template<typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

#line 2 "/mnt/c/Users/y4236/CPP/kyopro_library/structure/heap/middle_queue.hpp"

//中央値を求められるqueue. pair型で出力
template<typename T>
struct MiddleQueue{
    priority_queue<ll> L;
    priority_queue<ll,V<ll>,greater<ll>> R;
    MiddleQueue(T l, T r){
        L.push(l);
        R.push(r);
    }

    void push2(T x){
        L.push(x);
        R.push(L.top());
        L.pop();

        R.push(x);
        L.push(R.top());
        R.pop();
    }

    void push(T x){
        L.push(x);
        R.push(L.top());
        L.pop();
        L.push(R.top());
        R.pop();

        if(L.size()>R.size()+1){
            R.push(L.top());
            L.pop();
        }
    }

    void pop(){
        if(L.size()+R.size()==0) return;

        L.pop();
        if(L.size()<R.size()){
            L.push(R.top());
            R.pop();
        }
    }

    pair<T,T> top()const{
        return make_pair(L.top(), R.top());
    }

    size_t size()const{
        return L.size()+R.size();
    }

    bool empty()const{
        return (L.empty()||R.empty());
    }

    // MiddleQueue<ll> que(-LINF, LINF);
    // que.push(a);
    // que.push2(a);
    // que.pop();
    // pair<ll,ll> p = que.top(); 

};

#line 53 "C.cpp"
//MiddleQueue<ll> que(-LINF, LINF)
//que.push(a);//Nが偶数の時，小さいほう
//que.push2(a);//Nが偶数の時，中間値．pop非対応
//que.pop();
//pair<ll,ll> p = que.top();

void solve() {

    ll N; cin>>N;
    V<ll> A(N); cin>>A;
    rep(i,N) A[i] -= i+1;

    MiddleQueue<ll> que(-LINF, LINF);
    rep(i,N) que.push(A[i]);

    ll ans = 0;
    rep(i,N) ans += abs(A[i]-(que.top().fi));
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
