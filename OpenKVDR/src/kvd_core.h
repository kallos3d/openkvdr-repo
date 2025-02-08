#ifndef KVD_CORE_H
#define KVD_CORE_H

#include <vector>
#include <string>
#include <cstdint>

class KVDCore {
public:
    KVDCore();

    void init();
    bool loadImage(const std::string& filename);
    void renderRasterization();
    void renderRayTracing();
    void saveFrameToFile(const std::string& filename);

    // Nové metódy pre podporu CLI príkazov
    int getWidth() const;
    int getHeight() const;

    void resizeImage(int width, int height);
    void applyBlur(int radius);
    void applySharpen();
    void flipImage(bool horizontal);
    void rotateImage(int angle);
    void adjustContrast(float value);
    void adjustBrightness(float value);
    void invertColors();
    void convertToGrayscale();
    void applyThreshold(int value);
    void addNoise(int intensity);
    void cropImage(int x, int y, int width, int height);
    void clearFramebuffer();

private:
    int width, height;
    std::vector<uint32_t> framebuffer;
};

#endif
