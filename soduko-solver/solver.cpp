// soduko-solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>
#include <unordered_map>
using soduko = std::array<int, 81>;

auto row_is_valid(int row, const soduko& puzzel) -> bool {
    std::array<bool, 10> found{};
    for (size_t i = 0; i < 9; i++) {
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

auto col_is_valid(int row, const soduko& puzzel) -> bool {
    std::array<bool, 10> found{};
    for (size_t i = 0; i < 9; i++) {
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

auto box_is_valid(int x, int y, const soduko& puzzel) -> bool {
    std::array<bool, 10> found{};
    for (size_t i = 0; i < 9; i++) {

        int x_s = i % 3;
        int y_s = auto value = puzzel[i * 9 + row];
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

auto is_valid(const soduko& puzzel) -> bool {
    return true;
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

    std::cout << row_is_valid(0, puzzel) << "\n";
    std::cout << col_is_valid(0, puzzel) << "\n";

    if (is_valid(puzzel)) {
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
