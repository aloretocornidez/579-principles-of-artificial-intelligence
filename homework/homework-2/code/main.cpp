#include "node.hpp"
#include <iostream>
#include <ostream>
#include <queue>
#include <string>
#include <vector>

using std::cout;
using std::endl;
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

    // used to find how long the alrorithm ran.
    int iterations = 0;

    // create an open queue
    vector<Node *> openQueue;

    // Begin testing at the root.
    openQueue.push_back(this->rootNode);

    Node *currNode;

    // Initialize the index of the first node the algorithm will use.
    int openQueueMinIndex = 0;

    // begin finding a solution
    while (!openQueue.empty())
    {

      // find the lowest cost node on the open queue.
      currNode = openQueue.at(openQueueMinIndex);


      // pop the node off of the queue.
      openQueue.erase(std::next(openQueue.begin(), openQueueMinIndex));


      // print the current node board
      cout << "Current Board: " << currNode->getBoard() << endl;


      // return the node if a solution is found.
      if (currNode->getBoardCost() == 0)
      {
        cout << "Goal Reached! Printing Solution Now" << endl;

        return currNode;
      }

      // generate all of the children of the current state.
      vector<Node *> possibleMoves = generateChildMoves(currNode);

      // Remove nodes that have a board state present on the tree.
      removeDupsInTree(possibleMoves);
      removeDupsInQueue(possibleMoves, openQueue);

      // Add the moves to the tree.
      currNode->setChildren(possibleMoves);

      // add the moves to the queue.
      for (auto move : possibleMoves)
      {
        openQueue.push_back(move);
      }

      // Find the node with the lowest h cost and set the index of the node.
      int minHCost;
      for (int i = 0; i < openQueue.size(); i++)
      {
        Node *temp = openQueue.at(i);

        int hCost = temp->getBoardCost() + temp->getCumilativeMoveCost() + temp->getLevel();

        if (i == 0)
        {
          minHCost = hCost;
          openQueueMinIndex = 0;
        }

        if (hCost <= minHCost)
        {
          minHCost = hCost;
          openQueueMinIndex = i;
        }

      }

      // cout << "Current Open Queue\n";
      // for(auto move : openQueue)
      // {
      //   move->printBoard();
      // }
      // cout << "Current Open Queue\n\n";
      //
      // cout << "Current possibleMoves\n";
      // for(auto move : possibleMoves)
      // {
      //   move->printBoard();
      // }
      // cout << "Current possibleMoves\n\n";

      // std::string asdf; std::cout << std::to_string(minHCost) << endl; std::cin >> asdf;

      // update iteration count
      iterations++;
    }

    // returns the
    return currNode;
  };

  
  void removeDupsInQueue(vector<Node*> possibleMoves, vector<Node*> openQueue)
  {
    // delete all duplicate nodes that already exist.

    for(auto state : openQueue)
    {
      for (int index = 0; index < (int)possibleMoves.size(); index++)
      {

        // looks for a node in the tree.
        if (state->getBoard() == possibleMoves.at(index)->getBoard())
        {
          // cout << "Duplicate Node Found: " << possibleMoves.at(index)->getBoard() << endl;
          possibleMoves.erase(possibleMoves.begin(), possibleMoves.begin() + index);
        }
      }
    }

  }

  // searches for a duplicate nodes in a given vector and removes them.
  void removeDupsInTree(vector<Node *> possibleMoves)
  {
    // delete all duplicate nodes that already exist.
    for (int index = 0; index < (int)possibleMoves.size(); index++)
    {

      // looks for a node in the tree.
      if (searchForBoard(possibleMoves.at(index)))
      {
        // cout << "Duplicate Node Found: " << possibleMoves.at(index)->getBoard() << endl;
        possibleMoves.erase(possibleMoves.begin(), possibleMoves.begin() + index);
      }
    }
  }

  // method to search for a node.
  Node *searchForBoard(Node *input)
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
          // cout << "Matching Board: " << currentNode->getBoard() << endl;
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
          // cout << "Move Generated from: " + currNode->getBoard() + " : " + newMove->getBoard() << endl;
          // cout << "New Move Board Cost: " << newMove->getBoardCost() << " New Move Node Cost: " << newMove->getCumilativeMoveCost() << endl;
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
  vector<Node *> generateSolution(Node *solution)
  {

    Node *temp = solution;
    vector<Node *> solutionVector;

    while (temp->getParent() != nullptr)
    {
      solutionVector.push_back(temp);

      temp = temp->getParent();
    }

    return solutionVector;
  }

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
