#include <iostream>
#include <fstream>
#include <set>
#include <vector>




using namespace std;

set<int> st;
vector<int> base;
vector<int> sol;
const int mod=1000000007;




int main(int argc, char * argv[]) {


    ifstream infile(argv[1]);
    if(!infile.is_open()){
        cout << "input problem";
        return 0;
    }
    base.resize(1000);
    base[0]=1;
    for(int j=1;j<1000;j++){
        base[j]=((long long)base[j-1]*31) % (mod);
    }
    string message;
    int N;
    infile >> message >> N;
    message=' ' + message;
    sol.resize(message.length());

    string dic;


    for(int i=0;i<N;i++){
        infile >>dic;
        int hash=0;
        for(int k=0;k<dic.length();k++){
           hash = (hash+ (long long)(dic[k]-'a'+1)*base[dic.length()-k-1])%(mod);
        }
        st.insert(hash);
    }


    sol[0]=1;

    for(int l=1;l<sol.size();l++) {
        int hash = 0;
        for (int k = l; k > 0; k--) {

            hash = (hash + ((long long) message[k] - 'a' + 1) * base[l - k]) % mod;
            if (st.find(hash) != st.end()) {

                sol[l] = (sol[l] + sol[k - 1]) % (1000000007);

            }
        }
    }

    ofstream output;
    output.open(argv[2]);

    output <<sol[sol.size()-1];

    output.close();



return 0;

}