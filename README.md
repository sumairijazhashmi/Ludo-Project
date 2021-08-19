# Ludo-Project
Ludo game made using SFML library.
For my CS 100 Project, I made a Ludo game using the sfml graphics library.
There are 4 players, and each player has a single piece.
Where to find the code
Please find the main.cpp file in the following folder Ludo_24100004\code
The project was made in Visual Studio 2019. The solution (.sln) file is in the following folder
Ludo_24100004\Ludo.sln
The executable file is in the following folder executable\Ludo_sumair.exe
Ludo Rules:

- A player can only bring their piece out from their home if they get a 6
- A player takes another turn if they get a 6
- A player takes another turn if they capture someone’s piece
- If a player captures a piece, and gets a 6, they will get only one more turn
- A player can get as many sixes as they can. There is no max 3 sixes rule.
- A piece can only be captured if it is at none of the stop signs
- A player can only move into the victory point if its dice value exactly matches the
number of blocks it is away from the victory point
- If a player gets a 6 and then another number which is equal to the steps required to win
then the 6 will be disregarded and the person will win the game. For example, if red
needs a 3 to win and they get a 6 and a 3 then the 6 will be ignored.
- The game ends when any one player wins
