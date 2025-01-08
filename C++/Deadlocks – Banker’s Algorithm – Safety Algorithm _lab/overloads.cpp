#pragma once

#include <iostream>
#include <vector>

using std::vector;

typedef vector<int> row;
typedef vector<vector<int>> matrix;

/**
 * Overloads the subtraction operator to subtract two matrices
 *
 * @param matrix1 The first matrix
 * @param matrix2 The second matrix
 * @return The result of the matrix subtraction
 */
matrix operator-(matrix &matrix1, matrix &matrix2) {
  matrix result;
  for (int i = 0; i < matrix1.size(); i++) {
    row row;
    for (int j = 0; j < matrix1[i].size(); j++) {
      row.push_back(matrix1[i][j] - matrix2[i][j]);
    }
    result.push_back(row);
  }
  return result;
}

/**
 * Overloads the subtraction operator to subtract two rows
 *
 * @param row1 The first row
 * @param row2 The second row
 * @return The result of the row subtraction
 */
row operator-(row &row1, row &row2) {
  row result;
  for (int i = 0; i < row1.size(); i++) {
    result.push_back(row1[i] - row2[i]);
  }
  return result;
}

/**
 * Overloads the less than or equal to operator to compare two rows
 *
 * @param row1 The first row
 * @param row2 The second row
 * @return True if row1 is less than or equal to row2, false otherwise
 */
bool operator<=(row &row1, row &row2) {
  for (int i = 0; i < row1.size(); i++) {
    if (row1[i] > row2[i]) {
      return false;
    }
  }
  return true;
}

/**
 * Overloads the addition operator to add two rows
 *
 * @param row1 The first row
 * @param row2 The second row
 * @return The result of the row addition
 */
row operator+(row &row1, row &row2) {
  row result;
  for (int i = 0; i < row1.size(); i++) {
    result.push_back(row1[i] + row2[i]);
  }
  return result;
}

/**
 * Overloads the stream operator to display a row
 *
 * @param os The output stream
 * @param row The row to display
 * @return The output stream
 */
std::ostream &operator<<(std::ostream &os, const row &row) {
  os << "(";
  for (int i = 0; i < row.size(); i++) {
    std::cout << row[i] << ((i == row.size() - 1) ? "" : ",");
  }
  os << ")";
  return os;
}