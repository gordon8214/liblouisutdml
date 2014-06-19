/* liblouisutdml Braille Transcription Library

   This file may contain code borrowed from the Linux screenreader
   BRLTTY, copyright (C) 1999-2006 by
   the BRLTTY Team

   Copyright (C) 2004, 2005, 2006
   ViewPlus Technologies, Inc. www.viewplus.com
   and
  Abilitiessoft, Inc. www.abilitiessoft.com
   All rights reserved

   This file is free software; you can redistribute it and/or modify it
   under the terms of the Lesser or Library GNU General Public License 
   as published by the
   Free Software Foundation; either version 3, or (at your option) any
   later version.

   This file is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
   Library GNU General Public License for more details.

   You should have received a copy of the Library GNU General Public 
   License along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.

   Maintained by John J. Boyer john.boyer@abilitiessoft.com
   */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (void)
{
  static const char *makefileStub[] = {
    "# Make liblouisutdml.dll and liblouisutdml.lib",
    "# This file was generated by make_makefile.exe.",
    "# Do not edit this file. Change configure.mk.",
    "# Then run",
    "# nmake /f Makefile.nmake",
    "# to generate liblouisutdml.dll and liblouisutdml.lib",
    "!include configure.mk",
    "!include $(LIBLOUIS_PATH)\\windows\\configure.mk",
    "SRCDIR = ..\\liblouisutdml",
    "HEADERS = $(SRCDIR)\\louisutdml.h $(SRCDIR)\\liblouisutdml.h liblouisutdml.def",
    "HEADERS = $(HEADERS) $(SRCDIR)\\sem_enum.h $(SRCDIR)\\sem_names.h",
    "INCLUDES = /I$(LIBLOUIS_PATH)\\liblouis /I$(LIBLOUIS_PATH)\\windows\\include",
    "INCLUDES = $(INCLUDES) /Iinclude /I$(LIBXML2_PATH)\\include",
    "LIBLOUIS_DLL = $(LIBLOUIS_PATH)\\windows\\liblouis.dll",
    "CCFLAGS =  /nologo /O2 /W1 /c $(INCLUDES)",
    "DLLFLAGS = /dll /nologo /DEF:liblouisutdml.def",
    "!if \"$(UCS)\" == \"2\"",
    "CCFLAGS = $(CCFLAGS) /DWIDECHAR_TYPE=\"unsigned short int\"",
    "!else",
    "CCFLAGS = $(CCFLAGS) /DWIDECHAR_TYPE=\"unsigned int\"",
    "!endif",
    "CC = cl.exe",
    "# Macros for building libxml2 object files.",
    "LXHEADERS = include\\config.h include\\xmlversion.h",
    "LXCCFLAGS = /nologo /O2 /W1 /c",
    "LXCCFLAGS = $(LXCCFLAGS) /DVERSION=\"libxml2-1.2.7.2\"",
    "LXSRCDIR = $(LIBXML2_PATH)",
    "LXINCLUDES = /Iinclude /I$(LXSRCDIR) /I$(LXSRCDIR)\\include",
    "LXCCFLAGS = $(LXCCFLAGS) $(LXINCLUDES)",
    "# Now start the actual build.",
    "# The lists of object files in the LIBLOUISUTDML_OBJ and LIBXML2_OBJ",
    "#     macros are generated here.",
    "collect_results: liblouisutdml.dll",
    "    if not exist brailleblasterlib mkdir brailleblasterlib",
    "    copy liblouisutdml.dll brailleblasterlib",
    "    copy $(LIBLOUIS_PATH)\\windows\\liblouis.dll brailleblasterlib\\liblouis.dll",
    "    if not exist libslib mkdir libslib",
    "    copy liblouisutdml.lib libslib",
    "    copy $(LIBLOUIS_PATH)\\windows\\liblouis.lib libslib",
    "liblouisutdml.dll:  liblouisutdml.def liblouisutdml.lib",
    "    link $(DLLFLAGS) $(LIBXML2_OBJ) $(OBJ) \\",
    "   $(LIBLOUIS_PATH)\\windows\\liblouis.lib \\",
    "    wsock32.lib ws2_32.lib kernel32.lib \\",
    "    /DEF:liblouisutdml.def /OUT:liblouisutdml.dll",
    "liblouisutdml.lib: $(LIBXML2_OBJ) $(OBJ) configure.mk",
    "   lib /nologo $(OBJ) $(LIBXML2_OBJ) /out:liblouisutdml.lib",
    "Jliblouisutdml.obj: $(HEADERS) ..\\java\\Jliblouisutdml.c",
"    $(CC) $(CCFLAGS) /I$(JAVA_HEADERS_PATH) /I$(JAVA_HEADERS_PATH)\\win32 \\",
    "    /I..\\liblouisutdml ..\\java\\Jliblouisutdml.c",
    "# Description blocks for the other object files are generated here.",
    NULL
  };
static char *libxml2Module[] = {
"SAX",
"entities",
"encoding",
"error",
"parserInternals",
"parser",
"tree",
"hash",
"list",
"xmlIO",
"xmlmemory",
"uri",
"valid",
"xlink",
"HTMLparser",
"HTMLtree",
"debugXML",
"xpath",
"xpointer",
"xinclude",
"nanohttp",
"nanoftp",
"DOCBparser",
"catalog",
"globals",
"threads",
"c14n",
"xmlstring",
"xmlregexp",
"xmlschemas",
"xmlschemastypes",
"xmlunicode",
"xmlreader",
"relaxng",
"dict",
"SAX2",
"xmlwriter",
"legacy",
"chvalid",
"pattern",
"xmlsave",
"xmlmodule",
"schematron",
NULL
};

  FILE *makefile_am;
  FILE *configure_ac;
  FILE *Makefile_gen;
  char inbuf[256];
  char version[80];
  char module[50][50];
  int moduleCount = 0;
  char *curchar;
  int ch;
  int ignoreLine = 1;
  char *name;
  int nameLength;
  int k, kk;
  if ((makefile_am = fopen ("..\\liblouisutdml\\Makefile.am", "r")) == NULL)
    {
      fprintf (stderr, "Cannot open Makefile.am.\n");
      exit (1);
    }
  if ((configure_ac = fopen ("..\\configure.ac", "r")) == NULL)
    {
      fprintf (stderr, "Cannot open configure.ac.\n");
      exit (1);
    }
  if ((Makefile_gen = fopen ("Makefile.gen", "w")) == NULL)
    {
      fprintf (stderr, "Cannot open Makefile.gen.\n");
      exit (1);
    }

  // Get module names
  ignoreLine = 1;
  while (fgets (inbuf, sizeof (inbuf), makefile_am))
    {
      curchar = inbuf;
      while ((ch = *curchar++) <= 32 && ch != 0);
      name = curchar - 1;
      while ((ch = *curchar++) > 32 && ch != ',' && ch != '.');
      nameLength = curchar - name - 1;
      name[nameLength] = 0;
      if (strcmp (name, "liblouisutdml_la_SOURCES") == 0)
	{
	  ignoreLine = 0;
	  continue;
	}
      if (ignoreLine)
	continue;
      if (name[nameLength + 1] != 'c')
	continue;
      strcpy (module[moduleCount++], name);
      while ((ch = *curchar++) != 0 && ch != '\\');
      if (ch != '\\')
	break;
    }
  fclose (makefile_am);

  // Get version
  while ((fgets (inbuf, sizeof (inbuf), configure_ac)))
    {
      curchar = inbuf;
      while ((ch = *curchar++) <= 32 && ch != 0);
      name = curchar - 1;
      while ((ch = *curchar++) > 32 && ch != ',' && ch != '(');
      nameLength = curchar - name - 1;
      name[nameLength] = 0;
      if (strcmp (name, "AC_INIT") == 0)
	{
	  strcpy (version, "liblouisutdml-");
	  while (*curchar++ != ',');
	  while (*curchar++ == 32);
	  name = curchar - 1;
	  while ((ch = *curchar++) > 32 && ch != ',');
	  nameLength = curchar - name - 1;
	  name[nameLength] = 0;
	  strcat (version, name);
	  break;
	}
    }
  fclose (configure_ac);

  // Generate Makefile.gen
  for (k = 0; makefileStub[k] != NULL; k++)
    {
      strcpy (inbuf, makefileStub[k]);
      if (strncmp (inbuf, "collect_results", 15) == 0)
	{
  fprintf (Makefile_gen, "OBJ = Jliblouisutdml.obj \\\n");
	  for (kk = 0; kk < moduleCount; kk++)
if (kk != (moduleCount - 1))
	    fprintf (Makefile_gen, "    %s.obj \\\n", module[kk]);
else
	    fprintf (Makefile_gen, "    %s.obj \n", module[kk]);
  fprintf (Makefile_gen, "LIBXML2_OBJ = \\\n");
for (kk = 0; libxml2Module[kk]; kk++)
if (libxml2Module[kk + 1] != NULL)
fprintf (Makefile_gen, "    %s.obj \\\n", libxml2Module[kk]);
else
fprintf (Makefile_gen, "    %s.obj \n", libxml2Module[kk]);
	}
	fprintf (Makefile_gen, "%s\n", makefileStub[k]);
    }

  // Make the libluiusutdml object files.
  for (kk = 0; kk < moduleCount; kk++)
    {
      fprintf (Makefile_gen, "%s.obj: $(HEADERS) $(SRCDIR)\\%s.c\n",
	       module[kk], module[kk]);
    if (strcmp (module[k], "loblouisutdml") == 0)
      fprintf (Makefile_gen, 
"    $(CC) $(CCFLAGS) /DPACKAGE_VERSION=%s $(SRCDIR)\\%s.c\n",
	       version, module[kk]);
    else
      fprintf (Makefile_gen, "    $(CC) $(CCFLAGS) $(SRCDIR)\\%s.c\n",
	       module[kk]);
    }
 // Make the libxml2 object files.
for (kk = 0; libxml2Module[kk]; kk++)
{
fprintf (Makefile_gen, "%s.obj: $(LXHEADERS) $(LXSRCDIR)\\%s.c\n",
libxml2Module[kk], libxml2Module[kk]);
if (strcmp (libxml2Module[kk], "dict") == 0)
  fprintf (Makefile_gen,
"    $(CC) $(LXCCFLAGS) /Duint32_t=\"unsigned int\" $(LXSRCDIR)\\%s.c\n",
libxml2Module[kk]);
else
fprintf (Makefile_gen, 
"    $(CC) $(LXCCFLAGS) $(LXSRCDIR)\\%s.c\n",
libxml2Module[kk]);
}
  fclose (Makefile_gen);
  return 0;
}
