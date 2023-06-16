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
#define puts(a) cout<<(a)<<" ";
#define putl(a) cout<<(a)<<endl;

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

	int n; cin>>n;

	vector<int> A(n);
	rep(i,n) cin>>A[i];

	vector<int> ans(n,0);
	int grad = 1;
	int cnt = 0;
	rep(i,n-1){
		if(grad>0 && A[i]>A[i+1]){
			 ans[i] = 1;
			 cnt++;
		}
		else if(grad<0 && A[i]<A[i+1]){
			ans[i] = 1;
			cnt++;
		}

		if(A[i+1]>A[i]) grad = 1;
		else if(A[i+1]<A[i])grad = -1;
	}
	//<<"loop1 end"<<endl;
	
	
	int id = n-1;
	if(cnt>0 && cnt%2==1){
		//cout<<"extra loop"<<endl;
		bool keep = true;
		int i = n-1;
		int m = INF;
		while(keep){

			if(m>A[i]){
				id = i;
				m = A[i];
			}

			if(ans[i]==1) keep = false;
			i--;
		}
		ans[id] = 1-ans[id];
	}


	rep(i,n) cout<<ans[i]<<" ";
	cout<<endl;
	return;

}

int main() {
	solve();
	return 0;
}
