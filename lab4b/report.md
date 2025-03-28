# Lab 4b Report

## RadixSort Algorithm Recap and Pseudocode
```
So, the RadixSort Algorithm we implemented in the last lab initially ran at
roughly quadratic time because of our setup where we were popping items
from the [0] index which caused the ghost operations of having to shift the whole
array over every time we removed an item, resulting in the quadratic timings.

We changed it up to instead only do things on the back of the vector, but we tracked
both the beginning and ending indexes enabling us to manipulate the vector without
having to shift every index over after adding or removing an item.

I also set my queue size to initially start at 1000 so that it would only ever need
to change capacity if we hit that size. It's memory inefficient but, for our purposes,
it really doesn't matter as we're mostly just focused on the timing of the class.

The implemenation of the actual algorithm 
```
### Pseudocode
```
RaxixSort(size) function to create a queue with initial size
  // Fill with random 9-digit integers - running thorugh the for loop until it gets all digits
  for i = 0 while i < size of queue 
  get unsigned long long random int between 100,000,000 and 999,999,999
  
  // Make 10 queues for the 0-9 digits
  digitBins[10] which goes from 0-9 and gives us our 10 queues

  // Loop through to start processing each digit position from leas significant
  // To most significant
  WHILE mainBin is not empty DO
            num = mainBin.dequeue()
            digit = (num / 10^position) MOD 10
            digitBins[digit].enqueue(num)
        END WHILE
        
        // Collect phase
        FOR d = 0 TO 9 DO
            WHILE digitBins[d] is not empty DO
                mainBin.enqueue(digitBins[d].dequeue())
            END WHILE
        END FOR
    END FOR
    
    // Transfer results to output array
    results = new array
    WHILE mainBin is not empty DO
        results.append(mainBin.dequeue())
    END WHILE
    
    RETURN results

I am still not great at writing out my Pseudocode so it looks kind of funky. Hopefully it makes a little sense.
```
