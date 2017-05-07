#pragma once

#include "ofMain.h"
#include "Player.hpp"
#include "Ground.hpp"
#include "ofxNetwork.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

		void EvaluateWord(int index);
		void SendWord(int index);
		
  		enum States {Title, Info, Game, Win, GameOver};
		States state;

  		void SetState(States newState) {state = newState;}
		void InitializeState(States newState);

		Player qwerty = Player(1, 100, 1.0);
		Player azerty = Player(2, 100, 1.0);

		Player *p1 = &qwerty;
		Player *p2 = &azerty;
		
		
		Ground ground = Ground();
		
		string keyPress;
		string thisWord;
		string ip;
		
		bool wordInMotion();
		
		ofVec2f stringPos = qwerty.GetPos();
	
		ofSoundPlayer music[5];
  
		bool Cooldown(int duration);
  
		void ServerSetup();
		void ClientSetup();

		void Server();
		void Client();
	  
		
		float spd; //Word Throw Spd
		float fastSpd;
		float slowSpd;
		float vSlowSpd;
		float vFastSpd;
		
		float *throwSpd = &spd;
		
		float rot;
		float rotate = 12;
		float fastTate = rotate*2;
		float slowTate = rotate/2;
		float noTate = 0;
		
		float *rotSpd = &rotate;
		
		void ResetMotion();
		
		ofxUDPManager s;
		
		int timer;
};
