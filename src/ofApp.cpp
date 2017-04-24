/*
Welcome, all...to Key Boards!

Initially inspired by a desire to steal all the passwords! Only kiddingâ this project was originally a mere keylogger...er, idea for a keylogger. But the winds of creativity blew once more, and Key Boards was born.

In Key Boards, the player is tasked with the control of one of two characters: Qwert, and Azert. Creative names? I think so! Duke it out in this keyboard-inspired frenzy, flinging characters at strings at one another in order to prove once and for all...who truly holds the role of Warrior (get it? Because Keyboard Warrior? Hahah jokes)?

Made 2017, by Nathansbud
~Harro is lif


Reference to my brain:
  - TBI = To Be Implemented
  - TBF = To Be Fixed
*/

#include "ofApp.h"
#include <fstream>
#include <time.h>
#include <chrono>
#include <stdio.h>

ofColor Red(255, 0, 0);
ofColor Green(0, 255, 0);
ofColor Blue(0, 0, 255);

int wordLoc;
bool wordSubmit, fusrodahd;
int rot;
int currentSong;
vector<string> input;
vector<string> opponentInput;
long nanosecond = 100000000;
static int ticks;
//std::chrono::duration<3> poison;
//chrono::duration<std::chrono::seconds> wait(5);

void ofApp::setup()
{
  ofSetFrameRate(60);
  state = Game; //Should be changed to Title once implemented
  currentSong = 0;
  music[0].load("music/Acid Nova Dreams.mp3");
  music[1].load("music/All Star.mp3");
  music[2].load("music/You Reposted in the Wrong Neighborhood.mp3");
  music[3].load("music/Shooting Stars.mp3");
  music[4].load("music/Never Gonna Give You Up.mp3");
  
  music[currentSong].setLoop(true);
  music[currentSong].play();
  
  input.push_back("Begin Input. (Yeah, I see you there, trying to access null)"); //Vector 0, to ensure functions that call wordLoc - 1 don't break. Anything calling wordLoc - 2 might also break if called as first function. TBF.
  opponentInput.push_back("Begin Input, except it's actually the opponent. I SEE YOU THERE, STILL TRYING TO ACCESS NULL!");
  wordLoc = 0;
  ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL);
}

void ofApp::update()
{
  p1->Update();
  p2->Update();
  
  if(p2->GetHP() == 0)
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
	p1->Draw();
	p2->Draw();
	
	ofSetColor(0);
	if(keyPress != "")
	  ofDrawBitmapStringHighlight(keyPress, 300, 700);
	ofDrawBitmapStringHighlight("HP: " + p1->HP, 150, 450);
	ofDrawBitmapStringHighlight("HP: " + p2->HP, 1250, 450);
	
	
	
	if(wordSubmit)
	{
	  SendWord();
	}
	
	rot += 12;
  }

  if(state == Win)
  {
	ofBackground(Red);
	ofDrawBitmapString("A WinRar is You!", ofGetWidth()/2, ofGetHeight()/2); //Button TBI.
  }
  
  if(!music[currentSong].isPlaying())
  {
	music[0].setLoop(true);
	music[0].play();
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
		if(key >= 32 && key <= 126 && keyPress.length() < 30)
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
		InitializeState(Game);
		state == Game;
	}
  }
}

void ofApp::EvaluateWord()
{
  //Note to future me: you can do magical thiiiings. Never call wordLoc that doesn't exist. Yes, duh, you can't call wordLoc + 1. That is dumb. You CAN, however, call wordLoc - 1. Combos, babyyyyy. TBI.

  //Attacks//

  if(input.at(wordLoc) == "Attack" || input.at(wordLoc) == "attack")
  {
	if(input.at(wordLoc - 1) == "combo")
	{
	  p2->ChangeHP(-4 * p1->GetDMG());
	} else
	{
	  p1->ChangeHP(-1 * p1->GetDMG());
	  cout << p2->GetHP();
	}
  }
  
  //Status Effects//
  
  
  //Defense//
  
  if(input.at(wordLoc) == "Shield" || input.at(wordLoc) == "shield")
  {
  }
  
  if(input.at(wordLoc) == "Heal" || input.at(wordLoc) == "heal")
  {
	p1->ChangeHP(5);
  }
  
  if(input.at(wordLoc) == "poison" || input.at(wordLoc) == "venom")
  {
	p2->SetEffects(Player::Poisoned);
  }
  
  if(input.at(wordLoc) == "Memes" || input.at(wordLoc) == "memes")
  {
	music[currentSong].stop();
	currentSong = (int)ofRandom(1, 5);
	music[currentSong].play();
  }
  
  if(input.at(wordLoc) == "no more memes" || input.at(wordLoc) == "nomorememes")
  {
	if(currentSong != 0)
	{
	  music[currentSong].stop();
	  currentSong = 0;
	  music[currentSong].play();
	}
  }
  
  if(input.at(wordLoc) == "murder") //debug
  {
	p2->SetHP(0);
  }
  
  
  if(keyPress == "Fus ro dah" || keyPress == "fus ro dah" || keyPress == "fusrodah" || keyPress == "FUSRODAH" || keyPress == "Fusrodah")
  {
	
  }
  
  keyPress.clear();

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
  
  if(stringPos.x < p2->GetPos().x - 200)
	stringPos.x += 10;
  else if(stringPos.x > p2->GetPos().x - 200)
  {
	EvaluateWord();
	stringPos.x = p1->GetPos().x;
	wordSubmit = false;
  }
}

void ofApp::InitializeState(States newState)
{

  switch(newState)
  {
	case Game:
	  break;
	case Title:
	  break;
	case GameOver:
	  break;
	case Win:
	  break;
	case Info:
	  break;
  }
}

void ofApp::ServerSetup()
{
    s.Create();
    s.SetEnableBroadcast(true);
    s.Connect("127.0.0.1", 12345);
    s.SetNonBlocking(true);
}

void ofApp::Server()
{
  string word = keyPress;
  s.Send(keyPress.c_str(), keyPress.length());
}

void ofApp::Client()
{
  char text[30];
  c.Receive(text, 30);
  string data = text;
  opponentInput.push_back(text);
}



