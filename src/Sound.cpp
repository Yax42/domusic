//
// Sound.cpp for src in /home/brunie_j/local/my/domusic/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue May 14 18:41:37 2013 Brunier Jean
// Last update Wed May 15 10:21:09 2013 Brunier Jean
//

#include <sstream>
#include <iostream>

#include "Sound.hh"

Sound::~Sound()
{
  for (int i = 0; i < NB_STYLE; i++)
    for (int j = 0; j < NB_OCTAVE; j++)
      for (int k = 0; k < NB_NOTE; k++)
      FMOD_Sound_Release(_notes[i][j][k]);
  FMOD_System_Close(_system);
  FMOD_System_Release(_system);
}

Sound::Sound()
{

  FMOD_System_Create(&_system);
  FMOD_System_Init(_system, MAX_CHANELS, FMOD_INIT_NORMAL, NULL);
  for (int i = 0; i < NB_STYLE; i++)
    for (int j = 0; j < NB_OCTAVE; j++)
      for (int k = 0; k < NB_NOTE; k++)
      {
  	std::stringstream	stm;

	stm << "sound/" << i << "/" << j  << "/" << k << ".wav";
	//std::cout << stm.str() << std::endl;
        FMOD_System_CreateSound(
	  _system,
	  stm.str().c_str(),
	  FMOD_CREATESAMPLE | FMOD_LOOP_NORMAL,
	  0,
	  &_notes[i][j][k]);
        FMOD_Sound_SetLoopCount(_notes[i][j][k], -1);
        FMOD_System_PlaySound(_system,
	    FMOD_CHANNEL_FREE,
	    _notes[i][j][k], 0, &_chan[i][j][k]);
	FMOD_Channel_SetVolume(_chan[i][j][k], 0.35);
	pause(i, j, k);
      }
}

void		Sound::pause(int style, int octave, int note)
{
  int		paused;

  FMOD_Channel_GetPaused(_chan[style][octave][note], &paused);
  if (!paused)
    FMOD_Channel_SetPaused(_chan[style][octave][note], 1);
}

void		Sound::unpause(int style, int octave, int note)
{
  int		paused;

  FMOD_Channel_GetPaused(_chan[style][octave][note], &paused);
  if (paused)
    FMOD_Channel_SetPaused(_chan[style][octave][note], 0);
}

void		Sound::clean()
{
  for (int i = 0; i < NB_STYLE; i++)
    for (int j = 0; j < NB_OCTAVE; j++)
      for (int k = 0; k < NB_NOTE; k++)
	pause(i, j, k);
}

int		Sound::noteFromId(int note)
{
  switch (note)
    {
      case (0):
	return (DO);
        break;
      case (1):
	return (RE);
        break;
      case (2):
	return (MI);
        break;
      case (3):
	return (FA);
        break;
      case (4):
	return (SOL);
        break;
      case (5):
	return (LA);
        break;
      case (6):
	return (SI);
        break;
    }
  return (DO);
}
