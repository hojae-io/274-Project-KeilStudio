#include "readCSV.h"
#include <fstream>
#include <sstream>

void readCSV(const std::string& filename, int rows, int cols, Eigen::MatrixXd& output) {
    // Initialize output matrix
    output = Eigen::MatrixXd::Zero(rows, cols);

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
}
