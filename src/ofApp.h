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
		
		void EvaluateWord();
		void SendWord();
		
  		enum States {Title, Info, Game, Win, GameOver};
		States state;

  		void SetState(States newState) {state == newState;}
		void InitializeState(States newState);


		Player qwerty = Player(1, 100, 1.0);
		Player azerty = Player(2, 100, 1.0);
		Ground ground = Ground();
		
		string keyPress;
		
		ofVec2f stringPos = qwerty.GetPos();
	
		ofSoundPlayer music[5];
		
		enum Words {Slash, Strike, Fireball, Shield, Stun, Daze, Confuse, Derp, Poison};
		Words word;


//		string submittedPress;
		
		/* Global Colors */

  
		
		
};
