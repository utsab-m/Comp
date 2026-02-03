import java.util.*;
import java.io.*;

public class Day9Part1 {
    public static void main(String[] args) {
        try {
            File file = new File("Day9Input.txt");
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);
            String line;
            List<List<Integer>> tiles = new ArrayList<>();
            long largestArea = 0;
    
            while ((line = br.readLine()) != null) {
                String[] coords = line.split(",");
                List<Integer> tile = new ArrayList<>();
                tile.add(Integer.parseInt(coords[0]));
                tile.add(Integer.parseInt(coords[1]));
                tiles.add(tile);
            }

            int m = tiles.size();

            for (int i = 0; i < m - 1; i++) {
                for (int j = i+1; j < m; j++) {
                    long dy = Math.abs(tiles.get(i).get(0) - tiles.get(j).get(0) + 1);
                    long dx = Math.abs(tiles.get(i).get(1) - tiles.get(j).get(1) + 1);
                    largestArea = Math.max(largestArea, dy * dx);
                }
            }
    
            System.out.println(largestArea);
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
