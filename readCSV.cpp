#include "readCSV.h"
#include <Eigen/Dense>
#include <fstream>
#include <sstream>

Eigen::MatrixXd readCSV(const std::string& filename, int rows, int cols) {
    Eigen::MatrixXd output(rows, cols); // Initialize matrix with given dimensions

    std::ifstream file(filename);

    std::string line;
    int row = 0;

    while (std::getline(file, line) && row < rows) {
        std::stringstream ss(line);
        std::string value;
        int col = 0;

        while (std::getline(ss, value, ',') && col < cols) {
            output(row, col) = std::stod(value);
            col++;
        }

        row++;
    }

    file.close();
    return output;
}
