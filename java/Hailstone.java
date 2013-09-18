import java.io.*;
import java.util.List;
import java.util.ArrayList;

public class Hailstone {

    public static List<Integer> hailstoneSequence(int n) {
        List<Integer> l = new ArrayList<Integer>();
        while (n != 1 ) {
            if (n % 2 == 0) {
                n = n / 2;
            }
            else {
                n = n * 3 + 1;
            }
        }
        l.add(n);
        return l;
    }

}
