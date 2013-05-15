//
// main.cpp for src in /home/brunie_j/local/my/domusic/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue May 14 16:17:51 2013 Brunier Jean
// Last update Wed May 15 14:38:48 2013 Brunier Jean
//

#include <fmod.h>
#include <unistd.h>
#include <iostream>

#include "Sound.hh"
#include "Piano.hh"
#include "Input.hh"

int	main()
{
  SDL_Init(SDL_INIT_VIDEO);
  Input::create();
  Piano		piano(1);
  SDL_Surface	*screen =  SDL_SetVideoMode(1, 1, 32, SDL_NOFRAME);
  SDL_WM_SetCaption("Piano", NULL);
  while(!InputI.isQuit())
  {
    piano.proc();
    InputI.proc();
    //screen->Select();
    usleep(10000);
  }
  Input::destroy(); return (0);
  (void) screen;
  SDL_Quit();
}
