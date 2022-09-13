//
//  mazequeue.cpp
//  Homework 2
//
//  Created by Nikhil Isukapalli on 1/30/21.
//

#include <iostream>
#include <queue>
using namespace std;

class Coord
{
  public:
    Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
  private:
    int m_row;
    int m_col;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
    queue<Coord> pts;
    Coord start(sr, sc);
    pts.push(start);
    maze[sr][sc] = '#';
    while (! pts.empty()) {
        Coord topPt = pts.front();
        pts.pop();
        if (topPt.r() == er && topPt.c() == ec) {
            return true;
        }
        if (maze[topPt.r()-1][topPt.c()] == '.') {
            int nRow = topPt.r()-1;
            int nCol = topPt.c();
            Coord north(nRow, nCol);
            pts.push(north);
            maze[nRow][nCol] = '#';
        }
        if (maze[topPt.r()][topPt.c()+1] == '.') {
            int eRow = topPt.r();
            int eCol = topPt.c()+1;
            Coord east(eRow, eCol);
            pts.push(east);
            maze[eRow][eCol] = '#';
        }
        if (maze[topPt.r()+1][topPt.c()] == '.') {
            int sRow = topPt.r()+1;
            int sCol = topPt.c();
            Coord south(sRow, sCol);
            pts.push(south);
            maze[sRow][sCol] = '#';
        }
        if (maze[topPt.r()][topPt.c()-1] == '.') {
            int wRow = topPt.r();
            int wCol = topPt.c()-1;
            Coord west(wRow, wCol);
            pts.push(west);
            maze[wRow][wCol] = '#';
        }
    }
    return false;
}

int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X........X",
        "XX.X.XXXXX",
        "X..X.X...X",
        "X..X...X.X",
        "XXXX.XXX.X",
        "X.X....XXX",
        "X..XX.XX.X",
        "X...X....X",
        "XXXXXXXXXX"
    };

    if (pathExists(maze, 10,10, 6,4, 1,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}
