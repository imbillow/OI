module next_alphabet;

import std.stdio;

///
char resolve(char c)
{
    return cast(char)(c + 1);
}

void main(string[] args)
{
    char c;
    readf("%c", &c);
    writefln("%c", resolve(c));
}
