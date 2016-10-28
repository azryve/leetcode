//
//  valid-sudoku.h
//  leetcode
//
//  Created by Fedor Zhukov on 27.10.16.
//
//

#ifndef __leetcode__valid_sudoku__
#define __leetcode__valid_sudoku__

#include <vector>
#include <iostream>
#include <utility>
#include <bitset>

#define ANY '.'

template <typename T>
class SudokuTest {
    typedef size_t (*id_function)(size_t, size_t);
    typedef std::bitset<(1 << sizeof(T)*8) - 1> bitvec;
public:
    SudokuTest(id_function foo) : get_id(foo) {};
    bool test(size_t i, size_t j, T val) {
        size_t id = get_id(i,j);
        bool ret = bitset[id].test(val);
        bitset[id].set(val);
        return ret;
    };
private:
    id_function get_id;
    std::vector<bitvec> bitset = std::vector<bitvec>(9);
};

class Solution {
public:
    static size_t row_id(size_t i, size_t j) { return i; }
    static size_t col_id(size_t i, size_t j) { return j; }
    static size_t sq_id(size_t i, size_t j) { return (j/3)*3 + i/3; }
    bool isValidSudoku(std::vector<std::vector<char> >& board) {
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board.size(); j++)
            {
                if (board[i][j] == ANY) continue;
                if (row_test.test(i, j, board[i][j])) return false;
                if (col_test.test(i, j, board[i][j])) return false;
                if (sq_test.test(i, j, board[i][j])) return false;
            }
        }
        return true;
    }
private:
    SudokuTest<char> row_test = SudokuTest<char>(row_id);
    SudokuTest<char> col_test = SudokuTest<char>(col_id);
    SudokuTest<char> sq_test = SudokuTest<char>(sq_id);
};

#endif /* defined(__leetcode__valid_sudoku__) */
