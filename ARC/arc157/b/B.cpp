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

vector<pair<char, int>> RLE(const string& s){
    vector<pair<char, int>> ret;
    for(int i=0;i<(int)s.size();i++){
        if(ret.size()==0) ret.push_back({s[i],1});
        else if(ret.back().first==s[i]) ret.back().second++;
        else ret.push_back({s[i], 1});
    }
    return ret;
}

template <typename T>
vector<pair<T, int>> RLE(const vector<T>& vec){
    vector<pair<T, int>> ret;
    for(int i=0;i<(int)vec.size();i++){
        if(ret.size()==0) ret.push_back({vec[i],1});
        else if(ret.back().first==vec[i]) ret.back().second++;
        else ret.push_back({vec[i], 1});
    }
    return ret;    
}

void solve() {

    ll N,K; cin>>N>>K;
    string S; cin>>S;

    ll cntX = 0;
    ll cntY = 0;


    //i文字目を変更したときの，変化数
    pq<array<ll,3>> que;
    V<bool> changed(N);
    V<ll> last(N);
    rep(i,N){
        ll cnt = 0;
        if(S[i]=='X'){
            if(i-1>=0&&S[i-1]=='Y') cnt++;
            if(i+1<N&&S[i+1]=='Y') cnt++;
        }
        else{
            if(i-1>=0&&S[i-1]=='Y') cnt--;
            if(i+1<N&&S[i+1]=='Y') cnt--;
        }
        que.push({cnt, S[i]=='X',i});
        last[i] = cnt;
    }

    while(!que.empty()){
        if(K==0) break;

        auto [cnt, x, i] = que.top(); que.pop();
        if(changed[i]) continue;
        if(cnt!=last[i]) continue;
        changed[i] = true;
        if(S[i]=='X') S[i] = 'Y';
        else S[i] = 'X';
        K--;
        if(K==0) break;
        ES(cnt) EL(S)
        
        ll id = i-1;
        cnt = 0;
        if(0<=id&&id<N&&!changed[id]){
            if(S[id]=='X'){
                if(id-1>=0&&S[id-1]=='Y') cnt++;
                if(id+1<N&&S[id+1]=='Y') cnt++;
            }
            else{
                if(id-1>=0&&S[id-1]=='Y') cnt--;
                if(id+1<N&&S[id+1]=='Y') cnt--;
            }
            last[id] = cnt;
            que.push({cnt, S[i]=='X',id});
        }
        id = i+1;
        cnt = 0;
        if(0<=id&&id<N&&!changed[id]){
            if(S[id]=='X'){
                if(id-1>=0&&S[id-1]=='Y') cnt++;
                if(id+1<N&&S[id+1]=='Y') cnt++;
            }
            else{
                if(id-1>=0&&S[id-1]=='Y') cnt--;
                if(id+1<N&&S[id+1]=='Y') cnt--;
            }
            last[id] = cnt;
            que.push({cnt, S[i]=='X',id});
        }
    }

    
    ll ans = 0;
    rep(i,N-1) if(S[i]=='Y'&&S[i+1]=='Y') ans++;
    PL(ans)
    EL(S)
    EL(K)


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
