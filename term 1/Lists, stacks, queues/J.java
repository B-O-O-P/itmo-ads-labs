import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Scanner;


public class J {


    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("bureaucracy.in"));
        FileWriter fileWriter = new FileWriter(new File("bureaucracy.out"));

        int n = scanner.nextInt();
        long m = scanner.nextInt();
        long obhod = m / n;
        long sum = 0;
        int count = n;

        ArrayDeque<Long> ochered = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            long cur = scanner.nextInt();
            if (cur <= obhod) {
                count--;
                m = m - cur;
            } else {
                cur = cur - obhod;
                m = m - obhod;
                ochered.addLast(cur);
                sum = sum + cur;
            }
        }

        if (sum <= m) {
            fileWriter.write(-1 + "");
        } else {
            while (m != 0) {
                long cur = ochered.removeFirst();
                m--;
                cur--;
                if (cur > 0) {
                    ochered.addLast(cur);
                } else {
                    count--;
                }
            }
            fileWriter.write(count + "\n");
            while (!ochered.isEmpty()) {
                fileWriter.write(ochered.removeFirst() + " ");
            }
        }

        fileWriter.flush();
    }
}