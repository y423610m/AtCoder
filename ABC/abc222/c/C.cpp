#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define rrep(i, a, n) for (int i = (int)(a); i > (int)(n); i--)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define rrepll(i, a, n) for (ll i = (ll)(a); i > (ll)(n); i--)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define ALL(a)  (a).begin(),(a).end()

const int MAX_N = 100;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

const int MAX_V = 100;

ll Power(ll a, ll b){
	ll ret = 1;
	repll(i,b) ret *= a;
	return ret;
}

void solve() {

	int n,m;
	cin>>n>>m;

	vector<string> a(2*n);
	rep(i,2*n) cin>>a[i];
	//rep(i,2*n) cout<<a[i]<<endl;

	vector<pair<int, int> > rank(2*n);  // 勝ち数, id
	rep(i,2*n) rank[i] = make_pair(0, i);

	rep(i,m){
		
		rep(j,n){
			//cout<<a[rank[2*j].second][i]<<"             "<<a[rank[2*j+1].second][i]<<endl;
			//あいこ
			if(a[rank[2*j].second][i]==a[rank[2*j+1].second][i]){
				//とくになし
				//cout<<"aiko"<<endl;
				
			}
			else{
				//cout<<"not aiko"<<endl;
				if(a[rank[2*j].second][i]=='G'){
					if(a[rank[2*j+1].second][i]=='C'){
						rank[2*j].first++;
					}
					else{
						rank[2*j+1].first++;
					}
				}
				else if(a[rank[2*j].second][i]=='C'){
					if(a[rank[2*j+1].second][i]=='P'){
						rank[2*j].first++;
					}
					else{
						rank[2*j+1].first++;
					}
				}
				else{
					if(a[rank[2*j+1].second][i]=='G'){
						rank[2*j].first++;
					}
					else{
						rank[2*j+1].first++;
					}
				}

			}
		}

		//sort
		sort(ALL(rank), [](pair<int,int> a, pair<int,int> b){
			if(a.first!=b.first) return a.first>b.first;
			else return a.second<b.second;
		});

		//rep(k, 2*n){
			//cout<<i<<"  "<<rank[k].first<<"  "<<rank[k].second<<endl;
		//}
	}

	rep(k,2*n){
		cout<<1+rank[k].second<<endl;
	}

	return;
}

int main() {
	solve();
	return 0;
}
