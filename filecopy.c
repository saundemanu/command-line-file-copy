#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//You may also add more include directives as well.
#include <string.h>
// THIS VALUE CANNOT BE CHANGED.
// You should use this value when creating your buffer.
// And also to limit the amount of bytes each read CAN do.
#define BUFF_MAX 21
// ABOVE VALUE CANNOT BE CHANGED //

#define FNAME_MAX 64
#define DEBUG 0

int
main(int argc, char const *argv[])
{
    char ifilename[FNAME_MAX];
    char ofilename[FNAME_MAX];
    char buf[BUFF_MAX];
    int sizeOrig = 0, sizeCop = 0; 
    int fin, fout;
    ssize_t dataRead = 0;
    ssize_t dataWritten = 0; 
    size_t fsize = 0;  

// getting the name of the files
    printf("Welcome to File Copy Program by Emanuel!\n");
    printf("Enter the name of the file to copy from:\n");
    fgets(ifilename, FNAME_MAX, stdin);
    printf("Enter the name of the file to copy to:\n");
    fgets(ofilename, FNAME_MAX, stdin);

    ifilename[strcspn(ifilename, "\n")] = 0;
    ofilename[strcspn(ofilename, "\n")] = 0;  

// setting file descriptors/opening files
    
     fin = open(ifilename, O_RDONLY, O_TRUNC);
    // check if input file exists
     if(fin < 0){
         perror("Error");
         return -1; 
     }
     fout = open(ofilename, O_CREAT | O_WRONLY, 0777);


// data transfer 
  
    while((dataRead = read(fin, buf, BUFF_MAX)) > 0){
        //prints out buffer for debuging
        if(DEBUG == 1){printf("%s", buf);}
    if((dataWritten = write(fout, buf, dataRead)) != dataRead){
       fsize+= 21 - dataWritten;
        break;
    }
    fsize+=21; 
    }
//close files, deallocate descriptors, record
    close(fin);
    close(fout);

    printf("Filecopy Successful, %zi bytes copied \n", fsize); 

    return 0;
}