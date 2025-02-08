#ifndef KVD_VIDEO_H
#define KVD_VIDEO_H

#include <string>

class KVDVideo {
public:
    KVDVideo();
    bool saveVideo(const std::string& filename);
};

#endif
