import java.util.*;

//p5 TODO: error
public class Coin {
    Vector<Set<Integer>> d;
    int[] b;

    void add_rec(int i, int cnt) {
        b[i] += cnt;
        Set<Integer> set = d.get(i);
        if (!set.isEmpty()) {
            for (Integer ii : set)
                add_rec(ii, cnt);
        }
    }

    int get_rec(int i) {
        int r = b[i];
        Set<Integer> set = d.get(i);
        if (!set.isEmpty()) {
            for (Integer ii : set) {
                r %= (1e9 + 7);
                r += get_rec(ii);
            }
        } else {
            return b[i];
        }
        return r;
    }

    public int[] bonus(int n, int[][] leadership, int[][] operations) {
        d = new Vector<>(n + 1);
        b = new int[n + 1];
        List<Integer> r = new LinkedList<>();
        Arrays.fill(b, 0);
        for (int i = 0; i <= n; i++) {
            d.add(new TreeSet<Integer>());
        }
        for (int[] i : leadership) {
            d.get(i[0]).add(i[1]);
        }
        for (int[] i : operations) {
            switch (i[0]) {
                case 1: {
                    b[i[1]] += i[2];
                    break;
                }
                case 2: {
                    add_rec(i[1], i[2]);
                    break;
                }
                case 3: {
                    r.add(get_rec(i[1]));
                    break;
                }
            }
        }
        int[] rr = new int[r.size()];
        for (int i = 0; i < r.size(); i++) {
            rr[i] = r.get(i);
        }
        return rr;
    }

    public static void main(String[] args) {
        Coin coin = new Coin();
        System.out.println(Arrays.toString(coin.bonus(6, new int[][]{{1, 2}, {1, 6}, {2, 3}, {2, 5}, {1, 4}}, new int[][]{{1, 1, 500}, {2, 2, 50}, {3, 1}, {2, 6, 15}, {3, 1}})));
    }
}
