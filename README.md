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

## Day 7

```
5. Longest Palindromic Substring
104. Maxmimum Depth of Binary Tree
* use dfs to find the maxmimum depth of root->left and root->right
53. Maximum Subarray
* Three Methods:
  1. Brute Force: O(n^2), scan through the array twice
  2. Divide-and-conquer: O(nlog(n)),
     divide array into indiviudal sections and calculate the maximum sum of each section
  3. Dynamic Programming (Kadane's algorithm): O(n), 
     note the pattern of find maximum sum: A_{i+1} = max(A_{i} + B_{i+1}, B_{i+1})
122. Best Time to Buy and Sell Stock II:
```

## Day 8

```
206. Reverse Linked List
* Iterative and Recursive
146. Cache LRU
169. Majority Element
* Six Methods:
  1. Hash Table
  2. Sorting
  3. Randomization
  4. Divide-and-Conquer
  5. Moore Voting Algorithm
  6. Bit Manipulation
155. Min Stack
[Design Trick] Use two stacks to access the smallest element in
linear time
```

## Day 9

```
23. Merge k Sorted List
* Several Methods:
  1. [Brute Force] use merge two sorted lists function and iterate
  through all of the k sorted lists

  2. [Divide and Conquer] break k-length sorted lists into pairs of
  2 and merge them, and break into pairs of 4 and merge them, and
  so on

  ......[BETTER METHODS. TO BE CONTINUED]
38. Count and Say
[Dynamic Programming] Find the recurrence relations that v[i+1] is
equal to the counts of the number plus the number. 

148. Sort List
[Divide and Conquer] break n-length list into pairs of 2 and merge 
them, and break into pairs of 4 and merge them, and so on

191. Number of 1 Bits
* Two Methods:
  1. [XOR] use XOR to check if the last bit is 1, and use bitwise 
  right shift to cut off the last 1 bit.

  2. [AND] use n & (n-1) to identify the last 1 bit in n, and then
  set to 0. Faster than the first one.
```

## Day 10 

```
141. Linked List Cycle
* Three Methods:
  1. [Dummy Pointer]add a dummy pointer in between every two
  elements, if the dummy pointer was found again, then it means
  it has a cycle.

  2. [Hashtable ]build a hashtable to store the elements while
  traversing all the elements, if hashtable finds the same element,
  then it means it has a cycle

  3. [Two Pointers] 追逐问题: the left pointer takes 1 step while
  the right pointer takes 2 step. If the linked list has a cycle,
  left pointer would eventually be equal to the right pointer.

283. Move Zeroes
* Two Methods:
  1. [Operation suboptimal]
    (1). If the current element is not 0, then we need to append it 
    just in front of last non 0 element we found.
    (2). After we have finished processing new elements, all the
    non-zero elements are already at beginning of array. We just 
    need to fill remaining array with 0's.
  2. [Operation optimal]
    (1). all elements before slow pointer (j) are non-zeroes.
    (2). all elements between the current (i) and slow (j) pointer
    are zeroes.

121. Best Time to Buy and Sell Stocks
* Two Methods:
  1. [Dynamic Programming (Brute Force)] Find the recurrence
  relations that max(prices[i] - prices[j])
  
  2. [One Pass] update the lowest price and find out the max
  profit (profit - lowest price so far)
42. Trapping Rain Water
```

## Day 11

```
70. Climbing Stairs
[Dynamic Programming] fibonacci sequence

193. Valid Phone Numbers
[Regex] grep, sed, awk bash commands

412. Fizz Buzz
Easy Simulation

256. Add Digits
* Two Methods:
  1. [Recursion / loop] sum up digits repeatedly until there is only one digit
  2. [Digital Root Formulae] dr(num) = 1 + (num - 1) % 9

```

## Day 19

```
152. Maximum Product Subarray
139. Word Break
48. Rotate Image
8. String to Integer (atoi)
```

## Day 20

```
234. Palindrome Linked List
* The Method:
  1. reverse the first part of the linked list
  2. compare the second part of the linked list to compare the reversed first half

463. Island Perimeter
[kinda simulation]
  1. locate all neighboring positions of a specific location
  2. if not 1, add 1 to the overall perimeter

328. Odd Even Linked List


219. Contains Duplicate II
[Hash Table] use an unordered_map:
  1. first -> element, second -> index
  2. once find, compare the absolute difference of positions
```

## Day 21

```
176. Second Highest Salary
[SQL] Use SELECT, WHERE, FROM, MAX keywords to practice with SQL

197. Rising Temperature
[SQL] Create object to assign attributes for comparison

479. Largest Palindrome Product
[NEED TO CHECK AGAIN THE SOLUTION'S IDEA ......]

153. Find Minimum in Rotated Sorted Array
* Three Methods:
  1. [sort() function] -> O(n logn) runtime
  2. [Compare nums[i] and nums[i+1]] -> O(n) runtime
  3. [Binary Search]:
    (1). if rotated, the first element would be smaller than than the last element
    (2). use binary search to find the smallest element in the array
```

## Day 22

```
72. Edit Distance
[Dynamic Programming - Sequence Alignment]:
  1. (recurrence relation) SA[i, j] = SA[i + 1, j + 1] (x_i == y_j) 
  2. (recurrence relation) SA[i, j] = 1 + min(SA[i + 1, j], SA[i, j + 1], SA[i, j]) (x_i != y_j)
  3. (base case) SA[i, m + 1] = n - i + 1 (starting from 1)
  4. (base case) SA[n + 1, j] = m - j + 1 (starting from 1)

118. Pascal's Triangle
[Simulation] code in the way as described

33. Search in Rotated Sorted Array
[Binary Search] Combine with "153. Find Minimum in Rotated Sorted Array" and use binary search from left and right separated by minimum

627. Swap Salary
[SQL] Learn keywords such as UPDATE, CASE, WHEN, THEN, END;
```

## Day 23

```
319. Bulb Switcher
[Brainteaser]
* Thinking Process:
  1. Suppose bulb 1 to n. Bulb is switched on in round d if and only if d divides i.
  Therefore, bulb i would be on if and only if there are odd number of rounds.
  (Since the bulb is initially off and finally on)
  2. Divisors often come in pairs except when i comes in pairs, because when i is
  a square, it would have the same number but counted once.
  3. Therefore, just count the square numbers (return sqrt(n))

147. Insertion Sort List
[Insertion Sort]
* Procedure:
  1. create another helper linked list
  2. insert current linked list to the appropriate location (between pre and pre.next)
  3. advance the relevant pointers in the original linked lists and repeat

150. Evaluate Reverse Polish Notation
[Classical Stack Question]
* Two Methods (recursive & iterative)
  1. [Iterative implementation]
    (1). only push the numbers into the stack
    (2). when an operator is encountered, do corresponding operation between two numbers before
  2. [Recursive implementation]
    (1). pop string from the end of the vector
    (2). if it's number, just return it
    (3). if it's operation, call function recursively for 2nd operand and 1st

100. Same Tree
[Depth-first Search (Pre-order traversal)]
  1. check if either of p or q is null, then return (p == q)
    (1).p == NULL, q != NULL: return false (different pointers)
    (2). p != NULL, q == NULL: return false (different pointers)
    (3). p == NULL, q == NULL: return true
  2. check if p and q have the same value
  3. check the corresponding left subtree and right subtree
```

## Day 24

```
350. Intersection of Two Arrays II

139. Word Break 


```