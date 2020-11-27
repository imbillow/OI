module don_t_be_late;

import std.stdio;

void main(string[] args)
{
    float d, t, s;
    readf("%f %f %f\n", &d, &t, &s);
    if (d / s <= t)
    {
        writeln("Yes");
    }
    else
    {
        writeln("No");
    }
}
