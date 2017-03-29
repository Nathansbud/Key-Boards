//
//  Player.hpp
//  KeyloggerProject
//
//  Created by Zack Amiton on 3/29/17.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "ofMain.h"

class Player
{
  public:
	Player(int player);
	~Player();
	void Update();
	void Draw();
	void InflictStatusEffect();
	int CheckHP() {return _health};
	float CheckDamage() {return _damage};
	float CheckMoney() {return _money};
	enum StatusEffects {Burn, Shield, Poison, Daze, Paralyze}
	
  private:
	int _health;
	float _damage;
	int _money;
	int _player;
	ofImage p1, p2;
	ofVec2f _playerPos;

};

#endif /* Player_hpp */
