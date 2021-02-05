
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){



    if(argc != 3){ //Checks to make sure the correct number of arguments have been entered
        printf("You must enter 2 files, you have entered %d files\n",argc-1);
    }else{
        

        FILE *inFile=fopen(argv[1],"r"); //Create file pointers for the in and out files
        FILE *outFile=fopen(argv[2],"w");

        if(inFile==NULL){
            printf("%s is not a valid input file\n",argv[1]);
            return 0;
        }// Checks and makes sure the files exist
        if(outFile==NULL){
            printf("%s is not a valid input file\n",argv[2]);
            return 0;
        }
        
        int letCount=0;
        
        while(1){
            char let=fgetc(inFile); //takes letter from input files

            if(feof(inFile)){ //checks for end of file
                break;
            }
            letCount++; 
            fputc(let,outFile); //writes to out files

        }
        fclose(inFile); //closes both of the files
        fclose(outFile);

        printf("The files were copied successfully with a total of %d characters being copied over\n",letCount);
    }

   
    return 0;
}
