# Yang Li Shuati Repo

## Day 1

```
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

```
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

```
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

```
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

## Day 5

```
7. Reverse Integer:
* Some notes:
  1. watch for '-' ('0' would disappear when added to result) and multiply -1
  2. declare a long lnog variable would be much helpful in identifying overflow
20. Valid Parentheses:
* Classical Question about Stack:
  1. Scan character by character of the expression string
  2. Each time you hit an open-paren: '(', '[', '{' push it on the stack
  3. When you encounter a ')', ']', '}' the top character on the stack should be the matching opening
  paren type, otherwise return false!
371. Sum of Two Integers:
* Bit Manipulation:
  1. XOR operation to compute the sum,
  2. BITWISE SHIFT and AND operation to compute the carry
  3. recursively doing so
21. Merge Two Sorted Lists:
* Classical Merge Question, much easier if a dummyhead is added before
```

## Day 6

```
237. Delete Node in a Linked List:
* Two Methods (Both run in O(1)):
  1. Create a dummy head after the node, swap them, and delete node
  2. swap values of node and node->next, delete node->next
595. Big Countries
* 
195. Tenth Line:
* "sed -n" is used to suppress output
  "'xp' locates xth line
561. Array Partition I:
* Sort the array first and look for the smaller value of the pairs
535. Encode and Decode TinyURL:
* 
66. Plus one:
* Method:
  1. Add from the end of the digits 
  2. if the digit is smaller than 9, just add one, done
  3. if the digit is equal to 9, set to 0, and add one to the position upfront
  4. if there is no available digit upfront, add a position of 1, done
```