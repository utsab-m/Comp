import java.io.*;
import java.util.*;

public class Day4Part1 {
    static List<String> pos = new ArrayList<String>();

    public static boolean validRoll(int r, int c) {
        int count = 0;
        for (int nr = r-1; nr <= r+1; nr++) {
            for (int nc = c-1; nc <= c+1; nc++) {
                if (inbounds(nr, nc) && pos.get(nr).charAt(nc) == '@' && (nr != r || nc != c)) count++;
            }
        }
        return count < 4;
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
            long count = 0;
    
            while ((line = br.readLine()) != null) {
                pos.add(line);
            }

            for (int r = 0; r < pos.size(); r++) {
                for (int c = 0; c < pos.get(r).length(); c++) {
                    if (pos.get(r).charAt(c) == '@' && validRoll(r, c)) {
                        count++;
                    }
                }
            }
            
            System.out.println(count);
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
