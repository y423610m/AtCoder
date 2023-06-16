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
template<class T,class U> struct std::hash<std::pair<T,U>>{size_t operator()(const std::pair<T,U> &p) const noexcept {return (std::hash<T>()(p.first)+1) ^ (std::hash<U>()(p.second)>>2);}};
template<typename T, unsigned long int sz> ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz> istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A){for(auto& a:A){a--;}}//pre
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A, int){for(auto& a:A){a--;}}//post
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A){for(auto& a:A){a++;}}//pre
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A, int){for(auto& a:A){a++;}}//post
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp


template<typename T=int, typename U=int>
struct UnorderedMapWeightSumUnionFind{
    unordered_set<T> st;
    unordered_map<T,T> par;
    unordered_map<T,int> sz;
    unordered_map<T,U> weight;

    UnorderedMapWeightSumUnionFind(int N=1){
        st.reserve(N);
        par.reserve(N);
        sz.reserve(N);
        weight.reserve(N);
    }

    void check(T a){
        if(st.find(a)==st.end()){
            st.insert(a);
            par[a] = a;
            sz[a] = 1;
            weight[a] = 0;
        }
    }

    T leader(T x, bool first = true){
        if(first) check(x);
        if(par[x]==x) return x;
        T l = leader(par[x], false);
        return par[x] = l;
    }

    T& operator[](int i){
        check(i);
        return weight[i];
    }

    const T& operator[](int i)const{
        check(i);
        return weight[i];
    }

    bool same(T a, T b){
        return leader(a)==leader(b);
    }

    bool merge(T x, T y){
        x = leader(x);
        y = leader(y);
        if(x==y) return false;
        if(sz[x]<sz[y]) swap(x,y);
        par[y] = x;
        sz[x] += sz[y];
        weight[x] += weight[y];
        return true;
    }

    size_t size(){
        return st.size();
    }

    int size(T x){
        check(x);
        return sz[leader(x,false)];
    }
    /*
    頂点型，重み型
    UnorderedMapWeightSumUnionFind<int, int> uf(N*3);//reserve数
    if(!uf.same(x,y))uf.merge(x,y);
    EL(uf.size())//全体
    EL(uf.size(x))//xの属するサイズ
    EL(uf.leader(x))//xのリーダー．新規，単体は-1を返す
    for(auto x:uf.st)//含まれてる頂点走査
    uf[x] = 1;
    ABC277C
    */
};

void solve() {

    ll N,M; cin>>N>>M;
    UnorderedMapWeightSumUnionFind<int, int> uf(N);
    rep(i,M){
        ll u,v;
        cin>>u>>v;
        u--, v--;
        uf.merge(u,v);
        uf[uf.leader(u)]++;
    }

    rep(i,N){
        if(uf.size(i)!=uf[uf.leader(i)]) END("No")
    }
    PL("Yes")

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
