//
// Piano.cpp for src in /home/brunie_j/local/my/domusic/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue May 14 21:50:54 2013 Brunier Jean
// Last update Wed May 15 09:09:38 2013 Brunier Jean
//

#include "Piano.hh"
#include "Input.hh"

Piano::~Piano()
{
  delete (_sound);
}

Piano::Piano(int pattern) : _sound(new Sound())
{
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < Sound::COUNT; j++)
      _keys[i][j] = 0;
  if (pattern == 0)
    {
      _keys[0][0] = SDLK_q;
      _keys[0][1] = SDLK_2;
      _keys[0][2] = SDLK_w;
      _keys[0][3] = SDLK_3;
      _keys[0][4] = SDLK_e;
      _keys[0][5] = SDLK_r;
      _keys[0][6] = SDLK_5;
      _keys[0][7] = SDLK_t;
      _keys[0][8] = SDLK_6;
      _keys[0][9] = SDLK_y;
      _keys[0][10] = SDLK_7;
      _keys[0][11] = SDLK_u;

      _keys[1][0] = SDLK_i;
      _keys[1][1] = SDLK_9;
      _keys[1][2] = SDLK_o;
      _keys[1][3] = SDLK_0;
      _keys[1][4] = SDLK_p;
      _keys[1][5] = SDLK_LEFTBRACKET;
      _keys[1][6] = SDLK_EQUALS;
      _keys[1][7] = SDLK_RIGHTBRACKET;
      _keys[1][8] = SDLK_1;
      _keys[1][9] = SDLK_1;
      _keys[1][10] = SDLK_1;
      _keys[1][11] = SDLK_1;

      _keys[2][0] = SDLK_z;
      _keys[2][1] = SDLK_s;
      _keys[2][2] = SDLK_x;
      _keys[2][3] = SDLK_d;
      _keys[2][4] = SDLK_c;
      _keys[2][5] = SDLK_v;
      _keys[2][6] = SDLK_g;
      _keys[2][7] = SDLK_b;
      _keys[2][8] = SDLK_h;
      _keys[2][9] = SDLK_n;
      _keys[2][10] = SDLK_j;
      _keys[2][11] = SDLK_m;

      _keys[3][0] = SDLK_COMMA;
      _keys[3][1] = SDLK_l;
      _keys[3][2] = SDLK_PERIOD;
      _keys[3][3] = SDLK_SEMICOLON;
      _keys[3][4] = SDLK_SLASH;
      /*
      _keys[3][5] = SDLK_v;
      _keys[3][6] = SDLK_g;
      _keys[3][7] = SDLK_b;
      _keys[3][8] = SDLK_h;
      _keys[3][9] = SDLK_n;
      _keys[3][10] = SDLK_j;
      _keys[3][11] = SDLK_m;
      */
    }
  else if (pattern == 1)
    {
      _keys[0][0] = SDLK_a;
      _keys[0][1] = SDLK_w;
      _keys[0][2] = SDLK_s;
      _keys[0][3] = SDLK_e;
      _keys[0][4] = SDLK_d;
      _keys[0][5] = SDLK_f;
      _keys[0][6] = SDLK_t;
      _keys[0][7] = SDLK_g;
      _keys[0][8] = SDLK_y;
      _keys[0][9] = SDLK_h;
      _keys[0][10] = SDLK_u;
      _keys[0][11] = SDLK_j;

      _keys[1][0] = SDLK_k;
      _keys[1][1] = SDLK_o;
      _keys[1][2] = SDLK_l;
      _keys[1][3] = SDLK_p;
      _keys[1][4] = SDLK_SEMICOLON;
      _keys[1][5] = SDLK_QUOTE;
      _keys[1][6] = SDLK_RIGHTBRACKET;
      _keys[1][7] = SDLK_BACKSLASH;
    }
  else if (pattern == 2)
    {
      _keys[0][Sound::DO] = SDLK_a;
      _keys[0][Sound::MI] = SDLK_s;
      _keys[0][Sound::SOL] = SDLK_d;

      _keys[1][Sound::DO] = SDLK_f;
      _keys[1][Sound::MI] = SDLK_g;
      _keys[1][Sound::SOL] = SDLK_h;

      _keys[2][Sound::DO] = SDLK_j;
      _keys[2][Sound::MI] = SDLK_k;
      _keys[2][Sound::SOL] = SDLK_l;

      _keys[3][Sound::DO] = SDLK_SEMICOLON;
      _keys[3][Sound::MI] = SDLK_QUOTE;
      _keys[3][Sound::SOL] = SDLK_BACKSLASH;
    }
}

void	Piano::proc()
{
  _sound->clean();
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < Sound::COUNT; j++)
      if (InputI(_keys[i][j]))
        _sound->unpause(0, i, j);
}
