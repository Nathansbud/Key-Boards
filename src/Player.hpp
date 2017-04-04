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
	
	int GetHP() {return _hp;}
	float GetDMG() {return _damage;}
	float GetMoney() {return _money;}
	ofVec2f GetPos() {return _playerPos;}
	void ChangeHP(int amount);
	void SetHP(int amount) {_hp = amount;}
	string HP;
	
	

//	enum StatusEffects {Burn, Shield, Poison, Daze, Paralyze};
	
  private:
	void SetPos();
	void SetStats(int hp, float damage, int money);
	int _hp = 150;
	float _damage; //Use?
	int _money; //Offline mode/upgrades?
	int _player; //Player #
	ofImage p1, p2; //Qwerty/Azerty Images
	ofVec2f _playerPos; //...duh

};

#endif /* Player_hpp */
