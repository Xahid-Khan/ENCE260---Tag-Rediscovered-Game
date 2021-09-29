#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

/*Returns as boolean whether a tag has occured, takes the player positionand the enemy positions*/
bool Tag(Position_t* enemy, Position_t player);

/*Returns as boolean whether a new enemy spawn position is occupied, takes the new position, 
the enemy positions and the player positions*/
bool checkPosition(Position_t new, Position_t* enemy, Position_t player);

/*Show gameover message and play sound*/
void gameOver();

#endif
