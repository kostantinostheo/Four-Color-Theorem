#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colorinInterface.h"

int ColorIt(int countryPos,  char **AdjTable, int color[], int c, int fileLines) 
{ 
    int i;
    for (i = 0; i < fileLines; i++)
        if (AdjTable[countryPos][i] && c == color[i]) 
            return 0; 
    return 1; 
}

int paintGraph( char **graph, int fileLines, int m, int color[], int v) 
{ 

    if (v == fileLines)
        return 1; 
    
    int i;
    int isprecolored = color[v] > 0;
    
    for (i = 0; i < m; i++)
    { 
        
        if (ColorIt(v, graph, color, i, fileLines)) 
        { 
            if(!isprecolored)
                color[v] = i; 

            if (paintGraph(graph, fileLines, m, color, v+1) == 1)
                return 1; 

            if(!isprecolored)
                color[v] = 0; 
        } 
    } 
  
    return 0; 
}