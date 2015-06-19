//
//  FieldLayer.h
//  GameSample
//
//  Created by TakanoriMatsumoto on 2015/06/11.
//
//

#ifndef __GameSample__FieldLayer__
#define __GameSample__FieldLayer__

#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <cstdio>

USING_NS_CC;

class FieldLayer : public cocos2d::Layer {
  
public:
    virtual bool init();
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    virtual void onTouchCancelled(Touch *touch, Event *unused_event);
    
    DrawNode *getTouchedBlock(Point touchPoint);
    std::vector<int> vi;
    int hoge;
    
    CREATE_FUNC(FieldLayer);
    
    
//private:
//    vector<int> test;
    // blocks
    std::vector<DrawNode *> blocks;
    void setBlocks();

};

#endif /* defined(__GameSample__FieldLayer__) */
