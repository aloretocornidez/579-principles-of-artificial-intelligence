#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class Node {
public:
  Node();
  Node(std::string input);
  ~Node();

  // Print the current node board.
  void PrintNode();

  // calculate the total cost of the current board.
  void calculateBoardCost();

  // set the new board state using a string.
  void setBoard(std::string input);

  // pick a tile and make it move where you want.
  void moveTile(int tile, int move);

private:
  char board[7];
  Node *parent;
  std::vector<Node *> children;
  int hOfNnode;
};

// Initialize node with the default board given in the homework statement.
Node::Node() {
  this->board[0] = 'b';
  this->board[1] = 'b';
  this->board[2] = 'b';
  this->board[3] = 'w';
  this->board[4] = 'w';
  this->board[5] = 'w';
  this->board[6] = '_';
}

Node::Node(std::string input){
  this->board[0] = input.at(0);
  this->board[1] = input.at(1);
  this->board[2] = input.at(2);
  this->board[3] = input.at(3);
  this->board[4] = input.at(4);
  this->board[5] = input.at(5);
  this->board[6] = input.at(6);

}

Node::~Node() {}

// Print the board values.
void Node::PrintNode() {
  for (int i = 0; i < 7; i++) {
    std::cout << this->board[i];
  }
  std::cout << std::endl;
}

void Node::calculateBoardCost() {}

void Node::setBoard(std::string input) {

  if (input.size() < 7) {
    std::cout << "Board size is smaller than 7 tiles" << std::endl;
    exit(-1);
  }

  this->board[0] = input.at(0);
  this->board[1] = input.at(1);
  this->board[2] = input.at(2);
  this->board[3] = input.at(3);
  this->board[4] = input.at(4);
  this->board[5] = input.at(5);
  this->board[6] = input.at(6);
}

void Node::moveTile(int tile, int move) {
  if (tile < 0 || tile >= 7) {
    std::cout << "Invalid tile Size used ot move tile. Tile Size: " << tile
              << std::endl;
    exit(-1);
  }

  // there are 6 possible moves
  // 0. Tile hops two spots to the right.
  // 1. Tile hops over one tile to the right.
  // 2. Tile slides to the adjacent right.
  // 3. Tile moves to the adjecent left.
  // 4. Tile hops over one tile to the left.
  // 5. Tile hops over two tiles to the left.
  char tempTile = this->board[tile];

  // bbb_www
  switch (move) {
  case 0:
    this->board[tile] = this->board[tile+3];
    this->board[tile+3] = tempTile;
    break;
  case 1:
    this->board[tile] = this->board[tile+2];
    this->board[tile+2] = tempTile;
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  }
}

int main(int argc, char *argv[]) {

  Node rootNode("bwb_www");

  rootNode.PrintNode();

  rootNode.moveTile(0, 0);

  rootNode.PrintNode();

  return 0;
}
