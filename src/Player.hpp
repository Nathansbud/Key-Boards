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
#include "ofApp.h"
//#include "ofMain.h"

class Player
{
  public:
	Player(int player);
	~Player();
	void Update();
	void Draw();
  private:
	int _health;
	int _damage;
	int _money;
	int _player;
	ofImage p1, p2;
};

#endif /* Player_hpp */
