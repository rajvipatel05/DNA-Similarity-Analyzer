#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    string dna1, dna2;

    cout << "Enter DNA Sequence 1: ";
    cin >> dna1;

    cout << "Enter DNA Sequence 2: ";
    cin >> dna2;

    int n = dna1.length(), m = dna2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dna1[i - 1] == dna2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int lcs = dp[n][m];
    double similarity = (2.0 * lcs) / (n + m) * 100;

    cout << "\nLCS Length: " << lcs;
    cout << "\nSimilarity: " << fixed << setprecision(2)
         << similarity << "%";

    return 0;
}
