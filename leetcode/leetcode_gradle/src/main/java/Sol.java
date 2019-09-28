import java.util.Arrays;

public class Sol {
    public Sol() {
    }

    //p1
    public int game(int[] guess, int[] answer) {
        int r = 0;
        for (int i = 0; i < 3; i++) {
            r += guess[i] == answer[i] ? 1 : 0;
        }
        return r;
    }

    public int gcd(int a, int b) {
        if (b == 0) return a;
        if (a < b) return gcd(b, a);
        else return gcd(b, a % b);
    }

    //p2
    public int[] fraction(int[] cont) {
        int[] r = new int[2];
        int a0 = 1, a1 = cont[cont.length - 1],
                b, tmp;
        for (int i = cont.length - 2; i >= 0; i--) {
            b = cont[i];
            tmp = a0 + (b * a1);
            a0 = a1;
            a1 = tmp;
        }
        int g = gcd(a0, a1);
        a0 /= g;
        a1 /= g;
        r[0] = a1;
        r[1] = a0;
        return r;
    }

    /*        long nu = command.chars().filter(c -> c == 'U').count();
            long nr = command.chars().filter(c -> c == 'R').count();
            if (x % nu != 0)*/
//p3 TODO: error
    public boolean robot(String command, int[][] obstacles, int x, int y) {
        int mx = 0, my = 0;
        boolean danger = obstacles.length > 0;

        if (danger) {
            for (int[] pos : obstacles) {
                mx = Math.max(mx, pos[0]);
                my = Math.max(my, pos[1]);
            }
        }
        int ox = 0, oy = 0;
        int idx = 0, len = command.length();
        char c;
        char[] cs = command.toCharArray();
        while (true) {
            if (idx == command.length()) idx = 0;
            c = cs[idx];
            idx++;

            if (c == 'U') oy++;
            else if (c == 'R') ox++;
            if (danger) {
                for (int[] pos : obstacles) {
                    if (ox == pos[0] && ox == pos[1]) return false;
                }
            }
            if (ox == x && oy == y) return true;
            if (ox > mx && oy > my) danger = false;
            if (ox > x && oy > y) return false;
        }
    }

    public static void main(String[] args) {
        Sol p = new Sol();

//        System.out.println(Arrays.toString(p.fraction(new int[]{3, 2, 0, 2})));
        System.out.println(p.robot("URR", new int[][]{}, 3, 2));
    }
}
