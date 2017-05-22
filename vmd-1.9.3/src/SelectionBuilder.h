/***************************************************************************
 *cr
 *cr            (C) Copyright 1995-2016 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

/***************************************************************************
 * RCS INFORMATION:
 *
 *      $RCSfile: SelectionBuilder.h,v $
 *      $Author: johns $        $Locker:  $             $State: Exp $
 *      $Revision: 1.14 $       $Date: 2016/11/28 03:05:04 $
 *
 ***************************************************************************
 * DESCRIPTION:
 *  generated by Fast Light User Interface Designer (fluid) version 1.0011
 ***************************************************************************/
#ifndef selpalette_h
#define selpalette_h
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Menu_Button.H>
#include "GraphicsFltkMenu.h"

class SymbolTable;
class Molecule;

/// Fl_Group subclass implementing a set of controls for browsing atom 
/// data fields, editing atom selection macros, and GUI-based atom selection
/// construction.
class SelectionBuilder : public Fl_Group {
public:
  SelectionBuilder(int, int, GraphicsFltkMenu *, Fl_Input *, SymbolTable *);

  void use_molecule(Molecule *);
  void set_selection(const char *);
    
  void update_selection();

  /// The macro browser will contain all the valid singleword items, even
  /// those that aren't defined as macros, like 'water'.  We can determine
  /// which singlewords are macros by calling 
  /// SymbolTable::get_custom_singleword() on the name.  
  /// For now, it is possible to add macros only from the command line, mainly
  /// because we have no way of saving them.  At some point it would be
  /// desirable to be able to add, modify, and remove macros from this GUI.
  void update_macrobrowser();

private:
  GraphicsFltkMenu *menu; 
  SymbolTable *table;
  Molecule *mol;

  int goto_end;

  void append_text(const char *);

  static void apply_cb(Fl_Widget *, void *);
  static void reset_cb(Fl_Widget *, void *);
  static void cancel_cb(Fl_Widget *, void *);
  static void ok_cb(Fl_Widget *, void *);
  static void keyword_cb(Fl_Widget *, void *);
  static void value_cb(Fl_Widget *, void *);
  static void and_cb(Fl_Widget *, void *);
  static void or_cb(Fl_Widget *, void *);
  static void not_cb(Fl_Widget *, void *);
  static void macrobrowser_cb(Fl_Widget *, void *);

  Fl_Button *applybutton;
  Fl_Browser *keywordbrowser;
  Fl_Browser *valuebrowser;
  Fl_Button *andbutton;
  Fl_Button *orbutton;
  Fl_Button *notbutton;
  Fl_Button *resetbutton;
  Fl_Menu_Button *recentmenu;
  Fl_Input *selectiontext;

  Fl_Browser *macrobrowser;
  Fl_Output *macrooutput;
};
#endif
