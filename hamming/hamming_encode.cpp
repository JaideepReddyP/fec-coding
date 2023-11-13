// 3b1b implementation of hamming encoding
// even parity
// 4x4 block with 4 partial parity(1,2,4,8), 1 total parity(0), 11 data(all remaining)
// NOT AN OPTIMAL IMPLEMENTATION : only for understanding

#include<bits/stdc++.h>
using namespace std;

string hamming_encode(string data) {
    vector<vector<int>> block(4, vector<int>(4, 0));
    int p = 3;
    for(char c : data) {
        if(p == 4 || p == 8) p++;
        block[p/4][p%4] = c - '0';
        p++;
    }
    
    // partial parity
    for(int i = 1; i < 16; i++) {
        int bit = block[i/4][i%4];
        if((i & 1) == 1) block[0][1] ^= bit;
        if((i & 2) == 2) block[0][2] ^= bit;
        if((i & 4) == 4) block[1][0] ^= bit;
        if((i & 8) == 8) block[2][0] ^= bit;
    }

    // total parity
    for(int i = 1; i < 16; i++) {
        block[0][0] ^= block[i/4][i%4];
    }

    string encoded = "";
    for(int i = 0; i < 16; i++) {
        encoded += to_string(block[i/4][i%4]);
    }

    return encoded;
}

int main() {
    string data;
    cin >> data;

    string encoded_data = hamming_encode(data);
    cout << encoded_data;
}