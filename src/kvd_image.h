#ifndef KVD_IMAGE_H
#define KVD_IMAGE_H

#include <string>
#include <cstdint> // Opravené! Pridanie uint32_t

class KVDImage {
public:
    bool saveImage(const std::string& filename, const uint32_t* framebuffer, int width, int height);
};

#endif
