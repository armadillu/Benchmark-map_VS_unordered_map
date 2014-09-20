#include "ofApp.h"

#if __cplusplus>=201103L || defined(_MSC_VER)
	#include <unordered_map>
	#include <memory>
#else
	#include <tr1/unordered_map>
	using std::tr1::unordered_map;
#endif

vector<string>					keys;
map<string, int>				myMap;
unordered_map<string, int>		myUnorderedMap;
vector<string>					readKeys;


//--------------------------------------------------------------
void ofApp::setup(){

	TIME_SAMPLE_SET_PRECISION(2);
	TIME_SAMPLE_DISABLE_AVERAGE();
	ofxTimeMeasurements::instance()->setIdleTimeColorFadePercent(0.2);

	int numKeys =	100000;
	int numReads =	100000;

	//make random keys
	for(int i = 0; i < numKeys; i++){
		string k;
		for(int j = 0; j <  30; j++){
			if (ofRandom(1) < 0.5){
				k += ofToString((char)ofRandom('A', 'Z'));
			}else{
				k += ofToString((char)ofRandom('0', '9'));
			}
		}
		keys.push_back(k);
	}

	//make keys to be read
	for(int i = 0; i < numReads; i++){
		readKeys.push_back( keys[(int)floor(ofRandom(0, keys.size()-1))] );
	}


	TS_START("add N keys to map");
	for(int i = 0; i < numKeys; i++){
		myMap[keys[i]] = 0;
	}
	TS_STOP("add N keys to map");

	TS_START("add N keys to unordered_map");
	for(int i = 0; i < numKeys; i++){
		myUnorderedMap[keys[i]] = 0;
	}
	TS_STOP("add N keys to unordered_map");

	int a;
	TS_START("read N keys from map");
	for(int i = 0; i < numReads; i++){
		a = myMap[readKeys[i]];
	}
	TS_STOP("read N keys from map");


	TS_START("read N keys from unordered_map");
	for(int i = 0; i < numReads; i++){
		a = myUnorderedMap[readKeys[i]];
	}
	TS_STOP("read N keys from unordered_map");


	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}