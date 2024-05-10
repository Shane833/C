// Heap vs. Stack
// For now consider that whenever you use malloc you are using the heap and anywhere else it would be stack
// Now one of the advantages of using the heap is when you are passing structures in the function calls
// If you are passing the complete member of the structure it can easily take over the function call stack and will
// take more space in memory, and would have to be copied onto the stack. So now we are beginning to come to call by
// value vs. call by reference
// So here we are using the stack to store the actual value and the heap to share around the structures among the functions

// Using the Heap:
// In the function Database_open, we making a structure using malloc which will be from the heap
// Similary in the struct we again have a pointer to the struct database which we are allocating memory using malloc

// Function Stack
// Whenever you create local variables (includes parameterized) in a function they are stored in the function stack for the entirity
// of the execution of that function and automatically that memory gets freed once the execution ends
/** Note : Don't use memcpy() function to copy one struct to another,if they are variables of the same struct just directly assign them to each other using '=' **/

// EXTRA CREDIT PROGRAMS HERE

#include <stdio.h> // defines functions for handling standard input output data streams
#include <assert.h> // defines a macro which helps in debugging as it checks for a condition and terminates the program with an error message in case the condition is false
#include <errno.h> // defines a macro for reporting and retrieving error condtions, by providing an integer error no. which gets its value from system calls
#include <stdlib.h> // defines functions for dynamic memory allocation
#include <string.h> // defines functions for handling strings

#define MAX_DATA 512 // A constant defining the maximum amount of data to be stored
#define MAX_ROWS 100 // A constant for defining the maximum number of addresses to be stored

struct Address // This is a struct (a complex data structure) which will hold various values regarding the details of a person
{
	int ID; // This variable helps to provide each person a specific ID
	int set; // This variable helps in identifying whether the values for a given ID are set or not
	char name[MAX_DATA]; // An array called name that can store upto 512 characters
	char email[MAX_DATA];// An array called email that can also store upto 512 characters
	
};

struct Database // This is a struct which will store an array of 100 (MAX_ROWS) struct Address variables
{
	struct Address rows[MAX_ROWS]; 
};

struct Connection // As the name suggests this struct will be useful in making a connection with the locally stored database file and read and write its values
{
	FILE *file; // This is a file pointer which will help us traverse the database file
	struct Database *db; // This is a pointer to the struct Database which will help in writing and loading values from the locally stored database file
};

// Forward Declaration
void die(const char *message);
void printAddress(struct Address *addr);
struct Connection *createDatabase(const char *filename,char mode);
void loadDatabase(struct Connection *conn);
void closeDatabase(struct Connection *conn);
void writeDatabase(struct Connection *conn);
void initializeDatabase(struct Connection *conn);
void setData(struct Connection *conn,int id,const char *name,const char *email);
void getData(struct Connection *conn,int id);
void removeData(struct Connection *conn,int id);
void listDatabase(struct Connection *conn);


int main(int argc, char *argv[])
{
	if(argc < 3) // Here we are checking the no. of commandline arguments
	{
		// as we atleast need 3 arguments for the executio of the program and failure to do so will result in error
		// The first argument is the destination path of the executible itself
		die("Usage : main <dbfile> <action> [action params]");
	}
	
	// Moving forward, i.e. if the arguments are greater than equal to 3
	const char *filename = argv[1]; // Since the filename is the second parameter, hence it will be stored at index '1' of the argument arrays
	const char action = argv[2][0]; // Again since the action is provided as the third paramter, also since we storing a single char we only require the character at the 0th index
	struct Connection *conn = createDatabase(filename,action); // creating our database

	int id = 0; // We will use this variable to store the ID of the address to be operated upon, initially we will set it to 0
	
	if(argc > 3) // Now if we get more than 3 argument, then as per the program the 4th argument will always be the ID
	{
		id = atoi(argv[3]); // Setting it equal to the item at 3rd index
							// atoi() is a function  that converst the string part into integer upto the null character
	
	}

	// Error checking for the value of the ID, as it shouldn't be equal to exceed the max amount of rows in the array
	if(id >= MAX_ROWS)
	{
		die("There are not that many records");
	}

	// Now after all the initialization we will move onto handling the action
	// So we will simply start a switch based on the type of action
	
	switch(action)
	{
		// Creating the database
		case 'c':
			// Since we have already created an instance of the connection we will simply initialize the values and write them into a file
			initializeDatabase(conn);
			writeDatabase(conn);
			break;
		// Getting data from the database
		case 'g':
			if(argc != 4) // Here we are explicitely checking if the no. of commandline arguments are 4 ('main','database file','action','id')
						  // anything other then will be considered invalid
			{
				die("Need an ID to get");
			}
			getData(conn,id); // If the user have indeed provided the right amounts of arguments then display the data
			break;
		// Setting data into the database
		case 's':
			if(argc != 6) // Explicitely checking for the required no. of arguments
			{
				// terminating the program else wise
				die("Need ID, Name, Email to set");
			}
			// Else we will set the data into database and then write the changes to the file
			setData(conn,id,argv[4],argv[5]); // as the name is the 5th argument and the email is the 6th
			writeDatabase(conn);
			break;
		// Deleting data from the database
		case 'd':
			if(argc != 4) // Explicitely checking for the required no. of arguments
			{
				die("Need ID to delete"); // terminating program other wise
			}
			removeData(conn,id); // Deleting the address at the given ID
			writeDatabase(conn); // Writing those changes to the file
			break;
		// Listing all the available addresses in the database
		case 'l':
			if(argc != 4) // // Explicitely checking for the required no. of arguments
			{
				listDatabase(conn); // Listing the data from the database
			}
			break;
		
		default: // This case will get executed when an unknonwn action type is provided
			die("Invalid action : c = create, g = get, s = set, d = del, l = list");
	}

	// Finally doing some clean up work and deallocating memory from the variables
	closeDatabase(conn);

	
}

// Custom function to terminate the program with an error message
void die(const char *message)
{
	if(errno) // First we check the value of the pre defined variable errno, if its value is anything other than 0 (it mostly likely be -1 as defined in the man page) we know an error has occured
	{
		perror(message); // This function prints the value of the string provided in the arguments to the stderr stream desribing the last error occured during the function call
						 // then an error message corresponding to the current value of errno and a new-line.
	}
	else // However if we explicitely want to terminate the program despite of any system error
	{
		fprintf(stderr,"%s\n",message); // Then we can simply print the provided error message to the stderr stream
	}
	exit(1); // In the end we will exit the program with an exit code of 1, signifying failed execution
}

// Printing the values in struct Address
void printAddress(struct Address *addr) // This function will print the data member of the address variable
{
	printf("%d %s %s\n",addr->ID,addr->name,addr->email);
}

// Creating a Database
struct Connection *createDatabase(const char* filename,char mode) // This function will return a pointer to a dynamically allocated and new created variable of struct Database
{
	struct Connection *conn = malloc(sizeof(struct Connection)); // Dynamically allocting memory
	if(!conn) // Here we are checking if the memory was correctly allocated or not
	// As if the memory was correctly allocated the conn pointer will be pointing to a memory address, and using '!' on that memory address will give a 0
	// i.e. !(any_correctly_allocated_pointer) = 0, and if its zero the if block will not be executed
	// However if the memory was not allocated the pointer will not be pointing to any memory address  and will have the value NULL(if you print it, it'll either say nil or 0)
	// so now !(NULL or you can say its 0) = 1, so in this case the if block will run
	{
		
		die("Memory Error!!!");
	}
	
	conn->db = malloc(sizeof(struct Database)); // Now here we are allocating memory to the pointer to the database struct
	// Since pointer members are not allocated memory when the whole struct is allocated, you have to separately allocated memory to them
	if(!conn->db) // Again checking for correct memory allocation
	{
		die("Memory Error!!!");
	}

	if(mode == 'c') // if the mode is c that means we must create a file
	{
		conn->file = fopen(filename,"w"); // You can create a file with fopen function, which takes two parameters : 1. Filename 2. accessing mode (w : for writing, r : for reading,w+/r+ : both read and write)
		// It will create a new file if the specified file does not exists or will simply overwrite if it does exists
	}
	else // This block will get executed in case you want to open the database in any other mode other than 'c'
	{
		conn->file = fopen(filename,"r+"); // Now as we are not creating the file which means it probably exists and we can simply open it in read/write mode, however even if the file doesn't exits it will create one
			
		if(conn->file) // checking if the file is actually holds some value (i.e. is it valid)
		{
			// If it is indeed valid we will simply load the database from that file
			loadDatabase(conn);
		}
	}

	if(!conn->file) // Again checking if the file pointer is valid
	{
		// and in case its not we will abort the program
		die("Failed to open the File !!!");
	}
	
	return conn; // Finally we will return this newly created struct variable
}

// Initializing our Database
void initializeDatabase(struct Connection *conn)
{
	// we will initialize all the value to 0
	// We will create a local variable of the struct address and initialize its data members to be 0
	// and simply assign its value to each of the address variables stored in the array rows
	
	for(int i = 0;i < MAX_ROWS;i++) 
	{
		struct Address addr = {.ID = 0,.set = 0};
		// here we are using designated initializer (.) which can help to initialize the variables by name
		// so its clear which variables are being initialized
		conn->db->rows[i] = addr; // here we are simply assigning the value of this struct to the other of the same type
	}
}

// Setting the data in the database
void setData(struct Connection *conn,int id,const char *name,const char *email)
{
	// First we will create a pointer to the address variable whose value we are to set
	struct Address *addr = &conn->db->rows[id];
	
	if(addr->set) // Now we will check if the value is already set
	{
		// If the value is already set we might not want to overwrite it so we can simply terminate the program
		die("Already set, delete it first");
	}
	
	// If its not set then we will set it
	addr->set = 1;
	// Also updating its ID
	addr->ID = id;

	// Now we will set the name using strncpy function
	// Function Definition : strncpy(char *dest,const char *src,size_t n)
	// we provide a maximum length of characters for the destination as to save it from overflow
	// However if the source it less than the specified size then additional null character are copied onto the destination
	// It returns the address of the destination string, so it its null means something is wrong
	char *res = strncpy(addr->name,name,MAX_DATA); // setting the name
	
	if(!res) // Checking for validity of the operation
	{
		die("Name copy failed");
	}
	
	res = strncpy(addr->email,email,MAX_DATA); // setting the email
	
	if(!res)
	{
		die("Email copy failed");
	}
		
}

// Getting the data from the Database
void getData(struct Connection *conn, int id)
{
	// First we will create a pointer to the address variable whose value we are to retrieve
	struct Address *addr = &conn->db->rows[id];

	// Now we will check if the ID provided actually have some data or not
	if(addr->set) // i.e. if the data is set then only will be display the data
	{
		printAddress(addr);
	}
	else // This block means the address was invalid and no data was initially set
	{
		die("Address is not set");
	}
}

void removeData(struct Connection *conn,int id)
{
	// In order to remove the data from the database
	// we will simply overwrite the variable stored at that id in the database
	struct Address addr = {.ID = id,.set = 0}; // defining a temporary variable
	conn->db->rows[id] = addr; // Simply overwriting the address at the given ID
}

// Writing data to the database
void writeDatabase(struct Connection *conn)
{
	// This program works by overwriting the existing database file, so for overwriting the complete, first we move to the top of the file
	rewind(conn->file); // rewind(File *file) function ensure that provided file pointer points to the beginning of the file

	size_t read_count = fwrite(conn->db,sizeof(struct Database),1,conn->file); // Writing the data to the file
	
	if(read_count != 1) // Since we are only writing one instance of the data its value should be 1
	{
		// However if its not 1 meaning some error has occured so we will terminate the program
		die("Failed to write Database");
	}
	
	read_count = fflush(conn->file); // fflush(void *stream) function basically forces to clear any associated buffers with the provided stream, 
									 // since the data is buffered (i.e. stored in an internal memory and then operated upon later for better efficiency)
									 // we can force it immediately write (clear) all the contents of the provided stream
									 // on successful operation, this function will return a 0, and on unsuccessful operation it returns the EOF (end of file, -1) and other error no.
	if(read_count == -1) // Checking for unsuccessful flush
	{
		die("Cannot flush Database"); // we simply terminate the program
	}
}

// Loading the Database
void loadDatabase(struct Connection *conn)
{
	size_t read_count = fread(conn->db,sizeof(struct Database),1,conn->file);
	// The fread and fwrite functions are used for reading an writing binary data, it could be the whole array or struct
	// while the fprintf and fscanf can be used to read text data
	// Here we are reading a whole instance of the struct Database which will be stored in the file
	// both fread and fwrite returns the no. items read/written when eno of file is reached or an error occrus
	// FUNCTION TEMPLATE (fread) : size_t fread(void *ptr,size_t size,size_t nmemb(no. of instances of ptr to be read),FILE *stream)
	// Now as we provide the pointer of the databasae to the fread function, by call of reference all the data will automatically be stored in it	
	// here as we are only reading 1 instance of the database therefore when function completes it should return 1 (meaning read count must be 1)
	
	if(read_count != 1) // Now if the read count is not 1, means we have not succesfully read the file
	{
		die("Failed to load Database"); // Terminating the program with an error message
	}
}

// Listing all the set data fields in the database
void listDatabase(struct Connection *conn)
{
	// We will simple traverse through the whole database and print only those addresses whose values are set

	// 1. making a pointer to the database
	struct Database *db = conn->db;

	// 2. Looping through array of addresses
	for(int i = 0;i < MAX_ROWS;i++)
	{
		// 3. Create a pointer to addresses in the database
		struct Address *addr = &db->rows[i];

		// 4. Checking if the address is already set the print
		if(addr->set)
		{
			printAddress(addr);
		}
	}
}

// Closing out Database
void closeDatabase(struct Connection *conn)
{
	if(conn) // checking if the pointer provided is not NULL i.e. valid
	{
		// If so then first we will first close our file pointer
		fclose(conn->file);
	}
	if(conn->db) // Now checking the same for the database variable
	{
		// If its valid then free its memory
		free(conn->db);
	}
}