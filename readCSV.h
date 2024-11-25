#ifndef READCSV_H
#define READCSV_H

#include <Eigen/Dense>
#include <string>

// Function to read a CSV file into an Eigen matrix
Eigen::MatrixXd readCSV(const std::string& filename, int rows, int cols);

#endif // READCSV_H
