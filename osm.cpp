#include <sys/time.h>
#include <stdio.h>
#include <cmath>
#include "osm.h"

#define TIMES 10
#define SEC_FACTOR 1000000000
#define USEC_FACTOR 1000


void f(){}

double osm_operation_time(unsigned int iterations)
{
  struct timeval start_time;
  struct timeval end_time;
  if (iterations == 0) {return -1;}
  int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
  int iter = ceil(iterations/TIMES);
  int status1 = gettimeofday(&start_time, NULL);
  for(int i = 0; i<iter ;i++)
  {
    a0 = a0+1;
    a1 = a1+1;
    a2 = a2+1;
    a3 = a3+1;
    a4 = a4+1;
    a5 = a5+1;
    a6 = a6+1;
    a7 = a7+1;
    a8 = a8+1;
    a9 = a9+1;
  }
  int status2 = gettimeofday(&end_time, NULL);
  if (status1 != 0 or status2!=0) {return -1;}
  double total_time = (end_time.tv_sec - start_time.tv_sec)*SEC_FACTOR + (end_time.tv_usec - start_time.tv_usec)*USEC_FACTOR;
  return (total_time/(TIMES*iter));
}

double osm_function_time(unsigned int iterations)
{
  struct timeval start_time;
  struct timeval end_time;
  gettimeofday(&start_time, NULL);
  if (iterations == 0) {return -1;}
  int iter = ceil(iterations/TIMES);
  int status1 = gettimeofday(&start_time, NULL);
  for(int i = 0; i<iter ;i++)
  {
    f();
    f();
    f();
    f();
    f();
    f();
    f();
    f();
    f();
    f();
  }
  int status2 = gettimeofday(&end_time, NULL);
  if (status1 != 0 or status2!=0) {return -1;}
  double total_time = (end_time.tv_sec - start_time.tv_sec)*SEC_FACTOR + (end_time.tv_usec - start_time.tv_usec)*USEC_FACTOR;
  return (total_time/(TIMES*iter));
}

double osm_syscall_time(unsigned int iterations)
{
  struct timeval start_time;
  struct timeval end_time;
  gettimeofday(&start_time, NULL);
  if (iterations == 0) {return -1;}
  int iter = ceil(iterations/TIMES);
  int status1 = gettimeofday(&start_time, NULL);
  for(int i = 0; i<iter ;i++)
  {
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
  }
  int status2 = gettimeofday(&end_time, NULL);
  if (status1 != 0 or status2!=0) {return -1;}
  double total_time = (end_time.tv_sec - start_time.tv_sec)*SEC_FACTOR + (end_time.tv_usec - start_time.tv_usec)*USEC_FACTOR;
  return (total_time/(TIMES*iter));
}
