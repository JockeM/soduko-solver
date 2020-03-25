// soduko-solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>
#include <unordered_map>
#include <stack>

using soduko = std::array<int, 81>;

auto row_is_valid(const int row, const soduko& puzzel) -> bool {
    std::array<bool, 10> found{};
    for (int i = 0; i < 9; i++) {
        auto value = puzzel[i + row * 9];
        std::cout << value << " ";
        if (value != 0) {
            if (found[value] == true) {
                return false;
            } else {
                found[value] = true;
            }
        }
    }
    return true;
}

auto col_is_valid(const int row, const soduko& puzzel) -> bool {
    std::array<bool, 10> found{};
    for (int i = 0; i < 9; i++) {
        auto value = puzzel[i * 9 + row];
        std::cout << value << " ";
        if (value != 0) {
            if (found[value] == true) {
                return false;
            } else {
                found[value] = true;
            }
        }
    }

    return true;
}
/// 0 1 2
///
/// 0
/// 1
/// 2

auto box_is_valid(const int box_x, const int box_y, const soduko& puzzel) -> bool {
    const int start_x = box_x * 3;
    const int start_y = box_y * 3;

    std::array<bool, 10> found{};
    for (int y = start_y; y < start_y + 3; y++) {
        for (int x = start_x; x < start_x + 3; x++) {
            auto value = puzzel[x + (y * 9)];
            if (value != 0) {
                if (found[value] == true) {
                    return false;
                } else {
                    found[value] = true;
                }
            }
        }
    }

    return true;
}

auto is_valid(const soduko& puzzel) -> bool {
    for (int i = 0; i < 9; i++) {
        if (!col_is_valid(i, puzzel) || !row_is_valid(i, puzzel)) {
            return false;
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (!box_is_valid(x, y, puzzel)) {
                return false;
            }
        }
    }

    return true;
}

struct puzzel_value_t {
    int x{};
    int y{};
    int value{};
};

auto solve(soduko puzzel) -> soduko { //very unfinshed
    std::stack<puzzel_value_t> stack{};

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            auto& target = puzzel[x + (y * 9)];
            if (target != 0) {
                continue;            
            }

            for (int i = 1; i < 10; i++) {
                target = i;
                if (is_valid(puzzel)) {
                    stack.push({x, y, i});
                }
            }        
        }
    }
}

int main() {
    // clang-format off
    std::array puzzel{
        0, 0, 5, 8, 9, 0, 2, 0, 6,
        9, 0, 0, 0, 0, 0, 0, 0, 0,
        6, 3, 8, 0, 0, 7, 9, 0, 0,
        0, 1, 3, 0, 0, 5, 0, 0, 0,
        2, 0, 4, 0, 7, 0, 6, 0, 1,
        0, 0, 0, 4, 0, 0, 8, 5, 0,
        0, 0, 7, 3, 0, 0, 1, 6, 8,
        0, 0, 0, 0, 0, 0, 0, 0, 5,
        4, 0, 9, 0, 1, 6, 3, 0, 0};
    // clang-format on

    if (is_valid(puzzel)) {
        std::cout << "is valid";
    } else {
        std::cout << "is not valid";
    }

    return EXIT_FAILURE;
}
