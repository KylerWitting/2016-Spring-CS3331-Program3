// ----------------------------------------------------------- 
// NAME : Kyler Witting                      User ID: kmwittin 
// DUE DATE : 03/18/2016
// PROGRAM ASSIGNMENT 3
// FILE NAME : thread.h
// PROGRAM PURPOSE :
//      Head file for class PrefixThread definition 
// -----------------------------------------------------------

#ifndef _THREAD_H
#define _THREAD_H

// header file
#include "ThreadClass.h"

//Global Array used for the multiple threads
extern int B[1000][1000];

//---------------------------------------------------------------//
//  Process Thread Class: 
//     each thread is given a location that it fills with the 
//     proper data, using the given algorithm 
//---------------------------------------------------------------//

class PrefixThread : public Thread
{
	public:
		// constructor
		PrefixThread( int i, int j ); 

	private:
		void ThreadFunc();  // thread body
		int i;
		int j;
};

#endif
