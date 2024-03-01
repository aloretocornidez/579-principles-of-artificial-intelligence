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
  void updateBoardCost();

  // set the new board state using a string.
  void setBoard(std::string input);

  // pick a tile and make it move where you want.
  void moveTile(int tile, int move);

private:
  char board[7];
  const int boardSize = 7;
  int boardCost;
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

  updateBoardCost();
}

Node::Node(std::string input) {
  this->board[0] = input.at(0);
  this->board[1] = input.at(1);
  this->board[2] = input.at(2);
  this->board[3] = input.at(3);
  this->board[4] = input.at(4);
  this->board[5] = input.at(5);
  this->board[6] = input.at(6);

  updateBoardCost();
}

Node::~Node() {}

// Print the board values.
void Node::PrintNode() {
  std::cout << "Board Cost: " << this->boardCost << std::endl;
  for (int i = 0; i < this->boardSize; i++) {
    std::cout << this->board[i];
  }
  std::cout << std::endl;
}

void Node::updateBoardCost() {

  int blackTiles = 0;
  int cost = 0;
  for (int i = 0; i < this->boardSize; i++) {
    if (this->board[i] == 'b') {
      blackTiles++;
    }

    if (this->board[i] == 'w') {
      cost += blackTiles;
    }
  }

  this->boardCost = cost;
}

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

  updateBoardCost();
}

void Node::moveTile(int tileIndex, int move) {
  if (tileIndex < 0 || tileIndex >= 7) {
    std::cout << "Invalid tile Size used to move tile. Tile Size: " << tileIndex
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

  // checking move and making the move if it is valid.
  if (move == 0) {

    int change = 3;
    if (tileIndex + change >= 7 || tileIndex + change < 0) {
      std::cout << "The move is out of bounds" << std::endl;
      exit(-1);
    }
    if (this->board[tileIndex + change] != '_') {
      std::cout << "Tile " << tileIndex
                << " cannot hop over two places to the right." << std::endl;
      exit(-1);
    }
    char tempTile = this->board[tileIndex];

    this->board[tileIndex] = this->board[tileIndex + change];
    this->board[tileIndex + change] = tempTile;
  } else if (move == 1) {

    int change = 2;
    if (tileIndex + change >= 7 || tileIndex + change < 0) {
      std::cout << "The move is out of bounds" << std::endl;
      exit(-1);
    }
    if (this->board[tileIndex + change] != '_') {
      std::cout << "Tile " << tileIndex
                << " cannot hop over a tile to the right." << std::endl;
      exit(-1);
    }
    char tempTile = this->board[tileIndex];

    this->board[tileIndex] = this->board[tileIndex + change];
    this->board[tileIndex + change] = tempTile;

  } else if (move == 2) {
    int change = 1;
    if (tileIndex + change >= 7 || tileIndex + change < 0) {
      std::cout << "The move is out of bounds" << std::endl;
      exit(-1);
    }
    if (this->board[tileIndex + change] != '_') {
      std::cout << "Tile " << tileIndex
                << " cannot hop over a tile to the right." << std::endl;
      exit(-1);
    }
    char tempTile = this->board[tileIndex];

    this->board[tileIndex] = this->board[tileIndex + change];
    this->board[tileIndex + change] = tempTile;

  } else if (move == 3) {
    int change = -1;
    if (tileIndex + change >= 7 || tileIndex + change < 0) {
      std::cout << "The move is out of bounds" << std::endl;
      exit(-1);
    }
    if (this->board[tileIndex + change] != '_') {
      std::cout << "Tile " << tileIndex
                << " cannot hop over two tiles to the left." << std::endl;
      exit(-1);
    }
    char tempTile = this->board[tileIndex];

    this->board[tileIndex] = this->board[tileIndex + change];
    this->board[tileIndex + change] = tempTile;

  } else if (move == 4) {
    int change = -2;
    if (tileIndex + change >= 7 || tileIndex + change < 0) {
      std::cout << "The move is out of bounds" << std::endl;
      exit(-1);
    }
    if (this->board[tileIndex + change] != '_') {
      std::cout << "Tile " << tileIndex
                << " cannot hop over a tile to the left." << std::endl;
      exit(-1);
    }
    char tempTile = this->board[tileIndex];

    this->board[tileIndex] = this->board[tileIndex + change];
    this->board[tileIndex + change] = tempTile;

  } else if (move == 5) {

    int change = -3;
    if (tileIndex + change >= 7 || tileIndex + change < 0) {
      std::cout << "The move is out of bounds" << std::endl;
      exit(-1);
    }
    if (this->board[tileIndex + change] != '_') {
      std::cout << "Tile " << tileIndex << "cannot move adjacent to the left."
                << std::endl;
      exit(-1);
    }
    char tempTile = this->board[tileIndex];

    this->board[tileIndex] = this->board[tileIndex + change];
    this->board[tileIndex + change] = tempTile;
  } else {
    std::cout << "Move was not made in moveTile. Move: " << move << std::endl;
    exit(-1);
  }

  updateBoardCost();
}

int main(int argc, char *argv[]) {

  Node rootNode("bbbw_ww");

  rootNode.PrintNode();

  rootNode.moveTile(2, 1);

  rootNode.PrintNode();

  return 0;
}
