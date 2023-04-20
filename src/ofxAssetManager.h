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
	void addAssetFile(string file);
	void addAssetJson(ofJson assets);

	shared_ptr<ofxFontStash2::Fonts> getFonts();
	std::map<string, shared_ptr<ofTrueTypeFont>> getFontsOf();
	shared_ptr<ofTrueTypeFont> getFontOf(string id);


	ofTexture loadTexture(string id, string path, bool overwriteExisting = false);
	void addTexture(string id, ofTexture texture, bool overwriteExisting = false);
	ofTexture getTexture(string id);
	bool hasTexture(string id);

private:
	std::map<string, ofTexture> textures;
	shared_ptr<ofxFontStash2::Fonts> fonts;
	std::map<string, shared_ptr<ofTrueTypeFont>> fontsOf;
};

