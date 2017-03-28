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

class Button
{
  public:
	Button();
	~Button();
	
	void Update();
	void CheckPress();
  
  private:
	void Draw();
};

#endif /* Button_hpp */
