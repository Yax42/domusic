//
// Sound.hh for src in /home/brunie_j/local/my/domusic/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Tue May 14 18:45:46 2013 Brunier Jean
// Last update Wed May 15 08:55:21 2013 Brunier Jean
//

#ifndef SOUND_HH_
# define SOUND_HH_

# include <fmod.h>

# define NB_STYLE	1
# define NB_OCTAVE	5
# define NB_NOTE	12
# define MAX_CHANELS	(NB_OCTAVE * NB_NOTE * NB_STYLE)

class Sound
{
public:
  enum
  {
    DO,
    DO_D,
    RE,
    RE_D,
    MI,
    FA,
    FA_D,
    SOL,
    SOL_D,
    LA,
    LA_D,
    SI,
    COUNT,
  };

  ~Sound();
  Sound();
  void			pause(int style, int octave, int note);
  void			unpause(int style, int octave, int note);
  void			clean();
  static int		noteFromId(int note);
private:
  FMOD_SYSTEM		*_system;
  FMOD_SOUND		*_notes[NB_STYLE][NB_OCTAVE][NB_NOTE];
  FMOD_CHANNEL		*_chan[NB_STYLE][NB_OCTAVE][NB_NOTE];
};

#endif /* !SOUND_HH_ */
