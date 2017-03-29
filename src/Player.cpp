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
 _playerPos.y = ofGetHeight() * 5/9;
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
  if(_player == 1)
	p1.draw(ofGetWidth() * 0.07, _playerPos.y);
  else if(_player == 2)
	p2.draw(ofGetWidth() * 0.8, _playerPos.y);
}
