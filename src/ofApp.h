#pragma once

#include "ofMain.h"
#include "Player.hpp"
#include "Ground.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
		enum States { Title, Info, Game, GameOver };
  
		void ChangeColor(char type, ofColor color);
  
		Player qwerty = Player(1);
		Player azerty = Player(2);
		Ground ground = Ground();
		
		string keyPress;
		
		ofVec2f stringPos = qwerty.GetPos();
		
//		string submittedPress;
		
		/* Global Colors */

  
		
		
};
