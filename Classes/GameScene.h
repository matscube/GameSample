//
//  GameScene.h
//  GameSample
//
//  Created by TakanoriMatsumoto on 2015/06/10.
//
//

#ifndef __GameSample__GameScene__
#define __GameSample__GameScene__

#include <stdio.h>
#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
private:
    void drawTest();
    void deleteTest();
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};

#endif /* defined(__GameSample__GameScene__) */
