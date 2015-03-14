#General thought on requirements and structure of the project

# [Introduction](http://code.google.com/p/tombseller/wiki/Introduction) #

> We need a general structure that allows us to go step by step, giving always the possibility to easily extend and port what we did but also to finalize the project whenever necessary.

> Finally we need also a common header to copy/paste into each file.. :-)

# Details #

> We could divide the project in different _sections_:
    * I/O interface
    * Data interface
    * Objects
    * Main program

> The guideline is that each (main) section corresponds roughly to one working directory.

> In particular this could be our directory structure:

  * iomanager: libraries for I/O at user-level, including graphics
  * datamanager: libraries for I/O of permanent data
  * objects: Game classes
  * main: Main program and handling functions

> A discussion of the Makefile structure can be found [here](http://code.google.com/p/tombseller/wiki/CodeStructure).

# Headers #

Just a nice try... feel free to change it :)

Field without the ':' are meant to be replaced, fields with the trailing ':' are supposed to be filled.

## C++ Header ##
```
/* NomeFile
Project: tombseller
Comment
Authors: M. Antonelli, S. Pagan Griso
Description:
Special Notes:
*/

```

## Bash style header ##
```
# Nomefile
# Project: tombseller
# Comment
# Authors: M. Antonelli, S. Pagan Griso
# Description:
# Special Notes:
```

# I/O Interface #

> This section covers both graphical, text[, socket] and debug output, as well as keyboard/mouse inputs.
> A set of classes to wrap the details of the particular implementation. In my mind at the moment we need a quite high-level interface.
> I would put in this section all the classes that we use to display something, from the game from/to the _user_ (can also be another TombSeller program in the future for LAN parties, will be just the graphical interface plus debug information in the beginng).
> We need to specify in this section the guidelines for this interface in order to decide exactly at which level we want to put it; i would also specify the external resources and some detail of the current implementation of these interfaces (for this project it's useless to divide the interface and the implementations in different directories).

## Interface design ##

### Graphical interface ###

See GrpahicalInterface wiki page for implementation details and discussion.

### Debug interface ###

> I would use a simple (text file connected) stream to report errors, assigning a type of error.

```
 class TErrorHandler
   TErrorHandler // Init with output stream or filename. Some default choice also needed. 
   SetStream // Set output stream
   SetFileNmae // Create new output stream connected to a given file (create it if necessary)
   Debug(TMsgType, string) // report message of a given type as specified by the following enum. Have to write the type of error, the timestamp and the message.
   enum TMsgType = {TS_INFO, TS_WARNING, TS_ERROR, TS_DEBUG_L1, TS_DEBUG_L2, TS_DEBUG_L3} // define the type of messages that can be delivered to the class.
      // TS_INFO: general informations
      // TS_WARNING: general warnings
      // TS_ERROR: error condition detected
      // TS_DEBUG_LX: debug informations divide into 3 levels of depth
   ~TErrorHandler //Close output stream
```


## Input interface ##

## External resources ##

The following external resources will be used in this project for implementing the interface outlined in the previous sections:

  * opengl
  * gtkmm


# Data interface #
> Needed to store and retrieved different kind of informations. We'll use it to get things like images for the graphics library as well as game-related settings and status. This is needed because of the complexity of the information stored in an adventure game. Absolutely needed if we want to be able to expand it in a strategic game also in the future.

> We could use a DB-based storage for some kind of informations or simply serialize them. Anyway we need an interface to do that (i.e. to retrieve the different type of informations) so that we can easily switch the output mechanism in the future and start with a simple one.

> We can start with a skeleton of this interface and then add members as long as we need different data types or access methods.

# Objects #
> Collection of classes defining the different (meta-)physical objects we need. From a generic object in the graphic adventure (then specialized in things like a chair) to a wallet for the strategic part. This will be one the core parts of the project. Need a lot of development here.

> See [ObjectDefinitions](http://code.google.com/p/tombseller/wiki/ObjectDefinitions) wiki for details.


# Main program #

> This should be the core of the program.
> Here we need to be able to decide the _flow_ of the program. When to look at I/O interface for input/output, when to take special actions and whatever the real program needs. Could also think in creating a separate time-activated action handler (for schedule things to happen in a given amount of time, but this will be an implementation detail..).