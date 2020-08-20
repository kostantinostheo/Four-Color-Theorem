#ifndef HEADER_FILE_H
#define HEADER_FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Konstantinos Theofilis sdi1600287

static char *colorrPinakas[] = {"red","green","blue","yellow","orange" ,"violet", "cyan", "pink", "brown","grey", 
"purple", "mattel", "navy", "white" , "black", "teal" , "coral", "aqua", "lime", "peach" ,
"red2","green2","blue2","yellow2","orange2" ,"violet2", "cyan2", "pink2", "brown2", "grey2",
"red3","green3","blue3","yellow3","orange3" ,"violet3", "cyan3", "pink3", "brown3", "grey3"};


int countFileLines(FILE *fp);
char **getCountries(FILE *fp, int fileLine);
void fillAdjancyTable( char **AdjTable,  char **countriesArray, FILE *fp, int fileLine, int *colorTable);
void printAdjTable( char **AdjTable, int fileLine);
int fillAdjancyTableforAlreadyColoredMaps( char **AdjTable,  char **countriesArray, int *colorTable ,FILE *fp, int fileLine);

#endif
