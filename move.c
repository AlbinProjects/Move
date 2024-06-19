
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//
void print_error(char *filename1, char *filename2){
    fprintf(stderr, "Output error: cannot move %s to %s\n%s\n", 
             filename1, filename2, strerror(errno));
    exit(EXIT_FAILURE);
}

//
void print_usage(){
    fprintf(stderr, "SYNTAX ERROR:\nUsage: [old filename] [new filename]\n");
    exit(EXIT_FAILURE);
}



           
           
int main(int argc, char *argv[])
{

#ifdef _WIN32
	//check for windows
        printf("The program is not supported on Windows, please try in Linux\n");
        return 0;
    // Check for Linux
    #elif defined(__linux__)
        printf("The program is running on Linux.\n");

    // Other systems
    #else
        printf("Unidentified OS, please try in Linux\n");
        return 0;
    #endif
    
    
	char ch;

	if(argc != 3){
		print_usage(argv[0]);
	}
	
	
	int status = rename(argv[1], argv[2]);  //
	
	
    if(status == -1)
    {
        print_error(argv[1], argv[2]);
    }
    else if(status == 0)
    {
    fprintf(stderr, "Operation Success..");
    }
    else
    {
    fprintf(stderr, "Undefined error.");
    }
    
    return 0;
}



