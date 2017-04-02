//
//  Ground.cpp
//  KeyloggerProject
//
//  Created by Zack Amiton on 4/2/17.
//
//

#include "Ground.hpp"

Ground::Ground()
{
  _ground.load("images/Ground.png");
  _groundPos.set(0, ofGetHeight()*3/4);
}

Ground::~Ground()
{

}

void Ground::Draw()
{
  ofImage();
  _ground.draw(GetPos());
}

void Ground::Update()
{

}
