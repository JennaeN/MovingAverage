/*******************************************
 * Author: C2C Jennae Steinmiller
 * Created: 15 Oct 2013
 * Description: This program has four different functions in it. The first
 * function calculates a moving average between an array of integers.
 * The number of elements in the average is specified by a constant. The
 * second function calculates the largest integer within the array that is passed
 * to it. Next, a function calculates the smallest number passed to it. Finally, the
 * range is calculated in the same way the highest and lowest values were calculated.
 * Documentation: I received help from C2C Ryan Hub to try to troubleshoot my code.
 *******************************************/
#include <msp430.h> 
#define N_AVG_SAMPLES 0x04
#define LENGTH 10
/*
 * main.c
 */

void movingAverage(int array[]);
int maximum(int array[]);
int minimum(int array[]);
void range(int array[]);

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	//char sampleStream[] = { 45, 42, 41, 40, 43, 45, 46, 47, 49, 45 }; //Use zero as an ending point
	int sampleStream[] = { 174, 162, 149, 85, 130, 149, 153, 164, 169, 173, 0, 0 };

	//Call each of the functions
	movingAverage(sampleStream);
	int max = maximum(sampleStream);
	int min = minimum(sampleStream);
	range(sampleStream);

	return 0;
}

void movingAverage(int sampleStream[]) {

	char run = 1;
	char i;

	unsigned int sampleValue1 = sampleStream[0];
	//unsigned char sampleValue2 = sampleStream[1];

	while (run <= LENGTH) {
		float average = 0;

		for (i = 1; i <= N_AVG_SAMPLES; i++) {
			average += sampleValue1;	// + sampleValue2;
			sampleValue1 = sampleStream[i+run-1];	//sampleValue2;
			//sampleValue2 = sampleStream[run+1];

		}
		average = average / N_AVG_SAMPLES;
		sampleValue1 = sampleStream[run];
		//sampleValue2 = sampleStream[i - (N_AVG_SAMPLES - 1)];

		float averages[LENGTH - 1];
		averages[run - 1] = average;
		//if (sampleStream[count] == 0) {
		//run = 0;
		run++;

	}
}

int maximum(int sampleStream[]) {

	//Set the max equal to the first value
	int max = sampleStream[0];
	char count = 0;

	while (count < LENGTH) {
		//Set max as the largest number
		if (sampleStream[count] > max) {
			max = sampleStream[count];
		}
		count++;
	}
	return max;
}

int minimum(int sampleStream[]) {

	//Assume the first value is the smallest value
	int min = sampleStream[0];
	char count = 0;

	while (count < LENGTH) {
		//Set min as smallest number
		if (sampleStream[count] < min) {
			min = sampleStream[count];
		}
		count++;
	}
	return min;
}

void range(int sampleStream[]) {

	char range[2];
	//Assume first value is biggest and smallest
	int max = sampleStream[0];
	int min = sampleStream[0];
	char count = 0;

	//The range is calculated the same way the max and min values were
	while (count < LENGTH) {
		if (sampleStream[count] > max) {
			max = sampleStream[count];
		} else if (sampleStream[count] < min) {
			min = sampleStream[count];
		}
		count++;
	}
	range[0] = min;
	range[1] = max;
}
