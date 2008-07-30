/* TErrorHandler.hh
Project: tombseller
Class (declaration) to handle error messages output
Authors: M. Antonelli, S. Pagan Griso
Description:
 Simple class to handle debug messages
Special Notes:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/time.h>

#ifndef _TERRORHANDLER_GUARD_
#define _TERRORHANDLER_GUARD_

using namespace std;

class TErrorHandler {
 public:
  //Common structures
  //enumerator for return codes
  enum TErrHReturn {
    EHRET_OK=0,
    EHRET_NEWSTREAM=-1,
    EHRET_ERR_IOFILE=1
  };

  //enumerate allowed types of message
  enum TSMsgType {
    TS_INFO, 
    TS_WARNING, 
    TS_ERROR, 
    TS_DEBUG_L1, 
    TS_DEBUG_L2, 
    TS_DEBUG_L3
  };

 protected:
  // contains the output stream
  ostream *outputStream;
  //true if we created the stream and have to free it
  bool isStreamPrivate;

  //get timestamp string
  string getTimeStamp();
  // get type of message string
  string getTypeOfMessageStr(TSMsgType tom);  

 public:
  TErrorHandler();
  ~TErrorHandler();

  // Set the output stream
  TErrHReturn setStream(ostream *newOutputStream);
  // Create a text file and set the output stream acordingly
  TErrHReturn setFileName(string outputFileName);

  // Use this to write debug information into the log
  TErrHReturn debug(TSMsgType tom, string message);
  TErrHReturn debug(TSMsgType tom, const char* message);
  
};

#endif
