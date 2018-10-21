#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
int randRange();
void left_choices();

int main (void) {
  srand(time(0));

  int prize = randRange(3);

  int boxes[3] = { 0 , 0 , 0 };

  printf("The prize is in box: %d\n",prize);

  boxes[ prize ] = 1; //The box which gets the prize

  int player_choice =  randRange(3); //Player Chooses a random box
  
  printf("The player chose box: %d\n",player_choice);

  int left_choices_list[2];

  left_choices(player_choice , &left_choices_list );
  
  printf("We are left with the choices: [%d , %d]\n\n",
	 left_choices_list[0],left_choices_list[1]);
  

}

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

