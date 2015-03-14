# Grpahical Interface detailed discussion

# Introduction #

# General layout #
> Following the yesterday discussion I would propose a big window with a smaller window inside. The smaller window will actually play the graphic adventure while in the external one (surrounding the inner-one) I would put everything is needed for the strategic part. In this way the user can play the adventure and wait for something to happen from the strategic point of view. We can also allow switching to a full-screen mode for the adventure or a full-strategic view.

> We need various components:
    * A big status bar with:
      * dialogs display
      * object content
    * A screen for Adventure display
    * A screen for strategic view
    * A screen for menus and all out-of-game options


# Objects definitions #
> We need a general interface for handling different kind of objects, in particular:
    * a static small picture to be displayed in the "external" view (outside the Ad game, like in a status bar)
    * A full picture (or object, if 3D is preferred) for Ad display (With all the needed properties like position. motion)
    * An animated object (inherited by the full picture (framed motion must be implemented)

> This kind of objects could be implemented in different stages (like an object for handling animation, another just for the display, etc..) that can be built together to finally have the wanted classes described above..


# Details #