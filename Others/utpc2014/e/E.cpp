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
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp

#include "structure/trie/trie.hpp"
/*
    Trie<26, 'a'> tr;
    id[i] = tr.insert(S[i]);//追加．第二引数に文字列のidを指定もできる（S[i]のi）
    id = tr.lcp_id(s[i], s[j]);//共通接頭辞の末尾id
    len = tr.lcp_len(s[i], s[j]);//共通接頭辞の長さ
    t = tr.lcp_string(s[i], s[j]);//共通接頭辞返す
    t = tr.create_string(id);//idまでの文字列返す
    id = tr.find(S[i]);//構築せず，既存で進めるだけ進む．depthと文字列の長さが等しければ，構築済み．
    id = tr.Kth_element(k);//insertされた要素のうち，辞書順k番目の要素の末尾id.0-indexed
    k = tr.is_Kth(s[i]);//もしinsertされたら辞書順何番目か？
    int shared = tr[id].shared;//いくつの文字列がその頂点通ったか．その頂点で終わっていたら加算されていない．
    vector<int>& accept = tr[id].accept;//その頂点で終わった文字列のid．
    //insert以外は加算しない．
    //findは構築もしない
    //その他は構築だけする．

    //中身を辿るとき
    p = tr.proceed(str);
    while(p!=0){
        p = tr[p].parent;
        //val, parent, children[char_size], depth, shared, vector::accept
        children[c]は存在しなければ-1,そうでなければid
    }
    AGC047B
*/

void solve() {

    ll N; cin>>N;
    V<string> A(N);
    V<ll> B(N);
    rep(i,N) cin>>A[i]>>B[i];
    rep(i,N) reverse(ALL(A[i]));

    Trie<10, '0'> tr;
    V<ll> id(N);
    rep(i,N) id[i] = tr.proceed(A[i]);

    ll ans = 0;
    V<ll> Sum(tr.size());
    rep(i,N){
        ll b = B[i];
        auto dfs = [&](auto dfs, int p)-> void {
            Sum[p] += b;
            chmax(ans, Sum[p]);
            rep(i,10) if(tr[p].children[i]!=-1){
                ll to = tr[p].children[i];
                dfs(dfs, to);
            }
        };
        dfs(dfs, id[i]);

        PL(ans)
    }


    return;
}

void solve2() {

    ll N; cin>>N;
    V<string> A(N);
    V<ll> B(N);
    rep(i,N) cin>>A[i]>>B[i];
    rep(i,N) reverse(ALL(A[i]));

    Trie<10, '0'> tr;
    V<ll> id(N);
    rep(i,N) id[i] = tr.proceed(A[i]);

    /*
    oyaha,tadoreba yoi 
    -->kodomogawa no saidaiti hosii
    */

    ll ans = 0;
    //Sum[i]:=tyoutenn i no kodomo no naka de saidai no atai
    V<ll> Sum(tr.size());
    rep(i,N){

        tr.insert(A[i]);

        ll b = B[i];

        Sum[id[i]] += b;
        ll s = Sum[id[i]];

        
        int p = id[i];
        while(p!=0){
            p = tr[p].parent;
            for(auto i:tr[p].accept){
                s += B[i];
            }
            chmax(Sum[p], s);
        }

        PL(Sum[0])
    }


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
    for(int tt = 0; tt<TT; tt++) solve2();
    return 0;
}
