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
string welcome = "Welcome to Key Boards!";

void ofApp::setup()
{
  state = Title;
}

void ofApp::update(){

}

void ofApp::draw()
{
  if(state == Title)
  {
	ofBackground(Black);
	ChangeColor(White);
	ofDrawBitmapString(welcome, ofGetWidth()/2 - (welcome.length())*4, ofGetHeight()/9);
  }
  
  if(state == Info)
  {
	ofBackground(White);
	ChangeColor(Black);
	ofDrawBitmapString(info);
  }

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

                                                                
void ofApp::mouseDragged(int x, int y, int button){

}

                                                                
void ofApp::mousePressed(int x, int y, int button)
{

}

                                                                
void ofApp::mouseReleased(int x, int y, int button)
{

}

//void ofApp::GetColor(Colors color)
//{
//  switch(color)
//  {
//	case White:
//	  ofSetColor(255, 255, 255);
//	  break;
//	case Black:
//	  ofSetColor(0, 0, 0);
//	  break;
//	case Red:
//	  ofSetColor(255, 0, 0);
//	  break;
//	case Orange:
//	  ofSetColor(255, 140, 0);
//	  break;
//	case Yellow:
//	  ofSetColor(0, 255, 255);
//	  break;
//	case Green:
//	  ofSetColor(0, 255, 0);
//	  break;
//	case Blue:
//	  ofSetColor(0, 0, 255);
//	  break;
//  }
//}


//                                                                
//void ofApp::mouseEntered(int x, int y){
//
//}
//
//                                                                
//void ofApp::mouseExited(int x, int y)
//{
//
//}
//
//                                                                
//void ofApp::windowResized(int w, int h){
//
//}
//
//                                                                
//void ofApp::gotMessage(ofMessage msg)
//{
//
//}
//
//                                                                
//void ofApp::dragEvent(ofDragInfo dragInfo){
//
//}

