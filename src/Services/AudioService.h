//
// Created by philipp on 23.05.25.
//

#ifndef AUDIOSERVICE_H
#define AUDIOSERVICE_H

#include <SFML/Audio.hpp>
#include <string>

class AudioService {
public:
    AudioService();
    void playNotificationSound();

private:
    const std::string TIME_UP_SOUND = "timeup.ogg";

    sf::SoundBuffer notificationBuffer;
    sf::Sound sound;

    void playSound();
};



#endif //AUDIOSERVICE_H
