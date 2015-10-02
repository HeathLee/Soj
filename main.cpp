#include <iostream>
#include <vector>

using namespace std;

class DNA {
private:
    string dna;
public:
    DNA(string dna) {
        this->dna = dna;
    }
    string get_matched_dna() {
        string result = "";
        for (int i = 0; i < dna.length(); ++i) {
            switch (dna.at(i)) {
                case 'A':
                    result += "T";
                    break;
                case 'T':
                    result += "A";
                    break;
                case 'G':
                    result += "C";
                    break;
                case 'C':
                    result += "G";
                    break;
            }
        }
        return result;
    }
    string get_dna() {
        return dna;
    }
};

int main() {
    vector<DNA*> dna;
    int case_number;
    cin >> case_number;
    while (case_number--) {
        int dna_number, count = 0;
        cin >> dna_number;
        while (dna_number--) {
            string input_dna;
            cin >> input_dna;
            dna.push_back(new DNA(input_dna));
        }
        vector<DNA *>::iterator iterator = dna.begin();
        for (; iterator != dna.end(); iterator++) {
            vector<DNA *>::iterator temp = iterator;
            temp++;
            while (temp != dna.end()) {
                if ((*iterator)->get_matched_dna() == (*temp)->get_dna()) {
                    count++;
                    dna.erase(temp);
                    break;
                } else {
                    temp++;
                }
            }
        }
        dna.clear();
        cout << count << endl;
    }
    return 0;
}
