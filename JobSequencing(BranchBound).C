#include <stdio.h>
#include <stdbool.h>

#define MAX_JOBS 100

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

void sortJobs(Job jobs[], int numJobs) {
    for (int i = 0; i < numJobs - 1; i++) {
        for (int j = 0; j < numJobs - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

void jobSequencingBranchBound(Job jobs[], int numJobs) {
    sortJobs(jobs, numJobs);

    int maxDeadline = 0;
    for (int i = 0; i < numJobs; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    int profit = 0;
    int numScheduledJobs = 0;
    bool slot[maxDeadline];

    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = false;
    }

    for (int i = 0; i < numJobs; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == false) {
                slot[j] = true;
                numScheduledJobs++;
                profit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Scheduled Jobs:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i]) {
            printf("Job %d\n", jobs[i].id);
        }
    }

    printf("Total Profit: %d\n", profit);
}

int main() {
    int numJobs = 5;

    Job jobs[MAX_JOBS] = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };

    jobSequencingBranchBound(jobs, numJobs);

    return 0;
}
