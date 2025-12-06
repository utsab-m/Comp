import java.io.*;

public class Day3Part1 {
    public static int getJoltage(String bank) {
        int max = Integer.parseInt(bank.substring(0, 2));
        int pastMax = Math.max(bank.charAt(0) - '0', bank.charAt(1) - '0');

        for (int i = 2; i < bank.length(); i++) {
            int curr = bank.charAt(i) - '0';
            max = Math.max(max, pastMax * 10 + curr);
            pastMax = Math.max(pastMax, curr);
        }

        return max;
    }

    public static void main(String[] args) {
        try {
            File file = new File("Day3Input.txt");
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);
            String line;
    
            long totalJ = 0;
    
            while ((line = br.readLine()) != null) {
                totalJ += getJoltage(line);
            }
    
            System.out.println(totalJ);
    
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}