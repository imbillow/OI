module achieve_the_goal;
import std.stdio;
import std.string;
import std.algorithm;
import std.conv;

void main(string[] args)
{
    int n, k, m;
    readf("%d %d %d\n", &n, &k, &m);
    immutable s = readln.split.map!(to!int).sum;
    immutable need = max(n * m - s, 0);
    immutable result = need > k ? -1 : need;
    writeln(result);
}
