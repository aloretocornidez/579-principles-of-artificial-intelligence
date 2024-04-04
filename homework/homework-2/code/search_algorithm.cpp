#include "search_algorithm.hpp"

using std::vector;

void a_star::printRoot() { rootNode->printBoard(); }

// runs the a-star and returns a pointer to the solution node.
Node *a_star::a_star_run()
{

  // used to find how long the algorithm ran.
  int iterations = 0;

  // Begin testing at the root.
  this->openQueue.push_back(this->rootNode);

  Node *currNode;

  // Initialize the index of the first node the algorithm will use.
  int openQueueMinIndex = 0;

  // begin finding a solution
  while (!this->openQueue.empty())
  {

    // find the lowest cost node on the open queue.
    currNode = this->openQueue.at(openQueueMinIndex);

    // pop the node off of the queue.
    this->openQueue.erase(std::next(openQueue.begin(), openQueueMinIndex));

    // return the node if a solution is found.
    if (currNode->isSolution())
    {
      return currNode;
    }

    // generate all of the children of the current state.
    vector<Node *> possibleMoves = generateChildMoves(currNode);

    // Remove nodes that have a board state present on the tree.
    removeDupsInTree(&possibleMoves);
    removeDupsInQueue(&possibleMoves);

    // Add the moves to the tree.
    currNode->appendChildren(possibleMoves);

    // add the moves to the queue.
    for (auto move : possibleMoves)
    {
      this->openQueue.push_back(move);
    }

    // Find the node with the lowest h cost and set the index of the node.
    openQueueMinIndex = this->findMinCost();

    // update iteration count
    iterations++;
  }

  return nullptr;
};

int a_star::findMinCost()
{
  int minHCost;
  int minIndex;

  for (int i = 0; i < (int)this->openQueue.size(); i++)
  {
    Node *temp = this->openQueue.at(i);

    int hCost = temp->getBoardCost() + temp->getCumilativeMoveCost(); //  temp->getLevel();
    // int hCost = temp->getBoardCost() + temp->getCumilativeMoveCost() +
    // temp->getLevel();

    if (i == 0)
    {
      minHCost = hCost;
      minIndex = 0;
    }

    if (hCost <= minHCost)
    {
      minHCost = hCost;
      minIndex = i;
    }
  }

  return minIndex;
}

void a_star::removeDupsInQueue(vector<Node *> *children)
{

  for (int state = 0; state < (int)this->openQueue.size(); state++)
  {
    for (int index = 0; index < (int)children->size(); index++)
    {

      // looks for a node in the container and removes it.
      if (this->openQueue.at(state)->getBoard() == children->at(index)->getBoard())
      {
        children->erase(std::next(children->begin(), index));
      }
    }
  }
}

// searches for a duplicate nodes in a given vector and removes them.
void a_star::removeDupsInTree(vector<Node *> *children)
{
  // delete all duplicate nodes that already exist.
  for (int index = 0; index < (int)children->size(); index++)
  {
    // looks for a node in the tree.
    if (searchTreeForBoard(children->at(index)) != nullptr)
    {
      // cout << "Found duplicate" << endl;
      children->erase(children->begin() + index);
    }
  }

  // cout << "Children in function" << endl;
  // for (auto t : *children) { cout << t->getBoard() << endl; }
}

// method to search for a node.
Node *a_star::searchTreeForBoard(Node *input)
{
  vector<Node *> searchQueue;
  searchQueue.push_back(this->rootNode);

  // begin searching the queue.
  while (!searchQueue.empty())
  {
    int queueSize = searchQueue.size();
    while (queueSize > 0)
    {
      // get the first node
      Node *currentNode = searchQueue.front();

      // remove the node from the queue.
      searchQueue.erase(searchQueue.begin());

      // return matching node
      if (currentNode->getBoard() == input->getBoard())
      {
        // cout << "Matching Board: " << currentNode->getBoard() <<
        // endl;
        return currentNode;
      }

      // Append children of the queued item.
      for (int i = 0; i < (int)currentNode->getChildren().size(); i++)
      {
        searchQueue.push_back(currentNode->getChildren().at(i));
        queueSize++;
      }

      queueSize--;
    }
  }

  return nullptr;
}

vector<Node *> a_star::generateChildMoves(Node *currNode)
{
  vector<Node *> possibleMoves;

  for (int tile = 0; tile < 7; tile++)
  {

    // iterate through all possible moves.
    for (int move = 0; move < 5; move++)
    {
      Node *newMove = new Node(*currNode);

      int moveCost = newMove->moveTile(tile, move);

      if (moveCost > 0)
      {
        newMove->incrementNodeCost(moveCost);
        possibleMoves.push_back(newMove);
        newMove->setParent(currNode);
      }
      else
      {
        delete newMove;
      }
    }
  }

  return possibleMoves;
}

void a_star::showOptimalPath(vector<Node *> solution)
{

  for (auto element : solution)
  {
    // cout << "Move: " << i++ << endl;
    element->printBoard();
  }
};

// This function generates a vector given a solution node.
// The vector re-curses back from to the parent node.
vector<Node *> a_star::generateSolution(Node *solution)
{

  Node *temp = solution;
  vector<Node *> tempVec;
  vector<Node *> solutionVector;

  while (temp != nullptr)
  {

    tempVec.push_back(temp);

    temp = temp->getParent();
  }

  // reversing the vector.
  for (unsigned int i = 0; i < tempVec.size(); i++)
  {
    solutionVector.push_back(tempVec.at(tempVec.size() - i - 1));
  }

  return solutionVector;
}
