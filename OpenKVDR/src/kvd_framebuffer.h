#ifndef KVD_FRAMEBUFFER_H
#define KVD_FRAMEBUFFER_H

#include <vector>
#include <string>

class KVDFramebuffer {
public:
    KVDFramebuffer(int width, int height);
    ~KVDFramebuffer();

    void clear();
    void setPixel(int x, int y, int r, int g, int b);
    void saveToFile(const std::string& filename);

private:
    int width, height;
    std::vector<int> pixels;
};

#endif
