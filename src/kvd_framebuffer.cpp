#include "kvd_framebuffer.h"
#include <iostream>
#include <fstream>

KVDFramebuffer::KVDFramebuffer(int w, int h) : width(w), height(h) {
    pixels.resize(w * h * 3, 0);
}

KVDFramebuffer::~KVDFramebuffer() {}

void KVDFramebuffer::clear() {
    std::fill(pixels.begin(), pixels.end(), 0);
}

void KVDFramebuffer::setPixel(int x, int y, int r, int g, int b) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        int index = (y * width + x) * 3;
        pixels[index] = r;
        pixels[index + 1] = g;
        pixels[index + 2] = b;
    }
}

void KVDFramebuffer::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "P3\n" << width << " " << height << " 255\n";
        for (size_t i = 0; i < pixels.size(); i += 3) {
            file << pixels[i] << " " << pixels[i + 1] << " " << pixels[i + 2] << "\n";
        }
        file.close();
        std::cout << "Framebuffer saved to " << filename << std::endl;
    } else {
        std::cerr << "Error: Could not save framebuffer!" << std::endl;
    }
}
