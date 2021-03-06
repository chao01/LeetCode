/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 23, 2013
 Problem:    Palindrome Partitioning II
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_132
 Notes:
 Given a string s, partition s such that every substring of the partition is a palindrome.
 Return the minimum cuts needed for a palindrome partitioning of s.
 For example, given s = "aab",
 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

 Solution: dp. 'isP[i][j] == true' indicates that string s from index i to j is a palindrome.
 */

class Solution {
public:
    int minCut(string s) {
        int N = s.size();
        bool isP[N][N];  // isPalindrome
        for (int i = 0; i < N; ++i)
            isP[i][i] = true;
        for (int i = N - 2; i >= 0; --i)
            for (int j = i + 1; j < N; ++j)
                if (s[i] == s[j])
                    isP[i][j] = i + 1 < j ? isP[i+1][j-1] : true;
                else
                    isP[i][j] = false;

        int dp[N];
        dp[0] = 0;
        for (int i = 1; i < N; ++i)
        {
            dp[i] = dp[i-1] + 1;
            for (int j = 0; j < i; ++j)
                if (isP[j][i])
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j-1] + 1);
        }
        return dp[N-1];
    }
};