#include <iostream>
#include <vector>


//With Vector

//typedef std::vector<std::vector<int>> Matrix;
//
//Matrix createMatrix(int rows, int cols) {
//    Matrix matrix(rows, std::vector<int>(cols));
//    for(int i = 0; i < rows; ++i) {
//        for(int j = 0; j < cols; ++j) {
//            std::cout << "Enter value for matrix[" << i << "][" << j << "]: ";
//            std::cin >> matrix[i][j];
//        }
//    }
//    return matrix;
//}
//
//Matrix addMatrices(const Matrix& a, const Matrix& b) {
//    int rows = a.size();
//    int cols = a[0].size();
//    Matrix result = createMatrix(rows, cols);
//    for(int i = 0; i < rows; ++i) {
//        for(int j = 0; j < cols; ++j) {
//            result[i][j] = a[i][j] + b[i][j];
//        }
//    }
//    return result;
//}
//
//void printMatrix(const Matrix& matrix) {
//    for(const auto& row : matrix) {
//        for(const auto& elem : row) {
//            std::cout << elem << ' ';
//        }
//        std::cout << '\n';
//    }
//}
//
//int main() {
//    int rows, cols;
//    std::cout << "Enter number of rows: ";
//    std::cin >> rows;
//    std::cout << "Enter number of columns: ";
//    std::cin >> cols;
//
//    std::cout << "Creating first matrix...\n";
//    Matrix a = createMatrix(rows, cols);
//
//    std::cout << "Creating second matrix...\n";
//    Matrix b = createMatrix(rows, cols);
//
//    Matrix c = addMatrices(a, b);
//
//    std::cout << "First matrix:\n";
//    printMatrix(a);
//
//    std::cout << "Second matrix:\n";
//    printMatrix(b);
//
//    std::cout << "Sum matrix:\n";
//    printMatrix(c);
//
//    return 0;
//}

//With Arrays

const int MAX_SIZE = 100;

void createMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            std::cout << "Enter value for matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE];

    std::cout << "Creating first matrix...\n";
    createMatrix(a, rows, cols);

    std::cout << "Creating second matrix...\n";
    createMatrix(b, rows, cols);

    addMatrices(a, b, c, rows, cols);

    std::cout << "First matrix:\n";
    printMatrix(a, rows, cols);

    std::cout << "Second matrix:\n";
    printMatrix(b, rows, cols);

    std::cout << "Resultant matrix:\n";
    printMatrix(c, rows, cols);

    return 0;
}