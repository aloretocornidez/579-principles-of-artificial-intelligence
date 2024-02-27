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




To develop a heuristic for this problem space, we must first propose a measure by which to judge the current state in relation to the goal state. My proposed heuristic shall be to count all of the white tiles on the wrong side of each black tile. For example, using BBWBWW, there are three white tiles to the right of two black tiles and two white tiles to the right of one black tile, meaning that $h(n) = 3 + 3 + 2 = 8$.

While this heuristic may not be monotonic, it is a more informed heuristic than a simple breadth first search that only counts the out of place tiles in a given system.

Using this grading method, we can begin an implementation of the heuristic. 

Using the A\* algorithm grading method, we can set up the state space of our system using the equation $f(n) = g(n) + h(n)$ where $g(n)$ is the cost from the state node to node $n$ and $h(n)$ is the estimate of the distance from the node $n$ to the goal node.






























