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

}

void Button::Draw()
{
   ofSetColor(255);
   ofRectangle(_posX, _posY, _buttonWidth, _buttonHeight);
   ofSetColor(0);
   ofDrawBitmapString(_labelText.shrink_to_fit(ofRectangle(_posX, _posY, _buttonWidth, _buttonHeight)))
   
}
  private void Draw()
  {

    textAlign(CENTER); //Text alligned in the center for tidiness and aesthetics
    fill(_buttonColor);
    rect(_buttonPosX, _posY, _buttonWidth, _buttonHeight, _buttonCurve);
    fill(_textColor);
    textSize(_labelTextSize);
    text(_labelText, _posX, _posY + _labelTextSize);
    textAlign(LEFT); //Realligned to left for everything else
  }

  public void CheckPresses()
  {
    if (mouseIsReleased) //If mouse ever released, check if mouse is over button. 
    {
      if (mouseX > _buttonPosX && mouseX < _buttonPosX + _buttonWidth && mouseY > _posY && mouseY < _posY + _buttonHeight)
      {
        _buttonPressed = true; //If so, button pressed
      }  
      if (_buttonPressed)
      {
        switch(_buttonType) //Look to see what type of button
        {
        case "Story": //If story: current Screen = "_goesTo" of button.
          currentScreen = _goesTo;
          break;
        case "Music": //If music: open file selector
          FileSelector();
          break;
          //case:
        case "Menu": //If menu: change state to Button's _goesTo
          state = _goesTo;
          break;
        case "Inventory": //If inventory: open inventory
          InventoryManager();
          break;
        }
      }
    }
  }

