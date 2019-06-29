import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Locale;
import java.util.Scanner;

public class J {

    public static double binSearch(int n, double l, double r) {
        double x = -1;
        double h = r;

        while ((r - l) > 0.01 / (n - 1)) {
            double mid = (l + r) / 2;
            double h0 = h, hi = mid;
            boolean greater = hi > 0;

            for (int i = 3; i <= n; i++) {
                double hn = 2 * hi - h0 + 2;
                greater = (hn > 0) && (greater);
                h0 = hi;
                hi = hn;
            }

            if (greater) {
                r = mid;
                x = hi;
            } else {
                l = mid;
            }
        }
        return x;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("garland.in")).useLocale(Locale.US);

        int n = scanner.nextInt();
        double A = scanner.nextDouble();

        FileWriter filewriter = new FileWriter(new File("garland.out"));
        filewriter.write(new DecimalFormat("#0.00").format(search(n, 0, A)));
        filewriter.flush();
    }
}
