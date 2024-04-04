---
title: ECE 579 | Principles of Artificial Intelligence | Homework 2
  <!-- ![](){width=3in} -->
author: Alan Manuel Loreto Cornídez
date: March 28th, 2024
output: pdf_document
---

\newpage

\thispagestyle{empty} \clearpage \tableofcontents \pagenumbering{roman}
\clearpage \pagenumbering{arabic} \setcounter{page}{1}

# Problem Statement

Given an initial configuration of a sliding puzzle and a corresponding possible
move-set, please solve the system in the most efficient way possible.

# System Definitions

In order to begin our approach to a solution, we must first define the system's
goal states, rules that can be applied to reach a goal state, and the cost of
completing any solution. After defining these parameters, we can then apply them
in the usage of the A-Star search algorithm to explore the solution space in a
way that guarantees the optimal solution, at the possible cost of time and space
complexity of the aforementioned solution space.

To reiterate the initial definitions that must be made:

- What is the system's goal state?
- What rules can be applied to current states to approach the goal state?
- What are the respective costs of moving between intermediate states?

## Definition 1 | What Are The System's Goal States?

In the problem, we are given an initial board state consisting of 7 spaces, 3 of
which are populated with black tiles, and three of which are populated with
white tiles. The remaining space is an empty space. The initial configuration
can be any permutation of the 6 tiles as long as they fit within the board. A
goal state is reached when the resulting board has all white tiles to the left
of all black tiles, regardless of the position of the empty space. `wwwbbb_`,
`wwwbb_b`, `wwwb_bb`, and `www_bbb` are all valid board states where `w`
represents a white tile, `b` represents a black tile, and `_` represents an
empty tile.

## Definition 2 | What Rules Can Be Applied To Intermediate States To Reach The Goal State?

According to the given system, there are two restrictions that have been
provided.

1. A tile may move into an adjacent empty cell with unit cost.
2. A tile may hop over at most two other tiles into an empty cell with a cost
   equal to the number of tiles hopped over

By taking these considerations into account, we can then generate a rule-set
that can be applied to an intermediate system state to approach the goal. The
rule-set that I generated is as follows:

1. A tile hops two spots to the right into an empty spot.
2. A tile hops over one tile to the right into an empty spot.
3. A tile slides to the adjacent right into an empty spot.
4. A tile moves to the adjacent left into an empty spot.
5. A tile hops over one tile to the left into an empty spot.
6. A tile hops over two tiles to the left into an empty spot.

Given an initial state of `bbb_www` we can show how each rule is applied to the
state.

First, a tile is selected (we will assume zero-indexed tiles, that is, the first
tile is tile 0) and then a rule is applied to that tile. This assumes all bounds
and error checking has been conducted prior to the operation.

- Rule 1 on Tile 0: `bbb_www` --> `_bbbwww`
- Rule 2 on Tile 1: `bbb_www` --> `b_bbwww`
- Rule 3 on Tile 2: `bbb_www` --> `bb_bwww`
- Rule 4 on Tile 4: `bbb_www` --> `bbbw_ww`
- Rule 5 on Tile 5: `bbb_www` --> `bbbww_w`
- Rule 6 on Tile 6: `bbb_www` --> `bbbwww_`

Applying these rules to the intermediate states, we can then generate any
possible permutation of of the game board.

## Definition 3 | What Are The Respective Costs Of Moving Between Intermediate States?

The cost for transitioning between a state of the current system is relatively
straightforward. However, the cost for transitioning between states is
independent from other cost factors that are used by the search algorithm that
is implemented. In this case, the A-star algorithm. For the implementation thus
far, we can only define the cost for applying a rule to our current system
state.

The costs for applying the rules are defined by the number of tiles the selected
tile to jump over. If the tile is not jumping over another tile, then the cost a
unit cost. As such, the costs for each rule application be be derived as
follows:

- Rule 1: 2 units
- Rule 2: 1 units
- Rule 3: 1 units
- Rule 4: 1 units
- Rule 5: 1 units
- Rule 6: 2 units

# Search Algorithm Definitions

## Search Algorithm Explanation

First, let us briefly explain the algorithm that is being implemented to find
the solution. The A-Star algorithm is implemented similarly to a breadth first
search with the addition of a heuristic measurement that limits the search space
to nodes with lower costs than the underestimation of the cost to find the
solution. This effectively reduces the amount of searching to only nodes that
are guaranteed to give a solution that is optimal. This of course, introduces a
large amount of space and time complexity due to the search space growing very
quickly as more permutations of the search space are added to the search space.
In the previous section, we defined system parameters such as the goal state,
the rules that can be applied to intermediate states, and the direct cost of
transitioning between goal states. With those definitions having been made, it
is now possible to design an implementation of an algorithm that utilizes system
parameters to search for a solution in the system state space.

In our case, we will be using an A-Star search algorithm implementation to solve
for the optimal solution at the cost of search time and space complexity.

## Definition of the Heuristic

When using the A-Star algorithm, a heuristic must be designed to determine the
cost of the current state, and the cost of reaching the current state. This can
be expressed using the function:

$$f(n) = g(n) + h(n)$$

Where $g(n)$ is the cost of the path from the starting node, $n$, and $h(n)$ is
a heuristic function that estimates the cost of the cheapest path from node $n$
to the goal. The goal of the A-star algorithm is to find a goal state with a
minimized $f(n)$.

In this case, there are three parameters that are a part of the function,
$f(n)$.

1. The level of the node in the search space, that is, the number of parent
   nodes that are traversed until the initial state is reached.
2. The cost of the board at any given state
3. The cumulative cost of the moves/rules that were applied to reach a given
   state.

In this case, the heuristic, $h(n)$ can be defined as the absolute cost of the
game board and can be used at the marker for the closeness to the solution. The
first two parameters can be considered the cost to reach the goal state and can
be summed together in their calculation thus rendering $g(n)$.

# Implementation Details

I decided to implement the solution using C++.

A `node` class and `search_algorithm` class were created in addition to a
driving main function.

The `node` class was tasked with the following:

- Storing board states.
- Storing children of a given board state.
- Storing the costs of each node at any given point.

The `search_algorithm` class was tasked with the following:

- conducting a search operation initial root node
- printing the solution when/if it is found.
- Implementation of the search algorithm
- Manipulation of the costs for the search heuristics.

## Methods of Each Data Structure

Below are the methods implemented for each data structure that was used.

### Methods for the `Node` Class

- `void updateBoardCost()`: Calculates the sum of black tiles to the left of a
  white tile on the node's board and stores the result in the node's `boardCost`
  variable.

- `int moveTile(int tileIndex, int move)`: This function is called by the user
  of the nodes when a move wants to be made. Runs checks and returns the cost of
  the move that was made.

- `bool validateMove(int tileIndex, int move)`: Private class function that
  checks if the inputs to the `moveTile` function are a valid move and returns
  false if the move parameters are invalid.

- `int conductMoveOperation(int tileIndex, int move)`: After the move is
  validated by `validateMove`, this function conducts the move operation by
  moving board elements accordingly.

- `void incrementNodeCost(int cost)`: Increments the node cost according by the
  amount specified by the caller.

- `void printBoard()`: Prints the board state of the node.

- `void updateLevel()`: Traverses through the source node's parents until the
  root node is reached and counts how many nodes were traversed. This number is
  returned as the level of the node in the tree.

### Methods for the `search_algorithm` Class

- `Node \*a_star_run()`: This class runs the A-Star algorithm and returns a
  pointer to the solution node.

- `int findMinCost()`: Returns the minimum cost in the open queue for the A-Star
  Algorithm.

- `vector<Node *> generateChildMoves(Node *currNode)`: Generate a vector that
  points to all nodes that are possible children of the input node.

- `void removeDupsInQueue(vector<Node *> *children)`: This function takes as
  input a vector of node pointers. The function checks if the vector contains
  nodes that have a board state that is already present in the open queue.
- `void removeDupsInTree(vector<Node *> *children)`:

- `Node *searchTreeForBoard(Node *input)`: This function takes as input a vector
  of node pointers. The function checks if the vector contains nodes that have a
  board state that is already present in the solution state space, that is, the
  search tree.

- `void showOptimalPath(vector<Node \*> solution)`: This function takes as input
  a vector of nodes and prints the contents of the node sequentially.

- `vector<Node *> generateSolution(Node *solution)`: Takes as input a solution
  node and generates a vector containing the pointers to of parents of each node
  up to the root node of the tree. This function then reverses the vector and
  returns the solution path from the root node to the solution.

# Examples

# Question Answers

# Closing Remarks
