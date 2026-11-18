#include <iostream>
#include <string>
using namespace std;

int main() {
    string pt, ct = "", dec = "";
    int key;

    cout << "Enter plaintext: ";
    cin >> pt;
    cout << "Enter key: ";
    cin >> key;

    key = (key % 26 + 26) % 26;

    // Encryption
    for (int i = 0; i < pt.length(); i++) {
        if (pt[i] >= 'A' && pt[i] <= 'Z')
            ct += (pt[i] - 'A' + key) % 26 + 'A';
        else if (pt[i] >= 'a' && pt[i] <= 'z')
            ct += (pt[i] - 'a' + key) % 26 + 'a';
        else
            ct += pt[i];
    }
    cout << "Encrypted text: " << ct << endl;

    // Decryption
    for (int i = 0; i < ct.length(); i++) {
        if (ct[i] >= 'A' && ct[i] <= 'Z')
            dec += (ct[i] - 'A' - key + 26) % 26 + 'A';
        else if (ct[i] >= 'a' && ct[i] <= 'z')
            dec += (ct[i] - 'a' - key + 26) % 26 + 'a';
        else
            dec += ct[i];
    }
    cout << "Decrypted text: " << dec << endl;
    return 0;
}