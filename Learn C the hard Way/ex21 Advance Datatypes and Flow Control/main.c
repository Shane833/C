#include <stdio.h>
#include <stdint.h>

int main(int argc,char *argv[])
{
	// Available Datatypes in C
	/**
	-> int - stores a regular integer defaulting 32-bits in size
	-> double - holds a large floating point number
	-> float - holds a smaller floating point number
	-> char - holds a single 1-byte character
	-> void - Indicates "no type" and is used to say that a function return nothing or the pointer has not type as in void *thing
	-> enum - Enumerated Types, which works as are and gets converted to integers but give you symbolic names for the elements in the set
			  Some compilers will warn you if you don't cover all the elements of an enum in a switch
	*/

	// Type Modifiers in C
	// These are special keywords which are added in the prefix of the available datatypes to alter their default behaviour
	/**
	-> unsigned - This modifier changes the attributes such that there are no negative values hence giving you a larger upper bound
				  but you cannot have anything less than 0
	-> signed - This modifier allows you to have both positive and negative values but dividing your upper bound into half for that same lower bound
	-> long - This modifier uses a larger storage for the given type so that it can store more values usually doubling its capacity
	*/

	// Type Qualifiers in C
	// These are special keyword that alter the behaviour of a datatype
	/**
	-> const - Indicates that the variable won't change after being initialized
	-> volatile - Indicates that all the bets are off and the compiler should just leave it alone and shouln't try to do any fancy optimization to it
				  You only need this if you're doing really weird stuff to your variables
	-> register - forces the compiler to keep that variable in a register. However, compiler can simply ignore you as these days compilers are smart enough
				  to know where to put things. So be careful while using this and only use it if you can see any performance gain
	*/

	// Type Conversion in C
	// While performing an operation C will look at either of the operands and will promote the smaller side to match the larger side
	// The order of promotion of types is in the following way : long double -> double -> float -> int (but only char and short int) -> long
	// If you can't figure out how type conversions are working then explicitely type cast them for you. For eg : say x = 2 and y = 3.14f, then typecast as such y + (float)x
	// Just put whatever you want to type cast it to in the parenthesis and it will be type casted for you
	// However, remember a general rule of thumb that you should always try to typecast up not down like don't cast long into chars unless you know what you are doing
	
	// TYPE SIZES IN C
	// The stdint.h library defines certain macros that are platform independent in terms of their sizes as they are exact sized integers as well as a set of macros for the sizes of all the types
	// The types defined in the header file are :
	/**
	-> int8_t - 8-bit signed integer
	-> uint8_t - 8-bit unsigned integer
	-> int16_t - 16-bit signed integer
	-> uint16_t - 16-bit unsigned integer
	-> int32_t - 32-bit unsigned integer
	-> uint32_t - 32-bit unsigned integer
	-> int64_t - 64-bit signed integer
	-> uint64_t - 64-bit unsigned integer
	*/

	// So you may observe a pattern here in the form (u)int(BITS)_t where 'u' means unsigned and BITS determine the number of bits like 8,16,32 etc
	// The same pattern is repeated for macros defining the sizes:
	// ->INT(N)_MAX provides maximum value of the signed integer with N bits
	// -> INT(N)_MIN provides minimum value of the signed integer with N bits
	// -> UNIT(N)_MAX provides maximum value of an unsigned integer of N bits since the minimum for all unsigned integers will always be 0

}