/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//

//Taha Mahmood, Roll: 22I-0840, Section C, Final Project, Programming Fundamentals

#include <iostream>
using namespace std;

//void shadow(int a , int b,int c)
//{

	/*for(int i = 0; i <4; i++)
	{
		point_3[i][0] = point_2[i][0];
		point_3[i][1] = point_3[i][1];
	}
	
	for(int i = 0; i <4; i++)
	{
		for(int j = 19; j > 0; j--)
		{
			point_3[i][0] +=j;
			if(!anamoly())
 				for(int i = 0; i < 4; i++)
 					point_3[i][0] = point_2[i][0];
 					j--;
        }
	}
*/

            
            
 // }
	
//}
//}

/*void shadow()
{
	for(int i = 0; i < 4; i++)
		
}
*/


void fallingPiece(float& timer, float& delay, int& colorNum)
	{
	if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
        }
     
        if (!anamoly()){
        		for(int i = 0; i<4; i++)
        			gameGrid[point_2[i][1]][point_2[i][0]] = colorNum;
        		colorNum= 1+rand()%7;
			int n=rand()%7;
            
                for (int i=0;i<4;i++){
                    point_1[i][0] = (BLOCKS[n][i] % 2) + 4;
                    point_1[i][1] = BLOCKS[n][i] / 2;
                      
                }
        }
        timer=0;
      
	}
	}
	


 

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
///MOVE///
void move(int horizontal)
 {
 	for(int i = 0; i<4; i++)
 			{
 				point_2[i][0] = point_1[i][0];
 				point_1[i][0] = point_1[i][0] + horizontal;
 			}
 			if(!anamoly())
 			{
 				for (int i = 0; i <4; i++)
 				{
 					point_1[i][0] = point_1[i][0] - horizontal;
 				}
 			}
 			}


 			
 ///ROTATE///
 void rotation (int rotate)
 {
 if(rotate)
 	{
 		for(int i = 0; i < 4; i++)
 		{
 			int rotate_x = point_1[i][1] - point_1[1][1];
 			int rotate_y = point_1[i][0] - point_1[1][0];
 			point_1[i][0] = point_1[1][0] - rotate_x;
 			point_1[i][1] = point_1[1][1]+ rotate_y;
 		}
 		
 		if(!anamoly())
 			for(int i = 0; i < 4; i++)
 			point_1[i][0] = point_2[i][0];
 		}
 	}
 			
 ///REMOVE LINES///
 void RemoveLine()
 {
 
 int line = M - 1;
 for ( int i = M-1; i > 0; i--)
 	{
 		int loop = 0;
 		for (int j = 0; j < N; j++)
 			{
 				if(gameGrid[i][j])
 					{
 						loop = loop + 1;
 					}
 						gameGrid[line][j] = gameGrid[i][j];
 					}
 				if(loop<N)
 					{
 						line--;
 					}
 	}
}

///GAMEOVER///
 bool End()
{
	int r1 = 0;
	int r2 = 0;
	bool condition = false;

	for(int j = 0; j < 10; j++)
	{
		r1 = gameGrid[0][j];
		if(r1!=0)
		{
		break;
		}
	}
	for(int j = 0; j < 10; j++)
	{
		r2 = gameGrid[1][j];
		if(r2!=0)
		{
		break;
		}
	
}
	if(r1!= 0 || r2!=0)
	condition = true;
	else 
	condition = false;
	return condition;
}


///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
