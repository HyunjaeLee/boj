import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        boolean[][] map = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < N; j++) {
                if (line.charAt(j) == '1') {
                    map[i][j] = true;
                }
            }
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j]) {
                    int count = dfs(i, j, N, map);
                    list.add(count);
                }
            }
        }
        Collections.sort(list);
        bw.write(Integer.toString(list.size()));
        bw.newLine();
        for (Integer i : list) {
            bw.write(i.toString());
            bw.newLine();
        }
        bw.flush();
        bw.close();
        br.close();
    }

    private static int dfs(int row, int col, int N, boolean[][] map) {
        map[row][col] = false;
        int[] dr = {1, -1, 0, 0};
        int[] dc = {0, 0, 1, -1};
        int count = 1;
        for (int i = 0; i < 4; i++) {
            if (valid(row+dr[i], col+dc[i], N) && map[row+dr[i]][col+dc[i]]) {
                count += dfs(row+dr[i], col+dc[i], N, map);
            }
        }
        return count;
    }

    private static boolean valid(int row, int col, int N) {
        return row >= 0 && row < N && col >= 0 && col < N;
    }
}
