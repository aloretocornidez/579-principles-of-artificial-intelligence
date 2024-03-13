#include "node.hpp"
#include <iostream>
#include <string>
#include <vector>

// This class will operate on the nodes that are passed to it to calculate the best path to a solution.
class a_star
{
public:
  a_star() {}

  a_star(Node *node) { this->rootNode = node; }

  ~a_star() {}

  void printRoot() { rootNode->PrintNode(); }

  void run()
  {

    // create a node to begin testing
    Node *currNode = this->rootNode;

    // begin finding a solution
    while (currNode->getCost() != 0)
    {




    }
  };

  void showOptimalPath(){

  };

private:
  Node *rootNode;
  std::vector<std::vector<Node *>> levels;
};

int main(int argc, char *argv[])
{

  std::string firstState = "bbb_www";

  if (argc == 2)
  {
    std::string input = argv[1];

    if (input.size() != 7)
    {
      std::cout << "Size of the board should be 7.\n Your string has size: " << input.size() << std::endl;
      exit(-1);
    }

    // std::cout << "Initial State: " << firstState << std::endl;
    firstState = input;
  }
  else if (argc > 2)
  {
    std::cout << "Usage: {program} {initial state}" << std::endl;
  }

  // Initialize the node.
  Node *initialNode = new Node(firstState);

  a_star myAStar(initialNode);

  initialNode->PrintNode();

  myAStar.run();

  myAStar.showOptimalPath();

  return 0;
}
