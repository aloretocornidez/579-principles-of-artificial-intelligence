#pragma once
#include <string>
#include <vector>

// Node class used to hold the board state and the cost of the board. Manages
// board cost and conducts moves.
class Node
{
public:
  // Constructors
  Node()
  {
    this->board = std::string(7, 'x');
    this->parent = nullptr;
    updateBoardCost();
  };

  // Given the string
  Node(std::string input) : board(input)
  {

    this->parent = nullptr;
    updateBoardCost();
  };

  // Copy Constructor
  Node(const Node &input)
  {
    this->parent = input.parent;
    this->board = input.board;
    this->boardCost = input.boardCost;
    this->children = input.children;
    this->cumulativeMoveCost = input.cumulativeMoveCost;
  }

  // Destructor
  ~Node(){};

public:
  /* Getter Functions */
  int getLevel()
  {
    updateLevel();
    return this->levelsToRoot;
  }
  bool isSolution() { return this->getBoardCost() == 0; }
  int getBoardCost()
  {
    updateBoardCost();
    return this->boardCost;
  }
  int getCumilativeMoveCost() { return this->cumulativeMoveCost; }
  int getHeuristicCost() { return this->getBoardCost() + this->getCumilativeMoveCost(); }
  std::string getBoard() { return this->board; }
  Node *getParent() { return this->parent; }
  std::vector<Node *> getChildren() { return this->children; }

  /* Utility Functions */
  void addChild(Node *newChild) { this->children.push_back(newChild); }
  void setParent(Node *newParent) { this->parent = newParent; }
  void appendChildren(std::vector<Node *> list)
  {
    for (int i = 0; i < (int)list.size(); i++)
    {
      this->children.push_back(list.at(i));
    }
  }

  // calculate the total cost of the current board and assign the cost to the
  // `boardCost` variable.
  void updateBoardCost();

  void incrementNodeCost(int cost);

  // moves the tile by switching the string returns the cost.
  int moveTile(int tileIndex, int move);

  void printBoard();

  void updateLevel();
  /*
   * Getters
   */
private:
  // pick a tile and make it move where you want.
  // Move the tile to a valid spot.
  bool validateMove(int tileIndex, int move);

  int conductMoveOperation(int tileIndex, int move);
  // Stores the state of the board.
  std::string board;

  // Stores the cost of the node's board.
  int boardCost;

  // stores the cost of the moves required to get to the current board state.
  int cumulativeMoveCost;

  // Stores the parent of the node.
  Node *parent;

  // stores the level of the node in the tree.
  int levelsToRoot;

  std::vector<Node *> children; // stores the children of the given node.
};
