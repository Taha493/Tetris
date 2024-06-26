/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */



//Taha Mahmood, Roll: 22I-0840, Section C, Final Project, Programming Fundamentals
#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(320, 480), title);
    Texture obj1, obj2, obj3;
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.png");
    obj3.loadFromFile("img/frame.png");
    /*
        Load "frames.png","tiles.png" and "background.png" for Texture objects
    */
    Sprite sprite(obj1), background(obj2), frame(obj3);
    Music music;
    if(!music.openFromFile("song/faded.ogg"))
    {
    	cout <<"Error" << endl;
    }
    	
    	music.play();
    	
    	
    int horizontal=0, colorNum=1;
    float timer=0, delay=0.5;
    bool rotate=0;
    bool pause = true;
    Clock clock;
    while (window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
		

        //---Event Listening Part---//
        Event e;
        while (window.pollEvent(e)){                    //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                    rotate = true;                         //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                    horizontal = -1;                          //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                    horizontal = 1;                           //Change in X-Axis - Positive    
                    
            }
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.03;                                  //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
            if (Keyboard::isKeyPressed(Keyboard::Space))
            delay = 0.01;

			
        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
        fallingPiece(timer, delay, colorNum);               //Example: fallingPiece() function is called here
        move(horizontal);										//Move function is called here
        rotation(rotate);									//Rotation function is called here
        RemoveLine();										//Remove line function is called here 
      		if(End())
      		{
      		RenderWindow screen(VideoMode(320, 480), "Gameover", Style:: Default);
      		screen.setFramerateLimit(60);
      		
      		Font font;
      		if(!font.loadFromFile("Font/monserrat.ttf"))
      			throw("THE FONT IS NOT LOADED, SORRY!");
 
      		
      		Text text1;
      		text1.setFont(font);
      		text1.setCharacterSize(24);
      		text1.setFillColor(Color::Red);
      		text1.setStyle(Text::Bold);
      		text1.setString("GameOver");
      		
      		while(screen.isOpen())
      		{
      			Event event;
      			while(screen.pollEvent(event))
      			{
      				if (event.type == Event::Closed)
      					screen.close();
      			}
      			
      		///DRAW
      		screen.clear();
      		screen.draw(text1);
      		screen.display();
      		
      	}
      	window.close();
      	}
      	
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////
        
        rotate = 0;
		delay=0.5;
		horizontal =0;
		
        window.clear(Color::Black);
        window.draw(background);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
           // sprite.setPosition(point_3[i][0]*18,point_3[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          }
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
       }
      }
    
