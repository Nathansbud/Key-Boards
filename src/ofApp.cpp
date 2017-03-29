/*
Welcome, all...to Key Boards!

Initially inspired by a desire to steal all the passwords—only kidding—this project was originally a mere keylogger...er, idea for a keylogger. But the winds of creativity blew once more, and Key Boards was born.

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

void ofApp::update(){

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
		
  keylog.open("keylog.txt");
  keylog << key;
  cout << key;
  keylog.close();
}

                                                                
void ofApp::keyReleased(int key){

}

                                                                
void ofApp::mouseMoved(int x, int y ){

}

                                                                
void ofApp::mousePressed(int x, int y, int button)
{

}

                                                                
void ofApp::mouseReleased(int x, int y, int button)
{

}


