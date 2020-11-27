module deconstructed_password;

import std.stdio, std.algorithm, std.string, std.conv, std.array;

void main(string[] args)
{
    int n;
    readf("%d\n", &n);
    ubyte[] seq = readln.split.map!(to!ubyte).array;

    bool[] visited = new bool[n];
    ubyte[size_t] graph;
    ubyte idx = 0;

    foreach (i, v; seq)
    {
        if (visited[i])
            continue;
        if (idx >= 26)
        {
            writeln(-1);
            return;
        }

        auto pi = i, pv = v;
        while (true)
        {
            visited[pi] = true;
            if (pi < pv)
            {
                writeln(-1);
                return;
            }

            graph[pi] = idx;
            pi = pv;
            pv = seq[pi];

            if (pv >= n + 1)
            {
                break;
            }
        }
        idx++;

        debug
        {
            writeln(graph);
        }
    }

    ubyte[] password = new ubyte[n];
    ubyte ia = to!ubyte('a');
    foreach (i; 0 .. n)
    {
        password[i] = cast(ubyte)(graph[i] + ia);
    }
    writeln(password.assumeUTF);

    debug
    {
        writeln(seq);
    }
}
