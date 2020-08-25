module welcome_to_atcoder;
import std.stdio;
import std.container.rbtree;
import std.algorithm;

void main(string[] args)
{
    int n, m;
    readf("%d %d\n", &n, &m);
    int i;
    string s;
    int[int] penalties;
    auto acs = redBlackTree!int();
    foreach (_; 0 .. m)
    {
        readf("%d %s\n", &i, &s);
        if (s != "AC" && !(i in acs))
        {
            ++penalties[i];
            debug
            {
                writefln("%d %s :%d", i, s, penalties[i]);
            }
        }
        else
        {
            acs.stableInsert(i);
        }
    }
    writefln("%d %d", acs.length, penalties.byKeyValue.filter!(v => v.key in acs).map!"a.value".sum);
}
