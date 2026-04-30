//#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "profile.h"

bool isPerfectSquare_brute(int number){
    for(int i = 1; i <= number / 2;i++){
        if(i * i == number){
            return true;
        }
    }
    return false;
}

bool isPerfectSquare_optimized(int number){
    // Using binary search
    int low = 1;
    int high = number / 2;
    int mid = 0;

    while(low <= high){
       mid = (low + high) / 2;

      
       if(mid * mid < number){
            low = mid + 1;
       }else if (mid * mid > number){
            high = mid - 1;
       }
       else{
           return true;
       }

    }

    return false;
}

int main(){
    int num = 4'42'49'104; // We can separate the digits with apostrophe character
    
    /*
    struct timespec start, end; // timespec contains measurements of time in seconds and nanoseconds

    clock_gettime(CLOCK_REALTIME, &start); // captures the start time
    bool result = isPerfectSquare_brute(num);
    clock_gettime(CLOCK_REALTIME, &end); // captures the end time
    double elapsed_time = ((double)end.tv_sec * 1e9 + end.tv_nsec) - ((double)start.tv_sec * 1e9 + start.tv_nsec); // Storing time in nanoseconds
    printf("Brute force Time : %lf us\n", elapsed_time / 1e3); // Converting to microseconds 
    printf("BRUTE : %d a perfect square ? -> %s\n", num, (result == 1 ? "True" : "False"));

    clock_gettime(CLOCK_REALTIME, &start);
    result = isPerfectSquare_optimized(num);
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed_time = ((double)end.tv_sec * 1e9 + end.tv_nsec) - ((double)start.tv_sec * 1e9 + start.tv_nsec); // Storing time in nanoseconds
    printf("Optimized Time : %lf us\n", elapsed_time / 1e3); // Converting to microseconds 
    printf("OPTIMIZED : %d a perfect square ? -> %s\n", num, (result == 1 ? "True" : "False"));

    clock_gettime(CLOCK_REALTIME, &end);
   */
    measure_runtime(isPerfectSquare_brute, num);
    measure_runtime(isPerfectSquare_optimized, num);
}
