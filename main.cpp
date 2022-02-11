#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <cstring>

using namespace std;
ifstream fin("read.in");
ofstream fout("data.out");

typedef void(*array_pointers) (int a, unsigned int b, vector <unsigned int> &c);
typedef void(*array_pointers2) (int a, int b, vector <unsigned int> &c);

void BubbleSort(int n, unsigned int nrmax, vector <unsigned int> &v);
void ShellSort(int n,unsigned int nrmax, vector <unsigned int> &v);
void ShellSort2(int n,unsigned int nrmax, vector <unsigned int> &v);
void RadixSort1024(int n,unsigned int nrmax, vector <unsigned int> &v);
void RadixSort256(int n, unsigned int nrmax, vector <unsigned int> &v);
void StandardSort(int n, unsigned int nrmax, vector <unsigned int> &v);

void QuickSort_Random(int left,int right, vector <unsigned int> &v);
void QuickSort_MedianOf3(int left,int right, vector <unsigned int> &v);
void MergeSort(int left, int right, vector <unsigned int> &v);

array_pointers sorts1[]=
{
    StandardSort, ShellSort, ShellSort2, RadixSort256, RadixSort1024,BubbleSort

};
array_pointers2 sorts2[]=
{
    MergeSort, QuickSort_Random, QuickSort_MedianOf3

};

bool Correct_Sort(int n, vector <unsigned int> &v)
{
    int i;
    for(i=0; i<n-1; i++)
        if (v[i]>v[i+1])
            return 0;
    return 1;
}

void StandardSort( int n, unsigned int nrmax, vector <unsigned int> &v)
{
    fout<<"Standard sort:\n";
    sort(v.begin(), v.end());
}

void BubbleSort(int n, unsigned int nrmax, vector <unsigned int> &v)
{
    fout<<"BubbleSort:\n";
    try
    {
        int i;
        bool ok=0; //whether vector is sorted or not
        while (!ok)
        {
            ok=1;
            for(i=0; i<=n-2; i++)
                if(v[i]>v[i+1])
                {
                    swap(v[i], v[i+1]);
                    ok=0;
                }

        }
    }
    catch(...)
    {
        fout<<"This algorithm can't sort these numbers\n";
    }

}
int PivotRandom(int left, int right,vector <unsigned int> &v)
{
    int piv=left,i,index;

    piv=rand()%(right-left+1)+left;
    swap(v[left],v[piv]);   //move the pivot first

    piv=left;

    index=left+1;
    for(i=left+1; i<=right; i++)
    {
        if(v[i]<v[piv])
        {
            //the small values go first
            swap(v[i],v[index]);
            index++;
        }
    }
    swap(v[piv],v[index-1]);

    //return sorted position of pivot
    return index-1;


}
int PivotMedian3(int left, int right,vector <unsigned int> &v)
{
    int piv=left,l=left,r=right,m,index;
    m=l+(r-l)/2; //avoid l+r->overflow

    if((v[l]<v[m]) ^ (v[l]<v[r]))
        piv=l;
    else if((v[m]<v[r]) ^ (v[m]<v[l]))
        piv=m;
    else piv=r;

    swap(v[left],v[piv]); //move the pivot first
    piv=left;

    index=left+1;
    for(int i=left+1; i<=right; i++)
    {
        if(v[i]<v[piv])
        {
            //the small values go first
            swap(v[i],v[index]);
            index++;
        }
    }
    swap(v[piv],v[index-1]);
    //return sorted position of pivot

    return index-1;

}
void QuickSort_Random(int left,int right, vector <unsigned int> &v)
{
    try
    {
        if(left<right)
        {
            int p=PivotRandom(left,right,v);
            QuickSort_Random(left,p-1,v);
            QuickSort_Random(p+1,right,v);

        }
    }
    catch(...)
    {
        fout<<"This algorithm can't sort these numbers\n";
    }
}
void QuickSort_MedianOf3(int left,int right, vector <unsigned int> &v)
{
    try
    {
        if(left<right)
        {
            int p=PivotMedian3(left,right,v);
            QuickSort_MedianOf3(left,p-1,v);
            QuickSort_MedianOf3(p+1,right,v);

        }
    }
    catch(...)
    {
        fout<<"This algorithm can't sort these numbers\n";
    }
}

void GenerateRandom(int n,unsigned int nrmax, vector <unsigned int> &v)
{
    int number,i;
    for(i=0; i<n; i++)
    {
        if(i==n/2) //nrmax is in the middle
            v.push_back(nrmax);
        else
        {
            number=rand()%(nrmax+1);
            v.push_back(number);
        }
    }

}
void GenerateSorted(int n,unsigned int nrmax,  vector <unsigned int> &v)
{

    //1 2 3...nrmax nrmax nrmax...nrmax
    //or nrmax-n+1, nrmax-n+2, ...., nrmax

    int i;
    if(nrmax<n)
    {
        for(i=0; i<n && i+1<=nrmax; i++)
            v.push_back(i+1);
        while (i<n)
            v.push_back(nrmax),i++;
    }
    else
        for(i=nrmax-n+1; i<=nrmax; i++)
            v.push_back(i);


}
void ShellSort(int n, unsigned int nrmax, vector <unsigned int> &v)
{
    ///with gap reduced by half in every iteration
    fout<<"ShellSort:\n";
    try
    {
        unsigned int elem;
        int gap,i,j;
        for(gap=n/2; gap>0; gap/=2)
        {
            for(i=gap; i<n; i++)
            {
                elem=v[i]; //save the current element
                for(j=i; j>=gap && v[j-gap]>elem ; j-=gap)
                    v[j]=v[j-gap];
                v[j]=elem;
            }
        }
    }
    catch(...)
    {
        fout<<"This algorithm can't sort these numbers\n";
    }
}
void ShellSort2(int n, unsigned int nrmax, vector <unsigned int> &v)
{
    ///with gap calculated with the formula 2*[N/2^(2k+1)]+1
    fout<<"ShellSort2:\n";
    try
    {
        unsigned int elem;
        int j,gap,i,g;
        for(g=n/4; g>=0; g/=2)
        {
            gap=2*g+1;
            for(i=gap; i<n; i++)
            {
                elem=v[i]; //save the  current element
                for(j=i; j>=gap && v[j-gap]>elem ; j-=gap)
                    v[j]=v[j-gap];
                v[j]=elem;
            }
            if(gap==1) //for exiting infinite loop
                break;
        }
    }
    catch(...)
    {
        fout<<"This algorithm can't sort these numbers\n";
    }
}
void Merging(int l, int m, int r, vector <unsigned int> &v)
{
    int i,j,k;
    //for merging we need auxiliary vector
    vector <unsigned int> aux;
    i=l, j=m+1;
    while (i<=m && j<=r)
        if (v[i]<v[j])
            aux.push_back(v[i]), i++;
        else
            aux.push_back(v[j]), j++;

    while(i<=m)
        aux.push_back(v[i]), i++;
    while(j<=r)
        aux.push_back(v[j]), j++;

    //move the elements in the initial vector
    for(k=0,i=l; i<=r; i++,k++)
        v[i]=aux[k];

}

void MergeSort(int left, int right, vector <unsigned int> &v)
{
    try
    {
        if(left<right)
        {
            int middle=(left+right)/2;
            MergeSort(left,middle,v);
            MergeSort(middle+1,right,v);
            Merging(left,middle,right,v);
        }
    }
    catch(...)
    {
        fout<<"This algorithm can't sort these numbers\n";
    }
}

int Digits(unsigned int nrmax)
{
    int ct=0;
    while(nrmax>0)
        nrmax/=10, ct++;
    return ct;
}
void Print(int n,vector<unsigned int> v)
{
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
    cout<<"\n";

}

double log_a_base_b(unsigned int a,int b)
{
    return (double)log(a)/log(b);
}

void RadixSort1024(int n,unsigned int nrmax, vector<unsigned int> &v)
{
    fout<<"RadixSort1024:\n";
    try
    {
        vector<unsigned int> b[1024];
        int poz,rest;
        unsigned int pow=1;

        int nr_iter=ceil(log_a_base_b(nrmax,1024));

        for(int j=0; j<nr_iter; j++)
        {
            for(int i=0; i<n; i++)
            {
                b[(v[i]/pow)%1024].push_back(v[i]);
            }


            poz=0;
            for(int nr_bucket=0; nr_bucket<1024; nr_bucket++)
            {
                for(int k=0; k<b[nr_bucket].size(); k++)
                    {v[poz++]=b[nr_bucket][k]; //current element
                    //cout<<"bucket "<<nr_bucket<<" cu elem "<<b[nr_bucket][k]<<" ";
                    }



                //clear the buckets
                b[nr_bucket].clear();

            }
            pow*=1024;

        }

        for(int i=0;i<1024;i++)
        {
         b[i].clear();
         b[i].shrink_to_fit();
        }


    }
    catch(...)
    {
        fout<<"This algorithm can't sort these numbers\n";
    }

}
void RadixSort256(int n,unsigned int nrmax, vector<unsigned int> &v)
{
    fout<<"RadixSort256:\n";
    try
    {

        vector<unsigned int> b[256];
        int poz,rest;
        unsigned int pow=1;

        int nr_iter=ceil(log_a_base_b(nrmax,256));

        for(int j=0; j<nr_iter; j++)
        {
            for(int i=0; i<n; i++)
            {
                b[(v[i]/pow)%256].push_back(v[i]);
            }


            poz=0;
            for(int nr_bucket=0; nr_bucket<256; nr_bucket++)
            {
                for(int k=0; k<b[nr_bucket].size(); k++)
                    v[poz++]=b[nr_bucket][k]; //current element



                //clear the buckets
                b[nr_bucket].clear();

            }
            pow*=256;

        }

        for(int i=0;i<256;i++)
        {b[i].clear();
        b[i].shrink_to_fit();
        }



    }
    catch(...)
    {
        fout<<"This algorithm can't sort these numbers\n";
    }



}

void Sort(int n,unsigned int nrmax, vector <unsigned int> &v)
{
    vector <unsigned int> aux(n),sorted(n);

    ///Standard STL Sort
    sorted=v;
    auto start = chrono::high_resolution_clock::now();
    sorts1[0](n,nrmax,sorted);
    auto stop = chrono::high_resolution_clock::now();
    fout<<"Sorted: YES\n";
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    fout << "Elapsed time in milliseconds: "
         << duration.count()<<" ms\n\n";


    for (int i=0; i<6; i++)
    {
        aux=v;
        auto start = chrono::high_resolution_clock::now();
        sorts1[i](n,nrmax,aux);
        auto stop = chrono::high_resolution_clock::now();

        if(aux==sorted)///verify if elements are the same
        {
            fout<<"Sorted: YES\n";
            auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
            fout << "Elapsed time in milliseconds: "
                 << duration.count()<<" ms\n\n";

        }
        else
            fout<<"This algorithm can't sort these numbers!\n\n";


    }
    //for MergeSort and QuickSortRandom and QuickSort_MedianOf3
    for(int i=0; i<3; i++)
    {
        aux=v;
        if(i==0) fout<<"MergeSort:\n";
        else if (i==2)
        {
            fout<<"QuickSort-median of three pivot:\n";
            if(nrmax<=5 && n>=90000)
            {
                fout<<"These numbers can't be sorted!\n\n";
                //continue;
            }
        }
        else
        {
            fout<<"QuickSort-random pivot:\n";
            if(nrmax<=5 && n>=90000)
            {
                fout<<"This algorithm can't sort these numbers!\n\n";
                //continue;
            }

        }

        auto start = chrono::high_resolution_clock::now();
        sorts2[i](0,n-1,aux);
        auto stop = chrono::high_resolution_clock::now();

        if(aux==sorted) //verify if elements are the same
        {
            fout<<"Sorted: YES\n";
            auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
            fout << "Elapsed time in milliseconds: "
                 << duration.count()<<" ms\n\n";

        }
        else
            fout<<"This algorithm can't sort these numbers!\n\n";
    }
    aux.clear();
    aux.shrink_to_fit();

    sorted.clear();
    sorted.shrink_to_fit();

}
bool VerifyInput(char a[], char b[])
{
    if(strlen(a)>10) return 0;
    if(strlen(b)>10) return 0;
    if(!isdigit(a[0]) || !isdigit(b[0])) return 0;

    unsigned long long int A=0, B=0;
    for(int i=0; i<strlen(a); i--)
        A=A*10+a[i]-'0';

    if(A>=2147483647) return 0;

    for(int i=0; i<strlen(b); i--)
        B=B*10+b[i]-'0';

    if(B>=4294967295) return 0;

    return 1;


}
void Transfer(char a[], char b[], int &n, unsigned int &nrmax)
{
    int A=0;
    unsigned int B=0;
    for(int i=0; i<strlen(a); i++)
        A=A*10+a[i]-'0';
    n=A;

    for(int i=0; i<strlen(b); i++)
        B=B*10+b[i]-'0';

    nrmax=B;
}
int main()
{
    vector <unsigned int> v;
    int n,t;
    unsigned int nrmax;
    char inputN[100],inputNRMAX[100];

    fin>>t;

    for(int i=1; i<=t; i++)
    {
        fout<<"Test "<<i<<"\n";

        try
        {
            fin>>inputN>>inputNRMAX;
            //parsing

            if (!VerifyInput(inputN, inputNRMAX))
            {
                fout<<"These numbers can't be sorted!\n\n";
                continue;
            }

            Transfer(inputN, inputNRMAX, n,nrmax);
            v.clear();
            v.shrink_to_fit();

            ///Numbers can be generated with :
            GenerateRandom(n,nrmax,v); //random numbers up to nrmax, and nrmax in the middle
            ///or
            //GenerateSorted(n,nrmax,v); //->already sorted numbers (ascending order)

            fout<<"Sorting algorithms for n= "<<n<<" and nrmax= "<<nrmax<<":\n\n";
            Sort(n,nrmax,v);

            continue;

        }
        catch(...)
        {

            v.clear();
            v.shrink_to_fit();
            fout<<"These numbers can't be sorted!\n";
            continue;

        }

    }

    return 0;
}
