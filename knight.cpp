#include "knight.h"

#define debug(x) { cout << #x << " = "; cout << (x) << endl; }
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
//Prime number
bool isPrime(int n) {
    int count = 0;
    if (n == 1) {
        return false;
    }
    else if (n == 2) {
        return true;
    }
    else {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        if (count > 0) {
            return false;
        }
        else {
            return true;
        }
    }
}

//Check Lancelot
bool Lancelot(int& HP) {
    bool flag = isPrime(HP);
    if (flag) {
        return true;
    }
    else {
        return false;
    }
}
bool Arthur(int& HP) {
    if (HP == 999) {
        return true;
    }
    else {
        return false;
    }
}

//Battle1to5 //i was event ith
void Battle1to5(float basedamage, int i, int& level, int& HP, bool isArthur, bool isLancelot) { //i is event i
    int damage;
    int b, levelO;
    if (isArthur) {
        if (level < 10) {
            level++;
        }
    }
    else if (isLancelot) {
        if (level < 10) {
            level++;
        }
    }
    else {
        b = i % 10;
        levelO = i > 6 ? (b > 5 ? b : 5) : b;
        if (level > levelO) {
            if (level < 10) {
                level++;
            }
        }
        else if (level < levelO) {
            damage = (int)(basedamage * levelO * 10);
            HP = HP - damage;
        }
        else {
            level = level;
        }
    }
}
//Mini
void BattleShaman(int& i, int& level, int& HP, int& remedy, bool& isMini, int& maxHP) { //i is event i
    int b, levelO;
    b = (i + 1) % 10;
    levelO = i > 6 ? (b > 5 ? b : 5) : b;
    if (level > levelO) {
        if (level < 9) {
            level = level + 2;
        }
        else {
            level = 10;
        }
    }
    else if (level < levelO) {
        if (remedy > 0) {
            remedy--;
            HP = maxHP;
        }
        else {
            if (HP < 5) {
                HP = 1;
            }
            else {
                HP = HP / 5;
                isMini = true;
            }
        }

    }
}
//Frog
void BattleVajsh(int& i, int& level, int& HP, int& maidenkiss, bool& isFrog, int& level_temp) { //i is event i
    int b, levelO;
    b = (i + 1) % 10;
    levelO = i > 6 ? (b > 5 ? b : 5) : b;
    if (level > levelO) {
        if (level < 9) {
            level = level + 2;
        }
        else {
            level = 10;
        }
    }
    else if (level < levelO) {
        if (maidenkiss > 0) {
            maidenkiss--;
            isFrog = false;
        }
        else {
            level_temp = level;
            level = 1;
            isFrog = true;
        }
    }
}

//Fibonanci Mush
int Fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return Fib(n - 1) + Fib(n - 2);
    }
}
void FibMush(int& HP) {
    int i = 1;
    if (HP == 1) {
        HP = HP;
    }
    else if (HP > 1) {
        while (Fib(i) < HP) i++;
    }
    i--;
    HP = Fib(i);
}

//Mario Mush
void MarioMush(int& HP, int& level, int& phoenixdown, int& maxHP) {
    int n1 = ((level + phoenixdown) % 5 + 1) * 3;
    int s1 = 0;
    s1 = (99 * 2 - 2 * (n1 - 1)) / 2 * n1;
    HP = HP + s1 % 100;
    while (!isPrime(HP)) {
        HP++;
    }
    if (HP > maxHP) {
        HP = maxHP;
    }
}

//Asclepius
void Asclepius(string file_aclepius, int& remedy, int& maidenkiss, int& phoenixdown) {
    int r1, c1;
    int temp;
    int arr[100][100] ;
    ifstream ifs;
    ifs.open(file_aclepius);
    ifs >> r1 >> c1;
    for (int a = 0; a < r1; a++) {
        for (int b = 0; b < c1; b++) {
            ifs >> temp;
            arr[a][b] = temp;
        }
    }

    ifs.close();
    int count = 0;
    for (int a = 0; a < r1; a++) {
        for (int b = 0; b < c1; b++) {
            if (arr[a][b] == 16) {
                if (remedy < 99) {
                    remedy++;
                    count++;
                }
            }
            else if (arr[a][b] == 17) {
                if (maidenkiss < 99) {
                    maidenkiss++;
                    count++;
                }
            }
            else if (arr[a][b] == 18) {
                if (phoenixdown < 99) {
                    phoenixdown++;
                    count++;
                }
            }
            if (count == 3) break;
        }
        count = 0;
    }
}

//Merlin
bool Check3HP(string str) {
    int check1 = str.find("Merlin");
    int check2 = str.find("merlin");
    if (check1 != string::npos) {
        return true;
    }
    else if (check2 != string::npos) {
        return true;
    }
    else {
        return false;
    }
}
bool Check2HP(string str) {
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            int ch = str[i];
            str[i] = toupper(ch);
        }
    }
    int a1(0), a2(0), a3(0), a4(0), a5(0), a6(0);
    for (int i = 0; i < len; i++) {
        if (str[i] == 'M') {
            a1++;
        }
        else if (str[i] == 'E') {
            a2++;
        }
        else if (str[i] == 'R') {
            a3++;
        }
        else if (str[i] == 'L') {
            a4++;
        }
        else if (str[i] == 'I') {
            a5++;
        }
        else if (str[i] == 'N') {
            a6++;
        }
    }
    if (a1 * a2 * a3 * a4 * a5 * a6 == 0) {
        return false;
    }
    else {
        return true;
    }

}
void Merlin(string file_input, int& HP, int& maxHP) {
    int i = 0;
    int n9;
    ifstream ifs;
    string line;
    ifs.open(file_input);
    ifs >> n9;
    getline(ifs, line);
    while (getline(ifs, line)) {
        if (Check3HP(line)) {
            HP = HP + 3;
        }
        else if (Check2HP(line)) {
            HP = HP + 2;
        }
        i++;
    }
    ifs.close();
    if (HP > maxHP) {
        HP = maxHP;
    }
}
void MushGhost1(int n,int *arr, int& HP, int& maxHP) {
    int maxnum = -1e9;
    int minnum = 1e9;
    int mini, maxi;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxnum) {
            maxnum = arr[i];
            maxi = i;
        }
        if (arr[i] < minnum) {
            minnum = arr[i];
            mini = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == maxnum && i > maxi) {
            maxi = i;
        }
        if (arr[i] == minnum && i > mini) {
            mini = i;
        }
    }
    HP = HP - (maxi + mini);
    
}
void MushGhost2(int n,int *arr, int& HP, int& maxHP) {
    int climbUp = 0;
    int climbDown = n - 1;
    bool check = false;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[climbUp + 1] > arr[climbUp]) {
            climbUp++;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (arr[climbDown] < arr[climbDown - 1]) {
            climbDown--;
        }
    }
    if (climbDown == climbUp) {
        pos = climbDown;
        check = true;
    }
    else if (n == 1) {
        check = true;
    }
    else {
        check = false;
    }
    if (check) {
        HP = HP - arr[pos] - pos;
    }
    else {
        HP = HP + 5;
    }
    if (HP > maxHP) {
        HP = maxHP;
    }
}
void MushGhost3(int n,int *arr, int & HP, int& maxHP) {
    int arrchange[1000];
    for (int i = 0; i < n; i++) {
        arrchange[i] = arr[i] < 0 ? -arr[i] : arr[i];
        arrchange[i] = (17 * arrchange[i] + 9) % 257;
    }

    int maxnum = -1e9;
    int minnum = 1e9;
    int maxi2 = 0;
    int mini2 = 0;
    for (int i = 0; i < n; i++) {
        if (arrchange[i] > maxnum) {
            maxnum = arrchange[i];
            maxi2 = i;
        }
        if (arrchange[i] < minnum) {
            minnum = arrchange[i];
            mini2 = i;
        }
    }
    HP = min(HP - (maxi2+mini2),maxHP);
}
void MushGhost4(int n, int *arr, int& HP, int& maxHP) {
    int temp;
    int arrchange[1000];
    for (int i = 0; i < n; i++) {
        arrchange[i] = arr[i] < 0 ? -arr[i] : arr[i];
        arrchange[i] = (17 * arrchange[i] + 9) % 257;
    }
    if (n == 1) {
        HP = HP + 12;
    }
    else if (n == 2) {
        if (arrchange[0] == arrchange[1]) {
            HP = HP + 12;
        }
        else if (arrchange[0] > arrchange[1]) {
            HP = HP - arrchange[1] - 1;
        }
        else {
            HP = HP - arrchange[0];
        }
    }
    else if (arrchange[0] == arrchange[1] && arrchange[1] == arrchange[2]) {
        HP = HP + 12;
    }
    else if (arrchange[0] == arrchange[1] && arrchange[0] > arrchange[2]) {
        HP = HP - arrchange[2] - 2;
    }
    else if (arrchange[0] == arrchange[2] && arrchange[0] > arrchange[1]) {
        HP = HP - arrchange[1] - 1;
    }
    else if (arrchange[1] == arrchange[2] && arrchange[1] > arrchange[0]) {
        HP = HP - arrchange[0];
    }
    else if (arrchange[2] > arrchange[1] && arrchange[1] > arrchange[0]) {
        HP = HP - arrchange[1] - 1;
    }
    else if (arrchange[0] > arrchange[1] && arrchange[1] > arrchange[2]) {
        HP = HP - arrchange[1] - 1;
    }
    else if (arrchange[2] > arrchange[0] && arrchange[0] > arrchange[1]) {
        HP = HP - arrchange[0];
    }
    else if (arrchange[1] > arrchange[0] && arrchange[0] > arrchange[2]) {
        HP = HP - arrchange[0];
    }
    else if (arrchange[1] > arrchange[2] && arrchange[2] > arrchange[0]) {
        HP = HP - arrchange[2] - 2;
    }
    else if (arrchange[0] > arrchange[2] && arrchange[2] > arrchange[1]) {
        HP = HP - arrchange[2] - 2;
    }
    end: 
    if (HP > maxHP) {
        HP = maxHP;
    }
}
void fixtiny(int& tiny) {
    tiny = 0;
}
void fixfrog(int& frog) {
    frog = 0;
}
void boolFrog(bool& isFrog) {
    isFrog = false;
}
void boolMini(bool& isMini) {
    isMini = false;
}
void adventureToKoopa(string file_input, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue) {
    ifstream ifs;
    ifs.open(file_input);
    ifs >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
    int i = 0;
    int event[100000] = { 0 };
    string str, str_num, str_file;
    getline(ifs, str);
    getline(ifs, str_num);
    getline(ifs, str_file);
    stringstream snum(str_num);
    int num = 0;
    int temp = 0;
    while (snum >> temp) {
        event[num] = temp;
        num++;
    }
    stringstream file_name(str_file);
    string _file[5];
    int nn = 0;
    while (file_name.good())
    {
        string sub;
        getline(file_name, sub, ',');
            _file[nn++] = sub;   //mush_ghost=_file[0];
    }
    ifs.close();

    bool isLancelot = Lancelot(HP);
    bool isArthur = Arthur(HP);
    bool isMini = false;
    bool isFrog = false;
    bool isAsclepius = false;
    bool isMerlin = false;
    int maxHP = HP;
    int j = 0;
    //Let rescue:
    int tiny = 1000;
    int frog = 1000;
    int level_temp = 0;
    int HP_temp = 0;
    rescue = -1;
    for (i = 0; i < num; i++) {
        tiny++;
        frog++;
        if (event[i] == 0) {
            rescue = 1;
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break;
        }
        else if (event[i] == 1) {
            Battle1to5(1, i + 1, level, HP, isArthur, isLancelot);
        }
        else if (event[i] == 2) {
            Battle1to5(1.5, i + 1, level, HP, isArthur, isLancelot);
        }
        else if (event[i] == 3) {
            Battle1to5(4.5, i + 1, level, HP, isArthur, isLancelot);
        }
        else if (event[i] == 4) {
            Battle1to5(7.5, i + 1, level, HP, isArthur, isLancelot);
        }
        else if (event[i] == 5) {
            Battle1to5(9.5, i + 1, level, HP, isArthur, isLancelot);
        }
        else if (event[i] == 6) {
            if ((!isMini) && (!isFrog)) {
                if ((isArthur) || (isLancelot)) {
                    if (level < 9) {
                        level = level + 2;
                    }
                    else {
                        level = 10;
                    }
                }
                else {
                    HP_temp = HP;
                    BattleShaman(i, level, HP, remedy, isMini, maxHP);
                    if (HP < HP_temp) {
                        isMini = true;
                        fixtiny(tiny);
                    }
                }
            }
        }
        else if (event[i] == 7) {
            if (!isMini && !isFrog) {
                if ((isArthur) || (isLancelot)) {
                    if (level < 9) {
                        level = level + 2;
                    }
                    else {
                        level = 10;
                    }
                }
                else {
                    BattleVajsh(i, level, HP, maidenkiss, isFrog, level_temp);
                    if (isFrog) {
                        fixfrog(frog);
                    }
                }
            }
        }
        else if (event[i] == 11) {
            MarioMush(HP, level, phoenixdown, maxHP);
        }
        else if (event[i] == 12) {
            FibMush(HP);
        }
        else if (event[i] == 15) {
            if (remedy < 99)
                remedy++;
            if (isMini) {
                remedy--;
                HP = HP * 5;
                boolMini(isMini);
                tiny = 1000;
            }
        }
        else if (event[i] == 16) {
            if (maidenkiss < 99)
                maidenkiss++;
            if (isFrog) {
                maidenkiss--;
                level = level_temp;
                boolFrog(isFrog);
                frog = 1000;
            }
        }
        else if (event[i] == 17) {
            if (phoenixdown < 99)
                phoenixdown++;
        }
        else if (event[i] == 18) {
            if (!isMerlin) {
                Merlin(_file[2], HP, maxHP);
                isMerlin = true;
            }
        }
        else if (event[i] == 19) {
            if (!isAsclepius) {
                Asclepius(_file[1], remedy, maidenkiss, phoenixdown);
                isAsclepius = true;
            }
        }
        else if (event[i] == 99) {
            if (isArthur) {
                continue;
            }
            else if (isLancelot) {
                if (level >= 8) {
                    level = 10;
                }
                else {
                    rescue = 0;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }
            else {
                if (level == 10) {
                    continue;
                }
                else {
                    rescue = 0;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }
        }
        else if (event[i]>100) {// Mush ghost
            string s=to_string(event[i]);
            //READ FILE
            string file_name = _file[0];
            ifstream f_mush(file_name);
            
            string tmp;
            getline(f_mush, tmp);
            int n2;
            n2 = stoi(tmp);

            int mush[200],_n2=0;
            getline(f_mush,tmp);
            stringstream  read_mush(tmp);
            while (read_mush.good())
            {
                string sub;
                getline(read_mush,sub,',');
                mush[_n2++] = stoi(sub);
            }

            for (int i = 2; i < s.size(); i++) {
                if (s[i] == '1') {
                    MushGhost1(n2,mush, HP, maxHP);
                    if (HP <= 0) {
                        if (phoenixdown > 0) {
                            phoenixdown--;
                            HP = maxHP;
                            if (isMini) {
                                isMini = false;
                                tiny = 1000;
                            }
                            if (isFrog) {
                                isFrog = false;
                                frog = 1000;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }

                if (s[i] == '2') {
                    MushGhost2(n2, mush, HP, maxHP);
                    if (HP <= 0) {
                        if (phoenixdown > 0) {
                            phoenixdown--;
                            HP = maxHP;
                            if (isMini) {
                                isMini = false;
                                tiny = 1000;
                            }
                            if (isFrog) {
                                isFrog = false;
                                frog = 1000;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }
                else if (s[i] == '3') {
                    MushGhost3(n2, mush, HP, maxHP);
                    if (HP <= 0) {
                        if (phoenixdown > 0) {
                            phoenixdown--;
                            HP = maxHP;
                            if (isMini) {
                                isMini = false;
                                tiny = 1000;
                            }
                            if (isFrog) {
                                isFrog = false;
                                frog = 1000;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }
                else if (s[i] == '4') {
                    MushGhost4(n2, mush, HP, maxHP);
                    if (HP <= 0) {
                        if (phoenixdown > 0) {
                            phoenixdown--;
                            HP = maxHP;
                            if (isMini) {
                                isMini = false;
                                tiny = 1000;
                            }
                            if (isFrog) {
                                isFrog = false;
                                frog = 1000;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
        if (HP <= 0) {
            if (phoenixdown > 0) {
                phoenixdown--;
                HP = maxHP;
                if (isMini) {
                    isMini = false;
                    tiny = 1000;
                }
                if (isFrog) {
                    isFrog = false;
                    frog = 1000;
                }
            }
        }
        if (tiny == 3) {
            HP = HP * 5;
            if (HP > maxHP) {
                HP = maxHP;
            }
            isMini = false;
        }
        if (frog == 3) {
            isFrog = false;
            level = level_temp;
        }
        if (isMini == true && remedy > 0) {
            isMini = false;
            remedy--;
            HP = HP * 5;
            if (HP > maxHP) HP = maxHP;
            tiny = 1000;
        }
        if (isFrog == true && maidenkiss > 0) {
            isFrog = false;
            maidenkiss--;
            level = level_temp;
            frog = 1000;
        }
        if (i == num - 1) {
            if (HP > 0) {
                rescue = 1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }
            else {
                rescue = 0;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }
        }
        if (HP <= 0) {
            rescue = 0;
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break;

        }
        else {
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        }
    }
}

