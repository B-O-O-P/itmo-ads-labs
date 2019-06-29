import javafx.beans.binding.When;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Scanner;

public class B {

    static class Posl {
        ArrayDeque<Integer> p;
        int size;

        Posl(ArrayDeque<Integer> x, int y) {
            this.p = x;
            this.size = y;
        }
    }

    static Posl ToTheInfinityAndBeyond(int a[], int n) {
        int prev[] = new int[n];
        int dp[] = new int[n];
        for (int i = 0; i < n; i++) {
            prev[i] = -1;
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j])
                    if (dp[i] - 1 < dp[j]) {
                        prev[i] = j;
                        dp[i] = dp[j] + 1;
                    }
            }
        }

        int last = 0;
        int len = dp[0];
        for (int i = 0; i < n; i++) {
            if (len < dp[i]) {
                last = i;
                len = dp[i];
            }
        }

        ArrayDeque<Integer> ans = new ArrayDeque<>();
        while (last >= 0) {
            int cur = a[last];
            ans.addLast(cur);
            last = prev[last];
        }

        Posl x = new Posl(ans, len);
        return x;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a[] = new int[n];

        for (int i = 0; i < n; i++) a[i] = scanner.nextInt();

        Posl ans = ToTheInfinityAndBeyond(a, n);
        System.out.print(ans.size + "\n");
        while (!ans.p.isEmpty()) System.out.print(ans.p.removeLast() + " ");
    }
}
