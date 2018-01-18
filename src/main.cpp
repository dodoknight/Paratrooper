#include "ofxCogMain.h"
#include "jsonxx.h"
#include "pugixml.h"
#include "ParatrooperFactory.h"


class ParatrooperApp : public ofxCogApp {


	void RegisterComponents() {
		REGISTER_COMPONENT(new ParatrooperFactory());
	}


	void InitComponents() {	
		auto factory = GETCOMPONENT(ParatrooperFactory);
		auto model = factory->LoadGameModel();
		//factory->InitializeGame(root, model);
	}

	void InitStage(Stage* stage) {
		ofxCogEngine::GetInstance().LoadStage();
	}
};

#ifndef WIN32
#include <jni.h>
#endif

int main() {
	ofSetupOpenGL(800, 450, OF_WINDOW);
	ofRunApp(new ParatrooperApp());
	return 0;
}

#ifndef WIN32

//========================================================================
extern "C" {
	void Java_cc_openframeworks_OFAndroid_init(JNIEnv*  env, jobject  thiz) {
		main();
	}
}
#endif



