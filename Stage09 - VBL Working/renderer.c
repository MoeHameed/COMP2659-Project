/**
Name: Don Hagen, Mohammad Hameed
Course: COMP 2659
Due Date: 15/04/2016
Instructor: ppospisil
*/
#include <osbind.h>

#include "renderer.h"

void init_render(UINT8 *base) {
}

/*
Given a pointer the model, 
renders all the ships, score, and clears the screen
*/
void render_model(struct Model *modelPtr, UINT8 *base, UINT8 has_moved) {
	int i = 0;
	
	long *base2 = (long *)base;
	clear_screen(base2);
	render_line(base);

	render_ship(modelPtr, base, 1, 0);

	for(i = 0; i <= NUM_ENEMIES; i++){
		render_ship(modelPtr, base, 0, i);

	}
	
	render_score(modelPtr, base);
	
}

/* 
gievn a ship and the model, 
renders the ship to the screen
*/
void render_ship(struct Model *modelPtr, UINT8 *base, UINT8 ship, UINT16 ship_num) {
	UINT16 ship_posX;
	UINT16 ship_posY;

	if(ship) {
		ship_posX = get_player_posX(modelPtr, ship_num);
		ship_posY = get_player_posY(modelPtr, ship_num);

		plot_bitmap_64_byte(base, ship_posX, ship_posY, p1_ship, SHIP_HEIGHT);

		
	}
	else {
		ship_posX = get_enemy_posX(modelPtr, ship_num);
		ship_posY = get_enemy_posY(modelPtr, ship_num);

		plot_bitmap_64_byte(base, ship_posX, ship_posY, en_ship, SHIP_HEIGHT);

	}

}

/* 
renders a single horizontal line
*/
void render_line(UINT8 *base) {
	print_line(base,0,344,640,344);
}

/* 
given a pointer to the model,
renders the score to the screen
*/
void render_score(struct Model *modelPtr, UINT8 *base) {
	UINT16 score = get_score(modelPtr);
	
	print_clr_num(base, 590, 370);
	print_num(base, 590, 370, score);
	
}