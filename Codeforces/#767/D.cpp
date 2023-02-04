#include <bits/stdc++.h>

#define pii pair<int, int>
#define pdi pair<double, int>
#define pdd pair<double, double>
#define pid pair<int, double>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define INF 987654321
#define vi vector<int>
#define sq(x) ((x) * (x))
#define FOR(i, n) for (int i = 0; i < (n); ++i)

typedef long long ll;

using namespace std;

vector<string> S;
set<string> ht;

string rev_str(string s) {
  reverse(s.begin(), s.end());
  return s;
}

void solve() {
  int N;
  cin >> N;
  S.clear();
  ht.clear();

  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    S.push_back(s);
  }

  for (int i = 0; i < N; ++i) {
    if (S[i].length() == 1) {
      cout << "YES\n";
      return;
    } else if (S[i].length() == 2) {
      if (S[i][0] == S[i][1] || ht.find(rev_str(S[i])) != ht.end()) {
        cout << "YES\n";
        return;
      } else {
        for (char c = 'a'; c <= 'z'; ++c) {
          if (ht.find(rev_str(S[i]) + c) != ht.end()) {
            cout << "YES\n";
            return;
          }
        }
      }
    } else {
      if (S[i][0] == S[i][2] || ht.find(rev_str(S[i])) != ht.end() || ht.find(rev_str(S[i].substr(1))) != ht.end()) {
        cout << "YES\n";
        return;
      }
    }
    ht.insert(S[i]);
  }
  cout << "NO\n";
}

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();
}