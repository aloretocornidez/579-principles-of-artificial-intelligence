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

# Answer

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

Applying this case to

1. $(C \wedge F) \Leftrightarrow LT65$

<!-- TODO -->

| C   | LT65 | F   |
| --- | ---- | --- |
| 1   | 1    | 1   |
| 1   | 1    | 0   |
| 0   | 0    | 0   |
| 0   | 1    | 1   |

This table does not match the given statement, therefore, **it is not a valid
logical representation.**

2. $(C \Rightarrow (F \Rightarrow LT65))$

<!-- TODO -->

| C   | LT65 | F   |
| --- | ---- | --- |
| 1   | 1    | 1   |
| 1   | 0    | 0   |
| 0   | 1    | 0   |
| 0   | 0    | 1   |

3. $C \Rightarrow ((LT65 \Rightarrow F) \wedge \neg F)$

<!-- TODO -->

| C   | LT65 | F   |
| --- | ---- | --- |
| 1   | 1    | 1   |
| 1   | 0    | 0   |
| 0   | 1    | 0   |
| 0   | 0    | 1   |
