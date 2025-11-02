//this is normal hft buffer which gives an example of use of move constructor
#include <memory>
#include <iostream>
class HFTBuffer {
    std::unique_ptr<double[]> data;
    size_t size;
public:
    HFTBuffer(size_t n) : size(n), data(std::make_unique<double[]>(n)) 
    {
        std::cout << "Buffer of " << size << " doubles created\n";
    }
    HFTBuffer(HFTBuffer&& other) noexcept 
        : size(other.size), data(std::move(other.data)) {
        std::cout << "Buffer stolen. Size: " << size << "\n";
        other.size = 0;  
    }

    size_t get_size() const 
    { 
      return size; 
    }
};

void process(HFTBuffer buf) 
{  
    std::cout << "Processing buffer of size " << buf.get_size() << "\n";
}

int main() {
    HFTBuffer source(1'000'000);
    process(std::move(source)); 
}
