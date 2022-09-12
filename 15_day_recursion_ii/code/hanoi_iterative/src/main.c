#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "stackd.h"

void hanoi_iterative(int num_of_disks, Node *source, Node *auxiliary, Node *destination);
void moveDisksBetweenTwoPoles(Node **source, Node **destination, char s, char d);
void moveDisk(char from, char to, int disk);

int main(){
    
    unsigned num_of_disks = 5;
    Node *source, *destination, *auxiliary;

    source = createStack();
    destination = createStack();
    auxiliary = createStack();

    hanoi_iterative(num_of_disks, source, auxiliary, destination);

    destroyStack(source);
    destroyStack(destination);
    destroyStack(auxiliary);

    return 0;
}

void hanoi_iterative(int num_of_disks, Node *source, Node *auxiliary, Node *destination){
    int total_num_of_moves;
    char s = 's', d = 'd', a = 'a';

    if(num_of_disks % 2 == 0){
        char temp = d;
        d = a;
        a= temp;
    }

    total_num_of_moves = pow(2, num_of_disks) - 1;

    //Inicializar la torre origen
    for (int i = num_of_disks; i >= 1; i--){
        push(&source, i);
    }

    for (int i = 1; i <= total_num_of_moves; i++){
        if( i % 3 == 1)
            moveDisksBetweenTwoPoles(&source, &destination, s, d);
        else 
            if( i % 3 == 2)
                moveDisksBetweenTwoPoles(&source, &auxiliary, s, a);
            else
                if( i % 3 == 0)
                    moveDisksBetweenTwoPoles(&auxiliary, &destination, a, d);
    }
}

void moveDisksBetweenTwoPoles(Node **source, Node **destination, char s, char d){
    int pole1TopDisk = pop(source);
    int pole2TopDisk = pop(destination);

    // Cuando la torre 1 esta vacia
    if(pole1TopDisk == INT_MIN){
        push(source, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    } else {
        if (pole2TopDisk == INT_MIN){
            push(destination, pole1TopDisk);
            moveDisk(s, d, pole1TopDisk); 
        } else {
            if( pole1TopDisk > pole2TopDisk){
                push(source, pole1TopDisk);
                push(source, pole2TopDisk);
                moveDisk(d, s, pole2TopDisk);
            } else {
                // pole2TopDisk > pole1TopDisk
                push(destination, pole2TopDisk);
                push(destination, pole1TopDisk);
                moveDisk(s, d, pole1TopDisk);
            }
        }
    }
}

void moveDisk(char from, char to, int disk){
    printf("Move the disk %d from %c to %c \n", disk, from, to);
}