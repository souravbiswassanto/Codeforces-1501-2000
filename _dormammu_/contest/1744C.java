import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int test = input.nextInt();
        for (int cs = 0; cs < test; cs++) {
            int n = input.nextInt();
            char ch = input.next().charAt(0);
            char[] st = input.next().toCharArray();
            StringBuilder concatestr = new StringBuilder(n * 2);
            concatestr.append(st);
            concatestr.append(st);
            char[] str = concatestr.toString().toCharArray();
            int ans = 0, res = 0;
            int index = 0; n = 2 * n;
            for (int i = 0; i < n; i++) if (str[i] == 'g') index = i;

            for (int i = index; i >= 0; i--) {
                if (str[i] == 'g') {
                    ans = i;
                }
                if (str[i] == ch) res = Math.max(res, ans - i);
            }
            System.out.println(res);
        }
    }
}