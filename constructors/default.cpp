//this is a example of default constructors a quantum pool where all the qubits are starting from zero
#include <array>
#include <iostream>
template<size_t N>
class DefaultQubitPool {
    std::array<bool, N> qubits;
public:
    DefaultQubitPool() : qubits{} 
    {
        std::cout << "Quantum pool of " << N << " qubits born in |0...0>\n";
    }
    void measure_all() const 
    {
        for (size_t i = 0; i < N; ++i)
            std::cout << "Qubit " << i << ": |" << qubits[i] << ">\n";
    }

};
auto quantum_memory = DefaultQubitPool<8>();
int main() {
    quantum_memory.measure_all();  // All |0>
}
