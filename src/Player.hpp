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
	Player(int player, int hp, float damage);
	~Player();
	void Update();
	void Draw();
	void InflictStatusEffect();
	
	bool isPoisoned();
	bool isStunned();
	bool isBurning();
	bool isBleeding();
	
	void CheckStatusEffects();
	
	int GetHP() {return _hp;}
	float GetDMG() {return _damage;}
	float GetMoney() {return _money;}
	ofVec2f GetPos() {return _playerPos;}
	void ChangeHP(int amount);
	int GetEffects() {return _statusFlags;}
	string HP;
	
	enum StatusEffects
	{
	  Poisoned = 1 << 0,
	  Stunned = 1 << 1,
	  Burning = 1 << 2,
	  Bleeding = 1 << 3
	};
	
	void SetEffects(StatusEffects effects);
	void RemoveEffects(StatusEffects effects);
		
  private:
	void SetPos();
	void SetStats(int hp, float damage);
	
	int _statusFlags;
	int _hp = 150;
	float _damage; //Use?
	int _money; //Offline mode/upgrades?
	int _player; //Player #
	ofImage p1, p2; //Qwerty/Azerty Images
	ofVec2f _playerPos; //...duh
	bool _poisoned;
	bool _burning;
	bool _stunned;
	void SetHP(int amount) {_hp = amount;}
};

#endif /* Player_hpp */
