#include "kvd_cli.h"
#include <iostream>
#include <sstream>
#include <cstdlib> // Pre exit()

KVDCli::KVDCli() {
    commands["help"] = [&](const std::string&) {
        std::cout << "Commands:\n";
        std::cout << "  load [filename]      - Load image\n";
        std::cout << "  render raster        - Render using rasterization\n";
        std::cout << "  render raytrace      - Render using ray tracing\n";
        std::cout << "  save [filename]      - Save output image\n";
        std::cout << "  gtd [path]           - Get directory of image\n";
        std::cout << "  ld [filename]        - Load image and display info\n";
        std::cout << "  rndr [filename]      - Render and save image\n";
        std::cout << "  exit                 - Quit OpenKVDR\n";
        std::cout << "  clear                - Clear framebuffer\n";
        std::cout << "\nImage Editing Commands:\n";
        std::cout << "  resize [width] [height] - Resize image\n";
        std::cout << "  blur [radius]           - Apply blur effect\n";
        std::cout << "  sharpen                 - Apply sharpening filter\n";
        std::cout << "  flip horizontal/vertical - Flip image\n";
        std::cout << "  rotate [angle]          - Rotate image by angle\n";
        std::cout << "  contrast [value]        - Adjust contrast\n";
        std::cout << "  brightness [value]      - Adjust brightness\n";
        std::cout << "  invert                  - Invert colors\n";
        std::cout << "  grayscale               - Convert to grayscale\n";
        std::cout << "  threshold [value]       - Apply threshold effect\n";
        std::cout << "  noise [intensity]       - Add noise to image\n";
        std::cout << "  crop [x] [y] [w] [h]    - Crop image\n";
    };

    commands["gtd"] = [&](const std::string& arg) {
        std::cout << "Image is located at: " << arg << std::endl;
    };

    commands["ld"] = [&](const std::string& arg) {
        if (renderer.loadImage(arg)) {
            std::cout << "✅ Image loaded successfully!\n";
            std::cout << "  Width: " << renderer.getWidth() << "\n";
            std::cout << "  Height: " << renderer.getHeight() << "\n";
        } else {
            std::cerr << "❌ Error: Failed to load image!\n";
        }
    };

    commands["rndr"] = [&](const std::string& arg) {
        std::cout << "🎨 Rendering and saving image as " << arg << "...\n";
        renderer.renderRasterization();
        renderer.saveFrameToFile(arg);
        std::cout << "✅ Rendering complete!\n";
    };

    commands["resize"] = [&](const std::string& arg) {
        int width, height;
        std::istringstream iss(arg);
        if (iss >> width >> height && width > 0 && height > 0) {
            renderer.resizeImage(width, height);
            std::cout << "📏 Image resized to " << width << "x" << height << ".\n";
        } else {
            std::cerr << "❌ Error: Invalid parameters! Usage: resize [width] [height]\n";
        }
    };

    commands["blur"] = [&](const std::string& arg) {
        int radius;
        std::istringstream iss(arg);
        if (iss >> radius && radius > 0) {
            renderer.applyBlur(radius);
            std::cout << "✨ Blur effect applied with radius: " << radius << ".\n";
        } else {
            std::cerr << "❌ Error: Invalid radius! Usage: blur [radius]\n";
        }
    };

    commands["sharpen"] = [&](const std::string&) {
        renderer.applySharpen();
        std::cout << "🔪 Sharpening filter applied.\n";
    };

    commands["flip"] = [&](const std::string& arg) {
        if (arg == "horizontal") {
            renderer.flipImage(true);
            std::cout << "↔️ Image flipped horizontally.\n";
        } else if (arg == "vertical") {
            renderer.flipImage(false);
            std::cout << "↕️ Image flipped vertically.\n";
        } else {
            std::cerr << "❌ Error: Invalid flip option! Use 'horizontal' or 'vertical'.\n";
        }
    };

    commands["rotate"] = [&](const std::string& arg) {
        int angle;
        std::istringstream iss(arg);
        if (iss >> angle) {
            renderer.rotateImage(angle);
            std::cout << "🔄 Image rotated by " << angle << " degrees.\n";
        } else {
            std::cerr << "❌ Error: Invalid angle! Usage: rotate [angle]\n";
        }
    };

    commands["contrast"] = [&](const std::string& arg) {
        float value;
        std::istringstream iss(arg);
        if (iss >> value) {
            renderer.adjustContrast(value);
            std::cout << "🎚️ Contrast adjusted by " << value << ".\n";
        } else {
            std::cerr << "❌ Error: Invalid value! Usage: contrast [value]\n";
        }
    };

    commands["brightness"] = [&](const std::string& arg) {
        float value;
        std::istringstream iss(arg);
        if (iss >> value) {
            renderer.adjustBrightness(value);
            std::cout << "☀️ Brightness adjusted by " << value << ".\n";
        } else {
            std::cerr << "❌ Error: Invalid value! Usage: brightness [value]\n";
        }
    };

    commands["invert"] = [&](const std::string&) {
        renderer.invertColors();
        std::cout << "🔄 Colors inverted.\n";
    };

    commands["grayscale"] = [&](const std::string&) {
        renderer.convertToGrayscale();
        std::cout << "⚪ Image converted to grayscale.\n";
    };

    commands["threshold"] = [&](const std::string& arg) {
        int value;
        std::istringstream iss(arg);
        if (iss >> value && value >= 0 && value <= 255) {
            renderer.applyThreshold(value);
            std::cout << "⚫ Threshold effect applied with value: " << value << ".\n";
        } else {
            std::cerr << "❌ Error: Invalid value! Usage: threshold [0-255]\n";
        }
    };

    commands["noise"] = [&](const std::string& arg) {
        int intensity;
        std::istringstream iss(arg);
        if (iss >> intensity && intensity > 0) {
            renderer.addNoise(intensity);
            std::cout << "🎲 Noise added with intensity: " << intensity << ".\n";
        } else {
            std::cerr << "❌ Error: Invalid intensity! Usage: noise [intensity]\n";
        }
    };

    commands["clear"] = [&](const std::string&) {
        renderer.clearFramebuffer();
        std::cout << "🗑️ Framebuffer cleared.\n";
    };

    commands["exit"] = [&](const std::string&) {
        std::cout << "👋 Exiting OpenKVDR...\n";
        exit(0);
    };
}

void KVDCli::start() {
    std::string input, command, arg;
    std::cout << " OpenKVDR CLI Renderer - Version 1.1.0\n";
    std::cout << " Type 'help' to see available commands.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        std::istringstream iss(input);
        iss >> command;
        std::getline(iss, arg);
        if (!arg.empty() && arg[0] == ' ') arg = arg.substr(1);

        if (commands.find(command) != commands.end()) {
            commands[command](arg);
        } else {
            std::cerr << "❌ Unknown command! Type 'help' for a list of commands.\n";
        }
    }
}
