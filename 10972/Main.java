import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        int[] permutation = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < N; i++) {
            permutation[i] = Integer.parseInt(st.nextToken());
        }
        if (nextPermutation(permutation)) {
            for (int i = 0; i < N; i++) {
                bw.write(Integer.toString(permutation[i]));
                bw.write(' ');
            }
        } else {
            bw.write("-1");
        }
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();
    }

    private static boolean nextPermutation(int[] arr) {
        if (arr == null || arr.length <= 1) return false;
        int i = arr.length - 1;
        int j = arr.length - 1;
        while (i > 0 && arr[i - 1] >= arr[i]) i--;
        if (i == 0) return false;
        while (arr[i - 1] > arr[j]) j--;
        arr[i - 1] = arr[i - 1] ^ arr[j]; // XOR swap
        arr[j] = arr[i - 1] ^ arr[j];
        arr[i - 1] = arr[i - 1] ^ arr[j];
        j = arr.length - 1;
        while (i < j) {
            arr[i] = arr[i] ^ arr[j]; // XOR swap
            arr[j] = arr[i] ^ arr[j];
            arr[i] = arr[i] ^ arr[j];
            i++;
            j--;
        }
        return true;
    }
}
