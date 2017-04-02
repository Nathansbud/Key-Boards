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
  SetPos();
  p1.load("images/Qwerty.png");
  p2.load("images/Azerty.png");
}

void Player::SetPos()
{
  _playerPos.y = ofGetHeight()*5/9;
  if(_player == 1)
	_playerPos.x = ofGetWidth()*0.07;
  else if(_player == 2)
	_playerPos.x = ofGetWidth() * 0.8;
}

void Player::Draw()
{
  ofNoFill();
  if(_player == 1)
	p1.draw(GetPos());
  if(_player == 2)
	p2.draw(GetPos());
}

Player::~Player()
{

}

void Player::Update()
{
  
}



void Player::SetStats(int hp, float damage, int money)
{
  _hp = hp;
  _damage = damage;
  _money = money;
}
