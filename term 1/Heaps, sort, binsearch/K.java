import javafx.util.Pair;

import java.io.File;
import java.io.FileNotFoundException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

public class K {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("C:/Users/dimka/Desktop/tests/trainin.txt"));
        String s[] = scanner.nextLine().split(" ");

        int n = Integer.parseInt(s[1]), L = Integer.parseInt(s[0]);
        ArrayList<Pair<Integer, Integer>> a = new ArrayList<Pair<Integer, Integer>>();

        for (int i = 0; i < n; i++) {
            int time = scanner.nextInt();
            int speed = scanner.nextInt();

            a.add(new Pair<Integer, Integer>(time, speed));

            System.out.println(a.get(i).getKey() + " " + a.get(i).getValue());
        }
    }
}
