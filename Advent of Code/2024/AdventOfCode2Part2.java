import java.io.*;

public class AdventOfCode2Part2 {
    
    public static void main(String args[]) {
        String line;
        int safe = 0;

        File file = new File("day2.txt");
        try {
            Reader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);
            
            while ((line = br.readLine()) != null) {
                String[] arr = line.split(" ");
                
                if (safe(arr)) safe++;
                
            }
            System.out.println(safe);
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public static boolean safe(String[] arr) {
        int badLevel = 0; 
        boolean inc = Integer.parseInt(arr[0]) < Integer.parseInt(arr[arr.length - 1]);

        for (int i = 0; i < arr.length - 1; i++) {
            int leftNum = Integer.parseInt(arr[i]);
            int rightNum = Integer.parseInt(arr[i+1]);
            int diff = leftNum - rightNum;

            if (Math.abs(diff) > 3) return false;

            if (inc) {
                if (leftNum > rightNum ) {
                    badLevel++;
                }
            } else {
                if (leftNum <= rightNum) {
                    badLevel++;
                }
            }
            if (badLevel > 1) {
                return false;
            }
        }
        
        return true;
    }

    

}
