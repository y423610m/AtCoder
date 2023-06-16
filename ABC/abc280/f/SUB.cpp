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

/*
parent_or_size
*/
// template<class T> struct WeightedUnionFind {
//     vector<int> par;
//     vector<int> rank;
//     vector<T> diff_weight;

//     WeightedUnionFind(int n = 1)
//     :par(n,-1), rank(n,0), diff_weight(n,0)
//     {}

//     int leader(int x) {
//         if (par[x] == -1) {
//             return x;
//         }
//         else {
//             int r = leader(par[x]);
//             diff_weight[x] += diff_weight[par[x]];
//             return par[x] = r;
//         }
//     }

//     T weight(int x) {
//         leader(x);
//         return diff_weight[x];
//     }

//     bool same(int x, int y) {
//         return leader(x) == leader(y);
//     }

//     bool merge(int x, int y, T w) {
//         w += weight(x); w -= weight(y);
//         x = leader(x); y = leader(y);
//         if (x == y) return false;
//         if (rank[x] < rank[y]) swap(x, y), w = -w;
//         if (rank[x] == rank[y]) ++rank[x];
//         par[y] = x;
//         diff_weight[y] = w;
//         return true;
//     }

//     T diff(int x, int y) {
//         return weight(y) - weight(x);
//     }
//     /*
//     WeightedUnionFind<ll> tree(N);
//     if(!tree.same(x,y)) tree.merge(x,y,w);// weight[y] = weight[x]+w;
//     tree.leader();
//     tree.diff(x,y);//weight(y)-weight(x);
//     abc277 D2
//     */
// };

template<class T> struct WeightedUnionFind {
    vector<int> par;
    vector<int> sz;
    vector<T> diff_weight;

    WeightedUnionFind(int n = 1)
    :par(n,-1), sz(n,1), diff_weight(n,0)
    {}

    int leader(int x) {
        if (par[x] == -1) {
            return x;
        }
        else {
            int l = leader(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = l;
        }
    }

    T weight(int x) {
        leader(x);
        return diff_weight[x];
    }

    bool same(int x, int y) {
        return leader(x) == leader(y);
    }

    bool merge(int x, int y, T w) {
        w += weight(x); w -= weight(y);
        x = leader(x); y = leader(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y), w = -w;
        sz[x] += sz[y];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    T diff(int x, int y) {
        return weight(y) - weight(x);
    }

    int size(){
        return sz.size();
    }

    int size(int i){
        return sz[leader(i)];
    }

    /*
    WeightedUnionFind<ll> tree(N);
    if(!tree.same(x,y)) tree.merge(x,y,w);// weight[y] = weight[x]+w;
    tree.leader();
    tree.diff(x,y);//weight(y)-weight(x);
    abc277 D2
    */
};
/*
WeightedUnionFind<ll> tree(N);
if(!tree.same(x,y)) tree.merge(x,y,w);// weight[y] = weight[x]+w;
tree.leader();
tree.diff(x,y);//weight(y)-weight(x);
abc280 F
*/

void solve() {

    ll N,M,Q; cin>>N>>M>>Q;
    WeightedUnionFind<ll> uf(N+1);

    rep(i,M){
        ll a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        if(uf.same(a,b)&&uf.diff(a,b)!=c){
            ES(i) ES(uf.par[a]) EL(uf.par[b])
            uf.merge(a,N,0);
        }
        uf.merge(a,b,c);
    }

    rep(i,N+1){
        ES(i) ES(uf.weight(i)) EL(uf.par[i])
    }

    rep(q,Q){
        ll x,y;
        cin>>x>>y;
        x--, y--;
        if(!uf.same(x,y)) PL("nan")
        else if(uf.same(x,N)) PL("inf")
        else PL(uf.diff(x,y))
    }

    return;
}


template<typename T=int, typename U=int>
struct UnorderedMapWeightedUnionFind{
    unordered_set<T> st;
    unordered_map<T,T> par;
    unordered_map<T,int> sz;
    unordered_map<T,U> diff_weight;

    UnorderedMapWeightedUnionFind(int N=1){
        st.reserve(N);
        par.reserve(N);
        sz.reserve(N);
        diff_weight.reserve(N);
    }

    void check(T a){
        if(st.find(a)==st.end()){
            st.insert(a);
            par[a] = a;
            sz[a] = 1;
            diff_weight[a] = 0;
        }
    }

    T leader(T x, bool first = true){
        if(first) check(x);
        if(par[x]==x) return x;
        T l = leader(par[x], false);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = l;
    }

    U weight(T x){
        leader(x);
        return diff_weight[x];
    }

    U& operator[](T i){
        check(i);
        return diff_weight[i];
    }

    const U& operator[](T i)const{
        check(i);
        return diff_weight[i];
    }

    bool same(T a, T b){
        return leader(a)==leader(b);
    }

    bool merge(T x, T y, U w){
        w += weight(x); w -= weight(y);
        x = leader(x);
        y = leader(y);
        if(x==y) return false;
        if(sz[x]<sz[y]) swap(x,y), w = -w;
        par[y] = x;
        sz[x] += sz[y];
        diff_weight[y] = w;
        return true;
    }

    U diff(T x, T y) {
        return weight(y) - weight(x);
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
/*
UnorderedMapWeightedUnionFind<ll,ll> tree(N);//頂点，重み型
if(!tree.same(x,y)) tree.merge(x,y,w);// weight[y] = weight[x]+w;
tree.leader();
tree.diff(x,y);//weight(y)-weight(x);
abc280 F
*/
void solve2() {

    ll N,M,Q; cin>>N>>M>>Q;
    UnorderedMapWeightedUnionFind<ll, ll> uf(N);
    //rep(i,N+1) uf[i] = 0;

    rep(i,M){
        ll a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        if(uf.same(a,b)&&uf.diff(a,b)!=c){
            ES(i) ES(uf.par[a]) ES(uf.par[b]) EL(uf.diff(a,b))
            uf.merge(a,N,0);
        }
        uf.merge(a,b,c);
    }

    rep(i,N+1){
        ES(i) ES(uf.weight(i)) EL(uf.par[i])
    }

    rep(q,Q){
        ll x,y;
        cin>>x>>y;
        x--, y--;
        if(!uf.same(x,y)) PL("nan")
        else if(uf.same(x,N)) PL("inf")
        else PL(uf.diff(x,y))
    }

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
    for(int tt = 0; tt<TT; tt++) solve2();
    return 0;
}