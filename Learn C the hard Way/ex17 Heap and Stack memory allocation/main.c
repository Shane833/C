#include <stdio.h> // holds functions for standard input output data streams
#include <assert.h> // provides a macro that helps in debugging as it checks for conditions and terminates the program with an error message in case the condition is false
#include <errno.h> // defines a macro for reporting and retrieving error condtions
#include <stdlib.h> // defines functions for dynamic memory allocation
#include <string.h> // defines 

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address // This is a struct which holds the various members related to the address of a person
{
	int id;
	int set;
	char name[MAX_DATA]; // The memory given to this string is constant which is a stack memory and its capacity is a maximum of 512 bytes
	char email[MAX_DATA];// same the name
};

struct Database // This struct hold the collection of various objects of Address
{
	struct Address rows[MAX_ROWS]; // Inside the database we have created an array of objects of the struct Address which can hold 100 Addresses
	// Again this data is constant and cannot be changes dynamically and is stored in stack memory
};

struct Connection
{
	FILE *file;
	struct Database *db;
};

void die(const char *message)
{
	if(errno)
	{
		perror(message);
	}
	else
	{
		printf("ERROR : %s\n",message);
	}

	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n",addr->id,addr->name,addr->email);
}

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db,sizeof(struct Database),1,conn->file);
	
	if(rc != 1)
	{
		die("Failed to load database!!");
	}
}

struct Connection *Database_open(const char *filename,char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn)
	{
		die("Memory Error!!");
	}
	
	conn->db = malloc(sizeof(struct Database));
	if(!conn->db)
	{
		die("Memory Error!!");
	}

	if(mode == 'c')
	{
		conn->file = fopen(filename,"w");
	}
	else
	{
		conn->file = fopen(filename,"r+");
	
		if(conn->file)
		{
			Database_load(conn);
		}
	}

	if(!conn->file)
	{
		die("Failed to open the file!!");
	}
	
	return conn;
}

void Database_close(struct Connection *conn)
{
	if(conn)
	{
		if(conn->file)
		{
			fclose(conn->file);
		}
		if(conn->db)
		{
			free(conn->db);
		}
	}
}

void Database_write(struct Connection *conn)
{
	rewind(conn->file); // This function sets the file pointer to the beginning of the file
	
	int rc = fwrite(conn->db,sizeof(struct Database),1,conn->file);
	
	if(rc != 1)
	{
		die("Failed to write database");
	}
	
	rc = fflush(conn->file);
	if(rc == -1)
	{
		die("Cannot flush database");
	}
}

void Database_create(struct Connection *conn)
{
	int i = 0;
	
	for(i = 0;i < MAX_ROWS;i++)
	{
		// Making a prototype to initialize our addresses
		struct Address addr = {.id = i,.set = 0};
		// Then just assign this value
		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn,int id,const char *name,const char *email)
{
	struct Address *addr = &conn->db->rows[id];

	if(addr->set)
	{
		die("Already set, delete it first");
	}
	
	addr->set = 1;
	
	char *res = strncpy(addr->name,name,MAX_DATA);

	if(!res)
	{
		die("Name copy failed");
	}
	
	res = strncpy(addr->email,email,MAX_DATA);
	
	if(!res)
	{
		die("Email copy failed");
	}
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];
	
	if(addr->set)
	{
		Address_print(addr);
	}
	else
	{
		die("Address is not set");
	}
}

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id,.set = 0};
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn->db;

	for(i = 0;i < MAX_ROWS;i++)
	{
		struct Address *cur = &db->rows[i];

		if(cur->set)
		{
			Address_print(cur);
		}
	}
}

int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		die("Usage : main <dbfile> <action> [action params]");
	}
	
	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename,action);

	int id = 0;
	
	if(argc > 3) id = atoi(argv[3]); // atoi is a function that converts the string into numbers
	if(id >= MAX_ROWS) die("There are not that many records");

	switch(action)
	{
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;
		
		case 'g':
			if(argc != 4)
			{
				die("Need an ID to get");
			}
			Database_get(conn,id);
			break;
		
		case 's':
			if(argc != 6)
			{
				die("Need id, name, email to set");
			}
			Database_set(conn,id,argv[4],argv[5]);
			Database_write(conn);
			break;
		
		case 'd':
			if(argc != 4)
			{
				die("Need id to delete");
			}
			Database_delete(conn,id);
			Database_write(conn);
			break;
		
		case 'l':
			Database_list(conn);
			break;
		
		default:
			die("Invalid action : c = create, g = get, s = set, d = del, l = list");
	}
	
	Database_close(conn);
}