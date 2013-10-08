/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmUnsetCommand_h
#define cmUnsetCommand_h

#include "cmCommand.h"

/** \class cmUnsetCommand
 * \brief Unset a CMAKE variable
 *
 * cmUnsetCommand unsets or removes a variable.
 */
class cmUnsetCommand : public cmCommand
{
public:
  /**
   * This is a virtual constructor for the command.
   */
  virtual cmCommand* Clone()
    {
    return new cmUnsetCommand;
    }

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  virtual bool InitialPass(std::vector<std::string> const& args,
                           cmExecutionStatus &status);

  /**
   * This determines if the command is invoked when in script mode.
   */
  virtual bool IsScriptable() const { return true; }

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  virtual const char* GetName() const {return "unset";}

  /**
   * Succinct documentation.
   */
  virtual const char* GetTerseDocumentation() const
    {
    return "Unset a variable, cache variable, or environment variable.";
    }

  /**
   * More documentation.
   */
  virtual const char* GetFullDocumentation() const
    {
    return
      "  unset(<variable> [CACHE | PARENT_SCOPE])\n"
      "Removes the specified variable causing it to become undefined.  "
      "If CACHE is present then the variable is removed from the cache "
      "instead of the current scope.\n"
      "If PARENT_SCOPE is present then the variable is removed from the "
      "scope above the current scope.  See the same option in the set() "
      "command for further details.\n"
      "<variable> can be an environment variable such as:\n"
      "  unset(ENV{LD_LIBRARY_PATH})\n"
      "in which case the variable will be removed from the current "
      "environment.";
    }

  cmTypeMacro(cmUnsetCommand, cmCommand);
};



#endif
