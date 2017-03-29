/*
Welcome, all...to Key Boards!

Initially inspired by a desire to steal all the passwordsâ€”only kiddingâ€”this project was originally a mere keylogger...er, idea for a keylogger. But the winds of creativity blew once more, and Key Boards was born.

In Key Boards, the player is tasked with the control of one of two characters: Qwert, and Azert. Creative names? I think so! Duke it out in this keyboard-inspired frenzy, flinging characters at strings at one another in order to prove once and for all...who truly holds the role of Warrior (get it? Because Keyboard Warrior? Hahah jokes)?

Made 2017, by Nathansbud
~Harro is lif

*/

#include "ofApp.h"
#include <fstream>

ofstream keylog;
ofApp::States state;
ofColor Black(0, 0, 0);
ofColor White(255, 255, 255);
ofColor Red = (255, 0, 0);
ofColor Yellow(0, 255, 255);
ofColor Green(0, 255, 0);
ofColor Blue(0, 0, 255);
ofColor Orange(255, 140, 0);
ofColor Cyan(224,255,255);
string welcome = "Welcome to Key Boards!";
string info = "haha information";

void ofApp::ChangeColor(char type, ofColor color)
{
  if(type == 'b' || type == 'B')
  {
	ofBackground(color);
  } else
  {
	ofSetColor(color);
	ofFill();
  }
}

void ofApp::setup()
{
  state = Game;
}

void ofApp::update()
{
}

void ofApp::draw()
{

  if(state == Title)
  {
	ChangeColor('B', Black);
	ChangeColor('T', White);
	ofDrawBitmapString(welcome, ofGetWidth()/2 - (welcome.length())*4, ofGetHeight()/9);
  }
  
  if(state == Info)
  {
	ChangeColor('B', White);
	ChangeColor('T', Black);
	ofDrawBitmapString(Info, ofGetWidth()/50, ofGetHeight()/30);
  }
  
  if(state == Game)
  {
	ChangeColor('B', White);
	qwerty.Draw();
	azerty.Draw();
	
  }
  
//  if(state == GameOver)
//	{
//	  ChangeColor('B' Cyan);
//	  ChangeColor('T', Black);
//	  ofDrawBitmapString("Haha you losted");
//	}

}
                                        
void ofApp::keyPressed(int key)
{
	keylog.open("loggedkeys.txt");
	keyPress = key;
	keylog << keyPress;
	cout << keyPress;
	keylog.close();
}

/*

Note: As I seem to be having great difficulty doing the "code" work, this seems like an ample opportunity to do some design/ideation work rather than purely code-focused work...as I've seemingly been running headfirst into a brick wall for ages. Sooooo...some of this may be in psuedocode, but...

"Spell List"

switch(string) <- would be player input, find a method to parse through this; do strings work as Switch in C++?
{
  case "Derp": Ñ would it need to be defined for every case? Could case be ignored?
  case "derp":
	enemy.Stun(); Ñ what could stun potentially do? Potentially disable the enemy from sending things?
	break;
		OOOOOH! Could potentially cause enemy player's current word to be discarded
  case "Shield"
	if(cooldown == false)
	{
	  put up a "word" shield?
	} else continue;
	break;
  case "Regeneration":
	playerRegen = true; - could regain some health over time? Maybe while regen = true, regain at a rate of 2 hp per second
	break;
  case "Slash"
	deal 5 damage to opponent, but triggers x effect to self
  case "Hah!"
	text pops up, "you think this is some kind of joke?"
  case "Fireball" 
	inflict effect burn onto opponent, deals dot?
	could make enum { status effects }
  case "Retalliate"
   steals enemy last used ability?
  
}

*/



//void ofApp::keyReleased(int key)
//{
//
//}
//
//                                                                
//void ofApp::mouseMoved(int x, int y ){
//
//}
//
//                                                                
//void ofApp::mousePressed(int x, int y, int button)
//{
//
//}
//
//                                                                
//void ofApp::mouseReleased(int x, int y, int button)
//{
//
//}
//
//


