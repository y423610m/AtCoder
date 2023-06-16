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



void solve() {

    ll N,M,K; cin>>N>>M>>K;
    V<ll> A(N); cin>>A;

    queue<ll> que;
    //ok:小さいほういれる
    multiset<ll> ok, ng;
    ll sum = 0;
    rep(i,N){
        
        que.push(A[i]);
        ok.insert(A[i]);
        sum += A[i];
        
        if(que.size()>M){
            //次除く数
            ll a = que.front(); que.pop();

            //ok,ngからaを除く
            {
                auto it = ok.find(a);
                if(it!=ok.end()){
                    ok.erase(it);
                    sum -= a;
                }
                else{
                    it = ng.find(a);
                    ng.erase(it);
                }
            }
        }

        while(ok.size()>K){
            auto it = prev(ok.end());
            ng.insert(*it);
            sum -= *it;
            ok.erase(it);
        }

        while(ok.size()<K&&ng.size()>0){
            auto it = ng.begin();
            ok.insert(*it);
            sum += *it;
            ng.erase(it);
        }

        if(1){
            auto it = prev(ok.end());
            sum -= *it;
            ng.insert(*it);
            ok.erase(it);

            it = ng.begin();
            sum += *it;
            ok.insert(*it);
            ng.erase(it);
        }

        if(que.size()==M) PS(sum)
        ES(i) ES(sum) ES(ok.size()) EL(ng.size())
    }
    PL("")

    return;
}


#include "structure/set/top_k_sum_multiset.hpp"
/*
TopKSumMultiSet<ll> Kst;//小さい方K
TopKSumMultiSet<ll,greater<ll>> Kst;//大きいほうK
Kst.insert(a);
Kst.erase(a);
EL(Kst.sumL);
EL(Kst.size());
EL(Kst.clear());
//ABC281E
*/
void solve2(){
    ll N,M,K;
    cin>>N>>M>>K;

    V<ll> A(N); cin>>A;
    TopKSumMultiSet<ll, less<ll>> Kst(K);
    queue<ll> que;
    rep(i,N){
        que.push(A[i]);
        Kst.insert(A[i]);
        if(que.size()>M){
            ll a = que.front(); que.pop();
            Kst.erase(a);
        }
        if(Kst.size()==M) PS(Kst.sumL)
    }
    PL("")
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
