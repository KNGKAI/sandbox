#ifndef JAM_OPENAL_HPP
#define JAM_OPENAL_HPP

#include <cstddef>
#include "al.h"
#include "alc.h"

#include <string>
#include "glm/glm.hpp"

namespace JAM::Audio{
	typedef void (*generator)(ALsizei size, ALuint *name);
	unsigned int gen(generator e);

	struct JAMABuffer{
		const ALuint name = gen(alGenBuffers);
	};

	struct JAMASource{
		const ALuint name = gen(alGenSources);
		ALint pitch(ALint e = -1);
		ALint gain(ALint e = -1);
		glm::vec3 position(glm::vec3 *p = NULL);
		glm::vec3 velocity(glm::vec3 *p = NULL);
		bool loop(bool set = false);
		void bindBuffer(JAMABuffer &e);
		JAMASource();
		operator ALuint(){
			return name;
		}
		private:
			ALint _pitch, _gain;
			glm::vec3 _pos, _vel;
			bool _loop;
	};


	struct JAMASound{
		const unsigned int index;
		const std::string file;
		JAMABuffer *buffer;
		JAMASource *source;
		bool load();
		void play(bool async = false);
		void stop();
	};

	bool initOpenAL();
	JAMASound& genSound(std::string file);

}
	char* loadWAV(const char* fn, int& chan, int& samplerate, int& bps, int& size);

#endif