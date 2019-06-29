import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Scanner;

class OCHEREDNYARA {
    int ind;
    OCHEREDNYARA prev;
    OCHEREDNYARA next;
}

class DOTA {
    OCHEREDNYARA top;
    OCHEREDNYARA bot;
    OCHEREDNYARA mid;
    int len;

    DOTA() {
        top = null;
        bot = null;
        mid = null;
    }

    void addLast(int id) {
        OCHEREDNYARA tmp = new OCHEREDNYARA();
        tmp.ind = id;
        tmp.next = null;
        if (bot != null) {
            bot.next = tmp;
            tmp.prev = bot;
            bot = tmp;
            if (len % 2 == 0) {
                mid = mid.next;
            }
        } else {
            top = tmp;
            bot = tmp;
            mid = tmp;
            tmp.prev = null;
        }
        len++;
    }

    void addSoloMid(int id) {
        if (top == null) {
            addLast(id);
        } else {
            OCHEREDNYARA tmp = new OCHEREDNYARA();
            tmp.ind = id;
            tmp.prev = mid;
            tmp.next = mid.next;
            if (mid.next != null) {
                mid.next.prev = tmp;
            } else {
                bot = tmp;
            }
            mid.next = tmp;
            if (len % 2 == 0) {
                mid = tmp;
            }
            len++;
        }
    }

    int KILL() {
        if (top == null) {
            return 0;
        }
        int res = top.ind;
        if (len == 1) {
            top = null;
            bot = null;
            mid = null;
            len = 0;
            return res;
        }
        OCHEREDNYARA tmp = top;
        top = top.next;
        top.prev = null;
        if (len % 2 == 0) {
            mid = mid.next;
        }
        len--;
        return res;
    }
}


public class G {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("hospital.in"));
        FileWriter fileWriter = new FileWriter(new File("hospital.out"));

        int n = scanner.nextInt();
        DOTA dota = new DOTA();

        for (int i = 0; i < n; i++) {
            String cur = scanner.next();
            switch (cur) {
                case "-":
                    fileWriter.write(dota.KILL() + "\n");
                    break;
                case "+":
                    dota.addLast(scanner.nextInt());
                    break;
                case "*":
                    dota.addSoloMid(scanner.nextInt());
                    break;
            }
        }

        fileWriter.flush();
    }
}
