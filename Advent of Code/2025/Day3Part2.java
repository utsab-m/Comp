import java.io.*;
import java.util.*;

public class Day3Part2 {
    static long maxJoltage = 0;

    public static void backtrack(String num, List<Character> arr, int index) {
        if (arr.size() == 12) {
            maxJoltage = Math.max(maxJoltage, toLong(arr));
            return;
        } 

        for (int i = index; i < num.length(); i++) {
            arr.add(num.charAt(i));
            backtrack(num, arr, index + 1);
            arr.remove(arr.size() - 1);
        }
    }

    public static long toLong(List<Character> arr) {
        StringBuilder sb = new StringBuilder();

        for (char c: arr) sb.append(c);

        return Long.parseLong(sb.toString());
    }

    public static void getJoltage(String bank) {
        List<Character> arr = new ArrayList<Character>();
        backtrack(bank, arr, 0);
    }

    public static void main(String[] args) {
        try {
            File file = new File("Day3Input.txt");
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);
            String line;
    
            long totalJ = 0;
    
            while ((line = br.readLine()) != null) {
                maxJoltage = Long.parseLong(line.substring(0, 12));
                getJoltage(line);
                totalJ += maxJoltage;
            }
    
            System.out.println(totalJ);
    
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}