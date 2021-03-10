# Sorting_algorithms
Sorting algorithms (code)  and their time complexity in C++


•	Standard in C++ (std::sort() known as IntroSort): O(nlogn);  
•	RadixSort (with base 1024 or 256): O((n+b) * logb(k)), b=base, k=nrmax =>RadixSort1024 is faster in general terms, because of the base.
•	QuickSort: "Engineering a Sort Function"-> 1.386 n log n average comparisons using a randomized pivot and 1.188 n log n average comparisons using a median of 3 pivot. It has O(n^2) worst-case runtime (when the pivot is fixed and the numbers are already sorted);  
•	BubbleSort: O(n^2) and O(n) for already sorted numbers;  
•	MergeSort: O(nlogn) but is slower than QuickSort in general terms.  
•	ShellSort (with gap reduced by half in every iteration): O(n^2)  
 and ShellSort2 (with gap calculated with the formula 2*[N/22k+1]+1): O(N3/2).  
 
Top fastest sorting algorithms for nrmax=10^6 and:  
<img width="430" alt="tabel" src="https://user-images.githubusercontent.com/40547787/110668380-ec736480-81d3-11eb-9aeb-49bd2117a99f.png">

 Charts:  
 
<img width="442" alt="chart1" src="https://user-images.githubusercontent.com/40547787/110667215-ba153780-81d2-11eb-9ae9-2c0333ec2a54.png">
<img width="429" alt="chart5" src="https://user-images.githubusercontent.com/40547787/110667222-baadce00-81d2-11eb-95cb-b960abbd482e.png">
<img width="431" alt="chart6" src="https://user-images.githubusercontent.com/40547787/110667224-bb466480-81d2-11eb-89dd-954696629eb0.png">
<img width="444" alt="chart3" src="https://user-images.githubusercontent.com/40547787/110667217-baadce00-81d2-11eb-949a-e58677eea9c1.png">
<img width="432" alt="chart4" src="https://user-images.githubusercontent.com/40547787/110667220-baadce00-81d2-11eb-868f-660464a5c80b.png">
<img width="444" alt="charts2" src="https://user-images.githubusercontent.com/40547787/110667226-bb466480-81d2-11eb-9690-0b7a79a775cc.png">
