# DSA2 Project 4 - Bin Packing
This project will simulate the bin packing problem. It will implement both online and offline versions of the approximation algorithm and a simple approach to compute the optimal solution.

### Background

The Bin Packing Problem is a typical example of a greedy algorithm. As discussed in class, the problem is to store a number of items in bins. Versions of the bin packing problem may be characterized as either online or offline:

- online - you get an item and you must place it immediately

- offline - you can get all the items and then decide how to place them

The basic approach to solve this problem is NP-hard. However, three commonly used "heuristic" approximation algorithms exist for this problem:

- First Fit: Identifying the first bin in the list of bins that can hold the current item. If none can, get a new bin and place it there.

- Next Fit: If the current bin can hold the item, place it there. Otherwise, get a new bin and place the item in the new bin.

- Best Fit: Scan the list of bins and place the item in the bin that will be most full as a result of the item being placed there. If it does not fit in any of the bins so far, place it in a new bin.

### The Project:

You will implement both online and offline versions of the approximation algorithm and a simple approach to compute the optimal solution. You can make no assumptions about the number of items to be placed. Note: I expect you to generate your test data which will be read from a file named items.txt. Bins will be of unit size as in the Canonical version of the problem, so the size of legal items must be  0 < itemsize <= 1. The file items.txt will have an int that indicates the number of items to pack. Following that int will be the correct number of items to pack, represented as floats. You must do error checking to be sure that each item is <= the size of the bins. If you find an item that is not, report it, throw it away, and continue to process the rest.

It turns out that the basic approach to the optimal solution is another permutation problem. It is pretty straightforward, just computationally complex. You simply compute all permutations of the items, check how many bins each permutation takes, and keep the best one! Obviously, the optimal solution requires an offline approach because you must know all the items up front to be able to permute them.

Note: You are required to use the iterative permutation generator algorithm perm1() described in project 3. You are not permitted to use any predefined ermutation generator.

### Output:

Your main program will read the input file items.txt containing the items to pack, and generate the following table from them (displayed to the console):

Policy	Total Bins Used
Optimal Solution	(total bins used)
Online Algorithm	
     First Fit	(total bins used)
     Next Fit	(total bins used) 
     Best Fit	(total bins used)
Offline Algorithm	
     First Fit	(total bins used)
     Best Fit	(total bins used) 

Following the table, you will provide a display on the console that shows how the items were packed in the bins under each of the policies.

 

Optimal:

  b1: 0.7, 0.2
  b2: 0.5 0.43
  ...
  bn: 0.3 0.2
Online First Fit:

  b1: 0.5, 0.2
  b2: 0.5 0.43
  ...
  bn: 0.3 0.2
etc.


### Deliverables

You will submit the following for this project:

1. A User's manual that describes how to set up and run your program.

2. A UML diagram reflecting the final layout of your program.

3. Your source code in C++.

4. A makefile for the project

