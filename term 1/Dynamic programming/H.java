import java.util.ArrayList;
import java.util.Scanner;

public class H {
    static int mn = 101;
    static ArrayList<ArrayList<Integer>> a = new ArrayList<>();
    static int num[];
    static boolean old[];
    static int dp[][] = new int[mn][2];


    static void DepthFirstSearh(int x, int y) {
        old[x] = true;

        for (int i = 0; i < a.get(x).size(); i++) {
            int tmp = a.get(x).get(i);
            if (!old[tmp]) {
                DepthFirstSearh(tmp, x);
            }
        }

        int cnt = 0;
        int sum = 0;

        for (int i = 0; i < a.get(x).size(); i++) {
            int tmp = a.get(x).get(i);
            if (tmp != y) {
                int max = Math.max(dp[tmp][0], dp[tmp][1]);
                sum = sum + max;
                cnt = cnt + dp[tmp][0];
            }
        }

        dp[x][1] = dp[x][1] + cnt;
        dp[x][0] = sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int start = 0;

        for (int i = 0; i < mn; i++) {
            a.add(new ArrayList<Integer>());
        }

        old = new boolean[n];
        num = new int[n];

        for (int i = 0; i < n; i++) {
            int tmp = scanner.nextInt();
            if (tmp > 0) {
                a.get(i).add(tmp - 1);
                a.get(tmp - 1).add(i);
            } else {
                start = i;
            }
        }

        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        DepthFirstSearh(start, start);

        int max = Math.max(dp[start][0], dp[start][1]);
        System.out.print(max + "");
    }
}
