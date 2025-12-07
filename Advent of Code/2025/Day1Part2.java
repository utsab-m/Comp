import java.io.*;

public class Day1Part2 {
    public static int numZeros(long o, long n) {
        int z = 0;

        long smallZ = Math.min(o, n), bigZ = Math.max(o, n);

        System.out.println(smallZ);
        smallZ = (long)Math.floor((double)smallZ / 100);
        System.out.println(smallZ);
        System.out.println(bigZ);
        bigZ = (long)Math.ceil((double)bigZ / 100);
        System.out.println(bigZ);

        z += bigZ - smallZ - 1;

        return z;
    }
    public static void main(String[] args) {
        File file = new File("Day1Input.txt");
        String line;
        long c = 0;
        long pos = 50;

        try {
            Reader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);

            while ((line = br.readLine()) != null) {
                long turns = Integer.parseInt(line.substring(1));
                if (turns == 0) continue;

                if (line.charAt(0) == 'L') {
                    turns *= -1;
                } 
                
                long nextPos = pos + turns;

                c += numZeros(pos, nextPos);

                pos = (nextPos) % 100;
                if (pos == 0) c++;
            }

            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

        System.out.println(c);
    }
}
