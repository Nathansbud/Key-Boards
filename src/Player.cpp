//
//  Player.cpp
//  KeyloggerProject
//
//  Created by Zack Amiton on 3/29/17.
//
//

#include "Player.hpp"

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
	p1.draw(GetPos()); //240, 240)
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
  static int poisonTicks;
  static int burnTicks;
  static int stunTicks;
  static int poisonDur;
  static int burnDur;
  static int stunDur;
  
  if(isPoisoned())
  {
	if(poisonTicks == 0)
	{
	  poisonDur = _effectDuration;
	}

	if(ofGetElapsedTimef() - poisonTimer >= 5)
	{
	  ChangeHP(-5);
	  poisonTimer = ofGetElapsedTimef();
	  poisonTicks++;
	}
	
	if(poisonTicks == poisonDur)
	{
	  RemoveEffects(Poisoned);
	  poisonTicks = 0;
	}
  }
  
  if(isBurning())
  {
	if(burnTicks == 0)
	{
	  burnDur = _effectDuration;
	}
	
	if(ofGetElapsedTimef() - burnTimer >= 2)
	{
	  ChangeHP(-2);
	  burnTimer = ofGetElapsedTimef();
	  burnTicks++;
	} else if(burnTicks == burnDur)
	{
	  RemoveEffects(Burning);
	  burnTicks = 0;
	}
  }
  
  if(isStunned())
  {
	
	if(stunTicks == 0)
	{
	  stunDur = _effectDuration;
	}
	
	if(ofGetElapsedTimef() - stunTimer >= 2)
	{
	  stunTimer = ofGetElapsedTimef();
	  stunTicks++;
	} else if(stunTicks == stunDur)
	{
	  RemoveEffects(Stunned);
	  stunTicks = 0;
	}
  }
}

void Player::SetStats(int hp, float dmg)
{
  _hp = hp;
  _damage = dmg;
}

bool Player::isPoisoned()
{
  return _statusFlags & Poisoned ? 1 : 0;
}

bool Player::isStunned()
{
  return _statusFlags & Stunned ? 1 : 0;
}

bool Player::isBleeding()
{
  return _statusFlags & Bleeding ? 1 : 0;
}

bool Player::isBurning()
{
  return _statusFlags & Burning ? 1 : 0;
}

void Player::SetEffects(StatusEffects effects, int duration)
{
//  if(statusFlags & effects)
//  {
//	_effectDuration += duration;
//  } else
//  {
	_statusFlags |= effects;
	_effectDuration = duration;
//  }
}

void Player::RemoveEffects(StatusEffects effects)
{
  _statusFlags &= ~effects;
}

void Player::Restart()
{
  _hp = 100;
  _statusFlags = 0;
  _poisoned = false;
  _stunned = false;
  _burning = false;
}

