#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
typedef struct Job {
  char id[5];
  int deadline;
  int profit;
} Job;
void JobSequencingWithDeadline(Job jobs[], int n);
int minValue(int x, int y) {
  if(x < y) return x;
  return y;
}
int main() {
  int i, j, n;
  Job jobs[MAX], temp;
  printf("Enter the no of jobs : ");
  scanf("%d", &n);
  for(i=0; i<n; i++){
  	printf("\nEnter the job-%d : ", i+1);
  	scanf("%s", &jobs[i].id);
  	printf("Enter the deadline : ");
  	scanf("%d", &jobs[i].deadline);
  	printf("Enter the profit : ");
  	scanf("%d", &jobs[i].profit);
  	printf("\n");
  }
  for(i = 1; i < n; i++) {
    for(j = 0; j < n - i; j++) {
      if(jobs[j+1].profit > jobs[j].profit) {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }
  printf("%5s %10s %8s\n", "Job", "Deadline", "Profit");
  for(i = 0; i < n; i++) {
    printf("%5s %7i %9i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
  }
  JobSequencingWithDeadline(jobs, n);
  return 0;
}
void JobSequencingWithDeadline(Job jobs[], int n) {
	
  int i, j, k, maxprofit, timeslot[MAX], filledTimeSlot = 0;
  
  int Max_deadline = 0;
  for(i = 0; i < n; i++) {
    if(jobs[i].deadline > Max_deadline) {
      Max_deadline = jobs[i].deadline;
    }
  }
  for(i = 1; i <= Max_deadline; i++) {
    timeslot[i] = -1;
  }
  for(i = 1; i <= n; i++) {
    k = minValue(Max_deadline, jobs[i - 1].deadline);
    while(k >= 1) {
      if(timeslot[k] == -1) {
        timeslot[k] = i-1;
        filledTimeSlot++;
        break;
      }
      k--;
    }
    if(filledTimeSlot == Max_deadline) {
      break;
    }
  }
  printf("\nRequired Jobs: ");
  for(i = 1; i <= Max_deadline; i++) {
    if(timeslot[i] != -1){
    	printf(" --> ");
    	printf("%s", jobs[timeslot[i]].id);	
	}
  }
  maxprofit = 0;
  for(i = 1; i <= Max_deadline; i++) {
    maxprofit += jobs[timeslot[i]].profit;
  }
  printf("\nMax Profit: %d\n", maxprofit);
}
 
