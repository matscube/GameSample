//
//  GameScene.cpp
//  GameSample
//
//  Created by TakanoriMatsumoto on 2015/06/10.
//
//

#include "GameScene.h"
#include "FieldLayer.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
   
    
    auto fieldLayer = FieldLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    scene->addChild(fieldLayer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Game Scene", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // Background image
    auto sprite = Sprite::create("HelloWorld.png");
//    log("width: %f, height: %f", visibleSize.width, visibleSize.height);
    Size currentSize = sprite->getContentSize();
    sprite->setScale(visibleSize.width / currentSize.width, visibleSize.height / currentSize.height);
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    
    return true;
}



void GameScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void GameScene::drawTest()
{
    // 画面サイズの取得
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    // 描画用ノードの作成
    CCDrawNode* draw = CCDrawNode::create();
    draw->setPosition(ccp(0, 0));
    draw->setTag(1);
    this->addChild(draw);
    
    /* 円の描画 */
    draw->drawDot(ccp(size.width * 0.5, size.height * 0.5), // 中心
                  50,                        // 半径
                  ccc4FFromccc3B(ccBLUE)                    // 色
                  );

/*    draw->drawPolygon(points,                  // 頂点の座標のデータ
                      3,                       // 角数
                      ccc4FFromccc3B(ccGREEN), // 図形の色
                      1,                       // 枠線の太さ
                      ccc4FFromccc3B(ccBLACK)  // 枠線の色
                      );*/
}

void GameScene::deleteTest()
{
    // 描画用ノードを削除すると、描画された図形も消える
    this->removeChildByTag(1);
}