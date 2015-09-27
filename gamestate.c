#include <gb/gb.h>
#include "defines.h"
#include "music.h"

#include "gamestate.h"

UBYTE ticks;
UBYTE gamestate, level, selection;
UBYTE joystate, oldjoystate;
UBYTE next_sprite, sprites_used;
UBYTE elapsed_time, remaining_time, kills;
UBYTE last_highscore_level, last_highscore_slot;
UBYTE game_bank, music_bank;
UBYTE levels_completed;

const UBYTE level_names[5][6] = {
	{29U, 13U, 25U, 28U, 15U, 29U},
	{26U, 22U, 11U, 19U, 24U, 29U},
	{13U, 22U, 25U, 31U, 14U, 29U},
	{29U, 26U, 11U, 13U, 15U, 10U},
	{22U, 25U, 13U, 21U, 15U, 14U}
};

void setGameBank(UBYTE i) {
	game_bank = i;
	SWITCH_ROM_MBC1(i);
}

void setMusicBank(UBYTE i) {
	music_bank = i;
}

void playMusic(UBYTE *data) {
	SWITCH_ROM_MBC1(music_bank);
	mus_init(data);
	SWITCH_ROM_MBC1(game_bank);
}

void updateMusic() {
	SWITCH_ROM_MBC1(music_bank);
	mus_update();
	SWITCH_ROM_MBC1(game_bank);
}

void stopMusic() {
	mus_setPaused(1U);
}

void clearSprites() {
	UBYTE i;
	for(i = 0U; i < 40U; ++i) move_sprite(i, 0U, 0U);
	sprites_used = 0U;
	next_sprite = 0U;
}

void updateJoystate() {
	oldjoystate = joystate;
	joystate = joypad();
}

void setSprite(UBYTE x, UBYTE y, UBYTE tile, UBYTE prop) {
	move_sprite(next_sprite, x, y);
	set_sprite_tile(next_sprite, tile);
	set_sprite_prop(next_sprite, prop);

	sprites_used++;
	next_sprite++;
	if(next_sprite == 40U) next_sprite = 0U;
}

void clearRemainingSprites() {
	for(; sprites_used != 40U; ++sprites_used) {
		move_sprite(next_sprite++, 0, 0);
		if(next_sprite == 40U) next_sprite = 0U;
	}
	sprites_used = 0U;
}

void set_bkg_data_rle(UBYTE first, UBYTE n, UBYTE *data) {
	UBYTE i, j, run, tile;
	UBYTE block[16];

	run = 0U;
	for(i = first; i != first+n; ++i) {
		for(j = 0U; j != 16U; ++j) {
			if(run == 0U) {
				tile = data[0];
				if(data[0] == data[1]) {
					run = data[2];
					data += 3U;
				} else {
					run = 1U;
					data++;
				}
			}
			block[j] = tile;
			run--;
		}
		set_bkg_data(i, 1U, block);
	}
}

void set_bkg_tiles_rle(UBYTE x, UBYTE y, UBYTE width, UBYTE height, UBYTE *tiles) {
	UBYTE ix, iy, run, tile;
	run = 0U;
	for(iy = y; iy != y+height; ++iy) {
		for(ix = x; ix != x+width; ++ix) {
			if(run == 0U) {
				tile = tiles[0];
				if(tiles[0] == tiles[1]) {
					run = tiles[2];
					tiles += 3U;
				} else {
					run = 1U;
					tiles++;
				}
			}
			set_bkg_tiles(ix, iy, 1U, 1U, &tile);
			run--;
		}
	}
}
