#include<iostream>
#include <time.h>
using namespace std;

void quicksort_recursive(int array[], int left, int right) {
    // return if the all elements are sorted
    if (left >= right) {
        return; 
    }

    // Used the pivot element as right most element
    int pivot = array[right];
    int i = left-1;
    int j = left;

    //Loop to find the elements less than the pivot and the element greater than the pivot 
    while (j < right) {
       if (array[j]<pivot){
            i++;
            int temp=array[i];
            array[i]=array[j];
            array[j]=temp;
       }
       j++;
    }

    // Swap pivot element to its final position
    i++;
    int temp = array[i];
    array[i] = array[right];
    array[right] = temp;

    //This is the recursive algoritm call for left half of the array and right half of the array
    quicksort_recursive(array, left, i - 1);
    quicksort_recursive(array, i + 1, right);
}

void QuickSort_nonrecursive(int array[], int left, int right)
{
   
    int stack[right - left + 1]; 
    int top = -1;  
    stack[++top] = left;
    stack[++top] = right; 
    while (top >-1) {    
        right = stack[top--];
        left = stack[top--]; 
        int x = array[right];
        int i = (left - 1);
  
        for (int j = left; j <= right - 1; j++) {
            if (array[j] <= x) {
                i++;
                int temp = array[i];
                array[i]=array[j];
                array[j]=temp;            
            }
        }
        int temp=array[i+1];
        array[i+1]=array[right];
        array[right]=temp;      
        int p = i + 1;
        if (p - 1 > left) {
            stack[++top] = left;
            stack[++top] = p - 1;
        }
        if (p + 1 < right) {
            stack[++top] = p + 1;
            stack[++top] = right;
        }
    }
} 


int main() {
    int a,b,c,d,e;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>e;

    int lengths[] = {a,b,c,d,e};
    for (int m=0;m<5;m++){
        
        // set the length of the array

        const int length = lengths[m];
        
        // create an array of random integers between 0 and 999
        int array[length];
        for (int i = 0; i < length; i++) {
            array[i] = rand() % 1000;
        }

    
        int n = sizeof(array) / sizeof(array[0]);
        //Calling the quixk sort algorithm
        clock_t start = clock();
        quicksort_recursive(array, 0, n - 1);
        clock_t end=clock();
    
        double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
        std::cout << std::endl;
        cout<<"Total elements in array :"<<length<<endl;
        cout<<" Time taken for nonrecursive quick sort is "<<time_spent<<endl;
        cout<<"\n";

        clock_t start2 = clock();
        QuickSort_nonrecursive(array, 0, n - 1);
        clock_t end2=clock();

        double time_spent2 = (double)(end2-start2)/CLOCKS_PER_SEC;
        std::cout << std::endl;
        cout<<"Total elements in array :"<<length<<endl;
        cout<<" Time taken for recursive quick sort is "<<time_spent2<<endl;
        cout<<"\n";
    }
}