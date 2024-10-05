#include "D:\”нивер\3 семестр\ќќѕиѕ\OOPaP 2 semester\Laba1\ConverterSystem.h"
#include <Windows.h>
#include <iostream>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    set_terminate(myTerminate);

    ConverterSystem sys;
    sys.menu();

    return 0;
}
