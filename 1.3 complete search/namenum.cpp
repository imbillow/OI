/*
ID: yaagnto2
LANG: C++14
TASK: namenum
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
int deep{};
string mapper[60];
vector<string> dict{};

vector<string> rec(vector<string> &origin, u_long pos) {
    if (origin[0].length() == pos)
        return origin;
    vector<string> dst{};
    for (string &item:origin) {
        string opts = mapper[item[pos]];
        for (char opt : opts) {
            string tmp{item};
            tmp[pos] = opt;
            if (binary_search(dict.begin(), dict.end(), tmp,
                              [=](const string &a, const string &b) {
                                  return a.compare(0, pos, b.substr(0, pos)) < 0;
                              }))
                dst.push_back(tmp);
        }
    }
    deep++;
    cerr << "depth:" << deep << endl;
    cerr << "length:" << dst.size() << endl;
    if (!dst.empty())
        return rec(dst, pos + 1);
    else
        return dst;
}

int main() {
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");

    ifstream dict_in("dict.txt");
    string buf;
    while (dict_in >> buf)
        dict.push_back(buf);

    mapper['2'] = "ABC";
    mapper['3'] = "DEF";
    mapper['4'] = "GHI";
    mapper['5'] = "JKL";
    mapper['6'] = "MNO";
    mapper['7'] = "PRS";
    mapper['8'] = "TUV";
    mapper['9'] = "WXY";

    string in;
    fin >> in;
    vector<string> real_in{in};
    vector<string> res = rec(real_in, 0);
    bool flag = true;

    if (!res.empty())
        for (string &s:res)
            if (binary_search(dict.begin(), dict.end(), s)) {
                flag = false;
                fout << s << endl;
            }
    if (flag)
        fout << "NONE" << endl;
    return 0;
}