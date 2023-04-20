#include "ofxAssetManager.h"



ofxAssetManager::ofxAssetManager()
{
	fonts = shared_ptr<ofxFontStash2::Fonts>(new ofxFontStash2::Fonts());
	fonts->setup(false);
}


ofxAssetManager::~ofxAssetManager()
{
}

void ofxAssetManager::setup(string assetFile) {
	addAssetJson(ofLoadJson(assetFile));
}

void ofxAssetManager::addAssetFile(string file)
{
	addAssetJson(ofLoadJson(file));
}

void ofxAssetManager::addAssetJson(ofJson assets)
{
	// load textures and fonts
	for (auto& t : assets["textures"]["files"]) {
		loadTexture(t[0].get<string>(), assets["textures"]["folder"].get<string>() + "/" + t[1].get<string>(),true);
	}
	// disable logging each font that is loaded
	auto currentLogLevel = ofGetLogLevel();
	ofSetLogLevel(OF_LOG_ERROR);
	for (auto& f : assets["fonts"]["files"]) {

		getFonts()->addFont(f[0].get<string>(), assets["fonts"]["folder"].get<string>() + "/" + f[1].get<string>());
	}
	for (auto& f : assets["ofFonts"]["files"]) {
		shared_ptr<ofTrueTypeFont> font = shared_ptr<ofTrueTypeFont>(new ofTrueTypeFont());
		font->load(assets["ofFonts"]["folder"].get<string>() + "/" + f[1].get<string>(), assets["ofFonts"]["size"].get<int>(), true, true);
		fontsOf.insert(make_pair(f[0].get<string>(), font));
	}
	ofSetLogLevel(currentLogLevel);
}

shared_ptr<ofxFontStash2::Fonts> ofxAssetManager::getFonts()
{
	return fonts;
}

std::map<string, shared_ptr<ofTrueTypeFont>> ofxAssetManager::getFontsOf()
{
	return fontsOf;
}

shared_ptr<ofTrueTypeFont> ofxAssetManager::getFontOf(string id)
{
	if (fontsOf.find(id) != fontsOf.end()) {
		return fontsOf[id];
	}
	else {
		return fontsOf.begin()->second;
	}
	
}

ofTexture ofxAssetManager::loadTexture(string id, string path, bool overwriteExisting)
{
	ofTexture ret;

	// windows path replace
	ofStringReplace(path, "\\", "/"); 

	ofLoadImage(ret, path);
	addTexture(id, ret, overwriteExisting);
	
	return ret;
}

void ofxAssetManager::addTexture(string id, ofTexture texture, bool overwriteExisting)
{
	if (textures.find(id) == textures.end()) {
		textures.insert(pair<string, ofTexture>(id, texture));
		ofLogVerbose("ofxAssetManager", "Texture " + id + " loaded");
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

bool ofxAssetManager::hasTexture(string id) {
	if (textures.find(id) != textures.end()) {
		return true;
	} else {
		return false;
	}
}
