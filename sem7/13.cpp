#include <iostream>
using namespace std;

void parseTelemetry(const char* data) {
    const char* p = data;

    while (*p != '\0') {
        // Читаем имя параметра
        char name[20];
        int i = 0;
        while (*p != ':' && *p != '\0' && i < 19) {
            name[i++] = *p;
            p++;
        }
        name[i] = '\0';

        if (*p == ':') {
            p++; // пропускаем двоеточие

            // Читаем значение
            char value[20];
            i = 0;
            while (*p != ';' && *p != '\0' && i < 19) {
                value[i++] = *p;
            }
        }
    }
}