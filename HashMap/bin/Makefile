# /*
# Name: Safwan Hossain
# Student ID: 0918742
# Email: safwan@uoguelph.ca
CC          =	gcc
# Flags that are sent to the compiler  change the std if you wish

CFLAGS      =	-Wall -std=c99 -pedantic -g



#add a target to build a different program with the same library
make: ../src/main.c ../src/funcPointers.c ../src/main.c ../src/hashMap.c
	$(CC) $(CFLAGS) ../src/main.c ../src/hashMap.c ../src/funcPointers.c -I../include -o a

# note that cpp check reports memory leaks on these files that wouldn't really be leaks when the program was run
# don't blindly believe everything it tells you- check to make sure it is correct.  Usually it is
# but not always.   
#run cppcheck
cppcheck:
	 cppcheck --enable=all --language=c --std=c99 --inconclusive --suppress=missingInclude ../src/*.c -i ./include
