#pragma once

#include "node.hpp"
#include <vector>

using std::vector;

// This class will operate on the nodes that are passed to it to calculate the
// best path to a solution.
class a_star
{
public:
  a_star() {}

  a_star(Node *node) { this->rootNode = node; }

  ~a_star() {}
  void printRoot();
  Node *a_star_run();
  int findMinCost();
  Node *searchTreeForBoard(Node *input);
  vector<Node *> generateChildMoves(Node *currNode);
  void showOptimalPath(vector<Node *> solution);
  vector<Node *> generateSolution(Node *solution);

private:
  void removeDupsInQueue(vector<Node *> *children);
  void removeDupsInTree(vector<Node *> *children);
  Node *rootNode;
  std::vector<Node *> openQueue;
};
