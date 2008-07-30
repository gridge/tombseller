/* tombseller.cc
Project: tombseller
Main program
Authors: M. Antonelli, S. Pagan Griso
Description:
Special Notes:
*/

#include "tombseller.h"


int main(int argc, void **argv)
{

  globalInit();
  
  // Get command line options
  int MyOpt;                              // Option from getopt
  extern char *optarg;                    // getopt target name(s)
  extern int optind;                      // used to get last option index in argv array
  while ( (MyOpt = getopt(argc, (char* const*)argv, "h")) != -1) {
    switch (MyOpt) {
    case 'h':
      usage();
      return 0;
      break;
    default:
      ErrorHandler.debug(TErrorHandler::TS_ERROR, "Unrecognized command-line option.");
      return TErrorHandler::TS_ERROR;
    }    
  } //end loop over commandline options

  return 0;
}


void usage()
{
  std::cout << "=====================================================" << std::endl;
  std::cout << "==================== TOMB SELLER ====================" << std::endl;
  std::cout << "=== Authors: ========================================" << std::endl;
  std::cout << "==== M. Antonelli ===================================" << std::endl;
  std::cout << "==== S. Pagan Griso =================================" << std::endl;
  std::cout << "=====================================================" << std::endl;
  std::cout << "=== Usage:                                        ===" << std::endl;
  std::cout << "tombseller [-h]                                      " << std::endl;
  std::cout << "\t h: Print command-line help                        " << std::endl;
  std::cout << std::endl;

}

int globalInit()
{
  int ret = 0;

  ret |= ErrorHandler.setFileName("./log.txt");

  return ret;
}
