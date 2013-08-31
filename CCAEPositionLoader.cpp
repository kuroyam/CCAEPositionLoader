//
//  CCAEPositionLoader.cpp
//  Osan7
//
//  Created by kuroyam on 13/08/25.
//
//

#include "CCAEPositionLoader.h"
#include <string>

using namespace cocos2d;

CCAEPositionLoader* CCAEPositionLoader::create(const char* pPlistName)
{
    CCAEPositionLoader *pRet = new CCAEPositionLoader();
    if (pRet && pRet->init())
    {
        pRet->setPositionDataFileName(pPlistName);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

void CCAEPositionLoader::setPositionDataFileName(const char* pPlistName)
{
    CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
    
    std::string plistName = pPlistName;
    
    std::string prefix = plistName.erase(plistName.find('.'));
    std::string suffix;
    std::string extension = ".plist";
    
    // iOS
    if (platform == kTargetIphone || platform == kTargetIpad) {
        
        // iPhone-NonRetina
        if (screenSize.height <= 480)
            suffix = "";
        // iPhone-3.5inchRetina
        else if (screenSize.height <= 960)
            suffix = "-hd";
        // iPhone-4inchRetina
        else if (screenSize.height <= 1136)
            suffix = "-4inch";
        // iPad
        else
            suffix = "-ipad";
        
    }
    // Android
    else {
        
    }
    
    std::string result = prefix + suffix + extension;
    pPositionDataFileName = result.c_str();
    
    pPositionDict = CCDictionary::createWithContentsOfFile(pPositionDataFileName);
}

void CCAEPositionLoader::onExit()
{
    CCNode::onExit();
    pPositionDict->removeAllObjects();
    pPositionDict->release();
}

CCPoint CCAEPositionLoader::loadPosition(const char* pFileName)
{
    CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
    
    CCString *posString = (CCString*)pPositionDict->objectForKey(pFileName);
    CCPoint position  = CCPointFromString(posString->getCString());
    
    // iOS
    if (platform == kTargetIphone) {
        
        // iPhone-NonRetina
        if (screenSize.height <= 480)
            position = CCPoint(position.x, 480 - position.y);
        // iPhone-3.5inchRetina
        else if (screenSize.height <= 960)
            position = CCPoint(position.x, 960 - position.y);
        // iPhone-4inchRetina
        else if (screenSize.height <= 1136)
            position = CCPoint(position.x, 1136 - position.y);

    }
    // iPad
    else if (platform == kTargetIpad) {
        
    }
    // Android
    else {
        
    }
    
    return position;
}
