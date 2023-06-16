#define _CRT_SECURE_NO_WARNINGS
//#include <boost/multiprecision/cpp_int.hpp>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <bitset>
#include <string.h>
#include <numeric>
#include <random>
#if defined _DEBUG
//#include "TestCase.h"
//#include "Util.h"
#endif

using namespace std;

using ll = long long;
using ull = unsigned long long;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tlll;
typedef tuple<int, int, int> tiii;

using ai2 = array<int, 2>;
using ai3 = array<int, 3>;
using ai4 = array<int, 4>;
using al2 = array<ll, 2>;
using al3 = array<ll, 3>;
using al4 = array<ll, 4>;
using ad2 = array<double, 2>;
using ad3 = array<double, 3>;
using ad4 = array<double, 4>;

inline void Yes(bool upper = false) { cout << (upper ? "YES" : "Yes") << "\n"; }
inline void No(bool upper = false) { cout << (upper ? "NO" : "No") << "\n"; }

#define PI 3.14159265358979l

static const ll Mod = 1000000007;
static const ll Mod9 = 998244353;// 1000000007;
static const ll INF64 = 3000000000000000000;// 10000000000000000;
static const int INF32 = 2000000000;

random_device rd;
mt19937 mt(0);//(rd());
//using mpint = boost::multiprecision::cpp_int;

const double EPS = 1e-10;



ll Len(string T, int k)
{
   vector<int> x;
   for (int i = 0; i < T.size(); i++)
   {
      if (T[i] == 'x')
         x.emplace_back(i);
   }

   vector<int> xin(x.size()), xout(x.size());
   for (int i = 1; i < x.size(); i++)
   {
      xin[i - 1] = x[i] - x[i - 1];
   }
   xout[0] = x[0] + 1;
   for (int i = 1; i < x.size(); i++)
   {
      xout[i] = xin[i - 1];
   }
   xin.back() = T.size() - x.back();

   ll curr = accumulate(xin.begin(), xin.begin() + k, (ll)0) + x[0];
   ll ans = curr;
   for (int i = k; i < xin.size(); i++)
   {
      curr += xin[i] - xout[i - k];
      ans = max(ans, curr);
   }
	return ans;
}

void tmain()
{
	ll N, M, K;
	cin >> N >> M >> K;
	string S;
	cin >> S;

	if (M <= 3)
	{
		string T;
		for (int i = 0; i < M; i++) T += S;

		cout << Len(T, K) << "\n";
		return;
	}


	int xs = 0;
	for (auto c : S)
		xs += (c == 'x');

   if (K == xs * M)
	{
		cout << N * M << "\n";
	}
	// else if (K%xs)
	// {
	// 	ll base = Len(S + S, K%xs);
	// 	ll num = min(M - 1, K / xs);
	// 	ll tmp = N * num;
	// 	cout << min(N*M, base + tmp) << "\n";
	// }
	else
	{
		ll num = min(M - 1, K / xs - 1);
		ll base = 0;
      if(M-num==1) base = Len(S, K-num*xs);
      else if(M-num==2) base = Len(S + S, K-num*xs);
      else  base = Len(S + S + S, K-num*xs);
		ll tmp = N * num;
		cout << min(N*M, base + tmp) << "\n";
	}


	return;
}

int main()
{
	std::cin.tie(nullptr); //★インタラクティブ注意★
	std::ios_base::sync_with_stdio(false);
	int T = 1;
	//cin >> T;
	while (T--)
		tmain();

	return 0;
}

/// 値渡しになっていないか?
/// 入力を全部読んでいるか? 途中でreturnしない
/// 32bitで収まるか? 10^5数えるとき
/// modは正しいか?
/// multisetでcountしていないか?
