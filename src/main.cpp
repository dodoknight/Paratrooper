#include "ofxCogMain.h"
#include "jsonxx.h"
#include "pugixml.h"



class ParatrooperApp : public ofxCogApp {


	void RegisterComponents() {
		REGISTER_BEHAVIOR(NoahBeOver);
		REGISTER_BEHAVIOR(NoahLoading);
	}


	void InitComponents() {	
	
	}

	void InitStage(Stage* stage) {
		ofxCogEngine::GetInstance().LoadStage();
		stage->GetRootObject()->AddBehavior(new BackButtonKey());
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



