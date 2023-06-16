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
const double DINF = 2.0*1000000000;

const int MAX_V = 100;

ll Power(ll a, ll b){
	ll ret = 1;
	repll(i,b) ret *= a;
	return ret;
}

void solve() {

	int n; cin>>n;
	vector<pair<int,int> > vp(n);
	rep(i,n) cin>>vp[i].first>>vp[i].second;

	int ans = 0;
	int ans2=0;
	int res = 0;

	rep(i,n-2){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if((vp[j].first-vp[i].first)*(vp[k].second-vp[i].second)-(vp[k].first-vp[i].first)*(vp[j].second-vp[i].second)!=0){res++;}

				//if( 1.0*(vp[j].first-vp[i].first)*(vp[k].second-vp[i].second)!=1.0*(vp[j].second-vp[i].second)*(vp[k].first-vp[i].first)) ans2++;
				if( (vp[j].first-vp[i].first)*(vp[k].second-vp[i].second)!=(vp[j].second-vp[i].second)*(vp[k].first-vp[i].first)) ans2++;


				//縦一直線
				if(vp[i].first==vp[j].first && vp[i].first==vp[k].first){
					//ans++;
						//puts("b")

				}
				//横一直線
				else if(vp[i].second==vp[j].second && vp[i].second==vp[k].second){

				}
				//縦線含む
				else if(vp[i].first==vp[j].first || vp[j].first==vp[k].first || vp[k].first==vp[i].first){
					ans++;
				}
				//横線含む
				else if(vp[i].second==vp[j].second || vp[j].second==vp[k].second || vp[k].second==vp[i].second){
					ans++;
				}
				else{
					if( 1.0*(vp[k].second-vp[i].second)/(vp[k].first-vp[i].first) == 1.0*(vp[j].second-vp[i].second)/(vp[j].first-vp[i].first)   ){
						//cout<<vp[k].second<<vp[i].second<<endl;
						//cout<<(vp[k].second-vp[i].second)/(vp[k].first-vp[i].first)<<endl;
						//puts("aaa")
					}
					else{
						ans++;
					}
				}
				//cout<<i<<" "<<j<<" "<<k<<" "<<ans<<endl;

			}
		}
	}

	cout<<endl;
	cout<<ans<<endl;
	cout<<ans2<<endl;
	cout<<res<<endl;


/*
	vector<pair<double, double> > line;
	rep(i,n){
		for(int j=i+1;j<n;j++){
			if(vp[i].first!=vp[j].first){
				double a = (vp[i].second-vp[j].second)/(vp[i].first-vp[j].first);
				double b = vp[i].second-a*vp[i].first;
				line.push_back(mp(a,b));
			}
			else{
				line.push_back(mp(DINF, vp[i].first));
			}
		}
	} 

	auto result = unique(ALL(line));
	line.erase(result, line.end());

	n = line.size();

	if(n<3){
		putl(0)
		return;
	}
	else{
		putl(n*(n-1)*(n-2)/6)
		return;
	}
	*/
	

	return;
}

int main() {
	solve();
	return 0;
}
