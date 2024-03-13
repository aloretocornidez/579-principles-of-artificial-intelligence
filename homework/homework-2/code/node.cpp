#include "node.hpp"
#include <iostream>
#include <string>

// TODO
void Node::operator=(Node const &input) { this->board = input.board; }

// Print the board values.
void Node::PrintNode()
{
  std::cout << "Board Cost: " << this->boardCost << std::endl;
  for (auto &letter : this->board)
  {
    std::cout << letter;
  }

  std::cout << std::endl;
}

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

void Node::setBoard(std::string input)
{

  if (input.size() != 7)
  {
    std::cout << "Board size is smaller than 7 tiles" << std::endl;
    exit(-1);
  }

  this->board = input;

  updateBoardCost();
}

void Node::moveTile(int tileIndex, int move)
{
  if (tileIndex < 0 || tileIndex >= 7)
  {
    std::cout << "Invalid tile Size used to move tile. Tile Size: " << tileIndex << std::endl;
    exit(-1);
  }

  // there are 6 possible moves
  // 0. Tile hops two spots to the right.
  // 1. Tile hops over one tile to the right.
  // 2. Tile slides to the adjacent right.
  // 3. Tile moves to the adjacent left.
  // 4. Tile hops over one tile to the left.
  // 5. Tile hops over two tiles to the left.

  // checking move and making the move if it is valid.
  if (move == 0)
  {

    int change = tileIndex + 3;
    if (change >= 7 || change < 0)
    {
      std::cout << "The move is out of bounds" << std::endl;
      exit(-1);
    }
    if (this->board.at(change) != '_')
    {
      std::cout << "Tile " << tileIndex << " cannot hop over two places to the right." << std::endl;
      exit(-1);
    }
    char tempTile = this->board.at(tileIndex);

    this->board.at(tileIndex) = this->board.at(change);
    this->board.at(change) = tempTile;
  }
  else if (move == 1)
  {

    int change = tileIndex + 2;
    if (change >= 7 || change < 0)
    {
      std::cout << "The move is out of bounds" << std::endl;
      exit(-1);
    }
    if (this->board.at(change) != '_')
    {
      std::cout << "Tile " << tileIndex << " cannot hop over a tile to the right." << std::endl;
      exit(-1);
    }
    char tempTile = this->board.at(tileIndex);

    this->board.at(tileIndex) = this->board.at(change);
    this->board.at(change) = tempTile;
  }
  else if (move == 2)
  {
    int change = tileIndex + 1;
    if (change >= 7 || change < 0)
    {
      std::cout << "The move is out of bounds" << std::endl;
      exit(-1);
    }
    if (this->board.at(change) != '_')
    {
      std::cout << "Tile " << tileIndex << " cannot move adjacent to the right." << std::endl;
      exit(-1);
    }
    char tempTile = this->board.at(tileIndex);

    this->board.at(tileIndex) = this->board.at(change);
    this->board.at(change) = tempTile;
  }
  else if (move == 3)
  {
    int change = tileIndex - 1;

    if (change >= 7 || change < 0)
    {
      std::cout << "The move is out of bounds" << std::endl;
      exit(-1);
    }
    if (this->board.at(change) != '_')
    {
      std::cout << "Tile " << tileIndex << " cannot adjacent to the left." << std::endl;
      exit(-1);
    }
    char tempTile = this->board.at(tileIndex);

    this->board.at(tileIndex) = this->board.at(change);
    this->board.at(change) = tempTile;
  }
  else if (move == 4)
  {
    int change = tileIndex - 2;
    if (change >= 7 || change < 0)
    {
      std::cout << "The move is out of bounds" << std::endl;
      exit(-1);
    }
    if (this->board.at(change) != '_')
    {
      std::cout << "Tile " << tileIndex << " cannot hop over a tile to the left." << std::endl;
      exit(-1);
    }
    char tempTile = this->board.at(tileIndex);

    this->board.at(tileIndex) = this->board.at(change);
    this->board.at(change) = tempTile;
  }
  else if (move == 5)
  {

    int change = tileIndex - 3;
    if (change >= 7 || change < 0)
    {
      std::cout << "The move is out of bounds" << std::endl;
      exit(-1);
    }
    if (this->board.at(change) != '_')
    {
      std::cout << "Tile " << tileIndex << " cannot hop over two tiles to the left." << std::endl;
      exit(-1);
    }
    char tempTile = this->board.at(tileIndex);

    this->board.at(tileIndex) = this->board.at(change);
    this->board.at(change) = tempTile;
  }
  else
  {
    std::cout << "Move was not made in moveTile. Move: " << move << std::endl;
    exit(-1);
  }

  updateBoardCost();
}
