module maze_master;

import std.stdio;
import std.algorithm;
import std.container.dlist;
import std.typecons;

alias Vector2 = Tuple!(int, "x", int, "y");
alias V2List = DList!Vector2;

int h, w;
char[20][20] maze;
int[Vector2[2]] moves;
bool[20][20] visited;

void bfs(Vector2 start, V2List ps, int depth = 1)
{
    if (ps.empty)
        return;
    V2List vs;
    foreach (p; ps)
    {
        foreach (d; [[0, -1], [1, 0], [0, 1], [-1, 0]])
        {
            auto dx = d[0], dy = d[1];
            auto cx = p.x + dx, cy = p.y + dy;
            if (cx < 0 || cx >= w || cy < 0 || cy >= h || maze[cy][cx] == '#' || visited[cy][cx])
                continue;
            visited[cy][cx] = true;
            auto to = Vector2(cx, cy);
            Vector2[2] key = [start, to];
            moves[key] = depth;
            vs.insertBack(to);
        }
    }
    bfs(start, vs, depth + 1);
}

void main(string[] args)
{
    readf("%d %d\n", &h, &w);
    foreach (y; 0 .. h)
    {
        foreach (x; 0 .. w)
        {
            readf("%c", &maze[y][x]);
        }
        readln();
    }

    foreach (y; 0 .. h)
    {
        foreach (x; 0 .. w)
        {
            if (maze[y][x] == '#')
                continue;
            visited = visited.init;
            visited[y][x] = true;
            auto start = Vector2(x, y);
            bfs(start, V2List(start));
        }
    }

    debug
    {
        maze.each!(writefln);
        foreach (entry; moves.byKeyValue)
        {
            writeln(entry.key);
            writeln(entry.value);
        }
    }

    writefln("%d", moves.byValue.maxElement);
}
