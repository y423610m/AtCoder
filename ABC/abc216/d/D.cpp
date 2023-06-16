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

const int MAX_N = 100;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

const int MAX_V = 100;

void solve() {

	int n,m;
	cin>>n>>m;

	vector<queue<int>> vq(m); 
	rep(i,m){
		int k; cin>>k;
		rep(j,k){
			int a; cin>>a;
			vq[i].push(a);
		}
		vq[i].push(-1-i);
	}

	vector<pair<int,int>> vi;//front, i
	rep(i,m) vi.push_back(mp(vq[i].front(),i));

	int cnt = 0;
	while(1){
		sort(vi.begin(),vi.end());
		auto uni = unique(vi.begin(), vi.end());
		if(cnt==n){
			cout<<"Yes"<<endl;
			return;
		}
		if(uni==vi.end()) {
			cout<<"No"<<endl;
			return;
		}
		else if( uni != vi.end() ){
			cout<<"    "<<uni->first<<endl;
			auto it = find_if(
				vi.begin(),
				vi.end(),
				[uni](pair<int,int> a){return a.first == uni->first;}
			);
			vq[it->second].pop();
			*it = mp(vq[it->second].front(), it->second);
			vq[uni->second].pop();
			*uni = mp(vq[uni->second].front(), uni->second);
			uni++;
			cnt++;
		}
	}

	return;
}

int main() {
	solve();
	return 0;
}
