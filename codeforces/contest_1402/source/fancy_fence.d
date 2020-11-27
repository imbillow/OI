module fancy_fence;

import std.stdio, std.algorithm, std.string, std.conv;

const uint modulo = cast(uint)1e9+7;

void main(string[] args)
{
    int n;
    readf("%d\n", &n);
    auto h = readln.split.map!(to!int);
    auto w = readln.split.map!(to!int);
    debug
    {
        writeln(h);
        writeln(w);
    }
}
