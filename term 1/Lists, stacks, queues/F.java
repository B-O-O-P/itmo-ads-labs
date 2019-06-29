import javafx.util.Pair;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class F {

    static class vStroi{
        int sleva;
        int sprava;
    }
    static vStroi a[]=new vStroi[75001];

    static void GOLEFT(int i,int j){
        a[i].sleva=a[j].sleva;
         if (a[i].sleva!=0){
             a[a[i].sleva].sprava=i;
         }
         a[j].sleva=i;
         a[i].sprava=j;
    }
    static void GORIGHT(int i,int j){
        a[i].sprava=a[j].sprava;
        if (a[i].sprava!=0){
            a[a[i].sprava].sleva=i;
        }
        a[j].sprava=i;
        a[i].sleva=j;
    }
    static void LEAVEMEALONE(int i){
        if (a[i].sleva!=0){
            a[a[i].sleva].sprava=a[i].sprava;
        }
        if (a[i].sprava!=0){
            a[a[i].sprava].sleva=a[i].sleva;
        }
        a[i].sleva=0;
        a[i].sprava=0;
    }
    static String TELLME(int i){
        return (a[i].sleva+" "+a[i].sprava);
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("formation.in"));
        FileWriter fileWriter=new FileWriter(new File("formation.out"));
        int n=scanner.nextInt();
        int m=scanner.nextInt();
        for (int i=0;i<=n;i++){
            a[i]=new vStroi();
            a[i].sleva=0;
            a[i].sprava=0;
        }
        for (int o=0;o<m;o++){
            String s=scanner.next();
            int i=0;
            int j=0;
            switch (s){
                case "left":
                    i=scanner.nextInt();
                    j=scanner.nextInt();
                    GOLEFT(i,j);
                    break;
                case "right":
                    i=scanner.nextInt();
                    j=scanner.nextInt();
                    GORIGHT(i,j);
                    break;
                case "leave":
                    i=scanner.nextInt();
                    LEAVEMEALONE(i);
                    break;
                case "name":
                    i=scanner.nextInt();
                    fileWriter.write(TELLME(i)+"\n");
                    break;
            }
        }
        fileWriter.flush();
    }
}
