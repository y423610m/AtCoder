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
#define ALLR(a)  (a).rbegin(),(a).rend()
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

	int n,k;
	cin>>n>>k;

	vector<ll> A(n);
	rep(i,n) cin>>A[i];
	sort(ALLR(A));

	ll ans = 0;


	int id = A.size()-1;
	while(A.size()>=k&&id!=k-2){
		//cout<<id<<endl;
		ll tmp = 0;
		//id = A.size()-1;
		while(tmp+A[id]<A[k-2]&&id!=k-2){
			tmp += A[id];
			id--;
		}
		rep(i,k-1) A[i] -= tmp;

		ans += tmp;
		A.erase(A.begin()+id+1,A.end());

		//rep(i,id+1,n-1) A[i]=0;
		//cout<<" "<<A.back()<<endl;
		sort(ALLR(A));
	}
	//cout<<"size"<<A.size()<<endl;
	cout<<ans<<endl;

	return;
}

void solve0() {

	int n,k;
	cin>>n>>k;

	vector<ll> A(n);
	rep(i,n) cin>>A[i];
	sort(ALL(A));

	ll ans = 0;
	while(A[n-k]!=0){
		ll tmp = A[n-k];
		repi(i,n-k,n) A[i] -= tmp;
		ans += tmp;
		swap(A[n-k], A[n-1]);
		A.erase(A.end()-1, A.end());
		sort(ALL(A));
		n--;
	}

	cout<<ans<<endl;

	return;
}

int main() {
	solve();
	return 0;
}
