import java.io.*;

public class Day1Part1 {
    public static void main(String[] args) {
        File file = new File("Day1Input.txt");
        String line;
        int c = 0;
        int pos = 50;

        try {
            Reader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);

            while ((line = br.readLine()) != null) {
                int turns = Integer.parseInt(line.substring(1));
                if (line.charAt(0) == 'L') {
                    turns *= -1;
                } 
                pos = (pos + turns) % 100;
                if (pos == 0) c++;

            }

            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

        System.out.println(c);
    }
}
