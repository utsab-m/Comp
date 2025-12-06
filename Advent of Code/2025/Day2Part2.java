import java.io.*;

public class Day2Part2 {
    public static boolean invalidSplit(String num, int numSplits) {
        int length = num.length();
        int numChars = length / numSplits;

        String compare = num.substring(0, numChars);

        for (int i = numChars; i < length; i += numChars) {
            int start = i;
            int end = i + numChars;
            if (!num.substring(start, end).equals(compare)) return false;
        }

        return true;
    }

    public static boolean valid(long num) {
        String str = Long.toString(num);
        int n = str.length();

        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                if (invalidSplit(str, i)) return false;
            }
        }

        return true;
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
                    if (!valid(i)) sum += i;
                }
            }
    
    
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

        System.out.println(sum);
    }
}
