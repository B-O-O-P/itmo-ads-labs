import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class I {
    static int binSearchFirst(int a[], int k) {
        int l = 0;
        int r = a.length - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (a[m] >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        if (a[l] == k) {
            return l + 1;
        } else {
            return -1;
        }
    }

    static int binSearchLast(int a[], int k) {
        int l = 0;
        int r = a.length - 1;

        while (l < r) {
            int m = r - (r - l) / 2;

            if (a[m] <= k) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        if (a[l] == k) {
            return l + 1;
        } else {
            return -1;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("binsearch.in"));
        FileWriter fileWriter = new FileWriter(new File("binsearch.out"));

        int n = Integer.parseInt(scanner.nextLine());
        String s[] = scanner.nextLine().split(" ");
        int a[] = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(s[i]);

        }

        int m = Integer.parseInt(scanner.nextLine());
        s = scanner.nextLine().split(" ");
        int z[] = new int[m];

        for (int i = 0; i < m; i++) {
            z[i] = Integer.parseInt(s[i]);

        }

        for (int i = 0; i < m; i++) {
            int x = binSearchfirst(a, z[i]);
            int y = binSearchlast(a, z[i]);

            if (i < m - 1) {
                fileWriter.write(+x + " " + y + "\r\n");
                fileWriter.flush();
            } else {
                fileWriter.write(+x + " " + y);
                fileWriter.flush();
            }

        }
    }
}
