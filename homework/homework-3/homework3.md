---
title: Homework 3 | ECE 579 | Principles of Artificial Intelligence
author: Alan Manuel Loreto Cornídez
date: 04/23/2024
---

# Problem

Please consider the logical equivalence $\Leftrightarrow$, representing the if
and only if statement (sometimes referred to as iff. (Please look up the truth
table for it; you may also recall the XNOR gate from your digital circuits
classes).

Now, examine the following statement:

A pilot who is certified can fly commercial aviation if they are less than 65
years old, but otherwise cannot fly commercial. Which of the following are
correct representations of the above assertion? Please answer YES OR NO, and
justify your answer.

C – certified

F - fly

LT65 – less than 65

~ is a symbol for NOT

# Response

# Analysis of Problem Statement

The Truth table for an iff statement is as follows:

| A   | B   | iff |
| --- | --- | --- |
| 1   | 1   | 1   |
| 1   | 0   | 0   |
| 0   | 1   | 0   |
| 0   | 0   | 1   |

Applying a truth table to the previously mentioned system:

'A pilot who is certified can fly commercial if they are less than 65 years old,
otherwise, they cannot fly commercial.'

| C   | LT65 | F   |
| --- | ---- | --- |
| 1   | 1    | 1   |
| 1   | 0    | 0   |
| 0   | 1    | 0   |
| 0   | 0    | 1   |

Now we can compare the assertions made by each of the statements below.

# Assertion 1

1. $(C \wedge F) \Leftrightarrow LT65$

This statement has the following interpretation if we read it from left to
right:

A person is less than 65 if and only if the person is certified and can fly.

The assertion of statement 1 is not equivalent to the assertion made in the
given problem statement.

# Assertion 2

2. $(C \Rightarrow (F \Leftrightarrow LT65))$

The English interpretation of this statement is as follows:

If you are certified, then you can fly if and only if you are less than 65.

The assertion made by statement 2 is equivalent to the assertion made in the
problem statement.

# Assertion 3

3. $C \Rightarrow ((LT65 \Rightarrow F) \wedge \neg F)$

This statement is a tautology. That is because every combination of zeros and
ones causes this statement to be true.

Here is the English interpretation of this statement.

If you are certified, this implies that you are less than 65 and can fly, or
that you are unable to fly.

The assertion given in problem 3 does not match the assertion given in the
problem statement.
