//     CS 100 Ludo Game using sfml 
//     Copyright (C) 2020  Sumair Ijaz Hashmi - LUMS roll number: 24100004

//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.

//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.

//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace sf;
using namespace std;


//x and y coordinates of each piece when they are at home
const double GREEN_INITIAL_X = 440;
const double GREEN_INITIAL_Y = 440;

const double BLUE_INITIAL_X = 140;
const double BLUE_INITIAL_Y = 140;

const double YELLOW_INITIAL_X = 140;
const double YELLOW_INITIAL_Y = 440;

const double RED_INITIAL_X = 440;
const double RED_INITIAL_Y = 140;

Text text_value_dice; //to show the dice value
Text text_dice; //to print the words "Dice value"
Text victory; //to show who has won


//all coordinates of all pieces
int length_locations = 57;
const float locations_blue_x[] = { 51.6666666667,	93.3333333333667,	135.000000000033,	176.6666666667,	218.333333333367,	255,	255,	255,	255,	255,	255,	288.333333333333,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	363.333333333333,	405,	446.666666666667,	488.333333333333,	530,	571.666666666667,	571.666666666667,	571.666666666667,	530,	488.333333333333,	446.666666666667,	405,	363.333333333333,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	288.333333333333,	255,	255,	255,	255,	255,	255,	221.666666666667,	180,	138.333333333333,	96.6666666666666,	54.9999999999999,	13.3333333333333,	13.3333333333333,	54.9999999999999,	96.6666666666666,	138.333333333333,	180,	221.666666666667,	287};
const float locations_blue_y[] = { 253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	219.999999999667,	178.333333333,	136.666666666333,	94.9999999996667,	53.333333333,	11.6666666663334,	11.6666666663334,	11.6666666663334,	53.333333333,	94.9999999996667,	136.666666666333,	178.333333333,	219.999999999667,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	286.666666666333,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	361.666666666333,	403.333333333,	444.999999999667,	486.666666666333,	528.333333333,	569.999999999667,	569.999999999667,	569.999999999667,	528.333333333,	486.666666666333,	444.999999999667,	403.333333333,	361.666666666333,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	286.666666666333,	286.666666666333,	286.666666666333,	286.666666666333,	286.666666666333,	286.666666666333,	286.666666666333};
int blue_currentpos = 0;

const float locations_green_x[] = { 530,	488.333333333333,	446.666666666667,	405,	363.333333333333,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	288.333333333333,	255,	255,	255,	255,	255,	255,	221.666666666667,	180,	138.333333333333,	96.6666666666666,	54.9999999999999,	13.3333333333333,	13.3333333333333,	13.3333333333333,	51.6666666667,	93.3333333333667,	135.000000000033,	176.6666666667,	218.333333333367,	255,	255,	255,	255,	255,	255,	288.333333333333,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	363.333333333333,	405,	446.666666666667,	488.333333333333,	530,	571.666666666667, 571.666666666667, 530,	488.333333333333,	446.666666666667,	405,	363.333333333333,	287 };
const float locations_green_y[] = { 319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	361.666666666333,	403.333333333,	444.999999999667,	486.666666666333,	528.333333333,	569.999999999667,	569.999999999667,	569.999999999667,	528.333333333,	486.666666666333,	444.999999999667,	403.333333333,	361.666666666333,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	286.666666666333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	219.999999999667,	178.333333333,	136.666666666333,	94.9999999996667,	53.333333333,	11.6666666663334,	11.6666666663334,	11.6666666663334,	53.333333333,	94.9999999996667,	136.666666666333,	178.333333333,	219.999999999667,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,286.66667, 286.666666666333,	286.666666666333,	286.666666666333,	286.666666666333,	286.666666666333,	286.666666666333};
int green_currentpos = 0;

const float locations_yellow_x[] = { 255,	255,	255,	255,	255,	221.666666666667,	180,	138.333333333333,	96.6666666666666,	54.9999999999999,	13.3333333333333,	13.3333333333333,	13.3333333333333,	51.6666666667,	93.3333333333667,	135.000000000033,	176.6666666667,	218.333333333367,	255,	255,	255,	255,	255,	255,	288.333333333333,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	363.333333333333,	405,	446.666666666667,	488.333333333333,	530,	571.666666666667,	571.666666666667,	571.666666666667,	530,	488.333333333333,	446.666666666667,	405,	363.333333333333,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	288.333333333333, 288.333333333333 , 288.333333333333 , 288.333333333333 , 288.333333333333 , 288.333333333333 ,287};
const float locations_yellow_y[] = { 528.333333333,	486.666666666333,	444.999999999667,	403.333333333,	361.666666666333,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	286.666666666333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	219.999999999667,	178.333333333,	136.666666666333,	94.9999999996667,	53.333333333,	11.6666666663334,	11.6666666663334,	11.6666666663334,	53.333333333,	94.9999999996667,	136.666666666333,	178.333333333,	219.999999999667,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.3333333 ,286.666666666333,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	361.666666666333,	403.333333333,	444.999999999667,	486.666666666333,	528.333333333, 569.999999999667,	569.999999999667,528.333333333,	486.666666666333,	444.999999999667,	403.333333333,	361.666666666333,286.666666666333 };
int yellow_currentpos = 0;

const float locations_red_x[] = {321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	363.333333333333,	405,	446.666666666667,	488.333333333333,	530,	571.666666666667,	571.666666666667,	571.666666666667,	530,	488.333333333333,	446.666666666667,	405,	363.333333333333,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	321.666666666667,	288.333333333333,	255,	255,	255,	255,	255,	255,	221.666666666667,	180,	138.333333333333,	96.6666666666666,	54.9999999999999,	13.3333333333333,	13.3333333333333, 13.3333333333333,51.6666666667,	93.3333333333667,	135.000000000033,	176.6666666667,	218.333333333367,	255,	255,	255,	255,	255,	255,	288.333333333333, 	288.333333333333 ,	288.333333333333 ,	288.333333333333 ,	288.333333333333 ,	288.333333333333 ,	287};
const float locations_red_y[] = {53.333333333,	94.9999999996667,	136.666666666333,	178.333333333,	219.999999999667,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	286.666666666333,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	361.666666666333,	403.333333333,	444.999999999667,	486.666666666333,	528.333333333,	569.999999999667,	569.999999999667,	569.999999999667,	528.333333333,	486.666666666333,	444.999999999667,	403.333333333,	361.666666666333,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	319.999999999667,	286.666666666333,253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	253.333333333,	219.999999999667,	178.333333333,	136.666666666333,	94.9999999996667,	53.333333333,	11.6666666663334,	11.6666666663334, 53.333333333,	94.9999999996667,	136.666666666333,	178.333333333,	219.999999999667,286.666666666333	};
int red_currentpos = 0;

//stop locations coordinates
const float stops_x[] = { locations_blue_x[0],locations_blue_x[8],locations_blue_x[13],locations_blue_x[21],locations_blue_x[26],locations_blue_x[34],locations_blue_x[39],locations_blue_x[47]};
const float stops_y[] = { locations_blue_y[0],locations_blue_y[8],locations_blue_y[13],locations_blue_y[21],locations_blue_y[26],locations_blue_y[34],locations_blue_y[39],locations_blue_y[47] };

bool game_over = false;


//initial jump of red from its home to its starting location
//takes the circle and the dice's value as parameters
void initial_red_jump(CircleShape& circle, int dice)
{
    circle.setPosition(Vector2f(locations_red_x[0], locations_red_y[0]));
    red_currentpos++;
}

//moves red across the board using the array defined above
//take the circle and the dice's value as parameters
//takes in a font in order to display text on the sfml window
void red_movement(CircleShape& circle, int dice, Font &font)
{
    if (red_currentpos + dice > length_locations) //if the dice value is greater than what is required for red to win, red loses its turn. 6 STILL COUNTS
    {
        return;
    }
    for (int i = 0; i < dice; i++)
    {
        if (red_currentpos != length_locations - 1) //if the index is not at the victory/end position
        {
            circle.setPosition(Vector2f(locations_red_x[red_currentpos], locations_red_y[red_currentpos])); //moves the piece
            red_currentpos++;
        }
        else
        {
            circle.setPosition(Vector2f(locations_red_x[length_locations - 1], locations_red_y[length_locations - 1])); //moves the piece to the center of the board i.e the vic point
            victory.setFont(font);
            victory.setCharacterSize(24);
            victory.setPosition(Vector2f(300, 700));
            victory.setString("Red has won!");
            game_over = true;
            break;
        }
    }
}

//initial jump of yellow from its home to its starting location
//takes the circle and the dice's value as parameters
void initial_yellow_jump(CircleShape& circle, int dice)
{
    circle.setPosition(Vector2f(locations_yellow_x[0], locations_yellow_y[0]));
    yellow_currentpos++;
}

//moves yellow across the board using the array defined above
//take the circle and the dice's value as parameters
//takes in a font in order to display text on the sfml window
void yellow_movement(CircleShape& circle, int dice, Font &font)
{
    if (yellow_currentpos + dice > length_locations) //if the dice value is greater than what is required for yellow to win, yellow loses its turn. 6 STILL COUNTS
    {
        return;
    }
    for (int i = 0; i < dice; i++)
    {
        if (yellow_currentpos != length_locations - 1) //if the index is not at the victory/end position
        {
            circle.setPosition(Vector2f(locations_yellow_x[yellow_currentpos], locations_yellow_y[yellow_currentpos])); //moves the piece
            yellow_currentpos++;
        }
        else
        {
            circle.setPosition(Vector2f(locations_yellow_x[length_locations - 1], locations_yellow_y[length_locations - 1])); //moves the piece to the center of the board i.e the vic point
            victory.setFont(font);
            victory.setCharacterSize(24);
            victory.setPosition(Vector2f(300, 700));
            victory.setString("Yellow has won!");
            game_over = true;
            break;
        }
    }
}

//initial jump of green from its home to its starting location
//takes the circle and the dice's value as parameters
void initial_green_jump(CircleShape& circle, int dice)
{
    circle.setPosition(Vector2f(locations_green_x[0], locations_green_y[0]));
    green_currentpos++;
}

//moves green across the board using the array defined above
//take the circle and the dice's value as parameters
//takes in a font in order to display text on the sfml window
void green_movement(CircleShape& circle, int dice, Font &font)
{
    if (green_currentpos + dice > length_locations) //if the dice value is greater than what is required for green to win, green loses its turn. 6 STILL COUNTS
    {
        return;
    }
    for (int i = 0; i < dice; i++)
    {
        if (green_currentpos != length_locations - 1) //if the index is not at the victory/end position
        {
            circle.setPosition(Vector2f(locations_green_x[green_currentpos], locations_green_y[green_currentpos])); //moves the piece
            green_currentpos++; 
        }
        else 
        {
            circle.setPosition(Vector2f(locations_green_x[length_locations-1], locations_green_y[length_locations-1])); //moves the piece to the center of the board i.e the vic point
            victory.setFont(font);
            victory.setCharacterSize(24);
            victory.setPosition(Vector2f(300, 700));
            victory.setString("Green has won!");
            game_over = true;
            break;
        }
        
    }    
}

//initial jump of blue from its home to its starting location
//takes the circle and the dice's value as parameters
void initial_blue_jump(CircleShape& circle, int dice)
{
    circle.setPosition(Vector2f(locations_blue_x[0], locations_blue_y[0]));
    blue_currentpos++;
}

//moves blue across the board using the array defined above
//take the circle and the dice's value as parameters
//takes in a font in order to display text on the sfml window
void blue_movement(CircleShape& circle, int dice, Font &font)
{
    if (blue_currentpos + dice > length_locations) //if the dice value is greater than what is required for green to win, green loses its turn. 6 STILL COUNTS
    {
        return;
    }
    for (int i = 0; i < dice; i++)
    {
        if (blue_currentpos != length_locations - 1) //if the index is not at the victory/end position
        {
            circle.setPosition(Vector2f(locations_blue_x[blue_currentpos], locations_blue_y[blue_currentpos])); //moves the piece
            blue_currentpos++;
        }
        else
        {
            circle.setPosition(Vector2f(locations_blue_x[length_locations - 1], locations_blue_y[length_locations - 1]));  //moves the piece to the center of the board i.e the vic point
            victory.setFont(font);
            victory.setCharacterSize(24);
            victory.setPosition(Vector2f(300, 700));
            victory.setString("Blue has won!");
            game_over = true;
            break;
        }
    }
}


//checks if mouse has been pressed or not
bool mouse_pressed(Event& event)
{
    if (event.type == Event::MouseButtonPressed)
    {
       return true;
    }
    return false;
}

//generates a random dice value and returns it
//takes in a font in order to display text on the sfml window
int roll_dice(Font &font)
{    
       int dice = 0;
       dice = rand() % 6 + 1;
       
       //show the dice text and value
       text_dice.setFont(font);
       text_dice.setCharacterSize(24);
       text_dice.setPosition(Vector2f(50, 700));
       text_dice.setString("Dice value: ");

       text_value_dice.setFont(font);
       text_value_dice.setCharacterSize(24);
       text_value_dice.setPosition(Vector2f(250, 700));
       
       switch (dice)
       {
       case 1: text_value_dice.setString("1"); break;
       case 2: text_value_dice.setString("2"); break;
       case 3: text_value_dice.setString("3"); break;
       case 4: text_value_dice.setString("4"); break;
       case 5: text_value_dice.setString("5"); break;
       case 6: text_value_dice.setString("6"); break;
       }

       

       return dice;
}

//checks if red is at home or not by checking if it's current coordinates are the same as they were when it was initially at home
bool check_red_athome(CircleShape circle)
{
    bool is_home;
    if (circle.getPosition().x == RED_INITIAL_X && circle.getPosition().y == RED_INITIAL_Y)
    {
        is_home = true;
    }
    else
    {
        is_home = false;
    }
    return is_home;
}

//checks if yellow is at home or not by checking if it's current coordinates are the same as they were when it was initially at home
bool check_yellow_athome(CircleShape circle)
{
    bool is_home;
    if (circle.getPosition().x == YELLOW_INITIAL_X && circle.getPosition().y == YELLOW_INITIAL_Y)
    {
        is_home = true;
    }
    else
    {
        is_home = false;
    }
    return is_home;
}

//checks if green is at home or not by checking if it's current coordinates are the same as they were when it was initially at home
bool check_green_athome(CircleShape circle)
{
    bool is_home;
    if (circle.getPosition().x == GREEN_INITIAL_X && circle.getPosition().y == GREEN_INITIAL_Y)
    {
        is_home = true;
    }
    else
    {
        is_home = false;
    }
    return is_home;
}

//checks if blue is at home or not by checking if it's current coordinates are the same as they were when it was initially at home
bool check_blue_athome(CircleShape circle)
{
    bool is_home;
    if (circle.getPosition().x == BLUE_INITIAL_X && circle.getPosition().y == BLUE_INITIAL_Y)
    {
        is_home = true;
    }
    else
    {
        is_home = false;
    }
    return is_home;
}

//checks if a piece is at a stop sign or not by checking if it's current coordinates are same as any one of the stops' coordinates defined in the array above
bool at_stop(CircleShape circle)
{
    bool stop = false;
    for (int i = 0; i < 8; i++)
    {

        if ((circle.getPosition().x == stops_x[i]) && (circle.getPosition().y == stops_y[i]))
        {
            stop = true;
        }
    }
    return stop;
}


int main()
{
    srand(time(0));

    // make the game window
    RenderWindow game(VideoMode(600, 800), "CS 100 - Ludo");
    game.setFramerateLimit(30); //so that it doesnt go woosh


    //display the text on the window game
    Font font;
   font.loadFromFile("font/Langar-Regular.ttf");
   
    Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setPosition(Vector2f(50, 650));
    text.setString("WELCOME TO MY LUDO GAME!");

    Text text2;
    text2.setFont(font);
    text2.setCharacterSize(24);
    text2.setPosition(Vector2f(50, 750));
    text2.setFillColor(Color::Red);
    text2.setString("Press click to continue");


    //making the board
    RectangleShape board(Vector2f(600, 600));
    board.setFillColor(Color::White);

    //making home for each
    RectangleShape home_blue(Vector2f(250, 250));
    home_blue.setPosition(Vector2f(0, 0));
    home_blue.setFillColor(Color::Color(0,0,125,255));

    RectangleShape home_red(Vector2f(250, 250));
    home_red.setPosition(Vector2f(350, 0));
    home_red.setFillColor(Color::Color(150, 0, 0, 255));

    RectangleShape home_green(Vector2f(250, 250));
    home_green.setPosition(Vector2f(350, 350));
    home_green.setFillColor(Color::Color(0,100,0,255));

    RectangleShape home_yellow(Vector2f(250, 250));
    home_yellow.setPosition(Vector2f(0, 350));
    home_yellow.setFillColor(Color::Color(230,230,0,255));

    //making the dice
    RectangleShape dice_piece(Vector2f(50, 50));
    dice_piece.setPosition(Vector2f(270, 270));
    dice_piece.setFillColor(Color::Black);

    //making the victory spot
    RectangleShape vic(Vector2f(100, 100));
    vic.setPosition(Vector2f(250, 250));
    vic.setFillColor(Color::Black);

    RectangleShape vicB(Vector2f(25, 50));
    vicB.setPosition(Vector2f(250, 275));
    vicB.setFillColor(Color::Color(0, 0, 125, 255));

    RectangleShape vicR(Vector2f(50, 25));
    vicR.setPosition(Vector2f(275, 250));
    vicR.setFillColor(Color::Color(150,0,0,255));

    RectangleShape vicY(Vector2f(50, 25));
    vicY.setPosition(Vector2f(275, 325));
    vicY.setFillColor(Color::Color(230, 230, 0, 255));

    RectangleShape vicG(Vector2f(25, 50));
    vicG.setPosition(Vector2f(325, 275));
    vicG.setFillColor(Color::Color(0, 100, 0, 255));

    //making the white spots for each piece (1 for each now)
    CircleShape red_spot(30);
    red_spot.setPosition(Vector2f(425, 125));
    red_spot.setFillColor(Color::White);

    CircleShape blue_spot(30);
    blue_spot.setPosition(Vector2f(125, 125));
    blue_spot.setFillColor(Color::White);

    CircleShape yellow_spot(30);
    yellow_spot.setPosition(Vector2f(125, 425));
    yellow_spot.setFillColor(Color::White);

    CircleShape green_spot(30);
    green_spot.setPosition(Vector2f(425, 425));
    green_spot.setFillColor(Color::White);

    //making the pieces of each color (1 for each now)
    CircleShape red(10);
    red.setPosition(Vector2f(RED_INITIAL_X, RED_INITIAL_Y));
    red.setFillColor(Color::Red);

    CircleShape blue(10);
    blue.setPosition(Vector2f(BLUE_INITIAL_X, BLUE_INITIAL_Y));
    blue.setFillColor(Color::Blue);

    CircleShape yellow(10);
    yellow.setPosition(Vector2f(YELLOW_INITIAL_X, YELLOW_INITIAL_Y));
    yellow.setFillColor(Color::Color(255,255,0,255));

    CircleShape green(10);
    green.setPosition(Vector2f(GREEN_INITIAL_X, GREEN_INITIAL_Y));
    green.setFillColor(Color::Green);

    int turn = 1; //1 - yellow's turn, 2 - blue's turn, 3 - red's turn, 4 - green's turn    

    //game loop: everything happens here
    while (game.isOpen())
    {
        Event event;
        while (game.pollEvent(event))
        {

            //close the game if the window is closed
            if (event.type == Event::Closed)
            {
                game.close();
            }

            
            //UPDATE EVERYTHING // Main game logic happens here

           
            
            int dice = 0;
            

            if (mouse_pressed(event))
            {
                if (game_over) // if this is true then nothing else runs, this is decided in the green_movement and blue_movement functions
                {

                }
                else if (turn == 1)
                {
                    text.setString("Yellow's turn");
                    dice = roll_dice(font);
                    //if yellow is at home -> if dice is at 6 -> move yellow out of home and let yellow take another turn when the loop runs again 
                    //else -> its blue's turn
                    if (check_yellow_athome(yellow))
                    {
                        if (dice == 6)
                        {
                            initial_yellow_jump(yellow, dice);
                        }
                        else
                        {
                            turn = 2;
                        }
                    }
                    //if yellow is not at home -> move yellow -> if yellow captures a piece then the piece moves to it's home
                    //if yellow got a 6 then let it take another turn when the loop runs again else its blue's turn
                    else if (!check_yellow_athome(yellow))
                    {
                        yellow_movement(yellow, dice,font);
                        if (green.getPosition() == yellow.getPosition() && !at_stop(green))
                        {
                            green.setPosition(Vector2f(GREEN_INITIAL_X, GREEN_INITIAL_Y));
                            green_currentpos = 0;
                            continue;
                        }
                        
                        if (blue.getPosition() == yellow.getPosition() && !at_stop(blue))
                        {
                            blue.setPosition(Vector2f(BLUE_INITIAL_X, BLUE_INITIAL_Y));
                            blue_currentpos = 0;
                            continue;
                        }
                        

                        if (red.getPosition() == yellow.getPosition() && !at_stop(red))
                        {
                            red.setPosition(Vector2f(RED_INITIAL_X, RED_INITIAL_Y));
                            red_currentpos = 0;
                            continue;
                        }
                        
                        if (dice != 6)
                        {
                            turn = 2;
                        }
                    }

                }
                else if (turn == 2)
                {
                    text.setString("Blue's turn");
                    dice = roll_dice(font);
                    //if blue is at home -> if dice is at 6 -> move blue out of home and let blue take another turn when the loop runs again 
                    //else -> its red's turn
                    if (check_blue_athome(blue))
                    {
                        if (dice == 6)
                        {
                            initial_blue_jump(blue, dice);
                        }
                        else
                        {
                            turn = 3;
                        }
                    }
                    //if blue is not at home -> move blue -> if blue captures a piece then move the piece to it's home
                    //if blue got a 6 then let it take another turn when the loop runs again else its red's turn
                    else if (!check_blue_athome(blue))
                    {
                        blue_movement(blue, dice,font);
                        if (green.getPosition() == blue.getPosition() && !at_stop(green))
                        {
                            green.setPosition(Vector2f(GREEN_INITIAL_X, GREEN_INITIAL_Y));
                            green_currentpos = 0;
                            continue;
                        }
                        
                        if (blue.getPosition() == yellow.getPosition() && !at_stop(yellow))
                        {
                            yellow.setPosition(Vector2f(YELLOW_INITIAL_X, YELLOW_INITIAL_Y));
                            yellow_currentpos = 0;
                            continue;
                        }
                        
                        if (red.getPosition() == blue.getPosition() && !at_stop(red))
                        {
                            red.setPosition(Vector2f(RED_INITIAL_X, RED_INITIAL_Y));
                            red_currentpos = 0;
                            continue;
                        }
                        
                        if (dice != 6)
                        {
                            turn = 3;
                        }
                    }
                }
                else if (turn == 3)
                {
                    text.setString("Red's turn"); 
                    dice = roll_dice(font);
                    //if red is at home -> if dice is at 6 -> move red out of home and let red take another turn when the loop runs again 
                    //else -> its green's turn
                    if (check_red_athome(red))
                    {
                        if (dice == 6)
                        {
                            initial_red_jump(red, dice);
                        }
                        else
                        {
                            turn = 4;
                        }
                    }
                    //if red is not at home -> move red -> if red captures a piece then move the piece to it's home
                    //if red got a 6 then let it take another turn when the loop runs again else its green's turn
                    else if (!check_red_athome(red))
                    {
                        red_movement(red, dice,font);
                        if (green.getPosition() == red.getPosition() && !at_stop(green))
                        {
                            green.setPosition(Vector2f(GREEN_INITIAL_X, GREEN_INITIAL_Y));
                            green_currentpos = 0;
                            continue;
                        }

                        if (red.getPosition() == yellow.getPosition() && !at_stop(yellow))
                        {
                            yellow.setPosition(Vector2f(YELLOW_INITIAL_X, YELLOW_INITIAL_Y));
                            yellow_currentpos = 0;
                            continue;
                        }

                        if (red.getPosition() == blue.getPosition() && !at_stop(blue))
                        {
                            blue.setPosition(Vector2f(BLUE_INITIAL_X, BLUE_INITIAL_Y));
                            blue_currentpos = 0;
                            continue;
                        }

                        if (dice != 6)
                        {
                            turn = 4;
                        }
                    }
                    }

                else if (turn == 4)
                {
                    text.setString("Green's turn");
                    dice = roll_dice(font);
                    //if green is at home -> if dice is at 6 -> move green out of home and let green take another turn when the loop runs again 
                    //else -> its yellow's turn
                    if (check_green_athome(green))
                    {
                        if (dice == 6)
                        {
                            initial_green_jump(green, dice);
                        }
                        else
                        {
                            turn = 1;
                        }
                    }
                    //if green is not at home -> move green -> if green captures a piece then move the piece to it's home
                    //if green got a 6 then let it take another turn when the loop runs again else its yellow's turn
                    else if (!check_green_athome(green))
                    {
                        green_movement(green, dice,font);
                        if (green.getPosition() == blue.getPosition() && !at_stop(blue))
                        {
                            blue.setPosition(Vector2f(BLUE_INITIAL_X, BLUE_INITIAL_Y));
                            blue_currentpos = 0;
                            continue;
                        }

                        if (green.getPosition() == red.getPosition() && !at_stop(red))
                        {
                            red.setPosition(Vector2f(RED_INITIAL_X, RED_INITIAL_Y));
                            red_currentpos = 0;
                            continue;
                        }

                        if (green.getPosition() == yellow.getPosition() && !at_stop(yellow))
                        {
                            yellow.setPosition(Vector2f(YELLOW_INITIAL_X, YELLOW_INITIAL_Y));
                            yellow_currentpos = 0;
                            continue;
                        }

                        if (dice != 6)
                        {
                            turn = 1;
                        }
                    }
                }
                
            }

        }



        //clear everything before so that the screen doesn't show 2 green pieces etc
        game.clear();

        //DRAW EVERYTHING ON THE SCREEN
        game.draw(text_value_dice);
        game.draw(text_dice);
        game.draw(text2);
        game.draw(text);
        game.draw(victory);
        game.draw(board);
        game.draw(home_red);
        game.draw(home_blue);
        game.draw(home_yellow);
        game.draw(home_green);
        game.draw(vic);
        game.draw(dice_piece);
        game.draw(red_spot);
        game.draw(yellow_spot);
        game.draw(blue_spot);
        game.draw(green_spot);
        game.draw(vicB);
        game.draw(vicR);
        game.draw(vicY);
        game.draw(vicG);

        //drawing stop signs
        RectangleShape stop_spot1(Vector2f(250 / 6.0, 100 / 3.0));
        stop_spot1.setPosition(Vector2f(stops_x[0] - 10, stops_y[0] - 3));
        stop_spot1.setFillColor(Color::Color(0, 0, 125, 255));
        game.draw(stop_spot1);

        RectangleShape stop_spot2(Vector2f(100 / 3.0, 250 / 6.0));
        stop_spot2.setPosition(Vector2f(stops_x[1] - 5, stops_y[1] - 11));
        stop_spot2.setFillColor(Color::Color(128, 128, 128, 255));
        game.draw(stop_spot2);

        RectangleShape stop_spot3(Vector2f(100 / 3.0, 250 / 6.0));
        stop_spot3.setPosition(Vector2f(stops_x[2] - 6, stops_y[2] - 12));
        stop_spot3.setFillColor(Color::Color(150, 0, 0, 255));
        game.draw(stop_spot3);

        RectangleShape stop_spot4(Vector2f(250 / 6.0, 100 / 3.0));
        stop_spot4.setPosition(Vector2f(stops_x[3] - 13.5, stops_y[3] - 3));
        stop_spot4.setFillColor(Color::Color(128, 128, 128, 255));
        game.draw(stop_spot4);

        RectangleShape stop_spot5(Vector2f(250 / 6.0, 100 / 3.0));
        stop_spot5.setPosition(Vector2f(stops_x[4] - 13.5, stops_y[4] - 4));
        stop_spot5.setFillColor(Color::Color(0, 100, 0, 255));
        game.draw(stop_spot5);

        RectangleShape stop_spot6(Vector2f(100 / 3.0, 250 / 6.0));
        stop_spot6.setPosition(Vector2f(stops_x[5] - 6, stops_y[5] - 12));
        stop_spot6.setFillColor(Color::Color(128, 128, 128, 255));
        game.draw(stop_spot6);

        RectangleShape stop_spot7(Vector2f(100 / 3.0, 250 / 6.0));
        stop_spot7.setPosition(Vector2f(stops_x[6] - 5, stops_y[6] - 12));
        stop_spot7.setFillColor(Color::Color(230, 230, 0, 255));
        game.draw(stop_spot7);

        RectangleShape stop_spot8(Vector2f(250 / 6.0, 100 / 3.0));
        stop_spot8.setPosition(Vector2f(stops_x[7] - 13.5, stops_y[7] - 5));
        stop_spot8.setFillColor(Color::Color(128, 128, 128, 255));
        game.draw(stop_spot8);

        //marking the final 6 spots of each piece
        RectangleShape blue_final(Vector2f(5 * 250 / 6.0, 100 / 3.0));
        blue_final.setPosition(Vector2f(250 / 6.0, 250 + 100 / 3.0));
        blue_final.setFillColor(Color::Color(0, 0, 125, 255));
        game.draw(blue_final);

        RectangleShape red_final(Vector2f(100 / 3.0, 5 * 250 / 6.0));
        red_final.setPosition(Vector2f(250 + 100 / 3.0, 250 / 6.0));
        red_final.setFillColor(Color::Color(150, 0, 0, 255));
        game.draw(red_final);

        RectangleShape green_final(Vector2f(5.2 * 250 / 6.0, 100 / 3.0));
        green_final.setPosition(Vector2f(300 + 250 / 6.0, 250 + 100 / 3.0));
        green_final.setFillColor(Color::Color(0, 100, 0, 255));
        game.draw(green_final);

        RectangleShape yellow_final(Vector2f(100 / 3.0, 5.2 * 250 / 6.0));
        yellow_final.setPosition(Vector2f((250 + 100 / 3.0) - 0.5, 300 + 250 / 6.0));
        yellow_final.setFillColor(Color::Color(230, 230, 0, 255));
        game.draw(yellow_final);

        //marking major lines on the board
        //major in x 
        double x_increment = 100 / 3.0;
        for (int x = 250; x <= 350; x += x_increment)
        {
            Vertex line1[2] = { Vertex(Vector2f(x,0),Color::Black),Vertex(Vector2f(x,250),Color::Black) };
            Vertex line2[2] = { Vertex(Vector2f(x,350),Color::Black),Vertex(Vector2f(x,600),Color::Black) };
            game.draw(line1, 2, Lines);
            game.draw(line2, 2, Lines);
        }
        //major in y
        double y_increment = 100 / 3.0;
        for (int y = 250; y <= 350; y += y_increment)
        {
            Vertex line1[2] = { Vertex(Vector2f(0,y),Color::Black),Vertex(Vector2f(250,y),Color::Black) };
            Vertex line2[2] = { Vertex(Vector2f(350,y),Color::Black),Vertex(Vector2f(600,y),Color::Black) };
            game.draw(line1, 2, Lines);
            game.draw(line2, 2, Lines);
        }

        //marking the minor lines on the board
        double increment_x = 250 / 6.0;
        double increment_y = 250 / 6.0;

        //vertical
        for (double x = 0; x <= 250; x += increment_x)
        {
            Vertex line[2] = { Vertex(Vector2f(x,250),Color::Black),Vertex(Vector2f(x,350),Color::Black) };
            game.draw(line, 2, Lines);
        }
        for (double x = 350; x <= 600; x += increment_x)
        {
            Vertex line[2] = { Vertex(Vector2f(x,250),Color::Black),Vertex(Vector2f(x,350),Color::Black) };
            game.draw(line, 2, Lines);
        }

        //horizontal
        for (double y = 0; y <= 250; y += increment_y)
        {
            Vertex line[2] = { Vertex(Vector2f(250,y),Color::Black),Vertex(Vector2f(350,y),Color::Black) };
            game.draw(line, 2, Lines);
        }
        for (double y = 350; y <= 600; y += increment_y)
        {
            Vertex line[2] = { Vertex(Vector2f(250,y),Color::Black),Vertex(Vector2f(350,y),Color::Black) };
            game.draw(line, 2, Lines);
        }

        //drawing the pieces
        game.draw(blue);
        game.draw(green);
        game.draw(red);
        game.draw(yellow);

        game.display();
    }
    return 0;
}