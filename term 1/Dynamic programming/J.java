import java.io.File;
import java.io.FileNotFoundException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

public class J {
    static int infinity = 1000000000;
    static int dp[][];
    static int a[][];
    static int n, len;

    static int AREUREADY() {
        int res;
        int len = (1 << n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < len; j++) {
                dp[i][j] = infinity;
            }
        }
        dp[0][0] = 0;
        res = ChipAndDale(0, len - 1);
        return res;
    }


    static int ChipAndDale(int i, int j) {
        if (dp[i][j] != infinity) {
            return dp[i][j];
        }

        for (int e = 0; e < n; e++) {
            boolean bit;
            if ((j & (1 << e)) == 0) bit = false;
            else bit = true;
            if ((a[i][e] != 0) &&
                    bit) {
                dp[i][j] = Math.min(dp[i][j], (ChipAndDale(e, j - (1 << e)) + a[i][e]));
            }
        }

        return dp[i][j];
    }

    static ArrayList<Integer> HereYouAre() {
        ArrayList<Integer> way = new ArrayList<>();
        int i = 0;
        int j = len - 1;

        while (j != 0) {
            for (int e = 0; e < n; e++) {
                boolean bit;
                if ((j & (1 << e)) == 0) bit = false;
                else bit = true;
                if ((a[i][e] != 0) &&
                        bit &&
                        (dp[i][j] == dp[e][j - (1 << e)] + a[i][e])) {
                    way.add(e);
                    i = e;
                    j = j - (1 << e);
                }
            }
        }

        return way;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt() + 1;
        a = new int[n][n];
        len = 1 << n;
        dp = new int[n][len];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    a[i][j] = 0;
                    continue;
                }
                if (i == 0 || j == 0) a[i][j] = -1;
                else
                    a[i][j] = scanner.nextInt();
            }
        }

        int res = AREUREADY();
        System.out.println((res + 2));

        ArrayList<Integer> ans;
        ans = HereYouAre();

        for (int i = ans.size() - 2; i >= 0; i--) {
            System.out.print((ans.get(i)) + " ");
        }
    }
}
