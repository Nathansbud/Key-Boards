//
//  Button.hpp
//  KeyloggerProject
//
//  Created by Zack Amiton on 3/29/17.
//
//

#ifndef Button_hpp
#define Button_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofApp.h"

class Button
{
  public:
	Button(string _labelText, float posX, float posY, int goesTo, string buttonType);
	~Button();
	
	void Update();
	void CheckPress();
  
  private:
	void Draw();
};

#endif /* Button_hpp */
