# Traveling Salesman Problem using Dynamic Programming (Bitmasking)

##  Project Overview

This project implements a solution to the **Traveling Salesman Problem (TSP)** using **Dynamic Programming with Bitmasking** in C++.It provides an exact minimum-cost solution for small to moderately sized graphs (typically up to 20 cities).The TSP is a classic optimization problem where the objective is to find the minimum cost path that visits each city exactly once and returns to the starting city.

This was developed as part of my **Algorithms (CSE 246) course project** at university.

---
## 🧠 Problem Statement

Given a list of cities and the cost of travel between each pair, find the shortest possible route that:
- Starts from a given city
- Visits every other city exactly once
- Returns to the starting city

---
### 📚 Why is TSP Important?

-  It is a fundamental **NP-Hard problem**, meaning it cannot be solved efficiently for large inputs using brute-force.
-  It has widespread applications:
  - **Logistics and delivery routing**
  - **Manufacturing** (e.g., drilling PCBs)
  - **Genome sequencing**
  - **Travel planning and scheduling**

##  Features

- Takes user input for the number of cities and edge weights.
- Uses **bitmasking** to efficiently represent subsets of visited cities.
- Uses **dynamic programming** to store and reuse solutions to subproblems.
- Prevents negative edge weights and self-loops.
- Displays the adjacency matrix before computation.
- Outputs the **minimum cost** required to complete the tour.

---
###  Common Solution Approaches

| Method                       | Description                                      | Time Complexity |
|----------------------------|--------------------------------------------------|-----------------|
| Brute Force                | Try all possible permutations                    | O(n!)           |
| Dynamic Programming + Bitmask | Efficient for small graphs (used in this project) | O(n² × 2ⁿ)      |
| Heuristics (e.g. Nearest Neighbor, Genetic Algorithms) | Fast but approximate solutions                  | Varies          |
##  How It Works

The DP state is defined as:

- `mask` is a bitmask representing a subset of visited cities.
- The algorithm tries all possibilities of moving from one city to another and updates the DP table accordingly.

Time complexity is **O(n² * 2ⁿ)**, where `n` is the number of cities.

---

##  Sample Run
![image](https://github.com/user-attachments/assets/9c1a1165-591a-473d-b1e5-22eb1f59ba4d)


---

## 📂 File Structure

- `TSP.cpp`: C++ source file containing the full implementation.
- `README.md`: Project documentation (this file).
- `Report246Project.pdf`: Contain Report of this project

---

## ✅ Requirements

- C++11 or higher
- Standard I/O (no additional libraries needed)

---

## 💡 Concepts Used

- Bitmasking
- Dynamic Programming
- Adjacency Matrix
- Nested Loops and Conditionals
- Input Validation

---


