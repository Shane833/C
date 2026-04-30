# Now as I read that make will apply the recipe on the pre-requisites
# so lets give it a try

# However, if there is no recipe then make will simply recompile the files in the pre-requisite
# if the files do not exist or if some change has been made to these files

all: main.c main.o

# Since main.o file do not exist, hence it will compile it
# however once compiled, if you try to re run make, it will simply display the message:
# make: Nothing to be done for 'all'

# IMPORTANT:

# It is not necessary to spell out the recipes for compiling the individual C source files,
# because make can figure them out: it has an implicit rule for updating a ‘.o’ file from
# a correspondingly named ‘.c’ file using a ‘cc -c’ command. For example, it will use the
# recipe ‘cc -c main.c -o main.o’ to compile main.c into main.o. We can therefore omit the
# recipes from the rules for the object files.

# When a ‘.c’ file is used automatically in this way, it is also automatically added to the
# list of prerequisites. We can therefore omit the ‘.c’ files from the prerequisites, provided
# we omit the recipe. i.e

# we can just write 'all : main.o' and it will compile main from its corresponding *.c file
