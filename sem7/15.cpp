#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Command {
    string name;  // название команды
    int value;    // числовой параметр (0, если нет)
};

void parseCommand(const char* input, vector<Command>& buffer) {
    Command cmd;
    cmd.value = 0; // значение по умолчанию

    const char* p = input; // указатель на начало строки

    // „итаем им€ команды (до пробела или конца строки)
    string name = "";
    while (*p != ' ' && *p != '\0') {
        name += *p;
        p++;
    }
    cmd.name = name;

    // ≈сли есть пробел, читаем число
    if (*p == ' ') {
        p++; // пропускаем пробел

        // „итаем число
        int num = 0;
        while (*p >= '0' && *p <= '9') {
            num = num * 10 + (*p - '0');
            p++;
        }
        cmd.value = num;
    }

    // ƒобавл€ем команду в буфер
    buffer.push_back(cmd);
}

int main() {
    vector<Command> buffer;

    parseCommand("FORWARD 10", buffer);
    parseCommand("TURN 90", buffer);
    parseCommand("STOP", buffer);
    parseCommand("BACKWARD 5", buffer);
    parseCommand("WAIT", buffer);

    // ¬ыводим все команды
    for (const Command& cmd : buffer) {
        cout << "Command: " << cmd.name << ", Value: " << cmd.value << endl;
    }

    return 0;
}