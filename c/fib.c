#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>

int fib_analytic(int d)
{
  #define RES (floor(i * a - b) + 1)

  double a = log10((sqrt(5.0) + 1) / 2);
  double b = log10(5.0) / 2;

  int i;
  for (i = 0; i < INT_MAX; i++)
  {
    if (RES == d) break;
  }

  return i;
}

void print_elapsed(struct timeval *t1, struct timeval *t2)
{
  double elapsed;
  elapsed = (t2->tv_sec - t1->tv_sec) * 1000.0;    // sec to ms
  elapsed += (t2->tv_usec - t1->tv_usec) / 1000.0; // us to ms
  printf("Found in: %f ms\n", elapsed);
}

int get_current_year()
{
  time_t raw_time;
  struct tm *local_time;

  time(&raw_time);
  local_time = localtime(&raw_time);

  return (local_time->tm_year + 1900);
}

int main()
{
  struct timeval t1, t2;

  // start timer
  gettimeofday(&t1, NULL);

  // get current year as number of digits
  int digits = get_current_year();

  // find the term with that number of digits
  int result = fib_analytic(digits);

  // stop timer
  gettimeofday(&t2, NULL);

  // print result
  printf("First Fibonacci term with %d digits is the %dth\n", digits, result);

  // print elapsed time
  print_elapsed(&t1, &t2);

  return 0;
}
