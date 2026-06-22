# Subset Sum Problem: Logistics Package Matching using Backtracking

This repository contains a C++ implementation of the **Subset Sum Problem** solved using the **Backtracking** algorithm. The project demonstrates how to find exact combinations of numbers that meet a specific target constraint.

## Problem Statement (Case Study)

A logistics company operates a small cargo van that must be loaded with a total weight of **exactly 300 kg** for optimal driving balance and safety. The transit warehouse currently holds **6 packages** with the following weights:

* Package 1: **50 kg**
* Package 2: **80 kg**
* Package 3: **100 kg**
* Package 4: **120 kg**
* Package 5: **150 kg**
* Package 6: **170 kg**

### Objective
Find **all possible combinations** of packages whose combined weights sum up to **exactly 300 kg**.

## How Backtracking Works Here

1. **Exploration (DFS):** The algorithm takes the first package (50 kg), adds it to the truck, and then moves deeply into the next packages (e.g., adding 80 kg, then 100 kg, etc.).
2. **Bounding / Dead End:** If at any point the total weight exceeds 300 kg, the algorithm realizes it is a dead end. It immediately stops expanding that specific branch.
3. **Backtrack:** The algorithm steps back (removes the last added package) and tries the alternative decision (e.g., "What if we skip this package instead?").

## 🏆 Expected Output

When you run the program, it will successfully track and print all combinations that equal exactly 300 kg:
* **Solution 1:** `[ 50 kg 80 kg 170 kg ]` (50 + 80 + 170 = 300)
* **Solution 2:** `[ 50 kg 100 kg 150 kg ]` (50 + 100 + 150 = 300)
* **Solution 3:** `[ 80 kg 100 kg 120 kg ]` (80 + 100 + 120 = 300)

## 🚀 How to Run

1. Compile the file using a C++ compiler:
   ```bash
   g++ -o package_backtracking package_backtracking.cpp
