#include "node.hpp"
#include <iostream>

// calculate the total cost of the current board and assign the cost to the
// `boardCost` variable.

void Node::updateBoardCost()
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

bool Node::validateMove(int tileIndex, int move)
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
      // std::cout << "Tile " << tileIndex << " cannot hop over two
      // places to the right." << std::endl;
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
      // std::cout << "Tile " << tileIndex << " cannot hop over a tile to
      // the right." << std::endl;
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
      // std::cout << "Tile " << tileIndex << " cannot move adjacent to
      // the right." << std::endl;
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
      // std::cout << "Tile " << tileIndex << " cannot adjacent to the
      // left." << std::endl;
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
      // std::cout << "Tile " << tileIndex << " cannot hop over a tile to
      // the left." << std::endl;
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
      // std::cout << "Tile " << tileIndex << " cannot hop over two tiles
      // to the left." << std::endl;
      return false;
    }
  }

  return true;
}

int Node::conductMoveOperation(int tileIndex, int move)
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
    cost = 2;

    char tempTile = this->board.at(tileIndex);
    this->board.at(tileIndex) = this->board.at(change);
    this->board.at(change) = tempTile;
  }
  else if (move == 1)
  {
    cost = 1;

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
    cost = 1;
    char tempTile = this->board.at(tileIndex);

    this->board.at(tileIndex) = this->board.at(change);
    this->board.at(change) = tempTile;
  }
  else if (move == 5)
  {

    int change = tileIndex - 3;
    cost = 2;
    char tempTile = this->board.at(tileIndex);

    this->board.at(tileIndex) = this->board.at(change);
    this->board.at(change) = tempTile;
  }

  updateBoardCost();

  return cost;
}

void Node::incrementNodeCost(int cost) { this->cumulativeMoveCost += cost; }

int Node::moveTile(int tileIndex, int move)
{
  if (validateMove(tileIndex, move))
  {
    return conductMoveOperation(tileIndex, move);
  }
  return -1;
}

void Node::printBoard()
{
  std::cout << this->board << " Cost: " << this->getCumilativeMoveCost() << std::endl;
  // std::cout << this->board << " Cost: " << this->getHeuristicCost() <<
  // std::endl; std::cout << this->board << std::endl;
}

void Node::updateLevel()
{
  int level = 0;
  Node *temp = this;

  while (temp != nullptr)
  {
    level++;
    temp = this->parent;
  }

  this->levelsToRoot = level;
}
