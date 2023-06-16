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
template <class T> using V = vector<T>;
template<typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, unsigned long int sz > ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz > istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<class T, class U > void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U > void chmax(T& t, const U& u) {if (t < u) t = u;}

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


void solve() {

    ll N; cin>>N;
    string S; cin>>S;
    // string T = S;
    // sort(ALL(S));
    string _S = S;
    sort(ALL(_S));
    EL(_S)

    V<ll> cnt(26);
    rep(i,N) cnt[S[i]-'a']++;

    set<ll> NG;
    rep(i,N-1) if(S[i]>S[i+1]) NG.insert(i);

    V<RSQ<ll>> trees(26,RSQ<ll>(N));
    rep(i,N) trees[S[i]-'a'].set(i,1);
    


    ll Q; cin>>Q;
    rep(_,Q){
        EL(_)
        ll q; cin>>q;
        if(q==1){
            ll x; cin>>x; x--;
            char c; cin>>c;
            char oc = S[x];
            cnt[oc-'a']--;
            cnt[c-'a']++;
            trees[oc-'a'].set(x,0);
            trees[c-'a'].set(x,1);
            S[x] = c;
            NG.erase(x);
            NG.erase(x-1);
            if(x-1>=0&&S[x-1]>S[x]) NG.insert(x-1);
            if(x+1<N&&S[x]>S[x+1]) NG.insert(x);
        }
        else{
            ll l,r; cin>>l>>r;
            l--;
            EL(S.substr(l,r-l))
            //1文字なら確定Yes
            if(l+1==r){
                EL(1)
                PL("Yes")
                continue;
            }
            {//Tが昇順じゃない
                auto it = NG.lower_bound(l);
                if(it!=NG.end()){
                    auto NGL = *(it);
                    if(NGL+1<r){
                        EL(2)
                        ES(l) ES(r) EL(NGL) 
                        PL("No")
                        continue;
                    }
                }
            }
            //先頭と末尾以外が同じ文字数じゃないといけない
            bool found = false;
            ll badCnt = 0;
            ll lastChar = -1;
            ll lastBadChar = -1;
            bool ok = true;
            bool skiped = false;
            
            EL(cnt)
            rep(c,26){
                ll lenT = trees[c].prod(l,r);
                ES(c) EL(lenT)
                if(lenT>0&&skiped){
                    ok = false;
                }
                if(found&&lenT==0&&cnt[c]){
                    skiped = true;
                }
                if(lenT==cnt[c]){
                    
                }
                if(found&&lenT>0&&lenT<cnt[c]){
                    badCnt++;
                    lastBadChar = c;
                }
                if(lenT>0){
                    found = true;
                    lastChar = c;
                }
            }

            if(badCnt>=2){
                ok = false;
                EL(38)
            }
            if(badCnt==1&&lastChar!=lastBadChar){
                ok = false;
                EL(39)
            }


            EL(3)
            if(ok) PL("Yes")
            else PL("No")
        }
    }


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
