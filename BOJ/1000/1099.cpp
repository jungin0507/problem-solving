#include <bits/stdc++.h>

// #define int long long
#define fi first
#define se second
#define sq(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for (auto i = 0; i < (n); ++i)
#define rrep(i, n) for (auto i = (n) -1; i >= 0; --i)
#define fastio                                 \
    {                                          \
        ios::ios_base::sync_with_stdio(false); \
        cin.tie(0);                            \
        cout.tie(0);                           \
    }

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdi = pair<double, int>;
using pdd = pair<double, double>;
using pid = pair<int, double>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;

/* operators of std::pair<T1, T2> */
template<class T1, class T2>
ostream &operator<<(ostream &o, pair<T1, T2> x) {
    return o << x.first << ' ' << x.second;
}
template<class T1, class T2>
istream &operator>>(istream &i, pair<T1, T2> &x) {
    return i >> x.first >> x.second;
}
template<class T1, class T2>
pair<T1, T2> operator+(pair<T1, T2> x, pair<T1, T2> y) {
    return {x.first + y.first, x.second + y.second};
}
template<class T1, class T2>
pair<T1, T2> operator-(pair<T1, T2> x, pair<T1, T2> y) {
    return {x.first - y.first, x.second - y.second};
}
template<class T1, class T2>
void operator+=(pair<T1, T2> &x, pair<T1, T2> y) {
    x = x + y;
}
template<class T1, class T2>
void operator-=(pair<T1, T2> &x, pair<T1, T2> y) {
    x = x - y;
}

/* operators of std::vector<T> */
template<class T>
ostream &operator<<(ostream &o, vector<T> v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        o << (*it) << ' ';
    }
    return o;
}
template<class T>
istream &operator>>(istream &i, vector<T> &v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        i >> (*it);
    }
    return i;
}
void solve();
void preproc();

signed main() {
    fastio;
    int T = 1;
    // cin >> T;
    preproc();
    while (T-- > 0) solve();
}

/* actual code */

const int MAX_N = 55;
const int INF = 12345678;
const ll MOD = 1e9 + 7;

int N;
int M;
string sentence;
vector<string> words;
int cnt[MAX_N][26];
int V[MAX_N][MAX_N];
int DP[MAX_N][MAX_N];

int f(string s) {
    int ret = 0;
    for (const char &c : s) {
        ret |= 1 << (c - 'a');
    }
    return ret;
}

int calc(int idx, string s) {
    int ret = 0;
    int c[26] = {
        0,
    };
    for (int i = 0; i < s.length(); ++i) {
        ++c[s[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (c[i] != cnt[idx][i]) {
            return INF;
        }
    }

    for (int i = 0; i < s.length(); ++i) {
        if (words[idx][i] != s[i]) {
            ++ret;
        }
    }

    return ret;
}

void preproc() {
    rep(i, MAX_N) rep(j, MAX_N) DP[i][j] = INF;
    rep(i, MAX_N) rep(j, MAX_N) V[i][j] = INF;
}

void solve() {
    cin >> sentence;
    cin >> N;
    M = sentence.length();
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.push_back(word);
        for (char c : word) {
            ++cnt[i][c - 'a'];
        }
    }
    for (int i = 0; i < M; ++i) {
        for (int j = i + 1; j < M + 1; ++j) {
            int len = j - i;
            int mn = INF;
            string sub_sentence = sentence.substr(i, len);
            for (int k = 0; k < N; ++k) {
                mn = min(mn, calc(k, sub_sentence));
            }
            V[i][j] = mn;
        }
    }
    for (int len = 1; len <= M; ++len) {
        for (int i = 0; i < M; ++i) {
            int j = i + len;
            DP[i][j] = V[i][j];
            for (int k = i + 1; k < j; ++k) {
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
            }
        }
    }

    cout << (DP[0][M] == INF ? -1 : DP[0][M]) << "\n";
}
