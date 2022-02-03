//---------------------------------------------
//-             Sira� Petmez�iler             -
//-                1306190011                 -
//-                25.05.2020                 -
//-Development environment: Visual Studio 2019-
//---------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Entity {
public:
    string kod;
    string yer;
    bool �lebilir = false;
    bool ba����kl�k = true;
    bool enfekte = false;
    bool hasta = false;
    bool hayatta = true;
    bool yerde = false;
    bool yok = false;
    bool kurtulmus = false;
    int belirti_g�sterme = 0;
    int �lme = 0;
    int kurtulma = 0;
    int yok_olma = 0;
};
bool Yak�nl�k_kar��la�t�rma(string a, string b) {
    string temp = "";
    string temp2 = "";
    int sayac = 0;
    int sayac2 = 0;
    int ax = 0, ay = 0, bx = 0, by = 0;
    for (int i = 0;i < size(a);i++) {
        if (a[i] != 'x' && sayac == 0) {
            temp += a[i];
            ax = stoi(temp);
        }
        else if(a[i] == 'x'){
            sayac++;
            temp = "";
        }
        else if (a[i] != 'x' && sayac == 1) {
            temp += a[i];
            ay = stoi(temp);
        }
    }
    for (int i = 0;i < size(b);i++) {
        if (b[i] != 'x' && sayac2 == 0) {
            temp2 += b[i];
            bx = stoi(temp2);
        }
        else if (b[i] == 'x') {
            sayac2++;
            temp2 = "";
        }
        else if (b[i] != 'x' && sayac2 == 1) {
            temp2 += b[i];
            by = stoi(temp2);
        }
    }
    int farkx = abs(ax - bx);
    int farky = abs(ay - by);
    if (farkx <= 3 && farky <= 3) {
        return true;
    }
    else
    {
        return false;
    }
}
int Xdeki_konumu(string a) {
    int ax = 0;
    string temp = "";
    for (int i = 0;i < size(a);i++) {
        if (a[i] != 'x') {
            temp += a[i];
            ax = stoi(temp);
        }
        else if (a[i] == 'x') {
            break;
        }
    }
    return ax;
}
int Ydeki_konumu(string a) {
    int ay = 0;
    int sayac = 0;
    string temp = "";
    for (int i = 0;i < size(a);i++) {
          if (a[i] == 'x') {
          sayac++;
          }
          else if (a[i] != 'x' && sayac == 1) {
          temp += a[i];
          ay = stoi(temp);
          }
    }
    return ay;
}

int main(){
    string line = "",dna = "", yer = "",turn = "";
    bool hastal�k = false;
    int boyut = 0, turSayisi = 0;
    int boyutBasamak = 0;
    int entitySay�s� = 0;
    map<int, Entity> Entitybilgi;
    int entitySayac = 0;
    vector <vector<string>> Turbilgi;
    int enfektesayac = 0;
    int hastasayac = 0;
    int �l�sayac = 0;
    int kurtulmusayac = 0;
    ifstream efile("INPUT.txt");
    if (efile.is_open()) {
        while (getline(efile, line)) {
            if (line[0] == 'e' && line[1] == 'n' && line[2] == 't' && line[3] == 'i' && line[4] == 't' && line[5] == 'y') {
                entitySay�s�++;
            }
        }
        //cout << entitySay�s�;
        efile.close();
    }
    ifstream file("INPUT.txt");
    if (file.is_open()){
        while (getline(file, line)){
            //cout << line << '\n';
            string temp = "";
            string temp2 = "";
            for(int i = 0; i < size(line);i++){
                if (line[0] == 's' && line[1] == 'i' && line[2] == 'z' && line[3] == 'e' && '0' <= line[i] && line[i] <= '9') {
                    temp += line[i];
                    boyut = stoi(temp);
                    boyutBasamak++;
                }
            }
            //cout << boyutBasamak << endl;
            for (int i = 0; i < size(line);i++) {
                if (line[0] == 't' && line[1] == 'u' && line[2] == 'r' && line[3] == 'n' && line[4] == '_' && '0' <= line[i] && line[i] <= '9') {
                    temp += line[i];
                    turSayisi = stoi(temp);
                }
            }
            // 1 liler
            if (line[0] == 'e' && line[1] == 'n' && line[2] == 't' && line[3] == 'i' && line[4] == 't' && line[5] == 'y' && '0' <= line[7] && line[7] <= '9' && line[8] == ' ') {
                int a;
                for (int j = 9; j <= 13; j++){
                     temp += line[j];
                      dna = temp;
                }
                if (size(line) < 15 + (boyutBasamak) * 2 + 1) {
                    a = size(line);
                }
                else {
                    a = 15 + (boyutBasamak) * 2 + 1;
                }
                for (int j = 15; j <= a;j++) {
                    if (line[j] == ' ') {
                        break;
                    }
                    else
                    {
                        temp2 += line[j];
                        yer = temp2;
                    }
                }
                if (size(line) > 20) {
                    hastal�k = true;
                }
                else
                {
                    hastal�k = false;
                }
                //cout << dna << endl;
                //cout << yer << endl;
                //cout << hastal�k << endl;
                Entitybilgi[entitySayac].kod = dna;
                Entitybilgi[entitySayac].yer = yer;
                Entitybilgi[entitySayac].enfekte = hastal�k;
                entitySayac++;
            }
            // 2 liler
            if (line[0] == 'e' && line[1] == 'n' && line[2] == 't' && line[3] == 'i' && line[4] == 't' && line[5] == 'y' && '0' <= line[7] && line[7] <= '9' && '0' <= line[8] && line[8] <= '9' && line[9] == ' ') {
                int a;
                for (int j = 10; j <= 14; j++) {
                    temp += line[j];
                    dna = temp;
                }
                if (size(line) < 16 + (boyutBasamak) * 2 + 1) {
                    a = size(line);
                }
                else {
                    a = 16 + (boyutBasamak) * 2 + 1;
                }
                for (int j = 16; j <= a ;j++) {
                    if (line[j] == ' ' ) {
                        break;
                    }
                    else
                    {
                        temp2 += line[j];
                        yer = temp2;
                    }
                }
                if (size(line) > 23) {
                    hastal�k = true;
                }
                else
                {
                    hastal�k = false;
                }
                //cout << dna << endl;
                //cout << yer << endl;
                //cout << hastal�k << endl;
                Entitybilgi[entitySayac].kod = dna;
                Entitybilgi[entitySayac].yer = yer;
                Entitybilgi[entitySayac].enfekte = hastal�k;
                entitySayac++;
            }
            // 3 l�ler
            if (line[0] == 'e' && line[1] == 'n' && line[2] == 't' && line[3] == 'i' && line[4] == 't' && line[5] == 'y' && '0' <= line[7] && line[7] <= '9' && '0' <= line[8] && line[8] <= '9' && '0' <= line[9] && line[9] <= '9' && line[10] == ' ') {
                int a;
                for (int j = 11; j <= 15; j++) {
                    temp += line[j];
                    dna = temp;
                }
                if (size(line) < 17 + (boyutBasamak) * 2 + 1) {
                    a = size(line);
                }
                else {
                    a = 17 + (boyutBasamak) * 2 + 1;
                }
                for (int j = 17; j <= a ;j++) {
                    if (line[j] == ' ') {
                        break;
                    }
                    else
                    {
                        temp2 += line[j];
                        yer = temp2;
                    }
                }
                if (size(line) > 25) {
                    hastal�k = true;
                }
                else
                {
                    hastal�k = false;
                }
                //cout << dna << endl;
                //cout << yer << endl;
                //cout << hastal�k << endl;
                Entitybilgi[entitySayac].kod = dna;
                Entitybilgi[entitySayac].yer = yer;
                Entitybilgi[entitySayac].enfekte = hastal�k;
                entitySayac++;
            }
            // 1 li
            if (line[0] == 't' && line[1] == 'u' && line[2] == 'r' && line[3] == 'n' && line[4] == ' ' && '0' <= line[5] && line[5] <= '9' && line[6] == ' ') {
                int sayac3 = 0;
                vector<string>test(entitySay�s�+1);
                for (int i = 7; i <= size(line);i++) {
                    if (line[i] != ' ' && i != size(line)) {
                        temp += line[i];
                        turn = temp;
                    }
                    else if (line[i] != ' ' && i == size(line)) {
                        temp += line[i];
                        turn = temp;
                        test[sayac3] = turn;
                    }
                    else {
                        test[sayac3] = turn;
                        sayac3++;
                        temp = "";
                    }
                }
                Turbilgi.push_back(test);
            }
            // 2 li
            if (line[0] == 't' && line[1] == 'u' && line[2] == 'r' && line[3] == 'n' && line[4] == ' ' && '0' <= line[5] && line[5] <= '9' && '0' <= line[6] && line[6] <= '9' && line[7] == ' ') {
                int sayac3 = 0;
                vector<string>test(entitySay�s�+1);
                for (int i = 8; i <= size(line);i++) {
                    if (line[i] != ' ' && i != size(line)) {
                        temp += line[i];
                        turn = temp;
                    }
                    else if (line[i] != ' ' && i == size(line)) {
                        temp += line[i];
                        turn = temp;
                        test[sayac3] = turn;
                    }
                    else {
                        test[sayac3] = turn;
                        sayac3++;
                        temp = "";
                    }
                }
                Turbilgi.push_back(test);
            }
            // 3l�
            if (line[0] == 't' && line[1] == 'u' && line[2] == 'r' && line[3] == 'n' && line[4] == ' ' && '0' <= line[5] && line[5] <= '9' && '0' <= line[6] && line[6] <= '9' && '0' <= line[7] && line[7] <= '9' && line[8] == ' ') {
                int eleman = 0;
                vector<string>test(entitySay�s�+1);
                for (int i = 9; i <= size(line);i++) {
                    if (line[i] != ' ' && i != size(line)) {
                        temp += line[i];
                        turn = temp;
                    }
                    else if (line[i] != ' ' && i == size(line)) {
                        temp += line[i];
                        turn = temp;
                        test[eleman] = turn;
                    }
                    else {
                        test[eleman] = turn;
                        eleman++;
                        temp = "";
                    }
                }
                Turbilgi.push_back(test);
            }
            // 4l�
            if (line[0] == 't' && line[1] == 'u' && line[2] == 'r' && line[3] == 'n' && line[4] == ' ' && '0' <= line[5] && line[5] <= '9' && '0' <= line[6] && line[6] <= '9' && '0' <= line[7] && line[7] <= '9' && '0' <= line[8] && line[8] <= '9' && line[9] == ' ') {
                int eleman = 0;
                vector<string>test(entitySay�s� + 1);
                for (int i = 10; i <= size(line);i++) {
                    if (line[i] != ' ' && i != size(line)) {
                        temp += line[i];
                        turn = temp;
                    }
                    else if (line[i] != ' ' && i == size(line)) {
                        temp += line[i];
                        turn = temp;
                        test[eleman] = turn;
                    }
                    else {
                        test[eleman] = turn;
                        eleman++;
                        temp = "";
                    }
                }
                Turbilgi.push_back(test);
            }

        }
        /*for (int i = 0; i < size(Turbilgi);i++) {
            for (int j = 0; j < size(Turbilgi);j++) {
                cout << Turbilgi[i][j] << endl;
            }
        }*/
        file.close();
    }
    for (int i = 0;i < entitySay�s�;i++) {
        if (Entitybilgi[i].enfekte == true) {
            enfektesayac++;
        }
    }

    // ba����kl�k ontrol�
    for (int i = 0;i < entitySay�s�;i++) {
        for (int j = 0; j < 5;j++) {
            if (Entitybilgi[i].kod[j] == 'A' || Entitybilgi[i].kod[j] == 'B') {
                Entitybilgi[i].ba����kl�k = false;
            }
        }
    }

    // �lebilirlik kontrol�
    for (int i = 0;i < entitySay�s�;i++) {
        int sayac�l = 0;
        for (int j = 0; j < 5;j++) {
            if (Entitybilgi[i].kod[j] == 'A' || Entitybilgi[i].kod[j] == 'B' || Entitybilgi[i].kod[j] == 'C' || Entitybilgi[i].kod[j] == 'D') {
                sayac�l++;
            }
            if (sayac�l >= 3) {
                Entitybilgi[i].�lebilir = true;
            }
        }
    }

    ofstream bfile("TURNS.txt");
    if (bfile.is_open()) {

        // Turnlerin ba�lang�c�
        for (int tur = 0; tur < turSayisi; tur++) {

            // Bula�t�rma
            for (int i = 0; i < entitySay�s�; i++) {
                for (int j = i + 1; j < entitySay�s�;j++) {
                    if ((Entitybilgi[i].hayatta == true || Entitybilgi[i].yerde == true) && (Entitybilgi[j].hayatta == true || Entitybilgi[j].yerde == true) && Entitybilgi[i].yok != true && Entitybilgi[j].yok != true) {
                        bool asd = Yak�nl�k_kar��la�t�rma(Entitybilgi[i].yer, Entitybilgi[j].yer);
                        if (asd == true) {
                            if ((Entitybilgi[i].hasta == true || Entitybilgi[i].yerde == true) && Entitybilgi[j].hasta == false && Entitybilgi[j].enfekte == false && Entitybilgi[j].ba����kl�k == false && Entitybilgi[j].yerde == false) {
                                Entitybilgi[j].enfekte = true;
                                enfektesayac++;
                            }
                            else if ((Entitybilgi[j].hasta == true || Entitybilgi[j].yerde == true) && Entitybilgi[i].hasta == false && Entitybilgi[i].enfekte == false && Entitybilgi[i].ba����kl�k == false && Entitybilgi[i].yerde == false) {
                                Entitybilgi[i].enfekte = true;
                                enfektesayac++;
                            }
                        }
                    }
                }
            }

            // Kontroller
            for (int i = 0; i < entitySay�s�;i++) {
                if (Entitybilgi[i].enfekte == true) {
                    if (Entitybilgi[i].belirti_g�sterme < 3) {
                        Entitybilgi[i].belirti_g�sterme++;
                    }
                    else if (Entitybilgi[i].belirti_g�sterme == 3) {
                        Entitybilgi[i].hasta = true;
                        Entitybilgi[i].enfekte = false;
                        enfektesayac--;
                        hastasayac++;
                    }
                }
                if ((Entitybilgi[i].hasta == true || Entitybilgi[i].enfekte == true) && Entitybilgi[i].�lebilir == true) {
                    if (Entitybilgi[i].�lme < 14) {
                        Entitybilgi[i].�lme++;
                    }
                    else if (Entitybilgi[i].�lme == 14) {
                        Entitybilgi[i].yerde = true;
                        Entitybilgi[i].hayatta = false;
                        Entitybilgi[i].hasta = false;
                        hastasayac--;
                        �l�sayac++;
                    }
                }
                if ((Entitybilgi[i].hasta == true || Entitybilgi[i].enfekte == true) && Entitybilgi[i].�lebilir == false) {
                    if (Entitybilgi[i].kurtulma < 30) {
                        Entitybilgi[i].kurtulma++;
                    }
                    else if (Entitybilgi[i].kurtulma == 30) {
                        Entitybilgi[i].hasta = false;
                        Entitybilgi[i].ba����kl�k = true;
                        Entitybilgi[i].kurtulmus = true;
                        kurtulmusayac++;
                        hastasayac--;
                    }
                }
                if (Entitybilgi[i].yerde == true) {
                    if (Entitybilgi[i].yok_olma < 5) {
                        Entitybilgi[i].yok_olma++;
                    }
                    else if (Entitybilgi[i].yok_olma == 5) {
                        Entitybilgi[i].yerde = false;
                        Entitybilgi[i].yok = true;
                    }
                }
            }

            // yer de�i�tirme
            for (int i = 0; i < entitySay�s�;i++) {
                if (Entitybilgi[i].hayatta == true && Entitybilgi[i].yok != true) {
                    Entitybilgi[i].yer = Turbilgi[tur][i];
                }
            }

            // yazd�rma
            int x = 0, y = 0;
            vector<vector<char>>habitat;
            vector<char>habi(boyut);
            for (int i = 0;i < boyut;i++) {
                habi[i] = ' ';
            }
            for (int i = 0; i < boyut; i++) {
                for (int k = 0; k < entitySay�s�;k++) {
                    x = Xdeki_konumu(Entitybilgi[k].yer);
                    y = Ydeki_konumu(Entitybilgi[k].yer);
                    for (int j = 0; j < boyut; j++) {
                        if (i == x - 1&& j == y - 1) {
                            if (Entitybilgi[k].hasta == true || Entitybilgi[k].enfekte == true) {
                                habi[j] = 'X';
                            }
                            else if (Entitybilgi[k].kurtulmus == false && (Entitybilgi[k].hasta == false && Entitybilgi[k].enfekte == false && Entitybilgi[k].hayatta == true)) {
                                habi[j] = 'O';
                            }
                            else if (Entitybilgi[k].yerde == true) {
                                habi[j] = 'D';
                            }
                            else if (Entitybilgi[k].kurtulmus == true) {
                                habi[j] = '0';
                            }
                        }
                    }
                }
                habitat.push_back(habi);
                for (int i = 0;i < boyut;i++) {
                    habi[i] = ' ';
                }
            }
            bfile << "Turn " << tur + 1 << ":" << endl;
            for (int i = 0; i < boyut + 2; i++) {
                for (int j = 0; j < boyut + 2; j++) {
                    if (i == 0 || j == 0 || j == boyut + 1 || i == boyut + 1) {
                        bfile << "-";
                    }
                    else {
                        bfile << habitat[i-1][j-1];
                    }
                }
                bfile << endl;
            }
        }
        bfile.close();
    }

    ofstream afile("OUTPUT.txt");
    if (afile.is_open()) {
        afile << "Normal   : " << entitySay�s� - hastasayac - enfektesayac - �l�sayac - kurtulmusayac << endl;
        afile << "Infected : " << enfektesayac + hastasayac << endl;
        afile << "Dead     : " << �l�sayac << endl;
        afile << "Recovered: " << kurtulmusayac << endl;
        string a = "";
        for (int i = 0;i < entitySay�s�; i++) {
            if (Entitybilgi[i].hayatta == true && Entitybilgi[i].enfekte == false && Entitybilgi[i].hasta == false && Entitybilgi[i].yerde == false && Entitybilgi[i].yok == false && Entitybilgi[i].kurtulmus == false) {
                a = "normal";
            }
            if (Entitybilgi[i].hayatta == true && Entitybilgi[i].enfekte == true && Entitybilgi[i].hasta == false && Entitybilgi[i].yerde == false && Entitybilgi[i].yok == false && Entitybilgi[i].kurtulmus == false) {
                a = "infected";
            }
            if (Entitybilgi[i].hayatta == true && Entitybilgi[i].enfekte == false && Entitybilgi[i].hasta == true && Entitybilgi[i].yerde == false && Entitybilgi[i].yok == false && Entitybilgi[i].kurtulmus == false) {
                a = "infected";
            }
            if (Entitybilgi[i].hayatta == false && Entitybilgi[i].enfekte == false && Entitybilgi[i].hasta == false && Entitybilgi[i].yerde == true && Entitybilgi[i].yok == false && Entitybilgi[i].kurtulmus == false) {
                a = "dead";
            }
            if (Entitybilgi[i].hayatta == false && Entitybilgi[i].enfekte == false && Entitybilgi[i].hasta == false && Entitybilgi[i].yerde == false && Entitybilgi[i].yok == true && Entitybilgi[i].kurtulmus == false) {
                a = "dead";
            }
            if (Entitybilgi[i].hayatta == true && Entitybilgi[i].enfekte == false && Entitybilgi[i].hasta == false && Entitybilgi[i].yerde == false && Entitybilgi[i].yok == false && Entitybilgi[i].kurtulmus == true) {
                a = "immune";
            }
            afile << "entity " << i + 1 << " " << Entitybilgi[i].yer << " " << a << endl;
        }
        afile.close();
    }
}