/*
ID: yaagnto2
LANG: C++14
TASK: castle
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point &rhs) const {
        return x == rhs.x &&
               y == rhs.y;
    }

    bool operator!=(const Point &rhs) const {
        return !(rhs == *this);
    }
};

const int MAX_N = 51;
int M, N;
int A[MAX_N][MAX_N], G[MAX_N][MAX_N];
int Opposition[4], Dx[9], Dy[9];
int counter, largest, largest__create, wall;

vector<vector<Point> > Groups{};

int search(int x, int y, int sz) {
    G[y][x] = counter;
    Groups[counter].emplace_back(x, y);
    auto v = A[y][x];
    if ((v & 0b1111) == 0b1111) {
        return sz;
    } else {
        int w_sz = 4, dx, dy;
        for (int i = 0; i < 4; ++i) {
            int mask = 1 << i;
            dx = Dx[mask] + x;
            dy = Dy[mask] + y;
            if (!(v & mask) && G[dy][dx] == 0) {
                w_sz--;
                sz = search(dx, dy, sz + 1);
            }
        }
        return sz;
    }
}

void print() {
    int v;
    for (int i = 0; i < M * 4 + 1; ++i)cerr << "#";
    cerr << endl;
    for (int y = 2; y <= N * 2 + 1; ++y) {
        for (int x = 0; x <= M; ++x) {
            if (x == 0)cerr << "#";
            else {
                v = A[y / 2][x];
                if (y % 2 == 0) {
                    if (v & 4)cerr << "   #";
                    else cerr << "   |";
                } else {
                    if (v & 8)cerr << "####";
                    else cerr << "---#";
                }
            }
        }
        cerr << endl;
    }
}

auto main() -> int {
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    fin >> M >> N;
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= M; ++y) {
            fin >> A[x][y];
        }
    }
    print();


    Opposition[0] = 2;
    Opposition[1] = 3;
    Opposition[2] = 0;
    Opposition[3] = 1;
    Dx[1] = -1;
    Dy[2] = -1;
    Dx[4] = 1;
    Dy[8] = 1;
    Groups.emplace_back();
    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= M; ++x) {
            if (G[y][x] == 0) {
                counter++;
                Groups.emplace_back();
                largest = max(largest, search(x, y, 1));
            }
        }
    }
    fout << counter << endl;
    fout << largest << endl;
    if (counter == M * N && N >= 2) {
        fout << 2 << endl;
        fout << N << " " << 1 << " " << 'N' << endl;
    } else {
        sort(Groups.begin(), Groups.end(), [](vector<Point> &a, vector<Point> &b) { return a.size() > b.size(); });

        typedef tuple<int, Point, char> fuck_t;
        vector<fuck_t> fks;

        bool exist{};
        int create;
        for (auto a = Groups.begin(); a != prev(Groups.end()); ++a) {
            for (auto b = a + 1; b != Groups.end(); ++b) {
                exist = false;
                char d{}, nd{};
                Point p{0, 0}, np{M, 1};
                for (auto i:*a) {
                    for (auto j:*b) {
                        if ((abs(i.x - j.x) == 1 && i.y == j.y) ||
                            (abs(i.y - j.y) == 1 && i.x == j.x)) {
                            exist = true;
                            if (i.x == j.x) {
                                if (i.y > j.y) {
                                    p = i;
                                } else {
                                    p = j;
                                }
                                d = 'N';
                            } else {
                                if (i.x < j.x) {
                                    p = i;
                                } else {
                                    p = j;
                                }
                                d = 'E';
                            }
                            if (p.x < np.x || (p.x == np.x && p.y > np.y)) {
                                np = p;
                                nd = d;
                            }
                        }
                    }
                }
                if (exist > 0) {
                    create = static_cast<int>(a->size() + b->size());
                    fks.emplace_back(create, np, nd);
                }
            }
        }
        fuck_t fuck = *max_element(fks.begin(), fks.end(),
                                   [](const fuck_t &a, const fuck_t &b) { return get<0>(a) < get<0>(b); });
        fout << get<0>(fuck) << endl;
        auto p = get<1>(fuck);
        fout << p.y << " " << p.x << " " << get<2>(fuck) << endl;
    }
    return 0;
}
