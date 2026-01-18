import java.io.*;
import java.util.*;

public class Day5Part1 {
    static Map<Long, Long> ranges = new TreeMap<>();
    static List<List<Long>> finalRanges = new ArrayList<>();

    public static void main(String[] args) {
        try {
            File file = new File("Day5Input.txt");
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);
            String line;
            long fresh = 0;
    
            while ((line = br.readLine()) != null) {
                if (line.trim().equals("")) break;
                String[] ends = line.split("-");
                long cStart = Long.parseLong(ends[0]), cEnd = Long.parseLong(ends[1]);

                ranges.put(cStart, cEnd);
            }

            long start = 0, end = 0;

            for (Map.Entry<Long, Long> entry: ranges.entrySet()) {
                long cStart = entry.getKey(), cEnd = entry.getValue();

                if (start == 0 && end == 0) {
                    start = cStart;
                    end = cEnd;
                } else if (cStart > end) {
                    List<Long> cList = new ArrayList<>();
                    cList.add(start);
                    cList.add(end);
                    finalRanges.add(cList);

                    start = cStart;
                    end = cEnd;
                } else {
                    end = Math.max(end, cEnd);
                }


            }
            List<Long> fList = new ArrayList<>();
            fList.add(start);
            fList.add(end);
            finalRanges.add(fList);

            for (List<Long> l: finalRanges) {
                System.out.println(l.toString());
            }

            while ((line = br.readLine()) != null) {
                long id = Long.parseLong(line);

                for (List<Long> range: finalRanges) {
                    long cStart = range.get(0), cEnd = range.get(1);

                    if (cStart > id) break;
                    else if (id >= cStart && id <= cEnd) {
                        fresh++;
                        break;
                    }
                }
            }
            
            System.out.println(fresh);
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}