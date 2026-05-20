# Notes for Final Exam

## Why are some functions faster/slower than others in the same class?
    The section that is O(n logn) has fewer operations/commands. Some of the code inside of the function has a bigger coeffecient that affects the timing
## Are larger-magnitude big-O functions *always* slower than smaller-mag ones?
    No. If we look at the initial timing - n^2 starts faster, but gets slower super fast.
    So, for smaller sizes, n^2 could be faster if the input size is small. O(n^2) can outperform
    O(n) with a large constant factor for small inputs
## "Ghost operations" typically refer to hidden or non-obvious operations in code that impact performance or timing. These can include:
  1. **Implicit operations**: Hidden computations like type conversions, memory allocations, or destructors.
  2. **Caching effects**: CPU or memory cache behavior that speeds up or slows down access.
  3. **Branch prediction**: The CPU guessing the outcome of conditional statements, which can fail and cause delays.
  4. **Garbage collection**: Automatic memory management pauses in languages like Java or Python.
  5. **System calls**: Hidden interactions with the operating system, like I/O operations.

  These factors can make timing measurements inconsistent or misleading.
## Vector-Design limitations
    Python list/C++ Vector pop() performance
    Linked list performance - slow because we have to go thru the whole linked list to find what we're looking for
    Inserting or deleting from the beginning or middle is ineffecient because of the shifting of all indices
    within the vector. If we pop.back() it is faster, but uses more memory.
## Data Structures
  1. **Stacks** - good for Prefix, Infix, Postfix expressions
  2. **Queues** - 
  3. **Heaps** - 
  4. **LinkedList** - We listed those earlier.
  5. **BST** - L node R is called Inorder and is the main way to traverse it. Preorder, Postorder traversal are the otehrs
  6 **Recursion** - Function that calls itself to run until it reaches the base case.
## Know how to build a Binary Search Tree
## Searching Algorithms
  1. **Sequential Search**
  2. **Binary Search**
  3. **Hashing** - What happens with collision? We just double the size of the vector becasue it works better when it's not full.
  4. **Bubble Sort** - Slowest
  5. **Selection Sort** - 
  6. **Insertion Sort** - Be able to explain insertion sort in psuedo-terms b/c this is prob on exam
  7. **Merge Sort** - 
  8. **Quick Sort** - 
  9. **Radix Sort** - 
  10. **Shell Sort** - 
  11. **BST Sort** - Know how this is possible after building the BST. Traversing tree inorder gives sorted order. 
## Insertion Sort Psuedocode
    function insertionSort(list):
    // Start from the second element (index 1) because the first element (index 0) is already considered "sorted" by itself.
    for i from 1 to length(list) - 1:
      // Store the current element we want to insert into the sorted portion.
      current_element = list[i]

    // Start comparing with the element just before the current one.
    j = i - 1

    // Keep moving elements in the sorted portion (list[0] to list[j])
    // that are greater than the current_element one position to the right.
    // Stop when we find an element smaller than or equal to current_element,
    // or when we reach the beginning of the list.
    while j >= 0 and list[j] > current_element:
      list[j + 1] = list[j] // Shift the larger element to the right
      j = j - 1           // Move one position left to compare the next element

    // Insert the current_element into the correct position (the empty spot created).
    list[j + 1] = current_element

    // The list is now sorted.
    return list

    **In simpler terms:**

    1.  Go through the list, starting with the second item.
    2.  Pick up the current item.
    3.  Look back at the items you've already sorted (to the left).
    4.  Shift any larger items one step to the right until you find the right spot for the current item.
    5.  Put the current item in that spot.
    6.  Repeat for all items.

Insertion sort:
First number is sorted
look at the [1] index (the [0] is our start and "sorted")
Compare to the "sorted" one (in the first case it will be the [0] index item)
If "current_number" is < "sorted number" then we swap. If >= then it's in the right spot
Continue this for all [i] until list is sorted.

Best case is O(n) but usually averages at O(n^2)
