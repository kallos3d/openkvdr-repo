#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "kvd_core.h"
#include <iostream>
#include <fstream>
#include <algorithm>

KVDCore::KVDCore() : width(0), height(0) {}

void KVDCore::init() {
    std::cout << "Initializing OpenKVDR Renderer..." << std::endl;
}

bool KVDCore::loadImage(const std::string& filename) {
    int imgWidth, imgHeight, channels;
    uint8_t* imgData = stbi_load(filename.c_str(), &imgWidth, &imgHeight, &channels, 4); // RGBA

    if (!imgData) {
        std::cerr << "Error: Could not load image " << filename << std::endl;
        return false;
    }

    width = imgWidth;
    height = imgHeight;
    framebuffer.resize(width * height);

    for (int i = 0; i < width * height; i++) {
        uint8_t r = imgData[i * 4];
        uint8_t g = imgData[i * 4 + 1];
        uint8_t b = imgData[i * 4 + 2];
        framebuffer[i] = (r << 16) | (g << 8) | b; // Konverzia na 32-bit RGB
    }

    stbi_image_free(imgData);
    std::cout << "Image loaded successfully: " << filename << std::endl;
    return true;
}

void KVDCore::renderRasterization() {
    std::cout << "Rendering image using rasterization..." << std::endl;
    // Simulácia rasterizácie
}

void KVDCore::renderRayTracing() {
    std::cout << "Rendering image using ray tracing..." << std::endl;
    // Simulácia ray tracingu
}

void KVDCore::saveFrameToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "P3\n" << width << " " << height << " 255\n";
        for (int i = 0; i < width * height; i++) {
            file << ((framebuffer[i] >> 16) & 255) << " "
                 << ((framebuffer[i] >> 8) & 255) << " "
                 << (framebuffer[i] & 255) << "\n";
        }
        file.close();
        std::cout << "Frame saved as " << filename << std::endl;
    } else {
        std::cerr << "Error: Could not save frame!" << std::endl;
    }
}

int KVDCore::getWidth() const {
    return width;
}

int KVDCore::getHeight() const {
    return height;
}

void KVDCore::resizeImage(int newWidth, int newHeight) {
    std::cout << "Resizing image to " << newWidth << "x" << newHeight << std::endl;
    width = newWidth;
    height = newHeight;
    framebuffer.resize(width * height);
}

void KVDCore::applyBlur(int radius) {
    std::cout << "Applying blur effect with radius: " << radius << std::endl;
}

void KVDCore::applySharpen() {
    std::cout << "Applying sharpening effect..." << std::endl;
}

void KVDCore::flipImage(bool horizontal) {
    std::cout << "Flipping image " << (horizontal ? "horizontally" : "vertically") << std::endl;
}

void KVDCore::rotateImage(int angle) {
    std::cout << "Rotating image by " << angle << " degrees" << std::endl;
}

void KVDCore::adjustContrast(float value) {
    std::cout << "Adjusting contrast by " << value << std::endl;
}

void KVDCore::adjustBrightness(float value) {
    std::cout << "Adjusting brightness by " << value << std::endl;
}

void KVDCore::invertColors() {
    std::cout << "Inverting colors..." << std::endl;
}

void KVDCore::convertToGrayscale() {
    std::cout << "Converting image to grayscale..." << std::endl;
}

void KVDCore::applyThreshold(int value) {
    std::cout << "Applying threshold effect with value: " << value << std::endl;
}

void KVDCore::addNoise(int intensity) {
    std::cout << "Adding noise with intensity: " << intensity << std::endl;
}

void KVDCore::cropImage(int x, int y, int newWidth, int newHeight) {
    std::cout << "Cropping image to " << newWidth << "x" << newHeight << " from (" << x << ", " << y << ")" << std::endl;
    width = newWidth;
    height = newHeight;
    framebuffer.resize(width * height);
}

void KVDCore::clearFramebuffer() {
    std::cout << "Clearing framebuffer..." << std::endl;
    std::fill(framebuffer.begin(), framebuffer.end(), 0);
}
