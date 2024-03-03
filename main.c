/**********************************
 *	Snake & Ladder game
 *
 * Rules:
 * 	1. The game will start with any dice value.
 * 	2. If a six is appeared then a chance is awarded to that player.
 *	3. Only the location of current player is shown on the board,
 *		the location of other player is mentioned below the board.
 *	4. Snakes: 99 to 1, 65 to 40, 25 to 9.
 *	5. Ladders: 70 to 93, 60 to 83, 13 to 43'
 *
 **********************************/

#include <stdio.h>
#include <stdlib.h>

int generate_random() 
{
    int rem;

    do {
        rem = rand() % 7 + 1; // Generate a random number between 1 and 6
    } while (rem == 0); // Repeat if the generated number is 0

    return rem;
}

void displaychart(int curp, char* player) 
{
	int i, j, t, c, sft = 0, diceres, pos1, pos2;

	if(curp == 100)
	{
		printf("***** Congratulations *****\n\n\nPlayer %s wins\n", player);		     scanf("%*s");
		exit(0);
	}

	for(i = 10; i > 0; i--)
	{
		t = i - 1;
		if((sft % 2) == 0)
		{
			c = 0;
			for(j = 10; j >= 1; j--)
			{
				diceres = (i * j) + (t * c++);

				if(curp == diceres)
					printf("%s\t", player);
				else
					printf("%d\t", diceres);	
			}
			sft++;
		}
		else
		{
			c = 9;
			for(j = 1; j <= 10; j++)
			{
				diceres = (i * j) + (t * c--);
				if(curp == diceres)
					printf("%s\t", player);
				else
					printf("%d\t", diceres);
			}
			sft++;
		}
		printf("\n\n");
	}
	printf("--------------------------------------------------\n");
}

void main() 
{
	int i, dice, cur_pos1 = 0, cur_pos2 = 0;
	char character;

	char player1[] = "WP1W";
	char player2[] = "WP2W";

	while(1)
	{
		printf("     ** SNAKE AND LADDER GAME**     \n");
		printf("Snakes: 25 to 9,\t 65 to 40,\t 99 to 1.\n"
		       "Ladder: 13 to 42,\t 60 to 83,\t 70 to 93.\n\n");
		printf("Choose your option:\n");
		printf("1. Player 1 plays\n");
		printf("2. Player 2 plays\n");
		printf("3. Exit\n\n");
		scanf("%s", &character);

		switch(character)
		{
			case '1': dice = generate_random();
				system("clear");
				printf("\t\t\t\tDice: %d\n\n", dice);
				if(dice == 6)
					printf("You have earned a chance "
					       "to play one more time.\n\n");
				cur_pos1 = dice + cur_pos1;
				if(cur_pos1 < 101) 
				{
					if(cur_pos1 == 99)
					{
						displaychart(1, player1);//snake
					}
					if(cur_pos1 == 65)
					{
						displaychart(40, player1);//snake
					}
					if(cur_pos1 == 25)
					{
						displaychart(9, player1);//snake
					}
					if(cur_pos1 == 70)
					{
						displaychart(93, player1);//ladder
					}
					if(cur_pos1 == 60)
					{
						displaychart(83, player1);//ladder
					}
					if(cur_pos1 == 13)
					{
						displaychart(42, player1);//ladder
					}
					else
					{
						displaychart(cur_pos1, player1);
					}
				}
				else 
				{
					cur_pos1 = cur_pos1 - dice;
					printf("\nRange exceeded of Player 1.\n");
					displaychart(cur_pos1, player1);
				}
				printf("Player 2 position is %d\n\n", cur_pos2);
				break;

			case '2':dice = generate_random();
				 system("clear");
				 printf("\t\t\t\tDice: %d\n\n", dice);
				 if(dice == 6)
					printf("You have earned a chance"
					       "to play one more time.\n");
				cur_pos2 = dice + cur_pos2;
				if(cur_pos2 < 101) 
				{
					if(cur_pos2 == 99)
					{
						displaychart(1, player2);//snake
	
					}
					if(cur_pos2 == 65)
					{
						displaychart(40, player2);//snake
					}
					if(cur_pos2 == 25)
					{
						displaychart(9, player2);//snake
					}
					if(cur_pos2 == 70)
					{
						displaychart(93, player2);//ladder
					}
					if(cur_pos2 == 60)
					{
						displaychart(83, player2);//ladder
					}
					if(cur_pos2 == 13)
					{
						displaychart(42, player2);//ladder
					}
					else 
					{
						displaychart(cur_pos2, player2);
					}
				}
				else 
				{
					cur_pos2 = cur_pos2 - dice;
					printf("\nRange exceeded of Player 2.\n");
					displaychart(cur_pos2, player2);
				}
				printf("Player 1 position is %d\n\n", cur_pos1);
				break;
			case '3':exit(0);
				 break;
			default:
				 printf("\n\nIncorrect choice. Try again\n");
		}		
	}
}
