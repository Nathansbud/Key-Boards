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
		
		Player *p1 = &qwerty;
		Player *p2 = &azerty;
		
		
		Ground ground = Ground();
		
		string keyPress;
		string ip;
		
		ofVec2f stringPos = qwerty.GetPos();
	
		ofSoundPlayer music[5];
				
		void ServerSetup();
		void Server();
		void Client();
		
		ofxUDPManager s;
		ofxUDPManager c;
		
};
