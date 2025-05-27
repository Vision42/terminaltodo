//
// Created by philipp on 23.05.25.
//

#include "AudioService.h"

#include "StorageService.h"
#include "Exceptions/IOException.h"

AudioService::AudioService() {
    if (! notificationBuffer.loadFromFile(StorageService::getApplicationDirectory()  + TIME_UP_SOUND)) {
        throw IOException("Failed to load notification audio buffer");
    }
}

void AudioService::playNotificationSound() {
    sound.setBuffer(notificationBuffer);
    sound.play();
}
