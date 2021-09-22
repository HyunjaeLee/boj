import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextInt();
        Deque<Long> deque = new ArrayDeque<>();
        int pos = 0;
        for (int i = 0; n > 0; i++) {
            if (i % 2 == 0) {
                deque.addFirst(n % k);
            } else if (n % k > 0) {
                pos = (i + 1) / 2;
            }
            n /= k;
        }
        long count = 1;
        while (deque.size() > pos) {
            long a = deque.removeFirst();
            count +=  a * pow(k, deque.size() - pos);
        }
        count *= pow(k, deque.size());
        System.out.println(count);
        sc.close();
    }

    public static long pow(long x, int y) {
        long result = 1;
        for (int i = 0; i < y; i++) {
            result *= x;
        }
        return result;
    }
}