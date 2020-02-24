#include "audio/Audio.hpp"

int main(){
	JAM::Audio::JAMASound &q = JAM::Audio::genSound("../Explosion+1.wav");

	JAM::Audio::initOpenAL();
	for(int i = 1; i < 10; i ++){
		q.source->pitch(i);
		q.play();
	}

	JAM::Audio::deinitOpenAL();
}
