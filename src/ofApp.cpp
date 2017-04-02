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
string submittedWord; //Word used for
bool wordSubmit;
int rot = 0;

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
  ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL);
//  udpConnection.Create();
//  udpConnection.Connect("127.0.0.1",11999);
//  udpConnection.SetNonBlocking(true);
//  
}

void ofApp::update()
{

}

void ofApp::draw()
{
  
  /*[Game]*/
  
  if(state == Game)
  {
	ChangeColor('B', White);
	
	ground.Draw();
	qwerty.Draw();
	azerty.Draw();
	
	ofPushMatrix();
	ofTranslate(stringPos + 200);
	ofRotateZ(rot);
	ofDrawBitmapStringHighlight(keyPress, 0, 0);
	ofPopMatrix();
	
	if(wordSubmit)
	{
	  if(stringPos.x < azerty.GetPos().x - 200)
		stringPos.x += 10;
	  else if(stringPos.x > azerty.GetPos().x - 200)
	  {
		if(keyPress == "a")
		{
		  cout << " m e m e ";
		} else cout << ":(";
		
		stringPos.x = qwerty.GetPos().x;
		cout << azerty.GetHP();
		wordSubmit = false;
	  }
	}
	
	rot += 10;
  }
  
  /*[Title Screen]*/

  if(state == Title)
  {
	ChangeColor('B', Black);
	ChangeColor('T', White);
	ofDrawBitmapString(welcome, ofGetWidth()/2 - (welcome.length())*4, ofGetHeight()/9);
  }
  
  /*[Info Screen]*/
  
  if(state == Info)
  {
	ChangeColor('B', White);
	ChangeColor('T', Black);
	ofDrawBitmapString(Info, ofGetWidth()/50, ofGetHeight()/30);
  }
  
  /*[Game Over Screen???]*/

  
//  if(state == GameOver)
//	{
//	  ChangeColor('B' Cyan);
//	  ChangeColor('T', Black);
//	  ofDrawBitmapString("Haha you losted");
//	}

}
                                        
void ofApp::keyPressed(int key)
{
  if(key != OF_KEY_BACKSPACE && key != OF_KEY_RETURN && key != OF_KEY_SHIFT)
  {
	keyPress.push_back(key);
  }
  
  if(key == OF_KEY_BACKSPACE)
  {
	keyPress.pop_back();
  }
	
  keylog.open("loggedkeys.txt");
  keylog << keyPress << endl;
//cout << keyPress << endl;
  keylog.close();
	
  if(key == OF_KEY_RETURN) //End sending
  {
	  tempWord = keyPress; //Set submitted word to keyPress, in order to reset
	  wordSubmitted = tempWord;
	  wordSubmit = true; //Word has been sent
	  keyPress.clear(); //Clear out word
  }
}


void ofApp::keyReleased(int key)
{

}
                                                                
void ofApp::mousePressed(int x, int y, int button)
{

}

                                                                
void ofApp::mouseReleased(int x, int y, int button)
{

}



