//
// Created by adbhat on 9/17/16.
//

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <assert.h>
# include <ctype.h>
# include <errno.h>
# include <limits.h>

#define BILLION 1000000000L


long getAverageOverheadOfGettimeCallInNanoSeconds() {
    clockid_t clk_id;
    struct timespec tp_start, tp_end, res;
    long time_elapsed_sec;
    long time_elapsed_nsec;

    clk_id = CLOCK_MONOTONIC;

    // Just to warm up stuff
    clock_gettime(clk_id, &tp_start);
    clock_gettime(clk_id, &tp_end);

    int retVal;
    int i = 0;

    clock_gettime(clk_id, &tp_start);
    for (i = 0; i < 100000; i++) {
        clock_gettime(clk_id, &tp_end);
    }

    time_elapsed_sec = (tp_end.tv_sec - tp_start.tv_sec);
    time_elapsed_nsec = (tp_end.tv_nsec - tp_start.tv_nsec);

    return ((BILLION * time_elapsed_sec) + time_elapsed_nsec)/100000L;
}


void printOverheadsOfGettimeCallsInNanoSeconds(int numCalls) {
    clockid_t clk_id;
    struct timespec tp_start, tp_end, res;
    long time_elapsed_sec;
    long time_elapsed_nsec;

    clk_id = CLOCK_MONOTONIC;

    struct timespec * runTimes;
    runTimes = (struct timespec *) malloc(sizeof(struct timespec)*(numCalls+1));

    // Just to warm up stuff
    clock_gettime(clk_id, &tp_start);
    clock_gettime(clk_id, &tp_end);

    int retVal;
    int i = 0;

    clock_gettime(clk_id, &runTimes[0]);
    for (i = 1; i < numCalls+1; i++) {
        clock_gettime(clk_id, &runTimes[i]);
    }


    for(i=1;i<numCalls+1;i++) {
        time_elapsed_sec = (runTimes[i].tv_sec - runTimes[i-1].tv_sec);
        time_elapsed_nsec = (runTimes[i].tv_nsec - runTimes[i-1].tv_nsec);
        printf("\n%ld", (BILLION * time_elapsed_sec) + time_elapsed_nsec);
    }

    return ;
}



void computeResolution(int numCalls) {

    clockid_t clk_id;
    struct timespec tp_start, tp_end, res;
    long time_elapsed_sec;
    long time_elapsed_nsec;

    clk_id = CLOCK_MONOTONIC;

    printf("\nCompute Resolution");

    struct timespec * runTimes;
    runTimes = (struct timespec *) malloc(sizeof(struct timespec)*(numCalls+1));

    // Just to warm up stuff
    clock_gettime(clk_id, &tp_start);
    clock_gettime(clk_id, &tp_end);

    time_elapsed_sec = (tp_end.tv_sec - tp_start.tv_sec);
    time_elapsed_nsec = (tp_end.tv_nsec - tp_start.tv_nsec);
    printf("\n%ld", (BILLION * time_elapsed_sec) + time_elapsed_nsec);

    clock_gettime(clk_id, &tp_start);
    clock_gettime(clk_id, &tp_end);

    time_elapsed_sec = (tp_end.tv_sec - tp_start.tv_sec);
    time_elapsed_nsec = (tp_end.tv_nsec - tp_start.tv_nsec);
    printf("\n%ld", (BILLION * time_elapsed_sec) + time_elapsed_nsec);

    int cnt=0;
    while(tp_start.tv_nsec == tp_end.tv_nsec) {
        cnt++;
        clock_gettime(clk_id, &tp_end);
    }
    printf("\n%ld", (BILLION * time_elapsed_sec) + time_elapsed_nsec);

    printf("\n Number of times the system call was run is : %d", cnt);

}



int main(int argc, char *argv[]) {

    long overheadOfGettimeNs = -1l;

    printOverheadsOfGettimeCallsInNanoSeconds(50);

    computeResolution(10);

    //printf("%ld\n", overheadOfGettimeNs);

    return 0;
}


