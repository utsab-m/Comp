import java.io.*;
import java.util.*;

public class AdventOfCode2 {
    
    public static void main(String args[]) {
        String line;
        int safe = 0;

        File file = new File("day2.txt");
        try {
            Reader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);

            read:
            while ((line = br.readLine()) != null) {
                String[] arr = line.split(" ");
                
                int[] array = new int[arr.length];
                for (int i = 0; i < arr.length; i++) {
                    array[i] = Integer.parseInt(arr[i]);
                }
                int d = array[0] - array[1];
                if (d == 0) continue read;
                if (d < 0 && Math.abs(d) <= 3) {
                    for (int i = 1; i < array.length - 1; i++) {
                        int diff = array[i] - array[i+1];
                        if (diff >= 0) {
                            continue read;
                        }
                        if (Math.abs(diff) > 3) {
                            
                            continue read;
                        }
                        
                    }
                    System.out.println(Arrays.toString(arr)); 
                    safe++;
                } else if (d > 0 && Math.abs(d) <= 3) {
                    for (int i = 1; i < array.length - 1; i++) {
                        int diff = array[i] - array[i+1];
                        if (diff <= 0) {
                            
                            continue read;
                        }
                        if (Math.abs(diff) > 3) {
                            
                            continue read;
                        }
                        
                    }
                    System.out.println(Arrays.toString(arr)); 
                    safe++;
                }
            }
            System.out.println(safe);
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
}
