#include <stdio.h>

void hanoi_recursive(int n, char source, char destination, char auxiliary);

int main(){
   int n = 5;
   hanoi_recursive(5, 'A', 'C', 'B'); 
}

void hanoi_recursive(int n, char source, char destination, char auxiliary){
    if ( n == 1){
        printf("Mover el disco 1 de  %c a  %c\n", source, destination);
        return;
    } else {
        hanoi_recursive( n - 1, source, auxiliary, destination);
        printf("Mover dico %d de %c a %c\n", n, source, destination);
        hanoi_recursive( n - 1, auxiliary, destination, source);
    }
}