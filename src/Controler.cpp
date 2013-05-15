//
// Controler.cpp for src in /home/brunie_j/local/my/domusic/src
//
// Made by Brunier Jean
// Login   <brunie_j@epitech.net>
//
// Started on  Thu Apr 18 17:34:29 2013 Brunier Jean
// Last update Tue May 14 21:20:03 2013 Brunier Jean
//

#include <cstdio>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <sstream>

#include "Controler.hh"

#define STICK_TO_SPEED(x)	(x >> 5)

#define clean()			{if (_fd != -1)		\
				  close(_fd);		\
				_fd = -1;		\
				_axe.clear();		\
				_but.clear();		\
    				return ;}

Controler::~Controler()
{
  clean();
}

Controler::Controler(int id) : _id(id)
{
  _lastBut = -1;
  _fd = -1;
  update();
  _null = 0;
}

bool	Controler::isOk() const
{
  return (_fd != -1);
}

/***********/
/* PROCESS */
/***********/
void			Controler::update()
{
  char			tmp;
  std::stringstream	stm;

  stm << "/dev/input/js" << _id;
  if (access(stm.str().c_str(), R_OK) == -1)
    clean();
  if (_fd != -1)
    return ;
  _fd = open(stm.str().c_str(), O_RDONLY);
  if (_fd == -1)
    clean();
  ioctl(_fd, JSIOCGAXES, &tmp);
  if (tmp < 6 || tmp > 50)
    clean();
  _axe.resize(tmp);
  ioctl(_fd, JSIOCGBUTTONS, &tmp);
  if (tmp < 8 || tmp > 80)
    clean();
  _but.resize(tmp);
  ioctl(_fd, JSIOCGNAME(sizeof(_name)), &_name);

  fcntl(_fd, F_SETFL, O_NONBLOCK);
  //std::cout << _name << " Axe[" << _axe.size() <<
  //  "] Buttons [" << _but.size() << "]" << std::endl;
}

void	Controler::proc()
{
  if (_fd == -1)
    return ;
  while (read(_fd, &_event, sizeof(_event)) > 0)
    {
      _event.type &= ~JS_EVENT_INIT;
      if (_event.type == JS_EVENT_BUTTON)
        {
	  if (_event.value == 1)
	    _lastBut = _event.number;
 	  _but[_event.number] = _event.value;
        }
      else if (_event.type == JS_EVENT_AXIS)
	  _axe[_event.number] = STICK_TO_SPEED(_event.value);
    }
}

/**********/
/* CONFIG */
/**********/
Key			Controler::getKey()
{
  Key			k;

  for (int i = 0; i < 6; i++)
    k.ptr(i) = &_axe[i];
  for (int i = 0; i < 6; i++)
    k.ptr(i + 6) = &_but[i];
  k.ptr(6) = &_but[2];
  k.ptr(7) = &_but[0];
  k.ptr(8) = &_but[1];
  k.ptr(9) = &_but[3];
  return (k);
}

/***************/
/* LAST BUTTON */
/***************/


int		Controler::getLastBut()
{
  int		tmp = _lastBut;

  _lastBut = -1;
  return (tmp);
}
