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

const int N = 2e5 + 7;

inline void solve() {
    int n, k, x;
    int rs = 0x3f3f3f3f;
    cin >> n >> k;
    map<int, vector<int>> mp;
    map<int, vector<int>> mpp;
    rep(i, 1, n) {
        cin >> x;
        mp[x].emplace_back(i);
    }
    for (auto& [a, b] : mp) {
        mpp[a].emplace_back(b[0] - 1);
        mpp[a].emplace_back(n - b.back());
        rep(i, 1, b.size() - 1) {
            mpp[a].emplace_back(b[i] - b[i - 1] - 1);
        }
    }
    for (auto& [a, b] : mpp) {
        sort(b.begin(), b.end());
        int tmp = b.back() / 2;
        tmp = max(tmp, b[b.size() - 2]);
        rs = min(rs, tmp);
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
