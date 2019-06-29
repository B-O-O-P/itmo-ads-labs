import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;


public class H {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("saloon.in"));
        FileWriter fileWriter = new FileWriter(new File("saloon.out"));

        int n = scanner.nextInt();
        ArrayDeque<Integer> ochred = new ArrayDeque<>();
        int len = 0;

        for (int i = 0; i < n; i++) {
            int hour = scanner.nextInt();
            int min = scanner.nextInt();
            int st = scanner.nextInt();
            int timein = hour * 60 + min;
            int timeout = 0;
            if (len == 0) {
                timeout = timein + 20;
                ochred.addLast(timeout);
                len++;
                fileWriter.write(timeout / 60 + " " + timeout % 60 + "\n");
                continue;
            }
            int f = ochred.getFirst();
            if (timein >= f) {
                while (len != 0 && timein >= ochred.getFirst()) {
                    ochred.removeFirst();
                    len--;
                }
            }
            if (len == 0) {
                timeout = timein + 20;
                ochred.addLast(timeout);
                len++;
                fileWriter.write(timeout / 60 + " " + timeout % 60 + "\n");
                continue;
            }
            if (st < len) {
                fileWriter.write(hour + " " + min + " " + "\n");
                continue;
            }
            int l = ochred.peekLast();
            timeout = l + 20;
            len++;
            ochred.addLast(timeout);
            fileWriter.write(timeout / 60 + " " + timeout % 60 + "\n");
        }

        fileWriter.flush();
    }
}