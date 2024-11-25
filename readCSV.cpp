#include "readCSV.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

Eigen::MatrixXd readCSV(const std::string& filename, int rows, int cols) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    Eigen::MatrixXd data(rows, cols);
    std::string line;
    int row = 0;

    while (std::getline(file, line) && row < rows) {
        std::stringstream ss(line);
        std::string value;
        int col = 0;

        while (std::getline(ss, value, ',') && col < cols) {
            try {
                data(row, col) = std::stod(value);  // Convert string to double
            } catch (const std::invalid_argument& e) {
                throw std::runtime_error("Invalid value in file: " + filename);
            }
            col++;
        }

        if (col != cols) {
            throw std::runtime_error("Mismatch in column count at row " + std::to_string(row));
        }

        row++;
    }

    if (row != rows) {
        throw std::runtime_error("Mismatch in row count for file: " + filename);
    }

    return data;
}
