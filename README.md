CCAEPositionLoader
==================
#### AEPositionExporter.jsx
AfterEffectsのスクリプト。  
コンポジションに配置されたレイヤーの位置情報をplistで書き出す。  

#### CCAEPositionLoader.h/cpp
cocos2d-x向けに、上のスクリプトで書きだしたplistから位置情報を読むコード。

---
いろんな解像度のデバイスに対応したいけど、画像をそれぞれ絶対位置で置きたいってときに。  
相対位置でいいならcocosBuilderとかのほうがいいかも。  

    CCAEPositionLoader *posLoader = CCAEPositionLoader::create("position.plist");
    CCSprite *sprite = CCSprite::create("image.png");
    sprite->setPosition(posLoader->loadPosition("image.png"));
    this->addChild(sprite);

---
まだ途中。今のところ  
iPhone (320 * 480)  
iPhoneRetina 3.5inch (640 * 960)  
iPhoneRetina 4inch (640 * 1136)  
まで作った
