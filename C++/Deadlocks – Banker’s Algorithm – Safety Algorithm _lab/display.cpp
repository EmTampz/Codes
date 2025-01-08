#pragma once

#include "overloads.cpp"
#include <iomanip>
#include <iostream>

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