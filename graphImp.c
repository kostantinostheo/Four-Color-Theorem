#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grapgInter.h"
//Konstantinos Theofilis sdi1600287

/*
Metra tis grammes tou arxiou. O arithmoston gramwn xrisimopoieite istera stin dimiourgia 
2D pinaka gitniasis.
*/
int countFileLines(FILE *fp)
{
    int countFileLines=0;
    char c;

    if (fp == NULL) 
    { 
        printf("Could not open file"); 
        return 0; 
    } 
  
    for (c = getc(fp); c != EOF; c = getc(fp)) 
        if (c == '\n')
            countFileLines = countFileLines + 1; 

    rewind(fp);
    return countFileLines;
    
}

/*
Apo to arxeio paei kai pernei tis xwres. 2h stili arxeiou.
*/
 char **getCountries(FILE *fp, int fileLine)
{
    char BUFF[32];
    int i;
    char c;
    char **countryname;

    countryname=malloc(fileLine*sizeof(char*));
    //printf("Memory allocated\n");

    for (i = 0; i < fileLine; i++)
    {
        fscanf(fp,"%s",BUFF);
        fscanf(fp,"%s",BUFF);
       
        countryname[i]=malloc(strlen(BUFF)+1);
        strcpy(countryname[i], BUFF);
        do  //pare mono tis xwres. Ta alla parelipse ta.
        {
            c=getc(fp); 
        }while (c != EOF && c != '\n');
        
    }

    rewind(fp); //pointer ksana stin arxi tou arxiou.
    return countryname;
    
}
    
int findCountryPos(char **countriesArray, char *n_name, int fileLines)
{
    int i;
    for (i = 0; i < fileLines; i++)
    {
        if(strcmp(countriesArray[i],n_name)==0)
            return i;
    }
    return -1;

/*
Epistrefi tin thesi tis xwras apo ton pinaka. Metra katheta apo 0 ews 'fileLines'
*/

}

int returnPositionfromColor(char *color)
{
    int i;

    for (i = 0; i < sizeof(colorrPinakas)/sizeof(char*); i++)
    {
        if (strcmp(color,colorrPinakas[i])==0)
            return i;
    }
    return -1;
/*

*/
}


void fillAdjancyTable( char **AdjTable,  char **countriesArray, FILE *fp, int fileLine, int *colorTable )
{
    char BUFF[256];
    int i,j; 
    char *split_name;
    int posColor;
 
 //puts("fillAdj1");

    for (i = 0; i < fileLine; i++)
    {
        fscanf(fp,"%s",BUFF);
            
        posColor=returnPositionfromColor(BUFF);
        colorTable[i]=posColor;
    
        fscanf(fp,"%s",BUFF);
        fgets(BUFF,256,fp);

        split_name = strtok(BUFF," \n");

        while(split_name!=NULL)
        {
       
            
            if (findCountryPos(countriesArray,split_name,fileLine)!=-1)
                j=findCountryPos(countriesArray,split_name,fileLine);
        
            //printf("%s ",split_name);
            AdjTable[i][j]=1;
            AdjTable[j][i]=1;

            split_name = strtok(NULL," \n");
            //puts("A");
        }
        
    }

}



int fillAdjancyTableforAlreadyColoredMaps( char **AdjTable,  char **countriesArray, int *colorTable ,FILE *fp, int fileLine)
{
    char BUFF[256];
    int i,j; 
    char * split_name;
    int posColor;

    for (i = 0; i < fileLine; i++)
    {
        fscanf(fp,"%s",BUFF);
        

        posColor=returnPositionfromColor(BUFF);
        colorTable[i]=posColor;
        
        

        fscanf(fp,"%s",BUFF);
        fgets(BUFF,256,fp);

        split_name = strtok(BUFF," \n");

        while(split_name!=NULL)
        {
          
            if(findCountryPos(countriesArray,split_name,fileLine)!=-1)
                j=findCountryPos(countriesArray,split_name,fileLine);

            AdjTable[i][j]=1;
            AdjTable[j][i]=1;

            split_name = strtok(NULL," \n");
            
        }

    }
    int k;
    for (i = 0; i < fileLine; i++)
    {
        for (k = 0; k < fileLine; k++)
        {
           if(AdjTable[i][k]==1 && colorTable[i]==colorTable[k]) //An dio xwres pou gitonevoun exoun idio xrwma tote fail. 
                return -1;
        } 
    }
    return 0;   

}



void printAdjTable( char **AdjTable, int fileLine)
{
    int i,j;

    for (i = 0; i < fileLine; i++)
    {
        for (j = 0; j < fileLine; j++)
        {
            printf("%d " , AdjTable[i][j]);
        }
        puts("");      
    }
    
}


