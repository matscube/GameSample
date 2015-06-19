//
//  FieldLayer.cpp
//  GameSample
//
//  Created by TakanoriMatsumoto on 2015/06/11.
//
//

#include "FieldLayer.h"
#include <vector>
#include <cstdlib>
#include <cstdio>

#define BLOCK_COUNT_X 6
#define BLOCK_COUNT_Y 6
#define BLOCK_SIZE 100

USING_NS_CC;


bool FieldLayer::init() {
    if (!Layer::init()) {
        return false;
    }
    // BG for debug
/*    Sprite *bgSprite = Sprite::create();
    bgSprite->setTextureRect(Rect(0, 0, size.width * 2, size.height * 2));
    bgSprite->setColor(Color3B::RED);
    bgSprite->setOpacity(200);
    bgSprite->setPosition(Vec2::ZERO);
    this->addChild(bgSprite);*/
    
    srand((unsigned int)time(NULL));
    setBlocks();
    
    // Touch action
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(FieldLayer::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(FieldLayer::onTouchMoved,this);
    listener->onTouchEnded = CC_CALLBACK_2(FieldLayer::onTouchEnded, this);
    
    auto dip = Director::getInstance()->getEventDispatcher();
    dip->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

/* blocks */
void FieldLayer::setBlocks() {
    // 画面サイズの取得
    Size size = Director::getInstance()->getWinSize();
    
    // color types
    std::vector<Color4F> colors;
    colors.push_back(Color4F(Color3B::BLUE));
    colors.push_back(Color4F(Color3B::RED));
    colors.push_back(Color4F(Color3B::YELLOW));
    colors.push_back(Color4F(Color3B::GREEN));
    colors.push_back(Color4F(Color3B::MAGENTA));
    colors.push_back(Color4F(Color3B::ORANGE));
    
    
    
    float marginX = 20;
    float spaceX = ((size.width - 20 * 2) - BLOCK_SIZE * BLOCK_COUNT_X) / (BLOCK_COUNT_X - 1.0);
    float marginY = 20;
    float spaceY = ((size.width - 20 * 2) - BLOCK_SIZE * BLOCK_COUNT_Y) / (BLOCK_COUNT_Y - 1.0);
    
    for (int x = 0; x < BLOCK_COUNT_X; x++) {
        for (int y = 0; y < BLOCK_COUNT_Y; y++) {
            int id = x * BLOCK_COUNT_X + y;
            
            DrawNode* draw = DrawNode::create();
            draw->setPosition(Vec2(marginX + BLOCK_SIZE / 2 + (BLOCK_SIZE + spaceX) * x,
                                   marginY + BLOCK_SIZE / 2 + (BLOCK_SIZE + spaceY) * y));
            draw->setTag(id);
            int colorID = rand()%colors.size();
            draw->drawDot(Vec2(0, 0), BLOCK_SIZE / 2, colors[colorID]);
            this->blocks.push_back(draw);

        }
        
    }

    for (auto block : this->blocks) {
        log("block tag: %d", block->getTag());
        this->addChild(block);
    }
}




bool FieldLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) {
    
/*    if (currentTag == 0)
    {
        CCPoint touchPoint = background->convertTouchToNodeSpace(pTouch);
        TouchedBlock touched_block = getTouchedBlock(touchPoint);
        if (touched_block.tag != 0)
        {
            currentTag = touched_block.tag;
            CCNode* current = background->getChildByTag(currentTag);
            current->setVisible(false);
            
            tmpCurrentTag = currentTag + kTagBaseBlock;
            BlockSprite* block = BlockSprite::create(tmpCurrentTag, touched_block.type, kStatusNormal);
            block->setPosition(current->getPosition());
            block->setScale(1.2f);
            block->setOpacity(128);
            block->setAnchorPoint(ccp(0.3, 0.3));
            background->addChild(block, kZOrderBlock+1, tmpCurrentTag);
        }
    }*/
    Point touchPoint = this->convertTouchToNodeSpace(touch);
    DrawNode *touchedBlock = this->getTouchedBlock(touchPoint);
    
    log("touchPoint x: %f, y: %f", touchPoint.x, touchPoint.y);

    
    return true;
}

void FieldLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event) {
    
}

void FieldLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) {
    
}

void FieldLayer::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event) {
    
}

DrawNode* FieldLayer::getTouchedBlock(cocos2d::Point touchPoint) {
    DrawNode *node = DrawNode::create();
    
//    node->getBoundingBox().containsPoint(touchPoint);
  
    
//    bool res = node->getBoundingBox().containsPoint(Vec2(touchPoint.x, touchPoint.y));
//    log("res: %d", res);
    
    
    for (auto block : this->blocks) {
//        log("block tag: %d", block->getTag());
        bool res = block->getBoundingBox().containsPoint(Vec2(touchPoint.x, touchPoint.y));
        Rect rect = block->getBoundingBox();
        log("%f %f %f %f", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
        if (res) {
            log("tag: %d", block->getTag());
        }
    }
    
    return node;

/*
    GameScene::TouchedBlock GameScene::getTouchedBlock(CCPoint touchPoint)
    {
        for (std::vector<std::vector<BlockSprite*> >::const_iterator it = blockFields.begin(); it != blockFields.end(); ++it)
        {
            for (vector<BlockSprite*>::const_iterator block = (*it).begin(); block != (*it).end(); ++block)
            {
                if (currentTag != 0 && (*block)->getTag() == currentTag)
                {
                    continue;
                }
                
                if ((*block)->boundingBox().containsPoint(touchPoint))
                {
                    return TouchedBlock((*block)->getTag(), (*block)->getType());
                }
            }
        }
        
        return TouchedBlock(0, (new BlockSprite())->getType());
    }
*/
}

