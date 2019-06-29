import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.Stack;

public class C {

    static int calc(String s) {
        Stack<Integer> stack = new Stack<Integer>();
        String cur[] = s.split(" ");
        int res = 0, f1, f2;

        for (int i = 0; i < cur.length; i++) {
            switch (cur[i]) {
                case "+":
                    f1 = stack.pop();
                    f2 = stack.pop();
                    res = f1 + f2;
                    stack.push(res);
                    break;
                case "-":
                    f1 = stack.pop();
                    f2 = stack.pop();
                    res = f2 - f1;
                    stack.push(res);
                    break;
                case "*":
                    f1 = stack.pop();
                    f2 = stack.pop();
                    res = f1 * f2;
                    stack.push(res);
                    break;
                default:
                    stack.push(Integer.parseInt(cur[i]));
            }
        }

        res = stack.pop();
        return res;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("postfix.in"));
        String s = scanner.nextLine();

        FileWriter fileWriter = new FileWriter(new File("postfix.out"));
        fileWriter.write(calc(s) + "");
        fileWriter.flush();
    }
}
