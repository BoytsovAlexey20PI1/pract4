#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include "aes.h"
#include "des.h"

using namespace std;
using namespace CryptoPP;


int main ()
{
    unsigned op, cip;
    string FIn, FOut, Pass;

    do {
        cout << "\nВыберите операцию (0 - exit, 1 - encrypt, 2 - decrypt): ";
        cin >> op;

        if (op != 0) {
            cout << "\nВыберите способ: (1 - AES-256, 2 - DES): ";
            cin >> cip;
        }

        if (op > 2) {
            cerr << "Error! Invalid operation\n";
        }

        else if (op > 0) {
            cout << "\nУкажите путь изначального файла: ";
            cin >> FIn;

            cout << "\nУкажите путь конечного файла: ";
            cin >> FOut;

            cout << "\nВведите пароль: ";
            cin >> Pass;

            if (cip == 1) {
                AES_Cryptor aes(FIn, FOut, Pass);

                if (op == 1) {
                    if (aes.AES_Encrypt())
                        cout << "Успешно закодировано" << endl;
                    else
                        cout << "Кодирование не удалось" << endl;
                } else {
                    if (aes.AES_Decrypt())
                        cout << "Успешно декодировано" << endl;
                    else
                        cout << "Успешно декодировано" << endl;
                }
            }


            else if (cip == 2) {
                DES_Cryptor des(FIn, FOut, Pass);

                if (op == 1) {
                    if (des.DES_Encrypt())
                        cout << "Успешно закодировано" << endl;
                    else
                        cout << "Кодирование не удалось" << endl;
                } else {
                    if (des.DES_Decrypt())
                        cout << "Успешно декодировано" << endl;
                    else
                        cout << "Успешно декодировано" << endl;
                }
            } else {
                cerr << "Error! Incorrect algorithm number!!!\n";
            }
        }

    } while (op != 0);

    return 0;
}