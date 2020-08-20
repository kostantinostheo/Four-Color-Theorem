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

        // if(argc==2 && strcmp(argv[i],"-i")==0 || strcmp(argv[i],"-c")==0 || strcmp(argv[i],"-n")==0)
        // {
        //     perror("Error. Too few arguments. Code 2");
        //     exit(0);
        // }

    }



    //edw girna to megethos toy arxiou se enan int. Parakatw tha ftiaksw ton pinaka gitniasis oso to megethos auto "fileLines X fileLines"
    fileLines=countFileLines(fp);


    /*
    Desmeusi mnimis gia pinaka gitniasis.
    I logiki einai pws gia kathe gitoniki sxesi metaksi i kai j vazoume 1 alliws 0
    */
    AdjTable=malloc(fileLines*sizeof(char*));
    for (i = 0; i < fileLines; i++)
    {
        AdjTable[i]=malloc(fileLines*sizeof(char));
        for (j = 0; j < fileLines; j++)
        {
            AdjTable[i][j]=0;           
        }
    }

    /*
    Desmeusi mnimis gia pinaka xrwmatwn.
    */

    color = malloc (fileLines*sizeof(int));
    for (i = 0; i < fileLines; i++) 
    {
        color[i] = -1;       // init sto -1 
    }



    /*
    Desmeusi mnimis gia pinaka xwrwn.
    Apo to arxeio paei kai pernei tis xwres. 2h stili arxeiou.
    */
    countriesArray=getCountries(fp,fileLines);
    
    if(flag==0) //
    {
        //printf("--1\n");

        fillAdjancyTable(AdjTable,countriesArray,fp,fileLines, color);
        
        //printf("--2\n");

        if (paintGraph(AdjTable, fileLines, colornum, color, 0) == 0) 
        { 
            printf("Sorry, cannot color the given map. Exit from flag code: 0\n");  
        } 
        else
        {
            for (i = 0; i < fileLines; i++)
            {
                printf("%s %s ", colorrPinakas[color[i]],countriesArray[i]);
                for (j = 0; j < fileLines; j++)
                {
                    if(AdjTable[i][j]==1)
                        printf("%s " , countriesArray[j]);   
                }puts("");
            }
            
        }

    }
    else
    {   //Elegxos Egkirotitas xrwmatismou xarti.
        if(fillAdjancyTableforAlreadyColoredMaps(AdjTable,countriesArray,color,fp,fileLines)==-1)
        {
            printf("Sorry, cannot color the given map. Exit from flag code: 1\n");
        }
        else
        {
            printf("4 or more colors used\n");  
        }
    }


    return 0;

}

