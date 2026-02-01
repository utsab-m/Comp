import java.util.*;
import java.io.*;

public class Day7Part2 {
    static List<String> grid = new ArrayList<>();
    static int m;
    static int n;

    public static long dfs(int r, int c, long[][] timelines) {
        if (r == m) {
            return 1;
        }
        if (timelines[r][c] != 0) return timelines[r][c];

        char ch = grid.get(r).charAt(c);

        if (ch == '^') {
            timelines[r][c-1] = dfs(r, c-1, timelines);
            timelines[r][c+1] = dfs(r, c+1, timelines);
            
            return timelines[r][c-1] + timelines[r][c+1];
        }

        timelines[r][c] = dfs(r+1, c, timelines);
        
        return timelines[r][c];
    }

    public static void main(String[] args) {
        try {
            File file = new File("Day7Input.txt");
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);
            String line;

            while ((line = br.readLine()) != null) {
                grid.add(line);
            }

            m = grid.size();
            n = grid.get(0).length();

            long[][] timelines = new long[m+1][n+1];

            for (int i = 0; i < n; i++) {
                if (grid.get(0).charAt(i) == 'S') {
                    System.out.println(dfs(0, i, timelines));
                    break;
                }
            }
    
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
