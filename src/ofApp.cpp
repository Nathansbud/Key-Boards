/*
Welcome, all...to Key Boards!

Initially inspired by a desire to steal all the passwords! Only kidding‚ this project was originally a mere keylogger...er, idea for a keylogger. But the winds of creativity blew once more, and Key Boards was born.

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
bool wordSubmit;
int currentSong;
vector<string> input;
vector<string> opponentInput;
long nanosecond = 100000000;
static string delimiter[] = {"1:", "2:","3:","4:"};
locale loc;
int cooling;

void ofApp::setup()
{
  ofSetFrameRate(60);
  state = Game; //Should be changed to Title once implemented
  currentSong = 0;
  spd = ofGetWidth()*0.007;
  slowSpd = spd/2;
  fastSpd = spd*2;
  vSlowSpd = spd/3;
  vFastSpd = spd*3;
  
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
  ServerSetup();
//  ClientSetup();
}

void ofApp::update()
{
  Server();
  p1->Update();
  p2->Update();
  
  if(p2->GetHP() <= 0)
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
	ofDrawBitmapStringHighlight("S E R V E R", ofGetWidth()/2, ofGetHeight()/10);
	
	if(wordSubmit)
	{
	  SendWord(wordLoc);
	}
	
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
		if(keyPress != "" && !p1->isStunned())
		{
		  p1->SetEffects(Player::Stunned, 1);
		  rot = 0;
		  wordLoc += 1; //Increases wordLoc for any function trying to call it
		  thisWord = wordLoc;
		  input.push_back(keyPress);
		  wordSubmit = true;
		  Server();
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
		if(key >= 32 && key <= 126 && keyPress.length() < 30 && !p1->isStunned())
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

void ofApp::EvaluateWord(int index)
{
  string eval;
  string evalPrev;
  string caseEval = input.at(index);
  string caseEvalPrev = input.at(index);
	
  for (string::size_type i=0; i < input.at(index).length(); ++i)
  {
	eval += std::tolower(input.at(index)[i],loc);
  //	 if(eval.at(i) == ' ') //ignore space code?
  //	 {
  //	
  //	 }
	}
	
	for(string::size_type i=0; i < input.at(index - 1).length(); ++i)
		evalPrev += std::tolower(input.at(index - 1)[i], loc);

	//Note to future me: you can do magical thiiiings. Never call wordLoc that doesn't exist. Yes, duh, you can't call wordLoc + 1. That is dumb. You CAN, however, call wordLoc - 1. Combos, babyyyyy. TBI.

	//Attacks//
	
  if(wordInMotion())
  {
	if(eval == "spear")
	{
	  throwSpd = &fastSpd;
	  rotSpd = &noTate;
	}
	
	if(eval == "cannonball")
	{
	  throwSpd = &vSlowSpd;
	  rotSpd = &noTate;
	}
  }
 
  if(!wordInMotion())
  {
	if(eval == "attack")
	{
	  if(evalPrev == "combo")
	  {
		p2->ChangeHP(-4 * p1->GetDMG());
	  } else
	  {
		p2->ChangeHP(-1 * p1->GetDMG());
//		cout << p2->GetHP();
	  }
	}
	
	//Status Effects//
	
	if(eval == "poison" || eval == "venom" || eval == "toxic")
	{
	  p2->SetEffects(Player::Poisoned, 3);
	}
	
	if(eval == "burn" || eval == "fire")
	{
	  p2->SetEffects(Player::Burning, 5);
	}
	
	if(eval == "antidote")
	{
	  p1->RemoveEffects(Player::Poisoned);
	}
	
	//Defense//
	
	if(eval == "shield")
	{
	}
	
	if(eval == "heal")
	{
	  p1->ChangeHP(5);
	}
	
	if(eval == "memes")
	{
	  music[currentSong].stop();
	  currentSong = (int)ofRandom(1, 5);
	  music[currentSong].play();
	}
	
	if(eval == "stun" || eval == "daze")
	{
	  p1->SetEffects(Player::Stunned, 2);
	}
	
	if(eval == "nomorememes" || eval == "no more memes")
	{
	  if(currentSong != 0)
	  {
		music[currentSong].stop();
		currentSong = 0;
		music[currentSong].play();
	  }
	}
	
	if(eval == "murder") //debug
	{
	  p2->ChangeHP(-p2->GetHP());
	}
	
	
	if(caseEval == "r") //B U L L E T
	{
	  //Not Much Damage, Fast Fire
	}
	
	if(eval == "-->" || eval == "spear") //spear
	{
	  p2->ChangeHP(-10);
	  ResetMotion();
	}
	
	if(eval == "cannonball")
	{
	  p2->ChangeHP(-25);
	  ResetMotion();
	}
	
	if(caseEval == "o")
	{
	  //Long Cooldown, Slow Fire Rate, High Damage
	}
	
	if(eval == "-|==>")
	{
	  //S W O R D
	  //Breaks shield, super low damage
	}
	
	if(eval == "/\\/ /_\\")
	{
	  // N O
	  //High cool down, kill enemy word
	}
	
	if(eval == ">-|-o")
	{
	  //Tosses a slave???
	}
	
	if(eval == "(-)")
	{
	  //Chance of heal, but also of long poison!!
	}
	
	/* Debug */
	
	if(eval == "restart")
	{
	  p1->Restart();
	  p2->Restart();
	}
	
	keyPress.clear();
  }
}

void ofApp::SendWord(int index)
{
  EvaluateWord(index);
  ofPushMatrix();
  ofTranslate(stringPos + 200);
  ofRotateZ(rot);
  ofSetColor(255, 0, 0);
  ofDrawBitmapStringHighlight(input.at(index), 0, 0);
  ofPopMatrix();
  
  if(wordInMotion())
  {
	stringPos.x += *throwSpd;
	rot += *rotSpd;
  }
  else
  {
	stringPos.x = p1->GetPos().x;
	wordSubmit = false;
  }
}

bool ofApp::wordInMotion()
{
  if(stringPos.x < p2->GetPos().x - ofGetWidth()/7.2)
  {
	return true;
  } else return false;
}

void ofApp::ResetMotion()
{
  rotSpd = &rotate;
  throwSpd = &spd;
}

//void ofApp::ChangeMotion(float *speed, float *rotate)
//{
//	*speed = *s
//}

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
    s.Connect("127.0.0.1", 23339);
    s.SetNonBlocking(true);
}

void ofApp::Server()
{
  string status(to_string(p1->GetEffects()));
  string msg(keyPress);
  string send(status + delimiter[0] + msg);
  if(ofGetKeyPressed(OF_KEY_RETURN))
  {
	s.Send(send.c_str(), send.length());
  }
}

void ofApp::Client()
{
  char receive[100];
  s.Receive(receive, 100);
  string data(receive);
  string status = data.substr(0, data.find_first_of(delimiter[0]) - 1);
  string word = data.substr(data.find_first_of(delimiter[0]) + delimiter[0].length(), data.length());
}

