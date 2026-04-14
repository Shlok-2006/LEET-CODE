/*
DP
Time: O(n)
*/
int numDecodings(char* s) {
    int n = strlen(s);
    if (s[0] == '0') return 0;

    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = 0;

        if (s[i-1] != '0')
            dp[i] += dp[i-1];

        int two = (s[i-2]-'0')*10 + (s[i-1]-'0');
        if (two >= 10 && two <= 26)
            dp[i] += dp[i-2];
    }

    return dp[n];
}