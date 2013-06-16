/*
** main.cpp for Bomberman in /home/benj/Projets/tek2/cpp/bomberman
** 
** Made by benjamin deroche
** Login   <deroch_b@epitech.net>
** 
** Started on  Mon Feb 11 12:38:07 2013 benjamin deroche
** Last update Sun Feb 23 19:25:42 2013 benjamin deroche
*/

#include	"Camera.hh"

Camera::Camera() : _position(0.0f, 0.0f, 2500.0f), _rotation(0.0f, 0.0f, 0.0f), _barycentre(0.0f, 0.0f, 0.0f)
{

}

void		Camera::initialize()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 800.0f/600.0f, 1.0f, 10000.0f);
  gluLookAt(_position.x, _position.y, _position.z,
	    0.0f, 0.0f, -1.0f,
	    0.0f, 1.0f, 0.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

void		Camera::update(__attribute__((__unused__))gdl::GameClock const & gameClock, gdl::Input & input)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  if (input.isKeyDown(gdl::Keys::Add))
    _position.z += 50.0f;
  if (input.isKeyDown(gdl::Keys::Subtract))
    _position.z -= 50.0f;
  _position.x = _barycentre.x;
  _position.y = _barycentre.y;
  gluLookAt(_position.x, _position.y, _position.z,
	    _barycentre.x, _barycentre.y, _barycentre.z,
  	    0.0f, 1.0f, 0.0f);
}

void		Camera::setBarycentre(float x, float y, float z)
{
  _barycentre.x = x;
  _barycentre.y = y;
  _barycentre.z = z;
 }