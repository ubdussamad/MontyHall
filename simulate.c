#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

int rand_int();
int randRange();

int  main(void) {
  for ( int i = 0;  i < 5 ; i++ ) {
    printf("%d, " , randRange(90) );
  }
  printf("\n");
}

int randRange(int n) {
  int limit;
  int r; 
  limit = RAND_MAX - (RAND_MAX % n);
  while((r = rand()) >= limit);
  return r % n;
}

int rand_int(int range_x , int range_y) {
  while (1){
    int i = rand()/5;
  if ((range_x < i) && (i < range_y)){
      return(i);
   }
  }
}

