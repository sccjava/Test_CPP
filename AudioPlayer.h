#pragma once
#include <string>
#include <queue>
#include <pthread.h>

using namespace std;

class AudioPlayer{
private:
	
	AudioPlayer();
	~AudioPlayer();

	static void* handleUrl(void *arg);

public:
	
	static AudioPlayer* getInstance();

	void play(string url);

private:
	queue<string> m_urls;
	pthread_t m_playThread;
};
