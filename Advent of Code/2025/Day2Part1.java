import java.io.*;

public class Day2Part1 {
    public static boolean valid(long num) {
        String str = Long.toString(num);
        int n = str.length();
        return str.substring(0, n / 2).equals(str.substring(n / 2));
    }

    public static void main(String[] args) {
        long sum = 0;

        try {
            File file = new File("Day2Input.txt");
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);
            String line;

            line = br.readLine();

            String[] intervals = line.split(",");

            for (String interval: intervals) {
                String[] ends = interval.split("-");
                long left = Long.parseLong(ends[0]), right = Long.parseLong(ends[1]);
                
                for (long i = left; i <= right; i++) {
                    if (valid(i)) sum += i;
                }
            }
    
    
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

        System.out.println(sum);
    }
}
