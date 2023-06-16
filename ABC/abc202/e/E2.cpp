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


#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> children, List;
std::vector<int> in, out, depth;
int timer;

void dfs(const int u) {
    in[u] = timer++;
    List[depth[u]].push_back(in[u]);
    for (const int v : children[u]) {
        depth[v] = depth[u] + 1;
        dfs(v);
    }
    out[u] = timer++;
}

int main() {
    int N;
    std::cin >> N;
    children = List = std::vector<std::vector<int>>(N);
    in = out = depth = std::vector<int>(N);
    for (int i = 1; i < N; ++i) {
        int p;
        std::cin >> p;
        children[p - 1].push_back(i);
    }
    dfs(0);
    int Q;
    std::cin >> Q;
    while (Q--) {
        int u, d;
        std::cin >> u >> d;
        u -= 1;
        const auto& v = List[d];
        std::cout << std::lower_bound(v.cbegin(), v.cend(), out[u]) - std::lower_bound(v.cbegin(), v.cend(), in[u]) << '\n';
    }
    EL(in)
    EL(out)
    return 0;
}
