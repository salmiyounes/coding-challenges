import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Solution {
	public static Map<String, Integer> dists = new HashMap<>();
	public static Set<String> places = new HashSet<>();


    public static void main(String[] args) throws FileNotFoundException {

        Scanner s = new Scanner(new File("input.txt"));

        Map<String, Integer> dists = new HashMap<>();
        Set<String> places = new HashSet<>();

        while (s.hasNextLine()) {
            String line = s.nextLine();
            System.out.println(line);

            String[] split = line.split(" ");

            places.add(split[0]);
            places.add(split[2]);

            dists.put(split[0]+split[2], Integer.parseInt(split[4]));
            dists.put(split[2]+split[0], Integer.parseInt(split[4]));
        }

        List<Integer> res = new ArrayList<>();

        for (String place: places) {
            permutate(place, ,new ArrayList<String>(), 0, )
        }

    }

    private static void permutate(String place, String start, int count, List<String> string, int num, List<Integer> res) {
        if (count == places.size()) {
            res.add(num);
            return ;
        } 

        for (String key: places) {
            if (!string.contains(key)) {
                string.add(key);
                permutate(key, string.get(string.size() -2), count + 1,string, num + dists.get(string.get(string.size( ) - 2) + key), res);
                string.remove(key);
            }
        } 

    }
}