#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
#include<graphics.h>
#include<windows.h>


using namespace std;

// Class containing of all the sorting algorithms and the array
class vizsort
{
	private:
		vector<int>arr;							// Array is private
	public:
		vizsort();								// Constructor declaration
		
		void cprint();
		void swapprint(int a,int b);			// Display functions
		void solidprint(int a,int b);
		
		int arrsize();							// Sorting functions and their subparts
		void bubblesort();
		void insertionsort();
		void selectionsort();
		void merge(int l, int m, int r);
		void mergesort(int l,int r);		
		int partition(int low,int high);
		void quicksort(int low,int high);
};

int main()
{ 
    // Load the graphics driver
	
	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",true);
	
	vizsort s;
	s.cprint();
	s.mergesort(0,s.arrsize());
	
	setfillstyle(SOLID_FILL,GREEN);
	s.cprint();
	getch();
	//delay(3000);
	closegraph();
}

// Constructor for the class to initialize the array
vizsort::vizsort(){
	srand(time(0));
	for(int i = 0;i<250;i++)
	{	
		arr.push_back(rand()%850+1);	
	}
}

// Function to return the array size
int vizsort::arrsize(){
	return arr.size();
}

// Function to display the whole array with solid bars
void vizsort::cprint(){
	for(int i = 0;i<arr.size();i++)
	{
		//line(2*i,851,2*i+1,851-arr[i]);
		bar(4*i,851,4*i+3,851-arr[i]);		
	}
}
void vizsort::solidprint(int a,int b){
	setfillstyle(SOLID_FILL,BLACK);
	bar(4*a,851,4*a+3,0);
	bar(4*b,851,4*b+3,0);
	
}

void vizsort::swapprint(int a,int b){
	setfillstyle(SOLID_FILL,WHITE);
	bar(4*a,851,4*a+3,851-arr[a]);
	bar(4*(b),851,4*(b)+3,851-arr[b]);
	delay(1);
}


// Bubble sort algorithm
void vizsort::bubblesort(){
	for(int i = 0;i<arr.size();i++)
	{
		for(int j = 0;j<arr.size()-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{	
				setfillstyle(SOLID_FILL,BLACK);
				bar(4*j,851,4*j+3,0);
				bar(4*(j+1),851,4*(j+1)+3,0);
				swap(arr[j],arr[j+1]);
				swapprint(j,j+1);
			}
			
		}
	}
}

// Selection sort algorithm
void vizsort::selectionsort()
{
	for(int i = 0;i<arr.size();i++)
	{
		for(int j = i+1;j<arr.size();j++)
		{
			if(arr[i]>arr[j])
			{
				solidprint(i,j);		
				swap(arr[i],arr[j]);
				swapprint(i,j);
			}
		}
	}	
}

// Insertion Sort Algorithm
void vizsort::insertionsort()
{
	for(int i = 1;i<arr.size();i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(arr[i]<arr[j])
			{
				solidprint(i,j);
				swap(arr[i],arr[j]);
				swapprint(i,j);		
			}
		}
	}
}

// Partition member function for quick sort with last element as pivot
int vizsort::partition(int low,int high)
{
	int i = low,j=low-1;
	while(i<high){
		{
			if(arr[i]<=arr[high])
			{	
				j++;
				solidprint(i,j);
				swap(arr[i],arr[j]);
				swapprint(i,j);
			}
			i++;
		}
	}
	solidprint(j+1,high);
	swap(arr[j+1],arr[high]);
	swapprint(j+1,high);
	return j+1;
}
// Quick sort algorithm
void vizsort::quicksort(int low,int high)
{
	if(low<high){
		int i = partition(low,high);
		quicksort(low,i-1);
		quicksort(i+1,high);
	}
}


// Merge sort algorithm
void vizsort::merge(int l, int m, int r){
	int i = l;
    int j = m+1;
    int k = 0;
    vector<int>a;                 // Array to store the elements temporarily while merging   
    while(i<=m&&j<=r)
    {
        if(arr[i]<arr[j])
        {
        	a.push_back(arr[i]);
            i++;k++;
        }
        else{
            a.push_back(arr[j]);
            j++;k++;
        }
        
    }
    while(i<=m)
    {
        a.push_back(arr[i]);
        i++;k++;
    }
    while(j<=r)
    {
        a.push_back(arr[j]);
        j++;k++;
    }
    k = 0;
    for(int i = l;i<=r;i++)
    {
        arr[i]=a[k];
        k++;
    }
    delay(3);
    cleardevice();
	cprint();
}

void vizsort::mergesort(int l,int r){
	if (l < r)   {
        int m = l+(r-l)/2;
        mergesort(l, m);     // Dividing the array in two halves and calling mergesort on the two arrays
		mergesort( m+1, r);
        merge(l, m, r);      // This function is used to merge the two sorted halves	
		
    
	}
}

