#ifndef TIMEUTILS_H_INCLUDED
#define TIMEUTILS_H_INCLUDED

/*
 * Function: sampleStart()
 * Use sampleStart()
 * ---------------------------
 *  start counting time in the moment
 */
void sampleStart();

/*
 * Function: sampleStop
 * use: sampleStop()
 * ---------------------------
 *  stop counting time started by sampleStart
 */
void sampleStop();

/*
 * Function: printTime
 * use PrintTime()
 * ---------------------------
 *  print the time calculated between sampleStart and sampleStop
 *  in micro seconds (us)
 */
void printTime();

#endif
