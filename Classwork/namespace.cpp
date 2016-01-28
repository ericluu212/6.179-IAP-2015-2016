#include <cstdio>

namespace sheepville {
 void talk() { printf("baa\n"); }
}
namespace pigland {
 void talk() { printf("oink oink\n"); }
}

using namespace pigland;

int main() {
 sheepville::talk();
 talk();
 return 0;
}