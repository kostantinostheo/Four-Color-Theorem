#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colorinInterface.h"
//Konstantinos Theofilis sdi1600287

int ColorIt(int countryPos,  char **AdjTable, int color[], int c, int fileLines) 
{ 
    int i;
    for (i = 0; i < fileLines; i++)
        if (AdjTable[countryPos][i] && c == color[i]) 
            return 0; 
    return 1; 
}
/* 
    Elegxei an to xrwma apo ton pinaka xrwmatwn poy ftiaksame borei na xrisimopoithi ston sigkekrimeno vertex.
    Elegxei an iparxei i xwra kai istera an to xrwma pou paei na xrisimopoihsh xrisimopoieite idi apo gitoniko komvo.
*/


int paintGraph( char **graph, int fileLines, int m, int color[], int v) 
{ 

    if (v == fileLines) //xromatismenos idi.
        return 1; 
    
    int i;
    int isprecolored = color[v] > 0;    //an itan idi vameno kapoio, min to peiraxeis
    
    for (i = 0; i < m; i++) //dokimase ola ta xrwmata apo ton pinaka xrwmatwn apo 0 -> m mexri kapoi na teriazei.
    { 
        
        if (ColorIt(v, graph, color, i, fileLines)) 
        { 
            if(!isprecolored)//an einai vameno pame sto epomeno.
                color[v] = i; 

            if (paintGraph(graph, fileLines, m, color, v+1) == 1) //andromika gia kathe xwra kane to idio.
                return 1; 

            if(!isprecolored)//an einai apo prin vameno min vgalis to xrwma.
                color[v] = 0; 
        } 
    } 
  
    return 0; 
}