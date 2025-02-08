#include "kvd_video.h"
#include <iostream>

KVDVideo::KVDVideo() {}

bool KVDVideo::saveVideo(const std::string& filename) {
    std::cout << "Saving video to: " << filename << std::endl;
    
    // Tu sa môže integrovať FFmpeg na skutočný export videa
    return true;
}
