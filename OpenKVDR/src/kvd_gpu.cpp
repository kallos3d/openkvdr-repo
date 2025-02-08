#include "kvd_gpu.h"
#include <iostream>

KVDGPU::KVDGPU() {}

void KVDGPU::optimizeForNvidia() {
    std::cout << "Optimizing OpenKVDR for NVIDIA GPUs..." << std::endl;
}

void KVDGPU::optimizeForIntel() {
    std::cout << "Optimizing OpenKVDR for Intel GPUs..." << std::endl;
}
