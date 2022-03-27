package com.shahidul.leetcode;

import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 1/27/2022
 **/
public class _5_LongestPalindromicSubstring {
    public String longestPalindrome(String s) {
        int length = s.length();
        int[][] dp = new int[length][length];
        Arrays.stream(dp)
                .forEach(array -> Arrays.fill(array, -1));

        int a, b, mx;
        mx = a = b = 0;
        for (int i = 0; i < length; i++) {
            for (int j = i; j < length; j++) {
                int l = lps(i, j, s, dp);
                if (l > mx) {
                    mx = l;
                    a = i;
                    b = j;
                }
            }
        }
        return s.substring(a, b + 1);

    }

    private int lps(int i, int j, String s, int[][] dp) {
        if (i > j) {
            return 0;
        } else if (dp[i][j] != -1) {
            return dp[i][j];
        } else if (i == j) {
            dp[i][j] = 1;
            return 1;
        }
        int l = 0;
        if (s.charAt(i) == s.charAt(j)) {
            int infixLps = lps(i + 1, j - 1, s, dp);
            if (infixLps >= 0) {
                l = 2 + infixLps;
            } else {
                l = infixLps;
            }
        } else {
            l = -100;
        }

        dp[i][j] = l;
        return l;

    }
}
