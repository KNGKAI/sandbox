#include "audio/Audio.hpp"
#include <iostream>
#include <vector>

namespace JAM::Audio{
	ALCdevice  *AudioDevice = NULL;
	ALCcontext *AudioContext = NULL;

	std::vector<JAMASound *> sounds;

	bool initOpenAL(){
		// Init sound engine
		AudioDevice = alcOpenDevice(NULL);
		if(!AudioDevice) return false;
		AudioContext = alcCreateContext(AudioDevice, NULL);
		alcMakeContextCurrent(AudioContext);
		if(int error = alGetError()) std::cout << error << std::endl;
		ALboolean EAX = alIsExtensionPresent("EAX2.0");
		alGetError();


		ALfloat listenerOri[] = { 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f };

		alListener3f(AL_POSITION, 0, 0, 1.0f);
		// check for errors
		alListener3f(AL_VELOCITY, 0, 0, 0);
		// check for errors
		alListenerfv(AL_ORIENTATION, listenerOri);
		// check for errors


		// Init sounds
		for(std::vector<JAMASound *>::iterator i = sounds.begin(); i != sounds.end(); i++){
			if(int error = alGetError()) std::cout << "ALError: " << error << std::endl;
			std::cout << "[" << (*i)->index << "]Loading sound: " << (*i)->file << "\t\t";
			if(!(*i)->load()) std::cout << "NOJOY" << std::endl;
			else std::cout << "  JOY" << std::endl;
		}

		return true;
	}

	bool deinitOpenAL(){
		for(std::vector<JAMASound *>::iterator i = sounds.begin(); i != sounds.end(); i++){
			delete (*i);
		}
		return true;
	}

	unsigned int gen(generator e){
		unsigned int r;
		e(1, &r);
		return r;
	}

	JAMASound& genSound(std::string file){
		JAMASound *hold = new JAMASound{(ALuint)sounds.size(), file};
		sounds.push_back(hold);
		return *hold;
	}

	bool JAMASound::load(){
		buffer = new JAMABuffer();
		if(int error = alGetError()) std::cout << "ALError: " << error << std::endl;
		source = new JAMASource();
		if(int error = alGetError()) std::cout << "ALError: " << error << std::endl;

		int channel, sampleRate, bps, size;
		ALenum format;
		void *data = loadWAV(file.data(), channel, sampleRate, bps, size);
		if(!data) return false;
		if(channel == 1)
			format = bps == 8 ? AL_FORMAT_MONO8 : AL_FORMAT_MONO16;
		else
			format = bps == 8 ? AL_FORMAT_STEREO8 : AL_FORMAT_STEREO16;

		alBufferData(buffer->name, format, data, size, sampleRate);
		source->bindBuffer(*buffer);
		return true;
	}
	void JAMASound::play(){
		alSourcePlay(source->name);
		ALenum source_state;
		alGetSourcei(*source, AL_SOURCE_STATE, &source_state);
		// check for errors
		while (source_state == AL_PLAYING) {
				alGetSourcei(*source, AL_SOURCE_STATE, &source_state);
				// check for errors
		}
	}
	void JAMASound::stop(){}



	ALint JAMASource::pitch(ALint e ){
		if(e == -1) return _pitch;
		_pitch = e;
		alSourcef(name, AL_PITCH, _pitch);
		return _pitch;

	}

	ALint JAMASource::gain(ALint e ){
		if(e == -1) return _gain;
		_gain = e;
		alSourcef(name, AL_GAIN, _gain);
		return _gain;
	}

	glm::vec3 JAMASource::position(glm::vec3 *e){
		if(!e) return _pos;
		_pos = *e;
		alSource3f(name, AL_POSITION, _pos.x, _pos.y, _pos.z);
		return _pos;
	}
	glm::vec3 JAMASource::velocity(glm::vec3 *e){
		if(!e) return _vel;
		_vel = *e;
		alSource3f(name, AL_VELOCITY, _vel.x, _vel.y, _vel.z);
		return _vel;
	}
	bool JAMASource::loop(bool set){
		_loop = set;
		return _loop;
	}

	JAMASource::JAMASource(){
		glm::vec3 hold(0.f);
		gain(1);
		pitch(1);
		position(&hold);
		velocity(&hold);
		loop(false);
	}

	void JAMASource::bindBuffer(JAMABuffer &e){
		alSourcei(name, AL_BUFFER, e.name);
	}

	JAMASound::~JAMASound(){
		alDeleteBuffers(1, &(buffer->name));
		alDeleteSources(1, &(source->name));
	}
}