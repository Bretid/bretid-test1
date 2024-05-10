#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int num;
    int count;
} NumberCount;
 
int compare(const void* a, const void* b) {
    NumberCount* numCountA = (NumberCount*)a;
    NumberCount* numCountB = (NumberCount*)b;
    return numCountA->num - numCountB->num;
}
 
int main() {
    int n;
    scanf("%d", &n);
 
    int numbers[100];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
 
    qsort(numbers, n, sizeof(int), compare);

    NumberCount counts[100];
    int countIndex = 0;
    int currentNum = numbers[0];
    int currentCount = 1;
 
    for (i = 1; i < n; i++) {
        if (numbers[i] == currentNum) {
            currentCount++;
        } else {
            counts[countIndex].num = currentNum;
            counts[countIndex].count = currentCount;
            countIndex++;
            currentNum = numbers[i];
            currentCount = 1;
        }
    }
 
    counts[countIndex].num = currentNum;
    counts[countIndex].count = currentCount;
    countIndex++;
    int maxCount = 0;
    for (i = 0; i < countIndex; i++) {
        if (counts[i].count > maxCount) {
            maxCount = counts[i].count;
        }
    }
    for (i = 0; i < countIndex; i++) {
        if (counts[i].count == maxCount) {
            printf("%d %d\n", counts[i].num, counts[i].count);
        }
    }
 
    return 0;
}

