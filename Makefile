# Makefiles define rules for making files from other files.
# Rules have the a common form.
#    target:   dependency list
#        command to make target
# Note that the command is only run if the target is older than
# its dependencies.  For example, if a binary is older than the sources
# it is made from, it needs to be recompiled.

# Tabs are important in makefiles.
# There must be a tab or space(s) after the ":".
# There must be a tab before each command.

# Set up to use googletest
GTEST_ROOT = ../googletest/googletest
GTEST_MAIN = $(GTEST_ROOT)/make/gtest_main.a
CPPFLAGS = -I $(GTEST_ROOT)/include

# Use C++ 2011.  Compile for debugging (-g) with warnings.
CXXFLAGS = -std=c++11 -g -Wall -Wextra


# This rule makes the binary program from .o files.
# (.o files are made from .cc files using a rule further down.)
# The command uses some special variables:
#   $@  -- the name of the target
#   $^  -- the names of all dependencies (the .o files listed after ":")

list_test:	list_test.o list.o $(GTEST_MAIN)
	g++ -o $@ $^

# These rules just give additional dependencies.
# They don't have a command, because there are default commands to
# compile .cc to .o.  (They use the flag variables defined above.)

list.o:		list.h
list_test.o:	list.h
