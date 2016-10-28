//
//  valid-sudoku.cpp
//  leetcode
//
//  Created by Fedor Zhukov on 27.10.16.
//
//

#include "valid-sudoku.h"
#include <string>
#include <map>

static Solution s;

int main()
{
    const char *r[] = {".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........", "9........"};
    //char* r[] = {"....5..1.",".4.3.....",".....3..1","8......2.","..2.7....",".15......",".....2...",".2.9.....","..4......"};
    std::vector<std::vector<char> > v(sizeof(r)/sizeof(*r));
    for (size_t i = 0; i < sizeof(r)/sizeof(*r); i++) {
        for (auto s : std::string(r[i]))
            v[i].push_back(s);
    }
    if (s.isValidSudoku(v))
        std::cout << "true\n";
    else
        std::cout << "false\n";
    return 0;
}