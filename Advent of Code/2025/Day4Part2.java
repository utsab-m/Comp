import java.io.*;
import java.util.*;

public class Day4Part2 {
    static List<String> pos = new ArrayList<String>();
    static Set<int[]> seen = new HashSet<int[]>();
    static long count = 0;

    public static int countValidNeighbors(int r, int c) {

        int count = 0;
        for (int nr = r-1; nr <= r+1; nr++) {
            for (int nc = c-1; nc <= c+1; nc++) {
                if (inbounds(nr, nc) && pos.get(nr).charAt(nc) == '@' && (nr != r || nc != c)) count++;
            }
        }
        return count;
        
    }

    public static boolean validRoll(int r, int c) {
        int count = 0;
        for (int nr = r-1; nr <= r+1; nr++) {
            for (int nc = c-1; nc <= c+1; nc++) {
                if (inbounds(nr, nc) && pos.get(nr).charAt(nc) == '@' && (nr != r || nc != c)) count++;
            }
        }
        return count < 4;
    }

    public static int[][] getValidNeighbors(int r, int c) {
        int[][] neighbors = new int[countValidNeighbors(r, c)][2];
        int i = 0;

        for (int nr = r-1; nr <= r+1; nr++) {
            for (int nc = c-1; nc <= c+1; nc++) {
                if (inbounds(nr, nc) && pos.get(nr).charAt(nc) == '@' && (nr != r || nc != c)) {
                    neighbors[i++] = new int[] {r, c};
                }
            }
        }

        return neighbors;
    }

    public static void bfs(int r, int c) {
        Queue<int[]> q = new LinkedList<int[]>();
        q.add(new int[]{r, c});

        while (!q.isEmpty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                int[] node = q.poll();
                int nr = node[0], nc = node[1];

                if (validRoll(nr, nc)) {
                    count++;
                    seen()
                }

            }
        }
    }

    public static boolean inbounds(int r, int c) {
        return r >= 0 && r < pos.size() && c >= 0 && c < pos.get(r).length();
    }

    public static void main(String[] args) {
        try {
            File file = new File("Day4Input.txt");
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);
            String line;
    
            while ((line = br.readLine()) != null) {
                pos.add(line);
            }

            for (int r = 0; r < pos.size(); r++) {
                for (int c = 0; c < pos.get(r).length(); c++) {
                    if (validRoll(r, c))
                }
            }
            
            System.out.println(count);
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
