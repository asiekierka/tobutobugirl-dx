#ifndef WIN_BASE_DX_MAP_H
#define WIN_BASE_DX_MAP_H
#define win_base_dx_data_length 24U
#define win_base_dx_tiles_width 20U
#define win_base_dx_tiles_height 18U
#define win_base_dx_tiles_offset 40U
const unsigned char win_base_dx_data[] = {
	255,   0, 231,   0, 195,   0, 129,   0, 129,   0, 195,   0, 231,   0, 255,   0,
    255,  63, 192, 127, 128, 255, 128, 255, 128, 255, 128, 255, 128, 255, 128, 255,
    255,   3,   0,   0,  14, 255, 252,   3, 254,   1, 255,   1, 255,   1, 255,   1,
    255,   1, 255,   1, 255, 128, 128,  16,   0,   0,  18,  60,  60,   2, 102, 102,
      2,  96,  96,   4, 102, 102,   2,  60,  60,   2,   0,   0,   4,  96,  96,  10,
    126, 126,   2,   0,   0,   4, 126, 126,   2,  96,  96,   2, 124, 124,   2,  96,
     96,   4, 126, 126,   2,   0,   0,   4,  60,  60,   2, 102, 102,   4, 126, 126,
      4, 102, 102,   2,   0,   0,   4, 124, 124,   2, 102, 102,   4, 124, 124,   2,
    102, 102,   4,   0,   0,   2,   1,   1,  16, 255, 128,   0,   0,  14, 255,   0,
      0,  15, 255,   1,   0,   0,  16, 126, 126,   2,  24,  24,  10,   0,   0,   4,
     24,  24,  12,   0,   0,   4,  98,  98,   2, 118, 118,   2, 126, 126,   4, 106,
    106,   2,  98,  98,   2,   0,   0,   6,   8,   8,   4,  62,  62,   2,   8,   8,
      4,   0,   0,  16, 255,   0,   0,   3,  60,  60,   2, 102, 102,   2, 120, 120,
      2,  30,  30,   2, 102, 102,   2,  60,  60,   2,   0,   0,   4,  60,  60,   2,
    102, 102,   8,  60,  60,   2,   0,   0,   4, 124, 124,   2, 102, 102,   4, 124,
    124,   2,  96,  96,   4,   0,   0,  16, 255, 255,   2
};
const unsigned char win_base_dx_tiles[] = {
	 40,  40,   3,  41,  42,  42,  12,  43,  40,  40,   6,  44,  45,  45,   7,  46,  47,  48,  49,  50,
     51,  40,  40,   6,  44,  45,  45,  12,  51,  40,  40,   3,  42,  42,   3,  52,  53,  53,  12,  54,
     42,  42,   3,  45,  55,  56,  57,  48,  45,  45,  37,  58,  45,  45,  18,  59,  59,   7,  45,  45,
     33,  60,  55,  61,  57,  62,  60,  45,  45,  35,  58,  45,  45,  18,  59,  59,   7,  45,  45,  33,
     55,  61,  55,  49,  47,  45,  45,  34,  63,  63,  20,  40,  40,  20
};
#define win_base_dx_palette_data_length 2U
#define win_base_dx_palette_offset 0U
const unsigned char win_base_dx_palettes[] = {
      1,   1,   4,   0,   0,  12,   1,   1,   7,   0,   0,  14,   1,   1,   6,   0,   0,  14,   1,   1,
      3,   0,   0, 255,   0,   0,  25,   1,   1,  20
};

const unsigned int win_base_dx_palette_data[] = {
    32767, 20083, 14798,   0,
    23911, 14531, 32767,   0
};
#endif
