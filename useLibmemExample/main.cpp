#include <iostream>
#include <libmem/libmem.hpp>
using libmem::Address;
using libmem::Prot;
using libmem::Arch;
using libmem::Trampoline;
using libmem::Vmt;
using namespace std;

int main() {
	auto process = libmem::FindProcess("RustClient.exe").value();
	std::cout << "[*] Target Process: " << process.to_string() << std::endl;
	auto il2cpp_mod = libmem::FindModule(&process, "GameAssembly.dll");
	std::cout << "[*] IL2Cpp Value: " << il2cpp_mod.value().to_string() << std::endl;
	return 0;
}