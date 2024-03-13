#pragma once
#include <string>
#include <vector>

// Node class used to hold the board state and the cost of the board. Manages
// board cost and conducts moves.
class Node
{
public:
  // Constructors
  Node(){
    this->board = std::string(7, 'x');
    updateBoardCost();

  };
  Node(std::string input) : board(input){
    updateBoardCost();
  };
  Node(Node const &input);
  ~Node(){};

  // Print the current node board.
  void PrintNode();

  // calculate the total cost of the current board and assign the cost to the `boardCost` variable.
  void updateBoardCost();

  // set the new board state using a string.
  void setBoard(std::string input);

  // pick a tile and make it move where you want.
  int moveTile(int tile, int move);

  int getCost();

  //
  // void operator=(Node const &obj);

private:
  std::string board;
  int boardCost;

  Node *parent;
  std::vector<Node *> children;
};
