

#include <iostream>
#include <vector>
typedef struct Board {

  char board[7];
} Board;

class Node {
public:
  Node();
  ~Node();
  void PrintNode();
  void calculateCost();

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

Node::~Node() {}

// Print the board values.
void Node::PrintNode() {
  for (int i = 0; i < 7; i++) {
    std::cout << this->board[i];
  }
  std::cout << std::endl;
}

void Node::calculateCost()
{

}

int main(int argc, char *argv[]) {

  Node rootNode;

  rootNode.PrintNode();

  return 0;
}
