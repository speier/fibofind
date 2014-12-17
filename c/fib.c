#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <sys/time.h>

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
  printf("Elapsed: %f ms\n", elapsed);
}

int main()
{
  int d = 2012;
  struct timeval t1, t2;

  // start timer
  gettimeofday(&t1, NULL);

  int result = fib_analytic(2012);

  // stop timer
  gettimeofday(&t2, NULL);

  // print result
  printf("The %dth term has %d digits\n", d, result);

  // print elapsed time
  print_elapsed(&t1, &t2);

  return 0;
}
