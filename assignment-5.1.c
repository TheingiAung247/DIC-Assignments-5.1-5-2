// Created by TheinGiAung on 1/1/2023.
// Jump Search Algorithm

#include "stdio.h"
#include "math.h"

int min(int first, int second) {
    if(second > first) {
        return first;
    } else {
        return second;
    }
}

int jumpSearch(int arr[], int size, int key) {
//    int step =sqrt(size);   // In class
// For Assignment
    int step = (size % 2 == 0) ? size / 2 : size / 2 + 1;
    int previous = 0;
    while(arr[ min(step, size) - 1] <= key) {
        int arrIndex =  min(step, size) - 1;
        if(arr[arrIndex] == key) {
            return arrIndex;
        }
        previous = step;
        step += (size % 2 == 0) ? size / 2 : size / 2 + 1;  // for assignment
//        step += sqrt(size);  // in class
        if(previous >= size) {
            return -1;
        }
    }

    for(int j = previous; j < step; j++) {
        if(arr[j] == key) {
            return j;
        }
    }
        return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 50, 60, 70, 80, 100, 110, 120, 130};
    int size = sizeof(arr) / sizeof(arr[0]);
    int toFind = 110;

    int indexNumber = jumpSearch(arr, size, toFind);
    if(indexNumber != -1) {
        printf("We Found.\n");
        printf("Found at index %d data: %d", indexNumber, arr[indexNumber]);
    } else {
        printf("Not Found.");
    }
    return 0;
}