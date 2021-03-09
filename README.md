# Sorting_algorithms
Sorting algorithms (code)  and their time complexity in C++


•	Standard in C++ (std::sort() known as IntroSort): O(nlogn);
•	RadixSort (with base 10 or 2): O((n+b) * logb(k)), b=base, k=nrmax;
•	QuickSort: "Engineering a Sort Function"-> 1.386 n log n average comparisons using a randomized pivot and 1.188 n log n average comparisons using a median of 3 pivot. It has O(n^2) worst-case runtime (when the pivot is fixed and the numbers are already sorted);
•	BubbleSort: O(n^2) and O(n) for already sorted numbers;
•	MergeSort: O(nlogn) but is slower than QuickSort in general terms.
•	ShellSort (with gap reduced by half in every iteration): O(n^2)
 and ShellSort2 (with gap calculated with the formula 2*[N/22k+1]+1): O(N3/2) 
