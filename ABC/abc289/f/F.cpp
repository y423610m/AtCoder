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
template<typename T> using V = vector<T>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqr = priority_queue<T, vector<T>, greater<T>>;
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
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A){for(auto& a:A){a--;}}//pre
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A, int){for(auto& a:A){a--;}}//post
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A){for(auto& a:A){a++;}}//pre
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A, int){for(auto& a:A){a++;}}//post
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp



void solve() {

    ll sx, sy; cin>>sx>>sy;
    ll gx, gy; cin>>gx>>gy;

    if(sx==gx&&sy==gy){
        PL("Yes")
        return;
        // END(0)
    }


    ll N = 1000000;

    V<ll> Rx(2), Ry(2); cin>>Rx>>Ry;
    if(sx%2==0&&gx%2==1) END("No")
    if(sy%2==0&&gy%2==1) END("No")

    V<V<ll>> Px(N+1, V<ll>(2)), Py(N+1, V<ll>(2));
    Px[0] = {sx,sx};
    Py[0] = {sy,sy};

    rep(k, N){
        V<ll> Nx(2), Ny(2);
        Px[k+1] = {sx,sx};
        Py[k+1] = {sy,sy};

        rep(i,2) rep(j,2){
            ll x = Px[k][i] + (Rx[j] - Px[k][i])*2;
            chmin(Px[k+1][0], x);
            chmax(Px[k+1][1], x);
        }
        rep(i,2) rep(j,2){
            ll y = Py[k][i] + (Ry[j] - Py[k][i])*2;
            chmin(Py[k+1][0], y);
            chmax(Py[k+1][1], y);
        }

        ES(Px[k+1]) EL(Py[k+1])

        auto check = [&]()->bool {
            if(Px[k+1][0]<=gx&&gx<=Px[k+1][1] && Py[k+1][0]<=gy&&gy<=Py[k+1][1] ) return true;
            return false;
        };

        if(check()){
            PL("Yes")
            rep(l,k){

            }
        }

    }

    PL("No")

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


/*
ABC289 5完
A やる
B binary_searchとstack
C bit全探索．NとM逆にしてて2ぺナ
D シンプルなdp．binary_searchでBに含まれてなかったら更新．
E dp[i][j]:=高橋がi，青木がjにいる最短操作回数．C=0とC=1でグラフ２つ用意
F x,yは独立．到達可能かは，s,tの偶奇+長方形の角中心の移動のみ考えればできる（はず）．
復元がいい感じにできず．．．
*/