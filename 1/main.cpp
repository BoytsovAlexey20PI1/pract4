#include <iostream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>
#include <string>
using namespace std;
int main (int argc, char* argv[])
{
    using namespace CryptoPP;
    SHA1 hash;
    cout << "Name: " << hash.AlgorithmName() << endl;
    cout << "Digest size: " << hash.DigestSize() << endl;
    cout << "Block size: " << hash.BlockSize() << endl;
    string msg;
    ifstream fin;
    fin.open("/home/kali/Рабочий стол/File1.txt");
    while (getline(fin,msg)) {
        vector<byte> digest(hash.DigestSize());
        hash.Update((const byte*)msg.data(), msg.size());
        hash.Final(digest.data());
        cout << "Message: " << msg << endl;
        cout << "Digest: ";
        StringSource(digest.data(), digest.size(), true, new HexEncoder(new FileSink(cout)));
        cout << endl;
    }
    fin.close();
    return 0;
}
