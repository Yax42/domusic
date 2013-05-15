//
// help.cpp for src in /home/brunie_j/local/my/domusic/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue May 14 19:26:56 2013 Brunier Jean
// Last update Tue May 14 19:27:05 2013 Brunier Jean
//

  FMOD_SYSTEM		*system;
  FMOD_SOUND		*sound[MAX_CHANELS];

  FMOD_RESULT FMOD_System_Create(FMOD_SYSTEM &system);
  FMOD_System_Init(system, MAX_CHANELS, FMOD_INIT_NORMAL, NULL);

  FMOD_System_CreateSound(system, "pan.wav", FMOD_CREATESAMPLE | FMOD_LOOP_NORMAL, 0, &sound[0]);
  FMOD_System_PlaySound(system, 0, sound[0], 0, NULL);
  FMOD_Sound_SetLoopCount(sound[0], -1);
  FMOD_Channel_SetPaused(canal, etat); //switch le pause
  FMOD_Channel_GetPaused(canal, etat);
  FMOD_Sound_Release(sound[0]);


  FMOD_System_Close(system);
  FMOD_System_Release(system);
