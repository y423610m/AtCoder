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

template<class T>
struct WeightUpdateUnionFind {
    vector<int> par;
    vector<int> sz;
    vector<T> weight;

    WeightUpdateUnionFind(int n = 1)
    :par(n,-1), sz(n,1), weight(n,T())
    {}

    int leader(int x) {
        if (par[x] == -1) {
            return x;
        }
        else {
            int r = leader(par[x]);
            return par[x] = r;
        }
    }

    T& operator[](int i){
        return weight[leader(i)];
    }

    const T& operator[](int i)const{
        return weight[leader(i)];
    }

    bool same(int x, int y) {
        return leader(x) == leader(y);
    }

    template<typename Cmp, typename F>
    bool merge(int x, int y, Cmp cmp, F f) {
        x = leader(x); y = leader(y);
        if (x == y) return false;
        // if (sz[x] < sz[y]) swap(x, y);
        if (!cmp(x,y)) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
        // weight[x] = f(weight[x], weight[y]);
        f(x, y);
        return true;
    }

    int size(){
        return sz.size();
    }

    int size(int i){
        return sz[leader(i)];
    }

    /*
    WeightUpdateUnionFind<ll> tree(N);
    rep(i,N) tree.setWeight(i,A[i]);
    auto f = [&](ll a, ll b)->ll {return a+b;};
    if(!tree.same(x,y)) tree.merge(x,y, f);
    tree.leader();
    tree.getWeight(x);
    abc277D2
    abc295G
    */
};


// void solve() {//AC

//     ll N, M; cin>>N>>M;
//     V<ll> A(N); cin>>A;
//     sort(ALL(A));
//     EL(A)

//     WeightedUnionFind<ll> tree(N);
//     rep(i,N-1) if(A[i]==A[i+1]||(A[i]+1)%M==A[i+1]) tree.merge(i, i+1, A[i+1]);
//     if((A[N-1]+1)%M==A[0]) tree.merge(N-1, 0, A[0]);

//     ll sum = 0;
//     rep(i,N) sum += A[i];

//     ll ans = LINF;
//     rep(i,N){
//         ES(i) ES(tree.leader(i)) EL(tree.diff(tree.leader(i), i)+A[tree.leader(i)])
//         chmin(ans, sum-(tree.diff(tree.leader(i), i)+A[tree.leader(i)]));
//     }
//     PL(ans)

//     return;
// }

void solve2(){//WA
    ll N, M; cin>>N>>M;
    V<ll> A(N); cin>>A;
    sort(ALL(A));
    EL(A)

    WeightUpdateUnionFind<ll> uf(N);

    auto cmp = [&](int parent, int child)->bool {return uf.sz[parent]>=uf.sz[child];};
    auto f = [&](int parent, int child)->ll {return uf.weight[parent] += uf.weight[child];};


    rep(i,N) uf[i] = A[i];
    rep(i,N-1) if(A[i]==A[i+1]||(A[i]+1)%M==A[i+1]) uf.merge(i, i+1, cmp, f);
    if((A[N-1]+1)%M==A[0]) uf.merge(N-1, 0, cmp, f);

    ll sum = 0;
    rep(i,N) sum += A[i];

    ll ans = LINF;
    rep(i,N){
        //ES(i) ES(tree.leader(i)) EL(tree.diff(tree.leader(i), i)+A[tree.leader(i)])
        chmin(ans, sum-uf[i]);
    }
    PL(ans)
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
