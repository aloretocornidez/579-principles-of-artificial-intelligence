#include "node.hpp"
#include <iostream>
#include <string>

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
  Node initialNode(firstState);


  return 0;
}
