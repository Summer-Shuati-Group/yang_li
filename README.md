# Yang Li Shuati Repo

## Day 1

```md
1. Two Sum:
* Hash Map: O(n) Space, O(n) Time
* Sort + Two Pointers: O(n) Space, O(nlog(n)) Time
2. Add Two Numbers:
* Recursively traverse to the next node
13. Roman to Integers:
* notice that exceptions occur when the former letter is smaller than the previous letter
344. Reverse Strings:
* traverse and swap
```

## Day 2

```md
292. Nim Game:
* Brainteaser: observe the property that one that reaches the multiple of 4 wins
4. Median of Two Sorted Arrays:
* [NEED TO IMPROVE] merge takes (m + n), unable to reach O(log(n)), but still passess judge...
136. Single Number:
* Use XOR(^) bitwise operation [NEED TO LEARN]
175. Combine Two Tables:
* [DID NOT LEARN SQL, SKIP]
14. Longest Common Prefix:
* check character to the same position until disagreement appears
```

## Day 3

```md
11. Container with Most Water:
* In essence, we would find the optimal area from the start and the end.
  If we can find a better answer than just taking the front and the back,
  we have to find a higher height value by using two-pointer method.
461. Hamming Distance:
* XOR to create an integer that would contain bit "1" to indicate difference in bits.
  AND to count the number of different bits
  BITWISE SHIFT to reduce one bit by another
6. Zigzag Conversion:
* if numRows is larger than the length of the string, we can just output the string.
  Then, push characters in the string into the vector and check to see if it's going
  in an increasing or decreasing direction of indices.
9. Palindrome Number:
* [BETTER SOLUTION]: check if the first half and reversed second half are equal.
  (for odd cases, the middle value would always equal to itself)
```

## Day 4

```md
3. Longest Substring Without Repeating Characters
* Hash table: 
  Use a hash table to find if the new character is visited or unique
  Two pointers:
  right pointer: shift rightward if we discover unique characters and insert it into container
  left pointer: shift rightward if we discover repeating characters and remove it from container
12. Integer to Roman
  Convert digit from the largest to the smallest, and note the exceptions of 4 and 9
771. Jewels and Stones
  create a reference container and check if the any char is identical to any char in reference container.
  [container is used with hash table. Find: O(1)]
458. Poor Pigs
  
```