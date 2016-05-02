// ----------------------------------------------------------- 
// NAME : Kyler Witting                      User ID: kmwittin 
// DUE DATE : 03/18/2016
// PROGRAM ASSIGNMENT 3
// FILE NAME : thread-main.cpp
// PROGRAM PURPOSE :
//      Read in n integers into the array x[*]
//      Initialize the array B[*,*] by copying x[*]  to the 0­th row of B[*,*]
//      Iterates k = log 2 (n) times
//      Each iteration: 
//          Creates n threads
//          Waits for all n threads to exit
//      Prints out the last (i.e., k­th) row of array B[k,*]
// -----------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <math.h>
#include "thread.h"

int B[1000][1000];

//---------------------------------------------------------------//
//  main program 
//---------------------------------------------------------------//

int main(int argc, char *argv[])
{
	//Local array for cin 
	int *array;
	//array size and k= log2(arraySize)
	int	arraySize, k,
	//for loop variables 
		i, j;

	//Reads array size
	cin >> arraySize;
	k = log2( arraySize );

	//Reads array into array
	array = new int[arraySize]; // create the array
	for (i = 0; i < arraySize; i++)
		cin >> array[i]; 

	cout << "Concurrent Prefix Sum Computation" << endl << endl;
	cout << "Number of input data = " << arraySize << endl;

	//Prints the input array 
	cout << "Input array:" << endl;
	for (i = 0; i < arraySize; i++)
		cout << setw(4) << array[i];
	cout << endl << endl << endl;

	//Sets B[0] to the array[]
	for( i = 0; i < arraySize; i++ )
		B[0][i] = array[i];

	//Loop iterations for threading 
	PrefixThread *thread[k+1][arraySize];

	for( i = 1; i < k+1; i++ ) { 
		//goes into PrefixThreadfor each element
		for( j = 0; j < arraySize; j++ ){
			thread[i][j] = new PrefixThread(i, j);
			thread[i][j]->Begin();
		}

		//waits for threads to complete, then prints results of that run 
		for( j = 0; j < arraySize; j++ )
			thread[i][j]->Join();
		cout << "Result after run "<< i << ": " << endl;
		for (j = 0; j < arraySize; j++)
			cout << setw(4) << B[i][j];
		cout << endl << endl;
	}


	//Final Print statement and Exit() and return
	cout << endl << "Final result after run "<< k << ": " << endl;
	for (i = 0; i < arraySize; i++)
		cout << setw(4) << B[k][i];
	cout << endl;

	Exit();
	return 0; 
}
