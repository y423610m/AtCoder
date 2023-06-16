#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) if(1){PL(a) return;}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}

template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;

const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;
int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};

class DSU{
	private:
		vector<int> parent;
		vector<int> rank;
		int find(int x){
			if(parent[x]==x) return x;
			else return parent[x] = find(parent[x]);
		}

	public:
		DSU(int n){
			parent.resize(n);
			rank.resize(n);
			for(int i=0;i<n;i++) parent[i] = i;
		};

		void merge(int x, int y){
			x = find(x);
			y = find(y);
			if(x==y) return;
			if(rank[x]<rank[y]) parent[x] = y;
			else{
				parent[y] = x;
				if(rank[x]==rank[y]) rank[x]++;
			}
		}

		bool same(int x, int y){
			return find(x)==find(y);
		}

		void show(){
			for(int x: parent) cout<<x<<" ";
		}
};

void solve() {
	int n,m,q; cin>>n>>m>>q;
	vector<tuple<int,int,int,int> > E;
	rep(i,m){
		int a,b,c;
		cin>>a>>b>>c;
		E.push_back({c,a-1,b-1,-1});
	}

	rep(i,q){
		int u,v,w; cin>>u>>v>>w;
		E.push_back({w,u-1,v-1,i});
	}

	sort(ALL(E));

	DSU dsu(n);
	vector<string> ans(q);
	rep(i,E.size()){
		int w = get<0>(E[i]);
		int u = get<1>(E[i]);
		int v = get<2>(E[i]);
		int z = get<3>(E[i]);

		if(z==-1) dsu.merge(u,v);
		else{
			if(dsu.same(u,v)){
				ans[z] = "No";
			}
			else{
				ans[z] = "Yes";
			}
		}
	}
	//dsu.show();
	rep(i,q) PL(ans[i])


	/*
	rep(i,q){
		EL("-------")
		int u,v,w;
		cin>>u>>v>>w; u--; v--;
		tuple<int,int,int> edge = {w,u,v};
		vector<tuple<int,int,int> > e = E;
		e.push_back({w,u,v});
		sort(ALL(e));
		int cnt = 0;
		DSU dsu(n);
		rep(j,e.size()){
			int c = get<0>(e[j]);
			int a = get<1>(e[j]);
			int b = get<2>(e[j]);
			if(!dsu.same(a,b)){
				dsu.merge(a,b);
				cnt++;
				if(e[j]==edge){
					PL("Yes")
					break;
				}
			}

			if(e[j]==edge){
				ES(1)
				PL("No")
				break;
			}

			if(cnt==n-1){
				ES(2)
				dsu.show();
				PL("No")
				break;
			}
		}
	}
	*/

	return;
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	int t;
	t=1;
	rep(_, t) solve();

	return 0;
}
