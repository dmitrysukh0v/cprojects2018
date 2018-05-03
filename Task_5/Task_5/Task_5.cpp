// Task_5.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
void qsort(T *a,int size){
	int start=0;
	int end=size;
	T temp;
	T center;

	center=a[size/2];

	do{	
		while(a[start]<center){
			start++;
		}
		while(a[end]>center){
			end--;
		}
		if(start<=end){
			temp=a[start];
			a[start]=a[end];
			a[end]=temp;
			start++;
			end--;
		}
	}while(start<=end);

	if(end>0){
		qsort(a,end);
	}
	if(size>start){
		qsort(a+start,size-start);
	}
}

int main(int argc,char* argv[])
{
	int size;
	cout<<"Enter array size: ";
	cin>>size;

	srand(clock());
	//int
	int *arr=new int[size+1];

	cout<<"Generated array:"<<endl;
	for(int i=0;i<size;i++){
		arr[i]=-100+rand()%200;
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	int start=clock();
	qsort(arr,size-1);
	int end=clock();

	cout<<"Sorted array:"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<endl<<"Time: "<<end-start<<" ms"<<endl;

	//float

	float *arr2=new float[size+1];

	cout<<"Generated array:"<<endl;
	for(int i=0;i<size;i++){
		arr2[i]=static_cast<float>(rand())/static_cast<float>(100.0);
		cout<<arr2[i]<<" ";
	}
	cout<<endl;

	start=clock();
	qsort(arr2,size-1);
	end=clock();

	cout<<"Sorted array:"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr2[i]<<" ";
	}
	cout<<endl;

	cout<<endl<<"Time: "<<end-start<<" ms"<<endl;

    system("pause");
    return 0;
}
