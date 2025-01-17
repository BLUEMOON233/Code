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

void merge(vector<PII> &segs)
{
	vector<PII> res;
	sort(segs.begin(), segs.end());

	int l = -2e9, r = -2e9;
	for (auto [i, j] : segs)
	{
		if (r < i)
		{
			if (l != -2e9) res.push_back({l, r});
			l = i, r = j;
		}
		else
			r = max(r, j);
	}

	if (l != -2e9) res.push_back({l, r});

	//  for (auto [i, j] : res)
	//      cout << "i = " << i << " j = " << j << endl;
	segs = res;
}


inline void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	vector<PII> lr;
	rep(i, 1, n) if (a[i]) {
		if (i == 1) {
			lr.push_back({min(i + 1, n), min(i + a[i], n)});
			continue;
		}
		if (i == n) {
			lr.push_back({max(i - a[i], 1), max(i - 1, 1)});
			continue;
		}
		lr.push_back({max(i - a[i], 1), max(i - 1, 1)});
		lr.push_back({min(i + 1, n), min(i + a[i], n)});
	}
	merge(lr);
	LL rs = 0;
	for (auto [l, r] : lr) {
		// cout << l << ' ' << r << '\n';
		rs += r - l + 1;
	}
	cout << rs << '\n';

}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}
