#include <vector>
#include <cstring>

using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        memset(line, 0, sizeof line);
        memset(col, 0, sizeof col);
        memset(block, 0, sizeof block);

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    int used = board[i][j] - '0' - 1;
                    line[i][used] = true;
                    col[j][used] = true;
                    block[i / 3][j / 3][used] = true;
                }
                else
                {
                    blank.emplace_back(i, j);
                }
            }
        }

        backtrace(board, 0);
    }

    void backtrace(vector<vector<char>> &board, int pos)
    {
        if (pos == blank.size())
        {
            valid = true;

            return;
        }

        auto [i, j] = blank[pos];
        for (int digit = 0; digit < 9 && !valid; ++digit)
        {
            if (!line[i][digit] && !col[j][digit] && !block[i / 3][j / 3][digit])
            {
                line[i][digit] = col[j][digit] = block[i / 3][j / 3][digit] = true;
                board[i][j] = digit + '0' + 1;

                backtrace(board, pos + 1);

                if (!valid)
                {
                    line[i][digit] = col[j][digit] = block[i / 3][j / 3][digit] = false;
                    board[i][j] = '.';
                }
            }
        }
    }

    bool line[9][9];
    bool col[9][9];
    bool block[3][3][9];

    vector<pair<int, int>> blank;

    bool valid = false;
};