//
//  Button.cpp
//  KeyloggerProject
//
//  Created by Zack Amiton on 3/29/17.
//
//

#include "Button.hpp"

int _goesTo;
float _posX, _posY;
string _labelText;
float _buttonWidth, _buttonHeight;


Button::Button(string labelText, float posX, float posY, int goesTo, string buttonType)
{
   _goesTo = goesTo;
   _labelText = labelText;
   _posX = posX;
   _posY = posY;
   _buttonWidth = labelText.length() * 2;
   _buttonHeight = ofGetHeight()/30;
}

Button::~Button()
{

}

void Button::Update()
{

}

void Button::CheckPress()
{
   if(ofGetMousePressed(2))
   {
	  if(ofGetMouseX() >= _posX && ofGetMouseX() >= _posX + _buttonWidth && ofGetMouseY() >= _posY && ofGetMouseY() <= _posY + _buttonHeight)
	  {
//		 ofApp::SetState(_goesTo);
	  }
   }
}

void Button::Draw()
{
   ofSetColor(255);
   ofRectangle(_posX, _posY, _buttonWidth, _buttonHeight);
   ofSetColor(0);
   ofDrawBitmapString(_labelText, _posX, _posY + _labelText.max_size());
}
