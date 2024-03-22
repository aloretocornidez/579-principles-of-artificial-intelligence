#pragma once
#include <iostream>
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

  // Print the current node board.
  void PrintNode()
  {
    std::cout << "Board Cost: " << this->boardCost << std::endl;
    for (auto &letter : this->board)
    {
      std::cout << letter;
    }

    std::cout << std::endl;
  }

  // calculate the total cost of the current board and assign the cost to the `boardCost` variable.
  void updateBoardCost()
  {

    int blackTiles = 0;
    int cost = 0;
    for (auto &letter : board)
    {
      if (letter == 'b')
      {
        blackTiles++;
      }

      if (letter == 'w')
      {
        cost += blackTiles;
      }
    }

    this->boardCost = cost;
  }

  // set the new board state using a string.
  void setBoard(std::string input)
  {

    if (input.size() != 7)
    {
      std::cout << "Board size is smaller than 7 tiles" << std::endl;
      exit(-1);
    }

    this->board = input;

    updateBoardCost();
  }

  // pick a tile and make it move where you want.
  // Move the tile to a valid spot.
  bool validMove(int tileIndex, int move)
  {
    if (tileIndex < 0 || tileIndex >= 7)
    {
      std::cout << "Invalid tile Size used to move tile. Tile Size: " << tileIndex << std::endl;
      return false;
    }

    // checking move and making the move if it is valid.
    if (move == 0)
    {

      int change = tileIndex + 3;
      if (change >= 7 || change < 0)
      {
        // std::cout << "The move is out of bounds" << std::endl;
        return false;
      }
      if (this->board.at(change) != '_')
      {
        // std::cout << "Tile " << tileIndex << " cannot hop over two places to the right." << std::endl;
        return false;
      }
    }
    else if (move == 1)
    {

      int change = tileIndex + 2;
      if (change >= 7 || change < 0)
      {
        // std::cout << "The move is out of bounds" << std::endl;
        return false;
      }
      if (this->board.at(change) != '_')
      {
        // std::cout << "Tile " << tileIndex << " cannot hop over a tile to the right." << std::endl;
        return false;
      }
    }
    else if (move == 2)
    {
      int change = tileIndex + 1;
      if (change >= 7 || change < 0)
      {
        // std::cout << "The move is out of bounds" << std::endl;
        return false;
      }
      if (this->board.at(change) != '_')
      {
        // std::cout << "Tile " << tileIndex << " cannot move adjacent to the right." << std::endl;
        return false;
      }
    }
    else if (move == 3)
    {
      int change = tileIndex - 1;

      if (change >= 7 || change < 0)
      {
        // std::cout << "The move is out of bounds" << std::endl;
        return false;
      }
      if (this->board.at(change) != '_')
      {
        // std::cout << "Tile " << tileIndex << " cannot adjacent to the left." << std::endl;
        return false;
      }
    }
    else if (move == 4)
    {
      int change = tileIndex - 2;
      if (change >= 7 || change < 0)
      {
        // std::cout << "The move is out of bounds" << std::endl;
        return false;
      }
      if (this->board.at(change) != '_')
      {
        // std::cout << "Tile " << tileIndex << " cannot hop over a tile to the left." << std::endl;
        return false;
      }
    }
    else if (move == 5)
    {

      int change = tileIndex - 3;
      if (change >= 7 || change < 0)
      {
        // std::cout << "The move is out of bounds" << std::endl;
        return false;
      }
      if (this->board.at(change) != '_')
      {
        // std::cout << "Tile " << tileIndex << " cannot hop over two tiles to the left." << std::endl;
        return false;
      }
    }

    return true;
  }

  int conductMoveOperation(int tileIndex, int move)
  {

    // there are 6 possible moves
    // 0. Tile hops two spots to the right.
    // 1. Tile hops over one tile to the right.
    // 2. Tile slides to the adjacent right.
    // 3. Tile moves to the adjacent left.
    // 4. Tile hops over one tile to the left.
    // 5. Tile hops over two tiles to the left.

    // making the move if it is valid.
    int cost;

    if (move == 0)
    {
      int change = tileIndex + 3;
      cost = 3;

      char tempTile = this->board.at(tileIndex);
      this->board.at(tileIndex) = this->board.at(change);
      this->board.at(change) = tempTile;
    }
    else if (move == 1)
    {
      cost = 2;

      int change = tileIndex + 2;
      char tempTile = this->board.at(tileIndex);

      this->board.at(tileIndex) = this->board.at(change);
      this->board.at(change) = tempTile;
    }
    else if (move == 2)
    {
      int change = tileIndex + 1;
      cost = 1;
      char tempTile = this->board.at(tileIndex);

      this->board.at(tileIndex) = this->board.at(change);
      this->board.at(change) = tempTile;
    }
    else if (move == 3)
    {
      int change = tileIndex - 1;
      cost = 1;

      char tempTile = this->board.at(tileIndex);

      this->board.at(tileIndex) = this->board.at(change);
      this->board.at(change) = tempTile;
    }
    else if (move == 4)
    {
      int change = tileIndex - 2;
      cost = 2;
      char tempTile = this->board.at(tileIndex);

      this->board.at(tileIndex) = this->board.at(change);
      this->board.at(change) = tempTile;
    }
    else if (move == 5)
    {

      int change = tileIndex - 3;
      cost = 3;
      char tempTile = this->board.at(tileIndex);

      this->board.at(tileIndex) = this->board.at(change);
      this->board.at(change) = tempTile;
    }

    updateBoardCost();

    return cost;
  }

  void incrementNodeCost(int cost) { this->cumulativeMoveCost += cost; }

  // moves the tile by switching the string returns the cost.
  int moveTile(int tileIndex, int move)
  {
    if (validMove(tileIndex, move))
    {
      return conductMoveOperation(tileIndex, move);
    }
    return -1;
  }

  void printBoard() { std::cout << this->board << std::endl; }

  void updateLevel()
  {
    int level = 0;
    Node* temp = this;

    while(temp != nullptr)
    {
      level++;
      temp = this->parent;
    }

    this->levelsToRoot = level;

  }


  /*
   * Getters
   */
  int getLevel(){updateLevel(); return this->levelsToRoot;}
  int getBoardCost() { return this->boardCost; }
  int getCumilativeMoveCost() { return this->cumulativeMoveCost; }
  std::string getBoard() { return this->board; }
  Node *getParent() { return this->parent; }
  std::vector<Node *> getChildren() { return this->children; }
  void addChild(Node *newChild) { this->children.push_back(newChild); }
  void setParent(Node *newParent) { this->parent = newParent; }
  void setChildren(std::vector<Node *> list)
  {
    for (int i = 0; i < list.size(); i++)
    {
      this->children.push_back(list.at(i));
    }
  }

private:
  // Stores the state of the board.
  std::string board;

  // Stores the cost of the node's board.
  int boardCost;

  // stores the cost of the moves required to get to the current board state.
  int cumulativeMoveCost; // TODO still need to implement the node cost features.

  // Stores the parent of the node.
  Node *parent;

  int levelsToRoot;

  std::vector<Node *> children;
};
