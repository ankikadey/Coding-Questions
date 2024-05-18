#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestRepeatingSubsequence(string st, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (st[i - 1] == st[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        string st;
        cin >> st;
        int n = st.size();
        cout << longestRepeatingSubsequence(st, n) << endl;
    }
    return 0;
}
