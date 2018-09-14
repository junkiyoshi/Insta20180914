#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	this->font.loadFont("fonts/Kazesawa-bold.ttf", 180, true, true, true);
	this->fbo.allocate(ofGetWidth(), ofGetHeight());
	this->shader.load("shader/shader.vert", "shader/shader.frag");
}
//--------------------------------------------------------------
void ofApp::update() {

	this->fbo.begin();
	ofClear(0);
	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	ofSetColor(255);
	string word = "SCATTER";
	this->font.drawString(word, this->font.stringWidth(word) * -0.5, this->font.stringHeight(word) * 0.5);

	this->fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->shader.begin();
	this->shader.setUniform1f("time", ofGetElapsedTimef());
	this->shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
	this->shader.setUniformTexture("tex", this->fbo.getTexture(), 1);

	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	this->shader.end();
}

//--------------------------------------------------------------
int main() {

	ofGLWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.setSize(1280, 720);
	ofCreateWindow(settings);
	ofRunApp(new ofApp());
}