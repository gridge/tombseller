/* TErrorHandler.cc
Project: tombseller
Class (implementation) to handle error messages output
Authors: M. Antonelli, S. Pagan Griso
Description:
 Simple class to handle debug messages
Special Notes:
*/

#include "TErrorHandler.h"


TErrorHandler::TErrorHandler() 
{
  outputStream = NULL;
  isStreamPrivate = false;
}

TErrorHandler::~TErrorHandler() 
{
  if (outputStream && isStreamPrivate) {
    ((ofstream*)outputStream)->close();
    delete outputStream;    
  }
}

TErrorHandler::TErrHReturn TErrorHandler::setStream(ostream *newOutputStream) 
{
  TErrHReturn ret;
  ret = EHRET_OK;

  if (outputStream) {
    delete outputStream;
    ret = EHRET_NEWSTREAM;
  }

  outputStream = newOutputStream;

  return ret;
}

TErrorHandler::TErrHReturn TErrorHandler::setFileName(string outputFileName)
{
  TErrHReturn ret;
  ret = EHRET_OK;

  // if it exists and we own it, free it.
  if (outputStream && isStreamPrivate) {
    ((ofstream*)outputStream)->close();
    delete outputStream;
    ret = EHRET_NEWSTREAM;
  }

  //now we need to create the new output stream
  outputStream = new ofstream(outputFileName.c_str());

  if (!outputStream) {
    ret = EHRET_ERR_IOFILE;
  }
  
  return ret;
}

TErrorHandler::TErrHReturn TErrorHandler::debug(TSMsgType tom, string message) 
{
  string finalMessage;

  finalMessage = getTimeStamp();
  finalMessage += " ";
  finalMessage += getTypeOfMessageStr(tom);
  finalMessage += " ";
  finalMessage += message;

  *outputStream << finalMessage << std::endl;

  return EHRET_OK;
}

TErrorHandler::TErrHReturn TErrorHandler::debug(TSMsgType tom, const char *message)
{
  string msg = message;
  return debug(tom, msg);
}

string TErrorHandler::getTimeStamp() 
{  
  stringstream time;
  struct timeval tv;
  struct timezone tz;
  gettimeofday(&tv,&tz);
  time << "[" << tz.tz_minuteswest << ":" << tv.tv_sec << "]" << endl;

  return time.str();
}

string TErrorHandler::getTypeOfMessageStr(TSMsgType tom) 
{
  string msg;
  switch (tom) {
  case TS_INFO:
    msg = "INFO:";
    break;
  case TS_WARNING:
    msg = "WARNING:";
    break;
  case TS_ERROR:
    msg = "ERROR";
    break;
  case TS_DEBUG_L1:
    msg = "DEBUG(L1):";
    break;
  case TS_DEBUG_L2:
    msg = "DEBUG(L2):";
    break;
  case TS_DEBUG_L3:
    msg = "DEBUG(L3):";
    break;
  default:
    msg = "UNSPEC:";
  }
  
  return msg;
}

