# Assessment in CPP

# Examples (input arrays → outputs)

> The examples below show sample input arrays for each program and the expected output when the program processes those inputs. No code is shown — only inputs and outputs. ✅

---

## `BST_using_class.cpp` 🔧

- **Input array:** ` [10, 5, 15, 3, 7, 20]`
- **Output (in-order traversal):** `3 5 7 10 15 20`
- **Output (pre-order traversal):** `10 5 3 7 15 20`

> Explanation: inserting the values in the given order produces a binary search tree whose in-order traversal is the sorted sequence of inputs. 

---

## `BST.cpp` 

- **Input array:** ` [8, 3, 10, 1, 6, 14, 4, 7]`
- **Output (in-order traversal):** `1 3 4 6 7 8 10 14`
- **Output (level-order / breadth-first):** `8 3 10 1 6 14 4 7`

> Note: in-order yields sorted values; level-order shows tree shape after insertions. 

---

## `red_black.cpp` 

- **Input array:** ` [10, 20, 30, 15, 25]`
- **Sample output (level-order with colors):** `20(B), 10(B), 25(B), 15(R), 30(R)`
- **Verification output:** `Properties preserved: BLACK-HEIGHT balanced, no red-parent-red-child violations.`

---
