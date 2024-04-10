#include "node.hpp"
#include "search_algorithm.hpp"
#include <iostream>
#include <ostream>
#include <string>

using std::cout;
using std::endl;

void parseArgs(int argc, char **argv, std::string *firstState);

int main(int argc, char *argv[])
{

  std::string firstState;

  parseArgs(argc, argv, &firstState);

  // Initialize the node.
  Node *initialNode = new Node(firstState);

  // Generate the first node.
  a_star myAStar(initialNode);

  // run a-star on the initial node.
  Node *solution = myAStar.a_star_run();

  // get the array for the solution
  vector<Node *> solutionArray = myAStar.generateSolution(solution);

  // show the optimal solution
  myAStar.showOptimalPath(solutionArray);

  return 0;
}


void parseArgs(int argc, char **argv, std::string *firstState)
{

  if (argc == 2)
  {
    std::string input = argv[1];

    if (input.size() != 7)
    {
      cout << "Size of the board should be 7.\n Your string has size: " << input.size() << endl;
      exit(-1);
    }

    // cout << "Initial State: " << firstState << endl;
    *firstState = input;
  }
  else if (argc > 2)
  {
    cout << "Usage: {program} {initial state}" << endl;
  }
  else
  {
    *firstState = "bbbwww_";
  }
}
