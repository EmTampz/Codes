/*
 * Legolas Tyrael B. Lada 2-BSCS
 * 2022-04734
 */

// Start of overloads.cpp content
#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>

using std::vector;
using std::ostream;


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
ostream &operator<<(ostream &os, const row &row) {
  os << "(";
  for (int i = 0; i < row.size(); i++) {
    std::cout << row[i] << ((i == row.size() - 1) ? "" : ",");
  }
  os << ")";
  return os;
}
// End of overloads.cpp content

// Start of display.cpp content
/**
 * Takes a matrix and displays it in a tabular format
 *
 * @param matrix The matrix to display
 */
void displayMatrix(matrix &matrix) {
  // header row
  std::cout << std::left << std::setw(10) << "Process ";
  for (int i = 1; i <= matrix[0].size(); i++) {
    std::cout << "R" << std::left << std::setw(3) << i << " ";
  }

  std::cout << "\n";

  for (int i = 0; i < matrix.size(); i++) {
    std::cout << "P" << std::setw(9) << i + 1;
    for (int j = 0; j < matrix[i].size(); j++) {
      std::cout << std::setw(4) << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}

/**
 * Displays the information parsed from the file
 *
 * @param allocatedMatrix The matrix of allocated resources
 * @param maxMatrix The matrix of maximum resources
 * @param resourceInstances The row of resource instances
 */
void displayInfo(matrix &allocatedMatrix, matrix &maxMatrix,
                 row &resourceInstances, matrix &needMatrix,
                 row &availableRow) {

  for (int i = 1; i <= resourceInstances.size(); i++) {
    std::cout << "Resource " << i << "(R" << i << ") = " << std::setw(3)
              << resourceInstances[i - 1] << " instances\n";
  }

  std::cout << "\nAllocated Resources for the " << allocatedMatrix.size()
            << " processes:\n\n";
  displayMatrix(allocatedMatrix);

  std::cout << "\nMaximum Resources for the " << maxMatrix.size()
            << " processes:\n\n";
  displayMatrix(maxMatrix);

  std::cout << "\nNeed matrix for the 5 processes:\n\n";
  displayMatrix(needMatrix);

  int allocated;

  std::cout << "\nAvailable instances for each resource type: (";
  for (int i = 0; i < resourceInstances.size(); i++) {
    std::cout << "R" << i + 1
              << ((i == resourceInstances.size() - 1) ? "" : ",");
  }
  std::cout << ") = " << availableRow << "\n";
}

/**
 * Runs the safety algorithm to determine if a safe sequence exists
 *
 * @param allocatedMatrix The matrix of allocated resources
 * @param needMatrix The matrix of needed resources
 * @param resourceInstances The vector of resource instances
 * @param availableRow The row of available resources
 */
void runSafetyAlgorithm(matrix &allocatedMatrix, matrix &needMatrix,
                        row &resourceInstances, row &availableRow) {
  std::cout << "Running the Safety Algorithm...\n\n";

  row processesLeft, safeSequence;
  for (int i = 0; i < allocatedMatrix.size(); i++) {
    processesLeft.push_back(i);
  }

  int processLeftIndex, i = 0;
  // while there are processes left
  while (processesLeft.size()) {
    processLeftIndex = -1;
    for (i = i % processesLeft.size(); i < processesLeft.size(); i++) {
      if (needMatrix[processesLeft[i]] <= availableRow) {
        processLeftIndex = i;
        break;
      }
    }

    if (processLeftIndex == -1) {
      std::cout << "No safe sequence exists\n";
      return;
    }

    std::cout << "P" << processesLeft[processLeftIndex] + 1
              << " is given the resources...\nAvailable is " << availableRow
              << " - " << needMatrix[processesLeft[processLeftIndex]] << " = "
              << availableRow - needMatrix[processesLeft[processLeftIndex]]
              << "\n";

    std::cout << "Available is " << availableRow << "+"
              << allocatedMatrix[processesLeft[processLeftIndex]] << " = "
              << availableRow + allocatedMatrix[processesLeft[processLeftIndex]]
              << "\n";

    std::cout << "P" << processesLeft[processLeftIndex] + 1
              << " is now done with the resources.\n\n";

    availableRow =
        availableRow + allocatedMatrix[processesLeft[processLeftIndex]];

    safeSequence.push_back(processesLeft[processLeftIndex]);
    std::cout << "Current Safe Sequence is <";
    for (int sequence : safeSequence) {
      std::cout << "P" << sequence
                << ((sequence == safeSequence.back()) ? "" : ",");
    }
    std::cout << ">\n\n";
    processesLeft.erase(processesLeft.begin() + processLeftIndex);
  }
}
// End of display.cpp content

// Start of lada.cpp content




void parseFile(string filename, matrix &allocatedMatrix, matrix &maxMatrix,
               vector<int> &resourceInstances);
void getAvailableRow(matrix &allocatedMatrix, vector<int> &resourceInstances,
                     row &availableRow);

int main(int argc, char *argv[]) {
  string filename = argc > 1 ? argv[1] : "";
  if (filename == "") {
    std::cerr << "Please provide a file to parse\n\n"
                 "Usage: ./lada <filename>\n";
    return 1;
  }

  row resourceInstances, availableRow;
  matrix allocatedMatrix, maxMatrix, needMatrix;
  parseFile(filename, allocatedMatrix, maxMatrix, resourceInstances);

  // solve for the need matrix using matrix subtraction
  needMatrix = maxMatrix - allocatedMatrix;

  getAvailableRow(allocatedMatrix, resourceInstances, availableRow);
  displayInfo(allocatedMatrix, maxMatrix, resourceInstances, needMatrix,
              availableRow);

  runSafetyAlgorithm(allocatedMatrix, needMatrix, resourceInstances,
                     availableRow);

  return 0;
}

/**
 * Takes a filename and parses the file into the format specified by the
 * assignment.
 *
 * @param filename The name of the file to parse
 * @return 0 if successful, 1 if file not found
 */
void parseFile(string filename, matrix &allocatedMatrix, matrix &maxMatrix,
               vector<int> &resourceInstances) {
  int resourceTypesCount, processCount, resourceInstanceCount;

  // open file in read mode
  std::ifstream parsedFile(filename);
  if (parsedFile.rdstate() & std::ifstream::failbit) {
    std::cerr << "File not found\n";
    return;
  }

  // read the first two lines
  parsedFile >> resourceTypesCount >> processCount;
  for (int i = 0; i < resourceTypesCount; i++) {
    parsedFile >> resourceInstanceCount;
    resourceInstances.push_back(resourceInstanceCount);
  }

  int col;

  // read the rest of the file
  for (int i = 0; i < processCount; i++) {
    row columns;
    parsedFile.ignore(3, ' '); // skip the process name

    // first half of columns
    for (int j = 0; j < resourceTypesCount; j++) {
      parsedFile >> col;
      columns.push_back(col);
    }
    allocatedMatrix.push_back(columns);
    columns.clear();

    // second half of columns
    for (int j = 0; j < resourceTypesCount; j++) {
      parsedFile >> col;
      columns.push_back(col);
    }
    maxMatrix.push_back(columns);
    columns.clear();
  }

  parsedFile.close();
}

/**
 * Calculates the available row by subtracting the total allocation from the
 * resource instances.
 *
 * @param allocatedMatrix The matrix containing the allocated resources
 * @param resourceInstances The vector containing the total resource instances
 * @param availableRow The row containing the available resources
 */
void getAvailableRow(matrix &allocatedMatrix, row &resourceInstances,
                     row &availableRow) {
  row totalAllocation;
  int column;
  for (int i = 0; i < allocatedMatrix[0].size(); i++) {
    column = 0;
    for (int j = 0; j < allocatedMatrix.size(); j++) {
      column += allocatedMatrix[j][i];
    }

    totalAllocation.push_back(column);
  }
  availableRow = resourceInstances - totalAllocation;
}
// End of lada.cpp content
