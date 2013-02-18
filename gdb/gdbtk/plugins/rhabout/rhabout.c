/* Sample command procedure library for a plug-in. */

/* You have to include the Tcl headers, of course. */
#include <tcl.h>

/* Define the functions that implement your commands as required by Tcl */
#define EXPORT /* nothing */

int extra_text (ClientData clientData,
                Tcl_Interp *interp,
                int objc, Tcl_Obj *CONST objv[]);

/* Here you actually do whatever you want, like calling your target 
   libraries etc.  Here we just return a string. */

int
extra_text (ClientData clientData,
                Tcl_Interp *interp,
                int objc, Tcl_Obj *CONST objv[])
{
  interp->result = "\nThis is a sample plug-in\n";
  return TCL_OK;
}

/* Initialization function required in Tcl libraries. */

int EXPORT
Rhabout_Init (Tcl_Interp *interp)
{
  /* Register your command as a Tcl command with this interpreter. */
  Tcl_CreateObjCommand (interp, "rhabout_extra_text", extra_text,
                        (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);

  /* Register this package */
  Tcl_PkgProvide (interp, "RHABOUT", "1.0");
  return TCL_OK;
}
