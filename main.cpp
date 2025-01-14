#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

uint8_t shift_encoding = 4;
uint8_t shift_decoding = 9;

const char rotor0[] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
const char rotor1[] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
const char rotor2[] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

uint8_t find_Index(char c, const char *array) {
    for (uint8_t i = 0; i <= 25; i++) if (array[i] == c) return i;
}

void Enigma(const char *message, char *message_2, bool mode) {
    char c;
    for (uint8_t i = 0; message[i] != '\0'; i++) {
        if(mode) {
            c = message[i];
            c = alphabet[find_Index(c, rotor2)];
            c = alphabet[find_Index(c, rotor1)];
            c = alphabet[find_Index(c, rotor0)];

            c = alphabet[(find_Index(c, alphabet) - shift_decoding - i + 26) % 26];
            message_2[i] = c;
        } else {
            c = alphabet[(find_Index(message[i], alphabet) + shift_encoding + i) % 26];

            c = rotor0[find_Index(c, alphabet)];
            c = rotor1[find_Index(c, alphabet)];
            c = rotor2[find_Index(c, alphabet)];
            message_2[i] = c;
        }
    }
}

int main() {
    const char *message = "AAA";
    char cipher[50];
    const char *encoder = "PQSACVVTOISXFXCIAMQEM";
    char decoder[50];


    printf("\t\t\tEncoding\n\n");
    Enigma(message, cipher, 0);
    printf("Source text: %s\n", message);
    printf("Drain text: %s\n", cipher);

    printf("\t\t\t\tDecoding\n\n");
    Enigma(encoder, decoder, 1);
    printf("Source text: %s\n", encoder);
    printf("Drain text: %s\n", decoder);

    return 0;
}
