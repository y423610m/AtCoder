#include <bits/stdc++.h>
using namespace std;

const int MOD = 998'244'353;
//const int MOD = 1000'000'007;

const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
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
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    V<string> s(3); cin>>s;
    rep(i,3) reverse(ALL(s[i]));

    if(max(s[0].size(), s[1].size())>s[2].size()) END("UNSOLVABLE")

    int K = 0;
    rep(i,3) chmax(K, s[i].size());

    V<int> val(256, -1);
    rep(i,10) val['0'+i] = i;

    V<int> sum(K+1);

    V<int> ans;

    V<bool> used(10);

    bool found = false;


    auto dfs = [&](auto dfs, int keta)->void{
        if(keta==K){
            if(sum[K]==0) ans = val;
            found = true;
            return;
        }

        V<int> v(3);
        for(v[0]=0;v[0]<10;v[0]++){
            if(s[0].size()<=keta&&v[0]!=0) continue;
            if(keta<s[0].size()&&val[s[0][keta]]!=-1&&val[s[0][keta]]!=v[0]) continue;
            bool ori_used0 = used[v[0]];
            if(keta<s[0].size() && used[v[0]] && val[s[0][keta]]!=v[0]) continue;
            used[v[0]] = true;
            
            for(v[1]=0;v[1]<10;v[1]++){
                if(s[1].size()<=keta&&v[1]!=0) continue;
                if(keta<s[1].size()&&val[s[1][keta]]!=-1&&val[s[1][keta]]!=v[1]) continue;
                bool ori_used1 = used[v[1]];
                if(keta<s[1].size() && used[v[1]] && val[s[1][keta]]!=v[1]) continue;
                used[v[1]] = true;

                for(v[2]=0;v[2]<10;v[2]++){
                    if(s[2].size()<=keta&&v[2]!=0) continue;
                    if(keta<s[2].size()&&val[s[2][keta]]!=-1&&val[s[2][keta]]!=v[2]) continue;
                    bool ori_used2 = used[v[2]];
                    if(keta<s[2].size() && used[v[2]] && val[s[2][keta]]!=v[2]) continue;
                    used[v[2]] = true;

                    if((v[0]+v[1]+sum[keta])%10!=v[2]) continue;

                    bool ng = false;
                    
                    V<int> ori(3);
                    rep(i,3) if(keta<s[i].size()){
                        ori[i] = val[s[i][keta]];
                        val[s[i][keta]] = v[i];
                    }
                    
                    if(v[0]+v[1]>=10) sum[keta+1]++;
                    dfs(dfs, keta+1);
                    if(v[0]+v[1]>=10) sum[keta+1]--;

                    rep(i,3) if(keta<s[i].size()){
                        ori[i] = val[s[i][keta]];
                        val[s[i][keta]] = ori[i];
                    }
                    used[v[2]] = ori_used2;
                }
                used[v[1]] = ori_used1;
            }
            used[v[0]] = ori_used0;
        }
    };

    dfs(dfs, 0);

    rep(i,3) reverse(ALL(s[i]));

    rep(i,3){
        rep(j,s[i].size()){
            cout<<val[s[i][j]];
        }
        cout<<endl;
    }


    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
