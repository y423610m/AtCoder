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

ll n=Power(2,20);

void solve_() {

	//cout<<n<<endl;

	ll q; cin>>q;
	vector<ll> t(q), x(q);
	rep(i,q) cin>>t[i]>>x[i];

	vector<ll> idx;
	vector<ll> A(n, -1);

	rep(i,q){
		if(t[i]==1){
			ll h = x[i]%n;
			ll id = LINF;
			//int id = upper_bound(idx.begin(),idx.end(),h%n) - idx.begin();
			//while(A[h%n]!=-1) h++;
			if(idx.size()==0) id = h;
			else if(idx.size()==1&&idx[0]==h) h++;
			else rep(i,idx.size()-1) if(idx[i+1]-idx[i]!=1) id = min(id, idx[i]+1);
			id%=n;
			//cout<<"id"<<id<<endl;
			idx.push_back(id);
			idx.push_back(id+n);
			sort(ALL(idx));
			A[id%n]=x[i];
		}
		else cout<<A[x[i]%n]<<endl;

//cout<<"  "<<endl;
	//	rep(k,idx.size()) cout<<idx[k]<<" ";
	//	cout<<endl;
	}

	//cout<<"hi"<<endl;
	return;
}


void solve() {

	ll q; cin>>q;
	vector<ll> t(q), x(q);
	rep(i,q) cin>>t[i]>>x[i];

	vector<ll> A(n, -1);

	rep(i,q){
		if(t[i]==1){
			ll h = x[i];
			while(A[h%n]!=-1) h++;
			A[h%n]=x[i];
		}
		else cout<<A[x[i]%n]<<endl;
	}


	return;
}

int main() {
	solve();
	return 0;
}
