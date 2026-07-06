# 🚀 High-Performance Sorting Algorithm Matrix (C/C++ Implementation)

A comprehensive, production-grade suite of classic sorting algorithms implemented from scratch in C/C++. Beyond mere functional correctness, this project delves into low-level engineering optimization—incorporating precise boundary controls, defensive runtime assertions, and branch-cutting (pruning) mechanisms. It forms the core high-frequency computing (HPC) foundation for subsequent lightweight custom memory pools and high-performance computer vision (CV) deployment infrastructures.

---

## 🛠️ Algorithm Matrix & Complexity Dashboard

| Algorithm Family | Method Name | Best Time | Worst Time | Space | Stability | Engineering Highlights / Optimizations |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Insertion** | Straight Insertion (`InsertSort`) | $O(n)$ | $O(n^2)$ | $O(1)$ | Stable | Exceptional on nearly sorted arrays; streamlined element shifting |
| | Shell Sort (`ShellSort`) | $O(n^{1.2 \sim 1.3})$ | $O(n^2)$ | $O(1)$ | Unstable | Parallelized group interleaving pre-sorting optimization |
| **Selection** | Dual-Selection (`SelectSort`) | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Unstable | Simultaneous min/max lock-in per pass with index-overwrite override |
| | Heap Sort (`HeapSort`) | $O(n \log n)$ | $O(n \log n)$ | $O(1)$ | Unstable | Precise Max-Heap `AdjustDown` routine; ideal choice for ascending orders |
| **Exchange** | Bubble Sort (`BubbleSort`) | $O(n)$ | $O(n^2)$ | $O(1)$ | Stable | Smart pruning with early-exit `flag` to skip redundant scans |
| | Quick Sort (`QuickSort`) | $O(n \log n)$ | $O(n^2)$ | $O(\log n)$ | Unstable | *(Upcoming)* Covers Hoare Partition, Pit-Digging, & Two-Pointer methods |
| **Merge** | Merge Sort (`MergeSort`) | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | Stable | *(Upcoming)* Standard benchmark for external sorting & divide-and-conquer |

---

## 🌟 Architectural Highlights & Bug Prevention Design

### 1. Robust Defensive Coding: Pointer & Boundary Assertions
Zero toleration for unsafe, "naked" pointer operations. Every entry point is strictly fortified with `assert(arr)` and boundary constraints, eliminating runtime Segmentation Faults from the ground up.

### 2. Maximum Value Overwrite Fix in Dual-Selection Sort
Successfully eliminated a notorious edge-case bug in Dual-Selection Sort where the maximum element is located exactly at the `begin` position and gets prematurely swapped away by the minimum element. By injecting an adaptive index-rectification condition (`if (begin == max_idx)`), data integrity is preserved under multi-dimensional swaps.

### 3. Interleaved Pre-sorting in Shell Sort
Instead of iterating through sub-arrays group-by-group via nested loops, the code implements an interleaved, parallel-advancement mechanism controlled by a singular outer loop `i++`. This maintains the efficiency of large-stride (`gap`) element hopping while keeping the implementation highly compact and CPU cache-friendly.

### 4. Efficient Subtree Protection in Heap Sort
Leveraging the physical array properties of a complete binary tree to establish a robust Max-Heap. During the extraction phase, after swapping the heap root with the rear boundary element, the `end` pointer is directly piped as the new `size` parameter into `AdjustDown()`. This elegantly achieves un-sorted partition shifting and sorted region encapsulation in a single step, ensuring strict $O(n \log n)$ performance.

---

## 📂 Source Directory Tree

```text
├── src/
│   ├── InsertSort.c   # Straight Insertion & Shell Sort implementations
│   ├── SelectSort.c   # Dual-Selection & Heap Sort implementations
│   ├── BubbleSort.c   # Pruning-optimized Bubble Sort implementation
│   └── QuickSort.c    # Quick Sort matrix modules (In Development...)
├── include/
│   └── Sort.h         # Global function signatures & macro declarations
└── README.md          # Project documentation
