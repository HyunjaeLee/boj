import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long s = Long.parseLong(st.nextToken());
        long t = Long.parseLong(st.nextToken());
        bw.write(search(s, t));
        bw.flush();
        bw.close();
        br.close();
    }

    public static String search(long s, long t) {
        Deque<Node> deque = new ArrayDeque<>();
        if (s == t) {
            return "0";
        } else if (s == 1) {
            deque.addLast(new Node(1));
        } else if (s > t) {
            if ((t & (t - 1)) == 0) {
                deque.addLast(new Node(1, "/"));
            } else {
                return "-1";
            }
        } else {
            deque.addLast(new Node(s));
            deque.addLast(new Node(1, "/"));
        }
        List<String> result = new ArrayList<>();
        int minLen = Integer.MAX_VALUE;
        while (!deque.isEmpty()) {
            Node node = deque.removeFirst();
            if (node.str.length() > minLen) {
                break;
            }
            if (node.num == t) {
                result.add(node.str);
                minLen = node.str.length();
            } else if (node.num < t) {
                if (node.num != 1) {
                    deque.addLast(new Node(node.num * node.num, node.str + "*"));
                }
                deque.addLast(new Node(node.num * 2, node.str + "+"));
            }
        }
        if (result.isEmpty()) {
            return "-1";
        } else {
            return Collections.min(result);
        }
    }
}

class Node {
    long num;
    String str;

    public Node(long num) {
        this.num = num;
        this.str = "";
    }

    public Node(long num, String str) {
        this.num = num;
        this.str = str;
    }
}