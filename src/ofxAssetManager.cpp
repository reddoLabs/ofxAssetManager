#include "ofxAssetManager.h"



ofxAssetManager::ofxAssetManager()
{
	//ofTrueTypeFont::setGlobalDpi(128);
	fonts = shared_ptr<ofxFontStash2::Fonts>(new ofxFontStash2::Fonts());
	fonts->setup(false);
}


ofxAssetManager::~ofxAssetManager()
{
}

void ofxAssetManager::setup(string assetFile) {
	ofJson assetJson = ofLoadJson(assetFile);

	// load textures and fonts
	for (auto& t : assetJson["textures"]["files"]) {
		loadTexture(t[0].get<string>(), assetJson["textures"]["folder"].get<string>() + "/" + t[1].get<string>());
	}
	for (auto& f : assetJson["fonts"]["files"]) {

		getFonts()->addFont(f[0].get<string>(), assetJson["fonts"]["folder"].get<string>() + "/" + f[1].get<string>());
	}
}

shared_ptr<ofxFontStash2::Fonts> ofxAssetManager::getFonts()
{
	return fonts;
}

ofTexture ofxAssetManager::loadTexture(string id, string path)
{
	ofTexture ret;
	ofStringReplace(path, "\\", "/");
	ofImage bi;
	bi.load(path);
	ret.loadData(bi.getPixels());

	addTexture(id, ret);
	
	return ret;
}

void ofxAssetManager::addTexture(string id, ofTexture texture, bool overwriteExisting)
{
	if (textures.find(id) == textures.end()) {
		textures.insert(pair<string, ofTexture>(id, texture));
		ofLogNotice("ofxAssetManager", "Texture " + id + " loaded");
	}
	else {
		if (overwriteExisting) {
			textures[id] = texture;
			ofLogNotice("ofxAssetManager", "Texture " + id + " has been overwritten");
		}
		else {
			ofLogNotice("ofxAssetManager", "Texture " + id + " already exists.");
		}
	}
}

ofTexture ofxAssetManager::getTexture(string id)
{
	if (textures.find(id) != textures.end()) {
		return textures[id];
	}
	else {
		ofLogError("ofxAssetManager", "Texture " + id + " not found");
		return ofTexture();
	}
	
}
