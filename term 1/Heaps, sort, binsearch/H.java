import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class H {
    static int kth(int[] a, int l, int r, int k) {
        int i = l;
        int j = r;
        int x = a[(int) (Math.random() * (r - l + 1)) + l];

        while (i <= j) {
            while ((a[i] < x)) {
                i++;
            }

            while (a[j] > x) {
                j--;
            }

            if (i <= j) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
                i++;
                j--;
            }
        }

        if (l <= k && k <= j) {
            return kth(a, l, j, k);
        } else if (i <= k && k <= r) {
            return kth(a, i, r, k);
        }
        return a[k];
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("kth.in"));
        FileWriter fileWriter = new FileWriter(new File("kth.out"));

        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();

        int[] mas = new int[n];
        mas[0] = scanner.nextInt();
        mas[1] = scanner.nextInt();

        for (int i = 2; i < n; i++) {
            mas[i] = A * mas[i - 2] + B * mas[i - 1] + C;
        }

        fileWriter.write(Integer.toString(kth(mas, 0, mas.length - 1, k - 1)));
        fileWriter.flush();
    }
}
