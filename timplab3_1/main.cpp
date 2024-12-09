#include  "modAlphakey.h"
using namespace std;
bool isValid(const string& s)
{
    for (auto c:s)
        if (!isalpha(c) || !isupper(c))
            return false;
    return true;
}

int main()
{
    int key;
    string text;
    int op;
    cout<<"Cipher ready. Input key: ";
    cin>>key;
    if (!wcin.good()) {
        cerr<<"key not valid\n";
        return 0;
    }

    modAlphakey cipher(key);
    do {
        cout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        cin>>op;
        if (op > 2) {
            cout<<"Illegal operation\n";
        } else if (op >0) {
            cout<<"Cipher ready. Input text: ";
            cin>>text;
            if (isValid(text)) {
                if (op==1) {
                    cout<<"Encrypted text: "<<cipher.encrypt(text)<<endl;
                } else {
                    cout<<"Decrypted text: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                cout<<"Operation aborted: invalid text\n";
            }
        }
    } while (op!=0);
    return 0;
}













