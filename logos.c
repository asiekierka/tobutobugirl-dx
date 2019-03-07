#include <gb/gb.h>
#include "defines.h"
#include "gamestate.h"
#include "fade.h"
#include "logos.h"
#include "sound.h"
#include "mmlgb/driver/music.h"

#include "data/bg/tangram.h"
#include "data/bg/potato.h"
#include "data/sprite/shine.h"

extern UBYTE tangram_shine_song_data;
extern UBYTE tangram_vox_song_data;
extern UBYTE potato_jingle_song_data;

const UWORD tangram_flash_palette[4] = {
    32767, 32767, 32767, 32767
};

void initLogos() {
	disable_interrupts();
	DISPLAY_OFF;

	OBP0_REG = 0xD0U; // 11010000
	BGP_REG = 0xE4U; // 11100100

	HIDE_WIN;
	SHOW_SPRITES;
	SHOW_BKG;
	SPRITES_8x16;

	set_bkg_data_rle(0U, tangram_data_length, tangram_data);
	set_bkg_tiles_rle(0U, 0U, tangram_tiles_width, tangram_tiles_height, tangram_tiles);

    if(CGB_MODE) {
        set_sprite_palette(0U, 1U, tangram_flash_palette);
        set_bkg_palette_buffer(0U, tangram_palette_data_length, tangram_palette_data);
        VBK_REG = 1U;
        set_bkg_tiles_rle(0U, 0U, tangram_tiles_width, tangram_tiles_height, tangram_palettes);
        VBK_REG = 0U;
    }

	set_sprite_data(0U, shine_data_length, shine_data);

	DISPLAY_ON;
	enable_interrupts();
}

void enterLogos() {
	UBYTE i;

	initLogos();

	fadeFromWhite(8U);

	for(i = 0U; i != 8U; ++i) wait_vbl_done();

	setMusicBank(SONG_BANK_TANGRAM_VOX);
	disable_interrupts();
	playMusic(&tangram_vox_song_data);
	enable_interrupts();

	for(i = 0U; i != 60U; ++i) wait_vbl_done();
	stopMusic();

	setMusicBank(SONG_BANK_TANGRAM_SHINE);
	disable_interrupts();
	playMusic(&tangram_shine_song_data);
	enable_interrupts();

	for(i = 10U; i != 142U; i += 6U) {
		if(i < 64U) {
			setSprite(i+8U, 80U, 0U, OBJ_PAL0);
			setSprite(i+16U, 80U, 2U, OBJ_PAL0);
			setSprite(i+24U, 80U, 4U, OBJ_PAL0);
		} else {
			setSprite(i+4U, 88U, 0U, OBJ_PAL0);
			setSprite(i+12U, 88U, 2U, OBJ_PAL0);
			setSprite(i+20U, 88U, 4U, OBJ_PAL0);
		}

		setSprite(i, 96U, 0U, OBJ_PAL0);
		setSprite(i+8U, 96U, 2U, OBJ_PAL0);
		setSprite(i+16U, 96U, 4U, OBJ_PAL0);

		clearRemainingSprites();
		snd_update();
		wait_vbl_done();
	}

	clearRemainingSprites();

	while(!mus_is_done()) {
		wait_vbl_done();
	}

	stopMusic();
    fadeToWhite(8U);

	disable_interrupts();
	DISPLAY_OFF;
	set_bkg_data_rle(0U, potato_data_length, potato_data);
	set_bkg_tiles_rle(0U, 0U, potato_tiles_width, potato_tiles_height, potato_tiles);
    if(CGB_MODE) {
        for(i = 0U; i != 8U; ++i) {
            set_bkg_palette_buffer(i, 1U, gs_palette);
        }
    }

	DISPLAY_ON;
	enable_interrupts();

    BGP_REG = 0xE4U;
	fadeFromWhite(8U);

	disable_interrupts();

	for(i = 0U; i != 10U; ++i) wait_vbl_done();

	disable_interrupts();
	setMusicBank(SONG_BANK_POTATO_JINGLE);
	playMusic(&potato_jingle_song_data);
	enable_interrupts();

	while(!mus_is_done()) {
		wait_vbl_done();
	}

	stopMusic();
    fadeToWhite(8U);

	gamestate = GAMESTATE_INTRO;
}
