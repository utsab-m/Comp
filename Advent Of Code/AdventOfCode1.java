import java.io.*;
import java.util.*;

public class AdventOfCode1 {
    
    public static void main(String args[]) {
        ArrayList<Integer> left = new ArrayList<Integer>();
        ArrayList<Integer> right = new ArrayList<Integer>();
        HashMap<Integer, Integer> frequency = new HashMap<Integer, Integer>(); 
        int total = 0;
        boolean search = false;
        String line;

        File file = new File("txt.txt");
        try {
            Reader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);

            while ((line = br.readLine()) != null) {
                String[] split = line.split("   ");
                left.add(Integer.parseInt(split[0]));
                right.add(Integer.parseInt(split[1]));
            }

            Collections.sort(left);
            Collections.sort(right);

            for (int i = 0; i < left.size(); i++) {
                int freq = 0;
                for (int j = 0; j < right.size(); j++) {
                    if ((int)left.get(i) == (int)right.get(j)) {
                        freq++;

                        if (!search) {
                            search = true;
                        }
                    } else {
                        if (search) {
                            search = false;
                            frequency.put(left.get(i),  freq);
                        }
                    }
                }
                
            }

            for (Map.Entry<Integer, Integer> element: frequency.entrySet()) {
                System.out.println(element.getKey() + ": " + element.getValue());
                total += element.getKey() * element.getValue();
            }

            System.out.println(total);

            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
}
