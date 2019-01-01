/*
 Jarren Briscoe
 C program to mimic disk search algorithms
 Includes First Come First Served (FCFS), Shortest Seek Time First (SSTF), SCAN, and Circular SCAN (C-SCAN)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printTs(int* ts, int tsLength){ 
 int dif = 0;
 int totalDif = 0;
 printf("%d", ts[0]);
 for(int i = 1; i < tsLength; ++i){
  dif = abs(ts[i] - ts[i-1]);
  printf(" %d:%d", ts[i], dif);
  totalDif += dif;
 }
 printf(" Total:%d\n", totalDif);
}

int main(int argc, char **argv) {

 //convert argv[][] to int[]
 int tsLength = argc -1;
 int ts[tsLength];
 //array to sort the ts
 int tSort[tsLength];
 for(int i = 1; i < argc; ++i){
  //Converts string to int and saves in ts
  ts[i-1] = atoi(argv[i]);
 }

 memcpy(tSort, ts, sizeof(tSort));

 //FCFS does not need sorting
 printf("FCFS: Start:");
 printTs(tSort, tsLength);

 //SSTF sort

 for(int i = 1; i < tsLength; ++i){
  for(int j = i; j < tsLength; ++j){
   if(abs(tSort[i]-tSort[i-1]) > abs(tSort[j]-tSort[i-1])){
    int temp = tSort[i];
    tSort[i] = tSort[j];
    tSort[j] = temp;
   }
  }
 }

 printf("SSTF: Start:");
 printTs(tSort, tsLength);

 //SCAN sort
 for(int i = 1; i < tsLength; ++i){
  for(int j = i; j < tsLength; ++j){
   //if current is greater than next then swap
   if(tSort[i]-tSort[i-1] > tSort[j]-tSort[i-1]){
    int temp = tSort[i];
    tSort[i] = tSort[j];
    tSort[j] = temp;
   }
  }
 }
 int lessT[tsLength];
 int pivot;
 lessT[0] = tSort[0];
 for(pivot = 1; pivot < tsLength; ++pivot){
  if(tSort[pivot]>tSort[0]) break;
 }
 int j = 1;
 for(int i = pivot; i < tsLength; ++i, ++j){
  lessT[j] = tSort[i];
 }
 int newP = j;
 for(int i = 1; j < tsLength; ++j, ++i){
  lessT[j] = tSort[i];
 }


 printf("SCAN: Start:");
 printTs(lessT, tsLength);

 //C_SCAN sort
 
 for(int i = newP, q = tsLength - 1; i < (newP + tsLength)/2; ++i, --q){
  int temp = lessT[i];
  lessT[i] = lessT[q];
  lessT[q] = temp;
 }

 printf("C_SCAN: Start:");
 printTs(lessT, tsLength);
}
