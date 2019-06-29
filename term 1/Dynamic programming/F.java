import java.util.Scanner;

public class F {
    static int dp[][];
    static int pos[][];
    static String s;
    static StringBuilder res;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        s = scanner.nextLine();

        int n = s.length();
        dp = new int[n][n];
        pos = new int[n][n];
        res = new StringBuilder();

        if (n > 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i > j) {
                        dp[i][j] = 0;
                        continue;
                    }
                    if (i == j) dp[i][j] = 1;
                }
            }
            for (int right = 0; right < n; right++) {
                for (int left = right; left >= 0; left--) {
                    if (left == right) {
                        dp[left][right] = 1;
                    } else {
                        int min = 100000;
                        int mink = -10;
                        if ((s.charAt(left) == '(' && s.charAt(right) == ')') || (s.charAt(left) == '[' && s.charAt(right) == ']') || (s.charAt(left) == '{' && s.charAt(right) == '}'))
                            min = dp[left + 1][right - 1];
                        for (int k = left; k < right; k++) {
                            if (dp[left][k] + dp[k + 1][right] < min) {
                                min = dp[left][k] + dp[k + 1][right];
                                mink = k;
                            }
                        }
                        dp[left][right] = min;
                        pos[left][right] = mink;
                    }
                }
            }

            ans(0, n - 1);
            System.out.print(res.toString().length());
        } else System.out.print("");
    }

    static void ans(int left, int right) {
        if (dp[left][right] == right - left + 1) return;
        if (dp[left][right] == 0) {
            res.append(s.substring(left, right + 1));
            return;
        }
        if (pos[left][right] == -10) {
            res.append(s.charAt(left));
            ans(left + 1, right - 1);
            res.append(s.charAt(right));
            return;
        }
        ans(left, pos[left][right]);
        ans(pos[left][right] + 1, right);
    }
}
