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


long getAverageOverheadOfGettimeCallInNanoSeconds(clockid_t clk_id) {

    struct timespec tp_start, tp_end, res;
    long time_elapsed_sec;
    long time_elapsed_nsec;


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


void printOverheadsOfGettimeCallsInNanoSeconds(clockid_t clk_id, int numCalls) {

    printf("\n\nPrint the overhead of calling gettime");

    struct timespec tp_start, tp_end, res;
    long time_elapsed_sec;
    long time_elapsed_nsec;

    struct timespec * runTimes;
    runTimes = (struct timespec *) malloc(sizeof(struct timespec)*(numCalls+1));

    // Just to warm up stuff
    clock_gettime(clk_id, &tp_start);
    clock_gettime(clk_id, &tp_end);


    int i = 0;

    clock_gettime(clk_id, &tp_start);
    clock_gettime(clk_id, &runTimes[0]);
    for (i = 1; i < numCalls+1; i++) {
        clock_gettime(clk_id, &runTimes[i]);
    }
    clock_gettime(clk_id, &tp_end);


    printf("\nConsecutive call time differences, %d times",numCalls);
    for(i=1;i<numCalls+1;i++) {
        time_elapsed_sec = (runTimes[i].tv_sec - runTimes[i-1].tv_sec);
        time_elapsed_nsec = (runTimes[i].tv_nsec - runTimes[i-1].tv_nsec);
        printf("\n%ld", (BILLION * time_elapsed_sec) + time_elapsed_nsec);
    }

    time_elapsed_sec = (tp_end.tv_sec - tp_start.tv_sec);
    time_elapsed_nsec = (tp_end.tv_nsec - tp_start.tv_nsec);
    ulong total_time = (BILLION * time_elapsed_sec) + time_elapsed_nsec;
    printf("\nTotal time : %ld \nnumCalls : %d \nAvg overhead : %lf", total_time, numCalls+2, ((double)total_time/(double)(numCalls+2)));

    return ;
}



void computeResolution(clockid_t clk_id, int numIterations) {

    struct timespec tp_start, tp_end, res;
    long time_elapsed_sec;
    long time_elapsed_nsec;


    printf("\n\nComputing Resolution");

    struct timespec * runTimes;
    runTimes = (struct timespec *) malloc(sizeof(struct timespec)*(numIterations+1));

    // Just to warm up stuff
    clock_gettime(clk_id, &tp_start);
    clock_gettime(clk_id, &tp_end);

    time_elapsed_sec = (tp_end.tv_sec - tp_start.tv_sec);
    time_elapsed_nsec = (tp_end.tv_nsec - tp_start.tv_nsec);
//    printf("\nWarm up - Consecutive calls \n%ld", (BILLION * time_elapsed_sec) + time_elapsed_nsec);

    clock_gettime(clk_id, &tp_start);
    clock_gettime(clk_id, &tp_end);

    time_elapsed_sec = (tp_end.tv_sec - tp_start.tv_sec);
    time_elapsed_nsec = (tp_end.tv_nsec - tp_start.tv_nsec);
//    printf("\nWarm up 2 - Consecutive calls \n%ld", (BILLION * time_elapsed_sec) + time_elapsed_nsec);
    // End warm up


//
//    int cnt=0;
//    while(tp_start.tv_nsec == tp_end.tv_nsec) {
//        cnt++;
//        clock_gettime(clk_id, &tp_end);
//    }
//    printf("\n%ld", (BILLION * time_elapsed_sec) + time_elapsed_nsec);
//    printf("\n Number of times the system call was run is : %d", cnt);


    printf("\nConsecutive call time differences : %d times", numIterations);

    int i;
    for (i = 0; i < numIterations; i++) {
        clock_gettime(clk_id, &tp_start);
        clock_gettime(clk_id, &tp_end);

        time_elapsed_sec = (tp_end.tv_sec - tp_start.tv_sec);
        time_elapsed_nsec = (tp_end.tv_nsec - tp_start.tv_nsec);
        printf("\n%ld", (BILLION * time_elapsed_sec) + time_elapsed_nsec);
    }

    printf("\nCalls with small instructions in between : %d times", numIterations);

    int j;
    int uselessCtr = 0;
    for (i = 0; i < numIterations; i++) {
        clock_gettime(clk_id, &tp_start);

        // Increase this until we see a consistent reasonable difference
        for(j=0;j<2;j++) {
            uselessCtr++;
        }
        clock_gettime(clk_id, &tp_end);

        time_elapsed_sec = (tp_end.tv_sec - tp_start.tv_sec);
        time_elapsed_nsec = (tp_end.tv_nsec - tp_start.tv_nsec);
        printf("\n%ld", (BILLION * time_elapsed_sec) + time_elapsed_nsec);
    }

    // prevent possible optimizing out of uselessCtr itself?
    // I have no idea about how smart compilers are!
    printf("\n Useless ctr : %d", uselessCtr);
}



int main(int argc, char *argv[]) {
    
//    printOverheadsOfGettimeCallsInNanoSeconds(CLOCK_MONOTONIC, 50);

//    printf("\nAverage overhead of clock : %ld\n", getAverageOverheadOfGettimeCallInNanoSeconds(CLOCK_MONOTONIC));

    computeResolution(CLOCK_PROCESS_CPUTIME_ID, 1000);



    return 0;
}



