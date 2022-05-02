# Four Color Theorem

### The Idea
In mathematics, the four color theorem, or the four color map theorem, states that, given any separation of a plane into contiguous regions, producing a figure called a map, no more than four colors are required to color the regions of the map so that no two adjacent regions have the same color. Adjacent means that two regions share a common boundary curve segment, not merely a corner where three or more regions meet.

### About
The aim of this project is to colorize the maps (.txt) given as input.

### Compile & Execution

1. Compile
```
$user> cd /src
$user> make
```
2. Execute

``` 
i) Using stdin as input:
    $user> ./mapcol < ./maps/Balkans.txt 

ii) Using file as input (-i)
    $user> ./mapcol -i ./maps/Balkans.txt
    
iii) Validity check (-c)
    $user> ./mapcol -i ./maps/Balkans2.txt -c
    $user> ./mapcol -i ./maps/EuropeColoredTest.txt -c

iv) Filling not entirely colored maps. 
    $user> ./mapcol -i ./maps/BalkansPartlyColored.txt 
    $user> ./mapcol < ./maps/BalkansPartlyColored.txt 

v) Setting colors quantity (-n)
    $user> ./mapcol < ./maps/No4colors.txt -n 5
    $user> ./mapcol -i ./maps/No4colors.txt -n 5
    $user> ./mapcol -i ./maps/Europe25Uncolored.txt -n 5
```

### Approach

- I created a 2D matrix in which for every i,j "neighbour relationship" we find, we set the array element (at this position) to 1.
- I can color maps with up to 200 countries.
</br>

:warning: I'm not sure if everything works fine for a huge number of countries.