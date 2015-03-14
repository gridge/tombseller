#Definition and behavior of objects in the game

# Introduction #

We need to classify the different kind of objects, and then implement each one as soon as we need it.

> Ex. We could define an _object_ in the graphic adventure that can potentially _do_ some actions (enabled in a specific implementation) and has some image/position stored.

# General thoughts #
> Here we put general requirements that we need to satisfy.

## Adventure World (AdWorld) ##

  * We need a timer and a connected calendar. We have cycles of weeks, and each day is divided in day, evening, night.
  * Handling of causal connection of the events (could also be handled by objects, but less powerful)
  * Handling change of scenarios and movies


## Jeff ##
  * Containers for objects
  * Money (special object? sure!)

## "Static" Objects ##
> Referred in the following as _objects_. They are everything that can be placed on a scenario and can be interactive by the user (Jeff).

  * Can be in multiple satates
    * hidden
    * other specifc-states
  * Should be able to contain various graphical rapresentation:
    * small picture
    * big multiple states
    * animations

## Scenarios ##
> Consists in the "ambient" where the Ad part will take place. In my mind:
    * Have to contain a set of objects in predefined places (also multiple).
    * Multiple representations depending on world settings, like time.

## Actions ##

> This is everything is happening, includes:
    * a sequence starts (like a movie..)
    * a sequence of pre-defined changes to objects/scenario properties
    * changes in the strategic world

## Interactions ##
> This is one of the most complex design issues. _How to make everything interact?_

> We need:
    * objects interacting with other objects
    * objects interacting with scenarios (and vice-versa)
    * clock interacting with objects and scenarios
    * objects triggering _actions_


## Strategic world (StWorld) ##
> This is another world gathering all strategic part of the game. Includes everything you can imagine... and will be defined in the future :p

# Details #

> Different class of objects needed:
    * TCalendar: keeps track of the super-world clock (common to AdWorld and StWorld)
    * TStaticObject: inspite of the name can contain animation. Basic class for the objects as defined before.
    * TManInTheWorld: Jeff basic class. Can be used to extend to multi-players in the future.
    * TAdWorld: Graphic adventure container to handle all interactions as defined in the Interaction section above.
    * TStWorld: Strategic adventure container. Could think to have pointers to current instances of TAdWorld and vice-versa for easy (but dangerous) interaction.
    * TScenario: scenario base class.