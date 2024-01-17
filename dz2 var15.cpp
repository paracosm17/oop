#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int sum_elements(const std::vector<int>& row) {
    int sum = 0;
    for (int elem : row) {
        if (elem % 2 == 0) sum += elem;
    }
    return sum;
}

int main() {
    int N, M;
    std::cout << "Введите размеры матрицы N и M: ";
    std::cin >> N >> M;

    std::vector<std::vector<int>> matrix(N, std::vector<int>(M));
    srand(time(0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            matrix[i][j] = rand() % 100;
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::sort(matrix.begin(), matrix.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return sum_elements(a) > sum_elements(b);
    });

    std::cout << "Упорядоченная матрица:" << std::endl;

    for (const auto& row : matrix) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
