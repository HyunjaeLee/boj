import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        List<Integer> list = new ArrayList<>();
        while (st.hasMoreTokens()) {
            list.add(Integer.parseInt(st.nextToken()));
        }
        if (increase(list)) {
            System.out.println("Good");
        } else {
            System.out.println("Bad");
        }
        br.close();
    }

    public static boolean increase(List<Integer> list) {
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i-1) > list.get(i)) {
                return false;
            }
        }
        return true;
    }
}
