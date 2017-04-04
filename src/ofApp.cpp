/*
Welcome, all...to Key Boards!

Initially inspired by a desire to steal all the passwords—only kidding—this project was originally a mere keylogger...er, idea for a keylogger. But the winds of creativity blew once more, and Key Boards was born.

In Key Boards, the player is tasked with the control of one of two characters: Qwert, and Azert. Creative names? I think so! Duke it out in this keyboard-inspired frenzy, flinging characters at strings at one another in order to prove once and for all...who truly holds the role of Warrior (get it? Because Keyboard Warrior? Hahah jokes)?

Made 2017, by Nathansbud
~Harro is lif


Reference to my brain:
  - TBI = To Be Implemented
  - TBF = To Be Fixed
*/

#include "ofApp.h"
#include <fstream>

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
int wordLoc;
bool wordSubmit, restart, fusrodahd;
int rot = 0;
enum States {Title, Info, Game, Win, GameOver};
enum Words {Slash, Strike, Fireball, Shield, Stun, Daze, Confuse, Derp, Poison};
vector<string> input;

States state;
Words word;

//void ofApp::ChangeColor(char type, ofColor color) //This function is a whole world of broken. TBF
//{
//  if(type == 'b' || type == 'B')
//  {
//	ofBackground(color);
//  } else
//  {
//	ofSetColor(color);
//  }
//}

void ofApp::setup()
{
  state = Game; //Should be changed to Title once implemented
//  sickNastyTracks.load("All Star.mp3");
//  sickNastyTracks.setLoop(true);
//  sickNastyTracks.play();
  input.push_back("Begin Input. (Yeah, I see you there, trying to access null)"); //Vector 0, to ensure functions that call wordLoc - 1 don't break. Anything calling wordLoc - 2 might also break if called as first function. TBF.
  wordLoc = 0;
  ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL);
//  udpConnection.Create();
//  udpConnection.Connect("127.0.0.1",11999);
//  udpConnection.SetNonBlocking(true);
//
}

void ofApp::update()
{
  qwerty.Update();
  azerty.Update();
  
  if(azerty.GetHP() == 0)
  {
	state = Win;
  }
}

void ofApp::draw()
{
  
  /*[Game]*/
  
  if(state == Game)
  {
	ofBackground(255);
	
	ofSetColor(255);
	
	ground.Draw();
	qwerty.Draw();
	azerty.Draw();
	
	ofSetColor(0);
	ofDrawBitmapStringHighlight(keyPress, 300, 700);
	ofDrawBitmapStringHighlight("HP: " + qwerty.HP, 150, 450);
	ofDrawBitmapStringHighlight("HP: " + azerty.HP, 1250, 450);
	
	
	
	if(wordSubmit)
	{
	  SendWord();
	}
	
	rot += 10;
  }
  
  
  /*[Title Screen]*/ //TBI

  if(state == Title)
  {
//	ChangeColor('B', Black);
//	ChangeColor('T', White);
	ofDrawBitmapString(welcome, ofGetWidth()/2 - (welcome.length())*4, ofGetHeight()/9);
  }
  
  /*[Info Screen]*/
  
  if(state == Info) //TBI
  {
//	ChangeColor('B', White);
//	ChangeColor('T', Black);
	ofDrawBitmapString(Info, ofGetWidth()/50, ofGetHeight()/30);
  }
  
  /*[Game Over Screen???]*/

  
//  if(state == GameOver) //TBI, on networking*
//	{
//	  ChangeColor('B' Cyan);
//	  ChangeColor('T', Black);
//	  ofDrawBitmapString("Haha you losted");
//	}

  if(state == Win)
  {
	ofBackground(Red);
	ofDrawBitmapString("A WinRar is You!", ofGetWidth()/2, ofGetHeight()/2); //Button TBI.
  }
}
                                        
void ofApp::keyPressed(int key)
{
  
  if(state == Game)
  {
	switch(key)
	{
	  case OF_KEY_BACKSPACE:
	  case OF_KEY_DEL:
		keyPress.pop_back();
		break;
		
	  case OF_KEY_RETURN:
	  {
		if(keyPress != "")
		{
		  wordLoc += 1; //Increases wordLoc for any function trying to call it
		  input.push_back(keyPress);
		  wordSubmit = true;
		  keyPress.clear();
		}
		break;
	  }
	  
	  case OF_KEY_TAB:
		keyPress.clear();
		break;
		
	  case 16:
		break;
		
	  default:
	  {
		if(keyPress.length() < 15)
		{
		  keyPress += (char)key;
		}
		break;
	  }
	}
  }
	
  if(state == Win || state == GameOver)
  {
	switch(key)
	{
	  case 'R':
	  case 'r':
		Restart();
		state == Game;
	}
  }
}

void ofApp::EvaluateWord()
{
  //Note to future me: you can do magical thiiiings. Never call wordLoc that doesn't exist. Yes, duh, you can't call wordLoc + 1. That is dumb. You CAN, however, call wordLoc - 1. Combos, babyyyyy. TBI.

  if(input.at(wordLoc) == "Attack" || input.at(wordLoc) == "attack")
  {
  	azerty.ChangeHP(-1);
	cout << azerty.GetHP();

  }
  
  if(input.at(wordLoc) == "murder") //debug
  {
	azerty.SetHP(0);
  }
  
  if(keyPress == "Fus ro dah" || keyPress == "fus ro dah" || keyPress == "fusrodah" || keyPress == "FUSRODAH" || keyPress == "Fusrodah")
  {
	
  }
  
  keyPress.clear();

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

void ofApp::SendWord()
{
  ofPushMatrix();
  ofTranslate(stringPos + 200);
  ofRotateZ(rot);
  ofSetColor(255, 0, 0);
  ofDrawBitmapStringHighlight(input.at(wordLoc), 0, 0);
  ofPopMatrix();
  
  if(stringPos.x < azerty.GetPos().x - 200)
	stringPos.x += 10;
  else if(stringPos.x > azerty.GetPos().x - 200)
  {
	EvaluateWord();
	stringPos.x = qwerty.GetPos().x;
	wordSubmit = false;
  }
}

void ofApp::Restart()
{
  azerty = Player(2);
  qwerty = Player(1);
}




