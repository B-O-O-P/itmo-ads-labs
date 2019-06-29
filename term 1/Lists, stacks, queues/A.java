import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class A {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("decode.in"));
        String s = scanner.nextLine();
        ArrayList<Character> res = new ArrayList<Character>();

        for (int i = 0; i < s.length(); i++) {
            char cur = s.charAt(i);
            int len = res.size();
            if (len != 0 && cur == res.get(len - 1)) {
                res.remove(len - 1);
            } else {
                res.add(cur);
            }
        }

        FileWriter fileWriter = new FileWriter(new File("decode.out"));
        fileWriter.flush();

        for (int i = 0; i < res.size(); i++) {
            fileWriter.write(res.get(i));
        }
        fileWriter.flush();
    }
}
