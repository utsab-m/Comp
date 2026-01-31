import java.util.*;
import java.io.*;

public class Day7Part1 {
    public static void main(String[] args) {
        try {
            File file = new File("Day7Input.txt");
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);
            String line;
    
            int splits = 0;
            List<String> grid = new ArrayList<>();
    
            while ((line = br.readLine()) != null) {
                grid.add(line);
            }

            int m = grid.size(), n = grid.get(0).length();

            Queue<int[]> q = new LinkedList<>();
            boolean[][] seen = new boolean[m+1][n+1];

            for (int i = 0; i < n; i++) {
                if (grid.get(0).charAt(i) == 'S') {
                    q.add(new int[]{0, i});
                    break;
                }
            }

            while (!q.isEmpty()) {
                int s = q.size();

                for (int i = 0; i < s; i++) {
                    int[] pos = q.poll();
                    int r = pos[0], c = pos[1];

                    if (!seen[r][c] && r < m && c >= 0 && c < n) {
                        if (grid.get(r).charAt(c) == '^') {
                            splits++;
                            int[] left = new int[]{r, c-1}, right = new int[]{r, c+1};
                            q.add(left);
                            q.add(right);
                        } else {
                            int[] down = new int[]{r+1, c};
                            q.add(down);
                        }
                    }

                    seen[r][c] = true;
                }
            }
    
            System.out.println(splits);
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
