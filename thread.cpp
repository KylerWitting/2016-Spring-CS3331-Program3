// ----------------------------------------------------------- 
// NAME : Kyler Witting                      User ID: kmwittin 
// DUE DATE : 03/18/2016
// PROGRAM ASSIGNMENT 3
// FILE NAME : thread.cpp
// PROGRAM PURPOSE :
//      Class implemention file for the PrefixThread class
// -----------------------------------------------------------

#include <stdio.h>
#include <math.h>
#include "thread.h"

//---------------------------------------------------------------//
//  Prefix Sum Class: 
//     constructor
//---------------------------------------------------------------//

PrefixThread::PrefixThread(int i, int j):i( i ), j( j )
{
	fprintf( stdout, "      Thread %d Created\n", j );
}

//---------------------------------------------------------------//
//  Prefix Sum  Thread Class body: 
//     Determines if the location given needs to be copied 
//     or added to the new location
//---------------------------------------------------------------//

void PrefixThread::ThreadFunc() {
	Thread::ThreadFunc();
	
	//Algorithm that is given in Assignment Details
	if( j - (int)pow( 2, i-1)  < 0 ) { 
		fprintf( stdout, "      Thread %d copies x[%d]\n", j, j );
		B[i][j] = B[i-1][j];
	}
	else{
		fprintf( stdout, "      Thread %d computes x[%d] + x[%d-2^(%d-1)]\n", j, j, j, i );
		B[i][j] = B[i-1][j] + B[i-1][j - (int)pow(2, i-1)];
	}
	Exit();
}
