#pragma once
#include "ofMain.h"
#include "ofxFontStash2.h"

///\brief manages textures and fonts
class ofxAssetManager
{
public:
	ofxAssetManager();
	~ofxAssetManager();

	void setup(string assetFile = "assets.json");

	shared_ptr<ofxFontStash2::Fonts> getFonts();

	ofTexture loadTexture(string id, string path);
	void addTexture(string id, ofTexture texture, bool overwriteExisting = false);
	ofTexture getTexture(string id);

private:
	std::map<string, ofTexture> textures;
	shared_ptr<ofxFontStash2::Fonts> fonts;
};

