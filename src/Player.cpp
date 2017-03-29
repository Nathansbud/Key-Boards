//
//  Player.cpp
//  KeyloggerProject
//
//  Created by Zack Amiton on 3/29/17.
//
//

#include "Player.hpp"

Player::Player(int player)
{
 _player = player;
  p1.load("images/Qwerty.png");
  p2.load("images/Azerty.png");
}

Player::~Player()
{

}

void Player::Update()
{

}

void Player::Draw()
{
//  if(_player == 1)
	p1.draw(0, 400);
//  else
	p2.draw(700, 400);
}
