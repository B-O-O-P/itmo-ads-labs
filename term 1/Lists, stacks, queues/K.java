import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Scanner;

public class K {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("kenobi.in"));
        FileWriter fileWriter = new FileWriter(new File("kenobi.out"));

        int n = scanner.nextInt();
        ArrayDeque<Integer> forobi = new ArrayDeque<>();
        ArrayDeque<Integer> formum = new ArrayDeque<>();
        int count = 0;

        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            switch (s) {
                case "add":
                    count++;
                    int val = scanner.nextInt();
                    forobi.addLast(val);
                    if (count % 2 == 0) {
                        int tmp = forobi.removeFirst();
                        formum.addLast(tmp);
                    }
                    break;
                case "take":
                    if (count != 0) {
                        count--;
                        forobi.pollLast();
                        if (count % 2 == 1) {
                            int tmp = formum.removeLast();
                            forobi.addFirst(tmp);
                        }
                    }
                    break;
                case "mum!":
                    ArrayDeque<Integer> tmp = formum;
                    formum = forobi;
                    forobi = tmp;
                    if (count % 2 == 1) {
                        int tmp2 = formum.removeLast();
                        forobi.addFirst(tmp2);
                    }
                    break;
            }
        }

        fileWriter.write(count + "\n");

        while (!formum.isEmpty()) {
            fileWriter.write(formum.removeFirst() + " ");
        }
        while (!forobi.isEmpty()) {
            fileWriter.write(forobi.removeFirst() + " ");
        }
        fileWriter.flush();
    }
}
