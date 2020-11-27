module fancy_fence;

import std.stdio, std.algorithm, std.string, std.conv;

struct Light
{
    int x, a, g, r;
}

void main(string[] args)
{
    int n, d;
    readf("%d %d\n", &n, &d);
    Light[] lights = new Light[n];
    foreach (i; 0 .. n)
    {
        readf("%d %d %d %d\n", &lights[i].x, &lights[i].a, &lights[i].g, &lights[i].r);
    }

    lights.sort!"a.x < b.x";
    foreach (ref l; lights)
    {
        int v = l.x - l.a;
        int t = v % (l.g + l.r);
        if (v < 0 || t > l.g)
        {
            writeln("NO");
            return;
        }

        debug
        {
            writeln(v, ", ", v);
        }

    }
    writeln("YES");

    debug
    {
        writeln(lights);
    }
}
