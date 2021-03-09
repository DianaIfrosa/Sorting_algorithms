# Sorting_algorithms
Sorting algorithms (code)  and their time complexity in C++


•	Standard in C++ (std::sort() known as IntroSort): O(nlogn);  
•	RadixSort (with base 10 or 2): O((n+b) * logb(k)), b=base, k=nrmax;  
•	QuickSort: "Engineering a Sort Function"-> 1.386 n log n average comparisons using a randomized pivot and 1.188 n log n average comparisons using a median of 3 pivot. It has O(n^2) worst-case runtime (when the pivot is fixed and the numbers are already sorted);  
•	BubbleSort: O(n^2) and O(n) for already sorted numbers;  
•	MergeSort: O(nlogn) but is slower than QuickSort in general terms.  
•	ShellSort (with gap reduced by half in every iteration): O(n^2)  
 and ShellSort2 (with gap calculated with the formula 2*[N/22k+1]+1): O(N3/2).  
 
Top fastest sorting algorithms for nrmax=10^6 and:  
<img width="427" alt="tabel" src="https://user-images.githubusercontent.com/40547787/110506763-119aa100-8108-11eb-8815-805fb1a9735f.png">

 Charts:  
 
<img width="444" alt="charts2" src="https://user-images.githubusercontent.com/40547787/110505881-3e9a8400-8107-11eb-8064-57131ee830d2.png">  
<img width="444" alt="chart3" src="https://user-images.githubusercontent.com/40547787/110505875-3d695700-8107-11eb-9b2d-ddfbb616fceb.png">  
<img width="432" alt="chart4" src="https://user-images.githubusercontent.com/40547787/110505878-3e01ed80-8107-11eb-941b-07bd6e8e8bca.png">  
<img width="447" alt="charts1" src="https://user-images.githubusercontent.com/40547787/110505879-3e9a8400-8107-11eb-9928-06f9fc0d78d6.png">   


