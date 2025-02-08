#include "kvd_image.h"
#include <fstream>
#include <cstdint> // Opravené! Pridanie uint32_t

bool KVDImage::saveImage(const std::string& filename, const uint32_t* framebuffer, int width, int height) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        return false;
    }

    // Uloženie framebufferu ako surové binárne dáta
    file.write(reinterpret_cast<const char*>(framebuffer), width * height * sizeof(uint32_t));
    file.close();
    return true;
}
