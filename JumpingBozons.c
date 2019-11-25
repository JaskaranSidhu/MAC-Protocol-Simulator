/* -------------------------------------------------------------------------
 * This program provides a basic structure for a discrete-event simulator.
 *
 * Name              : a4.c
 * Author            : Jasaran Sidhu
 * Language          : C
 * Latest Revision   : 12-03-2018
 * -------------------------------------------------------------------------
 */

/* -------------- Libraries ------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* -------------- Global variables ------------------------ */
#define MAX_INT 2147483647 /* Maximum positive integer 2^31 - 1 */
#define SIM_END_TIME 1000000.0
#define SEED 123123
#define M 11			/* Set number of bozons */
#define S 100.0		/* Set mean sleep duration */
#define Y 10.0		/* Set mean yodel duration */


/* Debugging flag */
#define DEBUG 1

/* -------------- Structures ------------------------------ */
// Events can be defined as structures. Each event has at least two elements: 1.time 2.type

struct Bozons {
	int status;					// 1 = sleep	|	 2 = yodeling
	double sleepStart;
	double sleepFinish;
	double yodelStart;
	double yodelFinish;
	int flag;
};


// You can define your program entities (e.g. Bozon, Atmosphere and etc.) as structures.

/* -------------- Function declarations ------------------- */
double uniform01(void);
double getExponentialVar(double mean);
double getNextEvent();

/* -------------- Function definitions ------------------- */
/* ============== */
int main(void)
/* ============== */
{
	/* *************** Defining Variables *************************** */
	// You should define simulator variables (e.g. time, event list, entities, statistical counters and control variables)
	double curr_time;
	double nextEvent;
	struct Bozons Bozons_list[M]; /* An array of Events */
	int yodeler = 0;
	int attempted = 0;
	int successful = 0;
	double totalEvent1 = 0;
	double totalEvent2 = 0;
	double totalEvent3 = 0;
	int x = 0;
	int y = 0;
	/* ************************************************************** */

	/* *************** Initialization ******************************* */
	// You should initialize ALL VARIABLES before the main loop starts
	curr_time = 0.0;
	srandom(SEED);

	for(int i = 0; i < M; i++) {
		Bozons_list[i].status = 1;
		Bozons_list[i].sleepStart = 0.0;
		Bozons_list[i].sleepFinish = getExponentialVar(S);
		Bozons_list[i].flag = 1;
	}

	// You should initialize your random number generator
	// You should generate INITIAL EVENTS before the main loop starts
	/* ************************************************************** */

	/* Main loop */
	while (curr_time < SIM_END_TIME) {

		// This is where I calculate my values for melodious time, Idle time, and screeching time. 
		// I also calculate the number of perfect yodels here, by setting the flag to 0 (false) if there are more then 1 yodelers.
		nextEvent = getNextEvent(Bozons_list);
		if(yodeler == 0) {
			totalEvent1 = totalEvent1 + (nextEvent - curr_time);

			for(int i = 0; i < M; i++) {
				Bozons_list[i].sleepStart = nextEvent;
			}
		}

		if(yodeler == 1) {
			totalEvent2 = totalEvent2 + (nextEvent - curr_time);

			for(int i = 0; i < M; i++) {
				if(Bozons_list[i].status == 2) {
					Bozons_list[i].yodelStart = nextEvent;
					break;
				}
			}
		}

		if(yodeler > 1) {
			totalEvent3 = totalEvent3 + (nextEvent - curr_time);

			for(int i = 0; i < M; i++) {
				if(Bozons_list[i].status == 2) {
					Bozons_list[i].flag = 0;
					Bozons_list[i].yodelStart = nextEvent;
					break;
				}
			}
		}


		curr_time = nextEvent;

		// This is where I loop though all the Bozons and check to see which one will be triggering the event. It will then switch the state and do all the appropriate changes.
		for(int i = 0; i < M; i++) {

			if(Bozons_list[i].status == 1) {

				if(Bozons_list[i].sleepFinish <= curr_time) {
					Bozons_list[i].status = 2;
					Bozons_list[i].yodelStart = curr_time;
					Bozons_list[i].yodelFinish = (curr_time + getExponentialVar(Y));
					yodeler++;
					attempted++;
					if(yodeler == 1) {
						Bozons_list[i].flag = 1;
					} else {
						Bozons_list[i].flag = 0;
					}
				}

			} else if(Bozons_list[i].status == 2) {

				if(Bozons_list[i].yodelFinish <= curr_time) {
					Bozons_list[i].status = 1;
					Bozons_list[i].sleepStart = curr_time;
					Bozons_list[i].sleepFinish = (curr_time + getExponentialVar(S));
					yodeler--;

					if(Bozons_list[i].flag == 1) {
						successful++;
					}
					Bozons_list[i].flag = 0;
				}
			}
		}
	}

	double perfect = (float) successful / (float) attempted;

	//printf("M: %d and ", M);
	//printf("S: %f.\n", S);
	//printf("Y: %f\n", Y);
	//printf("Total time observing channel: %f\n", SIM_END_TIME);
	//printf(" _____________________________________________________________________________________________________________________________\n");
	//printf("|  M  | Idle Percentage | Melodious Percentage | Screeching Percentage | Total Attempted Yodels | Percentage of Perfect Yodels|\n");
	//printf("|_____________________________________________________________________________________________________________________________|\n");
	printf("|  %d  |    %f    |       %f       |        %f       |          %d          |           %f         |\n", M, totalEvent1 / 10000.0000, totalEvent2 / 10000.0000, totalEvent3 / 10000.0000, attempted, perfect * 100);
	printf("|_____________________________________________________________________________________________________________________________|\n");
	//printf("Total percentage of time everyone was sleeping: %f\n", totalEvent1 / 10000.0000);
	//printf("Total percentage of time one person Yodeling (melodious): %f\n", totalEvent2 / 10000.0000);
	//printf("Total percentage of time Screeching: %f\n", totalEvent3 / 10000.0000);
	//printf("Number of attempted yodels: %d\n", attempted);
	//printf("Percentage of attempted yodels that were perfect: %f\n\n\n", perfect * 100);

	return 0;
}


double getNextEvent(struct Bozons Bozons_list[]) {
	// This function is used to determine the time of the next event.
	double nextEvent = MAX_INT;
	for(int i = 0; i < M; i++) {

		if(Bozons_list[i].status == 1) {
			if(nextEvent > Bozons_list[i].sleepFinish){
				nextEvent = Bozons_list[i].sleepFinish;
			}

		} else if(Bozons_list[i].status == 2) {

			if(nextEvent > Bozons_list[i].yodelFinish){
				nextEvent = Bozons_list[i].yodelFinish;
			}
		}
	}
	return nextEvent;
}


/* Generate a random floating point number uniformly distributed in [0,1] */
/* ============== */
double uniform01()
/* ============== */
{
	double randnum;

	/* Get a random positive integer from random() */
	randnum = (double) 1.0 * random();

	/* Divide by max integer to get something in the range 0.0 to 1.0 */
	randnum = randnum / (1.0 * MAX_INT);
	return randnum;
}

/* Generate a random floating point number exponentially distributed with mean = m */
/* ============== */
double getExponentialVar(double m)
/* ============== */
{
	double randnum, ans;
	randnum = uniform01();
	ans = -(m) * log(randnum);
	return ans;
}

