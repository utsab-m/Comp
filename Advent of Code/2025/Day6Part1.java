import java.util.*;
import java.io.*;

public class Day6Part1 {
    public static void main(String[] args) {
    try {
        File file = new File("Day6Input.txt");
        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);
        String line;
        long sum = 0;
        ArrayList<String[]> lst = new ArrayList<>();

        while ((line = br.readLine()) != null) {
            lst.add(line.split("\\s+"));
        }

        int length = lst.get(0).length;
        int size = lst.size();

        for (int i = 0; i < length; i++) {
            char sign = lst.get(size - 1)[i].charAt(0);

            long col = (sign == '*') ? 1 : 0;

            for (int j = 0; j < size - 1; j++) {
                int num = Integer.parseInt(lst.get(j)[i]);
                if (sign == '*') {
                    col *= num;
                } else {
                    col += num;
                }
            }

            sum += col;
        }

        System.out.println(sum);
        br.close();
    } catch (Exception e) {
        e.printStackTrace();
    }
}
}
