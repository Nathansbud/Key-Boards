//
//  Ground.hpp
//  KeyloggerProject
//
//  Created by Zack Amiton on 4/2/17.
//
//

#ifndef Ground_hpp
#define Ground_hpp

#include <stdio.h>
#include "ofMain.h"

class Ground
{
  public:
	Ground();
	~Ground();
	
	void Draw();
	void Update();
	
	ofVec2f GetPos() {return _groundPos;}
		
  private:
	ofVec2f _groundPos;
	ofImage _ground;
	void SetPos(ofVec2f pos);
};

#endif /* Ground_hpp */
