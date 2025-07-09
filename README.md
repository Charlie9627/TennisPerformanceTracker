# Tennis Performance Tracker

**Author:** Charlie Vue  
**Course:** ITCS 2530 - C++ Programming Final Exam  
**Project Description:**  
This C++ program reads tennis performance data from a file, calculates a performance score for each player, provides personalized feedback, and outputs the results both on the console and to an output file.

---

## Features

- Uses a struct to store player statistics: aces, double faults, unforced errors, and winners.
- Calculates a performance score using a weighted formula:
  - Positive points for aces and winners
  - Negative points for unforced errors and double faults
- Gives feedback messages based on performance thresholds.
- Reads input data from a text file and writes output to a results file.
- Interactive menu to load data, calculate scores, display stats, and save results.
- Demonstrates core concepts: file I/O, arrays, structs, classes, loops, and conditional logic.

---

## Usage Instructions

1. Prepare an input file (default: `input.txt`) with player data in the format:  
   `PlayerName Aces DoubleFaults UnforcedErrors Winners`  
   Example:
- Charlie 4 2 8 12
- Alice 3 6 9 11
- Bob 6 1 4 15
