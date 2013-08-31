//
//  CCAEPositionLoader.h
//
//
//  Created by kuroyam on 13/08/25.
//
//

// ** suffix ** //
// iPhone3GS    ""
// iPhone4, 4S  "-hd"
// iPhone5      "-4inch"
// iPad         "-pad"
// iPad-retina  "-padhd"
// iPad-mini    "-padmini"

#ifndef __CCAEPositionLoader__
#define __CCAEPositionLoader__

#include "cocos2d.h"

class CCAEPositionLoader : public cocos2d::CCNode
{
public:
    CREATE_FUNC(CCAEPositionLoader);
    static CCAEPositionLoader* create(const char* pPlistName);
    void setPositionDataFileName(const char* pPlistName);
    
    cocos2d::CCPoint loadPosition(const char* pFileName);
    
private:
    virtual void onExit();
    const char* pPositionDataFileName;
    cocos2d::CCDictionary *pPositionDict;
};

#endif /* defined(__CCAEPositionLoader__) */
