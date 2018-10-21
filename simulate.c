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

  for ( int i = 0; i < 2001 ; ++i) {
      int z = play();
      if (z) {
	wins++;
      }
      else if (z==0)  {
	loss++;
      }
      else {
	continue;
	//printf("Undefined Beaviur")
      }
  }
  printf("Final Resuts are: Loss: %d  , Wins: %d\n\n",wins,loss);
  return(0);
}
    
	



int play() {
  srand(time(0));

  int prize = randRange(3);

  int boxes[3] = { 0 , 0 , 0 };

  //printf("The prize is in box: %d\n",prize);

  boxes[ prize ] = 1; //The box which gets the prize

  int player_choice =  randRange(3); //Player Chooses a random box
  
  //printf("The player chose box: %d\n",player_choice);

  int left_choices_list[2];

  left_choices(player_choice , &left_choices_list );
  
  //printf("We are left with the choices: [%d , %d]\n\n",left_choices_list[0],left_choices_list[1]);

  if ( (left_choices_list[0] != prize) && (left_choices_list[1] != prize) ) { //Case where player chose the box with prize
    //We can show any one of the left boxes randomly
    int ch = randRange(2); //Choose the first or the second box among the left onces
     printf("The assistant has 2 choices\n");
    //printf("Assitant revealed box: %d\n",left_choices_list[ch]);
    //If he switches he looses
    return(0);    
  }

  else if ( (left_choices_list[0] != prize) || (left_choices_list[1] != prize) ) { // Player chose the empty box
    //We can only show the empty box
    int ch_index;
    for (int i=0; i<2 ; i++ ){
      if ( left_choices_list[i] != prize ) {
	ch_index = i;
	break;
      }
    }
    // printf("The assistant has NO choices\n");
    //printf("The assistant revealed box: %d\n",left_choices_list[ch_index]);

    //If he switches he wins
    return(1);
  }
  return(-1);
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

