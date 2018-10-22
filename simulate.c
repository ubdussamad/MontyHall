#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
int randRange();
void left_choices();
int play();

int main(void) {
  int wins = 0;
  int loss = 0;
  srand(time(0));
  for ( int i = 0; i < 20000000 ; i++ ) {
      int z = play();
      if (z == 1) {
	wins++;
      }
      else if (z==0)  {
	loss++;
      }
      else {
	printf("Locha Play returned:%d" , z);
      }
  }
  
  printf("Final Resuts are: Loss: %d  , Wins: %d\n\n",wins,loss);
  return(0);
}
    
	



int play() {
  int prize = randRange(3);

  int boxes[3] = { 0 , 0 , 0 };
  boxes[ prize ] = 1; //The box which gets the prize

  int player_choice =  randRange(3); //Player Chooses a random box
  int left_choices_list[2];
  left_choices(player_choice , &left_choices_list );
  if ( (left_choices_list[0] != prize) && (left_choices_list[1] != prize) ) {
    //Player chose the right box, so if he switches he looses.
    return(0);
  }
  else if ( (left_choices_list[0] != prize) || (left_choices_list[1] != prize) ) {
    //Here if he switches he wins.
    return(1);
  }
  return(-1);
}







//Jos Som Libs
void left_choices(int ch, int * list) {
  int index = 0;
  int parent[3] = {0,1,2};
  for ( int i=0 ; i < 3; i++ ){
    if (parent[i] != ch) {
      memcpy( (int *) ((long unsigned int)list + 4*index) , &parent[i] , 4 );
      index++;
    }
  }
}

int randRange(int n) {
  int limit;
  int r; 
  limit = RAND_MAX - (RAND_MAX % n);
  while((r = rand()) >= limit);
  return r % n;
}

