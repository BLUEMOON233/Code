#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PII;
#define endl '\n'
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define mes(tmp, data) memset(tmp, data, sizeof tmp)
#define debug(x) cerr << "(" << __LINE__ << ")" << #x << " = " << x << endl;
#define debug0(tmp, Size) rep(i, 0, Size - 1) cout<<tmp[i]<<" \n"[i == Size - 1]
#define debug1(tmp, Size) rep(i, 1, Size) cout<<tmp[i]<<" \n"[i == Size]
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
template<class T>
inline T read() {
	T x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
template<class T>
inline void write(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
	return;
}
#define read() read<int>()
#define write(tmp) write<int>(tmp);
//#define read() read<LL>()
//#define write(tmp) write<LL>(tmp);
//#define read() read<__int128>()
//#define write(tmp) write<__int128>(tmp);

const int N = 1, mod = 998244353;

LL quickPow(LL a, LL b, LL mod) {
	LL rs = 1;
	while (b) {
		if (b & 1) rs = rs * a % mod;
		b >>= 1, a = a * a % mod;
	}
	return rs % mod;
}

inline void solve() {
	LL n, m, a, b;
	cin >> n >> m >> a >> b;
	LL bb = quickPow(b, mod - 2, mod);
	LL A = a * bb % mod;
	LL B = (b - a + mod) % mod * bb % mod;
	LL BB = quickPow(B, mod - 2, mod);
	LL nowA = 1;
	LL nowB = quickPow(B, n, mod);
	LL pre = 0, C;
	LL rs = 0;
	rep(i, 1, n) {
		LL now = quickPow(i, m, mod);
		pre = (pre + now) % mod;
		// C / i * i + 1
		if (i == 1) {
			C = n;
		} else {
			LL t = quickPow(i, mod - 2, mod);
			C = C * t % mod;
			C = C * (n - i + 1) % mod;
		}
		nowA = nowA * A % mod;
		nowB = nowB * BB % mod;
		LL trs = C * nowA % mod * nowB % mod * pre % mod;
		rs = (rs + trs) % mod;
	}
	cout << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}
