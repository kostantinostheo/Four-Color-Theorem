#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grapgInter.h"
#include "colorinInterface.h"
//Konstantinos Theofilis sdi1600287

int main(int argc, char *argv[])
{

    FILE *fp;
    fp=stdin;
    int i,j;
    char **AdjTable;
    int n,fileLines;
    char **countriesArray;
    int colornum=4;
    int flag=0;
    int *color;


    // Input check
    for(i=0; i<argc; i++)
    {
        if(argc>2 && strcmp(argv[i],"-i")==0)
        {
            fp=fopen(argv[i+1],"r");
        }
        else if(argc>2 && strcmp(argv[i],"-n")==0)
        {
            colornum=atoi(argv[i+1]);
        }
        else if(argc>2 && strcmp(argv[i],"-c")==0)
        {
            flag=1;    
        }
    }

    //Return file lines
    fileLines=countFileLines(fp);
    AdjTable=malloc(fileLines*sizeof(char*));
    
    for (i = 0; i < fileLines; i++)
    {
        AdjTable[i]=malloc(fileLines*sizeof(char));
        for (j = 0; j < fileLines; j++)
            AdjTable[i][j]=0;           
    }

    /*
    Allocate memory for the color table.
    */
    color = malloc (fileLines*sizeof(int));
    for (i = 0; i < fileLines; i++) 
        color[i] = -1;


    /*
    From file, get the second column.
    */
    countriesArray=getCountries(fp,fileLines);
    
    if(flag==0)
    {
        fillAdjancyTable(AdjTable,countriesArray,fp,fileLines, color);
        if (paintGraph(AdjTable, fileLines, colornum, color, 0) == 0) 
            printf("Sorry, cannot color the given map. Exit from flag code: 0\n");  
        else
        {
            for (i = 0; i < fileLines; i++)
            {
                printf("%s %s ", colorrPinakas[color[i]],countriesArray[i]);
                for (j = 0; j < fileLines; j++)
                {
                    if(AdjTable[i][j]==1)
                        printf("%s " , countriesArray[j]);   
                }
                puts("");
            }   
        }
    }
    else
    {   //Check if map can be colored
        if(fillAdjancyTableforAlreadyColoredMaps(AdjTable,countriesArray,color,fp,fileLines)==-1)
            printf("Sorry, cannot color the given map. Exit from flag code: 1\n");
        else
            printf("4 or more colors used\n");
    }
    return 0;
}

