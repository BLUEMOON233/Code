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

const int N = 1;

inline void solve() {
	int n;
	cin >> n;
	vector<int> a(n), pos(n);
	rep(i, 0, n - 1) {
		cin >> a[i];
		a[i]--;
		pos[a[i]] = i;
	}
	if (n == 1) {
		cout << 1 << '\n';
		return;
	}
	int mxpos = pos[n - 1];
	if (pos[n - 1] == 0) mxpos = pos[n - 2];
	vector<int> ans;
	rep(i, 0, mxpos - 1) {
		int p1 = i, p2 = mxpos - 1;
		vector<int> b;
		b.reserve(n);
		rep(j, mxpos, n - 1) b.push_back(a[j]);
		per(j, p2, p1) b.push_back(a[j]);
		rep(j, 0, i - 1) b.push_back(a[j]);
		if (b > ans) ans = b;
	}
	if (mxpos == n - 1) {
		vector<int> b;
		b.reserve(n);
		b.push_back(a[n - 1]);
		rep(i, 0, n - 2) b.push_back(a[i]);
		if (b > ans) ans = b;
	}
	for (auto x : ans) cout << x + 1 << ' ';
	cout << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}