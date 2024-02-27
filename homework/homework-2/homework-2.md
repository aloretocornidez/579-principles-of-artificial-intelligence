# Homework 2 | ECE 579

Student Name: Alan Manuel Loreto Cornídez


![[Pasted image 20240226092434.png]]

Solve this problem in the most efficient and optimal way.

Show the solutions, and how the solutions were obtained, specifically:

1. A heuristic is advised that you should explain in the material you hand in.

2. An efficient search algorithm is advised that you should explain (how it
   works)

3. Attach the code that your or generative AI has written for you or explain
   what off-the-shelf modules you have used.



Given an initial state of BBBWWWE, we desire our goal state to be WWWBBB. We can measure the distance from our goal state by taking the distance from the center of the tile if the tile is misplaced. For example, BBBWWW is (3 + 2 + 1 + 1 + 2 + 3) = 12. Another example: BBWBWW has a distance of (3 + 2 + 0 + 0 + 2 + 3) = 10.


Let us begin with the given initial state and move the centermost white tile to the left.

| BBWBWWE | $f(n) = g(n) + h(n) = 1 + 3 + 2 + 0 + 0 + 2 + 3 = 11$ |
| ------- | ----------------------------------------------------- |

From there, we can then look at the next few moves. Our goal is to reduce the cost as much as possible so that the total distance is the least amount possible. 

We can look into two possible moves for this: 
1. Switch tiles 2 and 3 | BWBBWWE $g(n) = 9 \therefore f(b) = 11$ 
2. Switch tiles 4 and 5 |  BBWWBWE $g(n) = 9 \therefore f(b) = 11$ 

Since doth options have the same distance, we can pick the first option. This option prioritizes moving already correct tiles to a spot that makes them "more" correct. We will follow that course of action so long as the distance options meet the A\* algorithm requirements. After checking the distance 

Current State: BWBBWWE $g(n) = 2, g(n) = 9 \therefore f(b) = 11$ 

Next step: WBBBWWE $g(n) = 3, h(n) = 8 \therefore f(b) = 11$

Next step: WBBWBWE $g(n) = 4, h(n) = 7 \therefore f(b) = 11$

Next step: WBWBBWE $g(n) = 5, h(n) = 5 \therefore f(b) = 10$

Next step: WWBBBWE $g(n) = 6, h(n) = 4 \therefore f(b) = 10$

Next step: WWBBWBE $g(n) = 7, h(n) = 2 h(n) = 3 \therefore f(b) = 10$

Next step: WWBWBBE $g(n) = 8, h(n) = 2 \therefore f(b) = 10$

Next step: WWWBBBE $g(n) = 9, h(n) = 0 \therefore f(b) = 9$

In this circumstance, we were able to complete the puzzle in only 9 moves! As we saw from the total cost of each st ate, we never surpassed the previous cost. We can also see that there were no movements of the empty space. What happens if the initial state does not put the empty tile spot on the edge? 


Initial State: 

WWBEWBB $g(n) = 3 \therefore f(b) = 10$













