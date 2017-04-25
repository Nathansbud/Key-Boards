//
//  Player.cpp
//  KeyloggerProject
//
//  Created by Zack Amiton on 3/29/17.
//
//

#include "Player.hpp"

int poisonDuration = 300; //5 Secs


Player::Player(int player, int hp, float dmg)
{
  _player = player;
  SetPos();
  SetStats(hp, dmg);
  p1.load("images/Qwerty.png");
  p2.load("images/Azerty.png");
  
  _statusFlags = 0;
  _poisoned = false;
  _stunned = false;
  _burning = false;
  
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
   HP = to_string(GetHP());
   CheckStatusEffects();
}

void Player::ChangeHP(int amount)
{
  _hp += amount;
}

void Player::CheckStatusEffects()
{
//  static int ticks = 300;
  if(isPoisoned())
	
	ChangeHP(-5);
  if(isBurning())
	ChangeHP(-2);
}


void Player::SetStats(int hp, float dmg)
{
  _hp = hp;
  _damage = dmg;
}

bool Player::isPoisoned()
{
  if(_statusFlags & Poisoned)
  {
	return true;
  } else
  {
	return false;
  }
}

bool Player::isStunned()
{
  if(_statusFlags & Stunned)
  {
	return true;
  } else
  {
	return false;
  }
}

bool Player::isBleeding()
{
  if(_statusFlags & Bleeding)
  {
	return true;
  } else
  {
	return false;
  }
}

bool Player::isBurning()
{
  if(_statusFlags & Burning)
  {
	return true;
  } else
  {
	return false;
  }
}

void Player::SetEffects(StatusEffects effects)
{
  _statusFlags |= effects;
}

void Player::RemoveEffects(StatusEffects effects)
{
  _statusFlags &= ~effects;
}

