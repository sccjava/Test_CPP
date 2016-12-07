#include "AudioPlayer.h"
#include <unistd.h>

AudioPlayer::AudioPlayer(){
	
}

AudioPlayer::~AudioPlayer(){

}

static AudioPlayer	*s_audioPlayer;

AudioPlayer* AudioPlayer::getInstance(){
	if (!s_audioPlayer)
	{
		s_audioPlayer = new AudioPlayer();
		pthread_create(&s_audioPlayer->m_playThread, NULL, &AudioPlayer::handleUrl, NULL);
	}
	return s_audioPlayer;
}

void AudioPlayer::play(string url)
{
	m_urls.push(url);
}

void* AudioPlayer::handleUrl(void *arg)
{
	AudioPlayer *ap = s_audioPlayer;
	printf("handle url\n");
	while(1)
	{
		usleep(1000 * 1000);
		if(ap->m_urls.size() > 0)
		{
			printf("aaa  %s\n", ap->m_urls.front().c_str());
			ap->m_urls.pop();
		}
	}
}

int main () {
	AudioPlayer *p = AudioPlayer::getInstance();

	usleep(1000 * 1000 * 5);

	string s1 = "http1";
	string s2 = "http2";

	p->play(s1);

	usleep(1000 * 1000 * 5);

	p->play(s2);

	getchar();
	return 0;
}