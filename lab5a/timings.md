<img width="361" alt="image" src="https://github.com/user-attachments/assets/0ebd3239-4ab5-4543-a5ec-005c3137ac10" />

<img width="361" alt="image" src="https://github.com/user-attachments/assets/226f0107-cfde-4b93-b5af-d5d954337a11" />

B. Now time the Sequential Search algorithm
Implement a C++ function implementation of the Python SequentialSearch approach
I showed you in the class Powerpoint for the SequentialSearch algorithm
In your main timing function, you may use the same unsigned unique integer
vectors of the same 7-10 sizes you used for Part A above.H owever, they should not be sorted.
For each of these sizes, be sure you have 1000 more unique integers than you actually need.
You will use these 1000 extra integers for one of your two SequentialSearch 
timing-series (in Part 4a below).

Generate two timing-series for SequentialSearch to display in Excel: 
one timing a batch-search for 1000 integers that are NOT IN that vector;
one timing a batch-search for 1000 integers that are known to be IN that vector
(use the same functions to accomplish this that you found/developed for BinarySearch Part 4b above)
Note: you need not implement the "Ordered Sequential Search" approach we touched on in class

Algorithm search-timings
Graphically compare timing-results of (Unsorted) Sequential Search, and Binary Search, for both present and nonpresent items.  (Since these timings can be very short, to generate an average search-time-per-item, you should search for a fixed number of values for each list-size, then determine the average time to find a single value by dividing that total search-time by your fixed number (1000 in the examples suggested above) )

You may divide your timing result by the (fixed) number of
items searched-for to get the average; or you may use the total time value if you prefer.
Generate a graph for each pair of timing-series (i.e. INS, NOT INS).
There should be one graph for SequentialSearch timings, and a second graph containing the BinarySearch timings.
Create a third graph containing all four series, but assign the BinarySearch series
to a Secondary Y-axis
Describe your three (3) resulting graphs and explain why they are shaped the way they are



