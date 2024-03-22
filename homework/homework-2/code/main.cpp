#include "node.hpp"
#include <iostream>
#include <iterator>
#include <ostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::vector;

// typedef vector<pair<Node *, int>> stateSpace;

// This class will operate on the nodes that are passed to it to calculate the best path to a solution.
class a_star
{
public:
  a_star() {}

  a_star(Node *node) { this->rootNode = node; }

  ~a_star() {}

  void printRoot() { rootNode->PrintNode(); }

  // runs the a-star and returns a pointer to the solution node.
  Node *run()
  {

    // Begin testing at the root.
    Node *currNode = this->rootNode;

    Node *testNode = new Node(*currNode);

    std::queue<Node *> searchQueue;
    searchQueue.push(currNode);

    currNode->addChild(testNode);
    testNode->setParent(currNode);
    testNode->moveTile(4, 1);

    // add the first node
    searchQueue.push(currNode);

    // begin finding a solution
    while (currNode->getBoardCost() != 0)
    {

      // return the node if a solution is found.
      if (currNode->getBoardCost() == 0)
      {
        cout << "Goal Reached! Printing Solution Now" << endl;
        return currNode;
      }

      // generate all of the children of the current state.
      vector possibleMoves = generateChildMoves(currNode);

      // clang-format off
      // DEBUG
      
      cout << "Before removing Duplicates" << endl; 
      for (auto move : possibleMoves) { cout << move->getBoard() << endl; }

      // Remove duplicate nodes.
      removeDuplicates(possibleMoves);

      // DEBUG
      cout << "After removing Duplicates" << endl; for (auto move : possibleMoves) { cout << move->getBoard() << endl; }
      std::string temp; cout << "Waiting on input from user" << endl; std::cin >> temp;
      // clang-format on
    }

    // returns the
    return currNode;
  };

  // searches for a duplicate nodes in a given vector and removes them.
  void removeDuplicates(vector<Node *> possibleMoves)
  {
    // delete all duplicate nodes that already exist.
    for (int index = 0; index < (int)possibleMoves.size(); index++)
    {

      // looks for a node in the tree.
      if (searchForNode(possibleMoves.at(index)))
      {
        cout << "Duplicate Node Found: " << possibleMoves.at(index)->getBoard() << endl;
        possibleMoves.erase(possibleMoves.begin(), possibleMoves.begin() + index);
      }
    }
  }

  // method to search for a node.
  Node *searchForNode(Node *input)
  {
    vector<Node *> searchQueue;
    searchQueue.push_back(this->rootNode);

    // begin searching the queue.
    while (!searchQueue.empty())
    {
      int queueSize = searchQueue.size();

      while (queueSize > 0)
      {
        // get the first node
        Node *currentNode = searchQueue.front();

        // remove the node from the queue.
        searchQueue.erase(searchQueue.begin());

        // return matching node
        if (currentNode->getBoard() == input->getBoard())
        {
          cout << "Matching Board: " << currentNode->getBoard() << endl;
          return currentNode;
        }

        // Append children of the queued item.
        for (int i = 0; i < (int)currentNode->getChildren().size(); i++)
        {
          searchQueue.push_back(currentNode->getChildren()[i]);
          queueSize++;
        }

        queueSize--;
      }
    }

    return nullptr;
  }

  void printChilren(vector<Node *> input)
  {

    // print all found moves.
    for (auto child : input)
    {
      child->printBoard();
    }
  }

  vector<Node *> generateChildMoves(Node *currNode)
  {
    vector<Node *> possibleMoves;

    for (int tile = 0; tile < 6; tile++)
    {

      // iterate through all possible moves.
      for (int move = 0; move < 5; move++)
      {
        Node *newMove = new Node(*currNode);

        int moveCost = newMove->moveTile(tile, move);

        if (moveCost > 0)
        {
          newMove->incrementNodeCost(moveCost);
          possibleMoves.push_back(newMove);
          cout << "Move Generated from: " + currNode->getBoard() + " : " + newMove->getBoard() << endl;
          cout << "New Move Board Cost: " << newMove->getBoardCost() << " New Move Node Cost: " << newMove->getNodeCost() << endl;
        }
        else
        {
          delete newMove;
        }
      }
    }

    return possibleMoves;
  }

  void showOptimalPath(){

  };

  // This function generates a vector given a solution node.
  // The vector recurses back from to the parent node.
  vector<Node *> generateSolution(Node *) {}

  void printSolution(vector<Node *> solution)
  {

    for (int i = solution.size(); i >= 0; i--)
    {
      Node *curr = solution.at(i);
      cout << "Cost: " << curr->getBoardCost() << "\t Board:" << curr->getBoard() << endl;
    }
  }

private:
  Node *rootNode;
};

int main(int argc, char *argv[])
{

  std::string firstState = "bbbwww_";

  if (argc == 2)
  {
    std::string input = argv[1];

    if (input.size() != 7)
    {
      cout << "Size of the board should be 7.\n Your string has size: " << input.size() << endl;
      exit(-1);
    }

    // cout << "Initial State: " << firstState << endl;
    firstState = input;
  }
  else if (argc > 2)
  {
    cout << "Usage: {program} {initial state}" << endl;
  }

  // Initialize the node.
  Node *initialNode = new Node(firstState);

  a_star myAStar(initialNode);

  // initialNode->PrintNode();

  myAStar.run();

  myAStar.showOptimalPath();

  return 0;
}
