# 🚀 High-Performance Sorting Toolkit (Production-Grade C Sorting Matrix)

## 📌 🎯 Developer's Note
This project is NOT a naive textbook replication of basic algorithms. It is a production-grade C sorting library engineered specifically for **rigorous boundary control** and **micro-level memory efficiency**. It implements deep engineering optimizations to eliminate critical real-world defects such as execution stack overflow, adversarial worst-case performance degradation, and non-$2^n$ array boundary violations.

---

## 🛠️ Features & Implementation Matrix

| Algorithm | Core Mechanism | Time Complexity | Space Complexity | Technical Interview Focus |
| :--- | :--- | :--- | :--- | :--- |
| **ShellSort** | Gap Reduction, Segmented Pre-sorting | $O(N^{1.3})$ | $O(1)$ | Macro-interval scaling & local insertion stability |
| **HeapSort** | Array-based Binary Tree Mapping, `AdjustDown` | $O(N \log N)$ | $O(1)$ | Top-K foundation, maximum space efficiency |
| **QuickSort (Recursive)** | Two-pointer Hoare / **PartSort3 (Forward-backward pointer)** | $O(N \log N)$ | $O(\log N)$ | Pivot selection optimization, small-interval thresholding |
| **QuickSortNOR (Non-Rec)** | **Manual Stack-allocated Task Dispatcher** | $O(N \log N)$ | $O(\log N)$ | **Heap-allocated task scheduling, physical immunity to Stack Overflow** |
| **MergeSort (Recursive)** | Post-order Divide-and-Conquer, Two-way Merge | $O(N \log N)$ | $O(N)$ | Strict `mid` truncation line preventing infinite downward loops |
| **MergeSortNOR (Non-Rec)** | **Bottom-up Iterative Window Scaling** | $O(N \log N)$ | $O(N)$ | **Asymmetric interval truncation and defensive boundary patch** |
| **CountSort** | Relative Address Mapping | $O(N + \text{Range})$ | $O(\text{Range})$ | The pinnacle of non-comparison sorting for targeted industry data pipelines |

---

## 🔥 Technical Highlights & Core Optimizations

### 1. ⚡ Defensive Strategies in QuickSort
* **🔥 Median-of-Three Pivot Selection**:
  * **Problem**: Standard QuickSort degrades drastically to $O(N^2)$ (equivalent to Bubble Sort) when encountering adversarial, fully sorted (ascending or descending) datasets due to highly unbalanced binary partitions.
  * **Solution**: Implemented a robust `GetMidNum` logic to force balanced pivots every partition, defending the worst-case time complexity strictly at $O(N \log N)$.
* **🔥 Small Interval Short-Circuit**:
  * For micro-level sub-arrays where the element count $\le 10$, the engine cuts off the recursion chain and hot-swaps to **Insertion Sort**, heavily flattening the system call-stack frame overhead.

### 2. 🛡️ Controlled Memory: Non-Recursive QuickSort Ledger Dispatcher
* **Implementation**: Completely severed reliance on the OS runtime function call stack by constructing a manual generic stack in the **Heap** region.
* **Mechanism**: Implicit system call-stack frames are refactored into physical data nodes storing `[begin, end]` task intervals. Utilizing a "Right-then-Left" push sequence ensures the left sub-intervals are prioritized for pop execution, enforcing absolute control over physical memory consumption and preventing system-level `Stack Overflow`.

### 3. 🧩 The Three Boundary Guardians in Non-Recursive MergeSort
In iterative bottom-up sorting, when the array size $n \neq 2^k$, doubling the step size (`gap *= 2`) inevitably forces the dual-pointer merge window to overrun into out-of-bounds, illegal memory spaces. This library deploys three precise assertion interceptors to adaptively patch boundaries:
1. `if (end1 >= n) break;` $\rightarrow$ The first sub-array is incomplete and the second does not exist. Halts merge operations immediately while preserving existing local sorted orders.
2. `if (begin2 >= n) break;` $\rightarrow$ The second sub-array is entirely absent. Rejects invalid pair-merge execution to prevent segmentation faults.
3. `if (end2 >= n) end2 = n - 1;` $\rightarrow$ The second sub-array exists but is clipped. Forcefully snaps the right boundary back to the final valid sentinel index (`n - 1`), executing a precise partial merge with available elements.

### 4. 🧮 Relative Address Mapping in Counting Sort
* Rejects memory-heavy absolute index allocation. Dynamically scales space utilization via `max - min + 1` to define the optimal mapping `range`, offering out-of-the-box support for negative integers and large-value narrow-range datasets.
* Utilizes `calloc` to ensure memory sanitization (zeroed state) and abstracts array rewriting through a dedicated, isolated `index` cursor to protect outer loop variables.


# Execute stress testing and random matrix validation
./sort_benchmark
