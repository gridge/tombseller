/* tombseller.h
Project: tombseller
Main program header file
Authors: M. Antonelli, S. Pagan Griso
Description:
Special Notes:
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <getopt.h>

#include <TErrorHandler.h>

#ifndef _TOMBSELLER_GUARD_
#define _TOMBSELLER_GUARD_


//global variables
TErrorHandler ErrorHandler;

//global functions
void usage();
int globalInit();

#endif
