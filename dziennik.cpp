#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
using namespace std;

//Nowy typ zmiennej "Uczeń"
class Pupil{
public:
    string login, passwd, name, surname;
    vector<int> english, history, chemistry, maths, science;
    Pupil(string name, string surname, string login, string passwd, vector<int> english, vector<int> history, vector<int> chemistry, vector<int> maths, vector<int> science){
        this -> login = login;
        this -> passwd = passwd;
        this -> english = english;
        this -> history = history;
        this -> chemistry = chemistry;
        this -> maths = maths;
        this -> science = science;
        this -> name = name;
        this -> surname = surname;
    }
};

//Nowy tym zmiennej "Nauczyciel"
class Teacher{
public:
    string login, passwd, subject, name, surname;
    Teacher(string name, string surname, string login , string passwd, string subject){
        this -> login = login;
        this -> passwd = passwd;
        this -> subject = subject;
        this -> name = name;
        this -> surname = surname;
    }
};

//Klasa zawierająca poszczególne metody
class Metody{
public:
    //Metoda główna
    void mainMenu(){
        vector<Teacher> BaseOfTeachers = declareTeacher();
        vector<Pupil> BaseOfPupils = declarePupil();
        int use = 1;
        while(use != 0){
            int role, numer, operation, first;
            Sleep(1500);
            system("cls");
            cout << "Co chcesz zrobic?" << endl << "1.Zalogowac sie do dziennika" << endl << "2.Wyjsc z aplikacji" << endl << "3.Wyczyscic ekran" << endl;
            cin >> operation;
            switch(operation){
                case 1:
                    system("cls");
                    cout << "Witaj na stronie logowania do dziennika " << endl << "\nKim jestes?\n" << "1.Nauczyciel" << endl << "2.Uczen" << endl;
                    cin >> role;
                    switch(role){
                        case 1:
                            system("cls");
                            cout << "Wprowadz specjalny numer systemowy podany przez administratora: ";
                            cin >> numer;
                            if(numer >=1 && numer <= BaseOfTeachers.size()){
                                cout << "Czy to twoje pierwsze logowanie ?" << endl << "1.Tak" << endl << "2.Nie" << endl;
                                cin >> first;
                                switch(first){
                                    case 1:
                                        BaseOfTeachers = newTeacherPassword(BaseOfTeachers, BaseOfPupils, numer, role);
                                        break;
                                    case 2:
                                        if(logIn(BaseOfTeachers, BaseOfPupils, role, numer)){
                                            system("cls");
                                            BaseOfPupils = teacherWork(BaseOfTeachers[numer - 1], BaseOfPupils);
                                        }    
                                        break;
                                    default:
                                        cout << "Podana wartosc jest nieprawidlowa, przenosze do ekranu glownego..." << endl;         
                                }
                            }else{
                                cout << "Podany bledny numer systemowy" << endl << "Jesli problem sie powtarza skontaktuj sie z administratorem" << endl;
                                cout << "Przenosze na strone glowna..." << endl;
                            } 
                            break;       
                        case 2:
                            system("cls");
                            cout << "Wprowadz specjalny numer systemowy podany przez administratora: ";
                            cin >> numer;
                            if(numer >= 1 && numer <= BaseOfPupils.size()){
                                cout << "Czy to twoje pierwsze logowanie ?" << endl << "1.Tak" << endl << "2.Nie" << endl;
                                cin >> first;
                                switch(first){
                                    case 1:
                                        BaseOfPupils = newPupilPassword(BaseOfTeachers, BaseOfPupils, numer, role);
                                        break;
                                    case 2:
                                        if(logIn(BaseOfTeachers, BaseOfPupils, role, numer)){
                                            system("cls");
                                            pupilWork(BaseOfPupils[numer - 1], numer, BaseOfTeachers);
                                        }    
                                        break;
                                    default:
                                        cout << "Podana wartosc jest nieprawidlowa, przenosze do ekranu glownego..." << endl;        
                                }
                            }else{
                                cout << "Podany bledny numer systemowy" << endl << "Jesli problem sie powtarza skontaktuj sie z administratorem" << endl;
                                cout << "Przenosze na strone glowna..." << endl;
                            }
                            break;
                        default:
                            cout << "Podany numer nie odpowiada zadnej roli" << endl << "Powrot na strone glowna..." << endl;  
                    }
                    break;
                case 2:
                    cout << "Dziekuje za korzystanie z dziennika" << endl;
                    cout << "Do zobaczenia!" << endl;
                    use = 0;
                    break;
                case 3:
                    system("cls");
                    break;   
                default:
                    cout << "Podany numer nie odpowiada zadnej operacji" << endl;
                    cout << "\n\n";        
            }
        }     
    }

    //Metody charakterystyczne dla pracy nauczyciela
    
    //Metoda obslugująca pracę nauczyciela
    vector<Pupil> teacherWork(Teacher nauczyciel, vector<Pupil> pupils){
        int operation;
        int log = 1;
        cout << "Witaj " << endl << nauczyciel.name << " " << nauczyciel.surname << " !" << endl; 
        while (log != 0){
            cout << "Menu operacji:" << endl << "1.Wyswietl liste klasy" << endl << "2.Wstaw ocene" << endl 
            << "3.Usun ocene" << endl << "4.Pokaz oceny ucznia" << endl <<"5.Kto jest zalogowany?" << endl << "6.Wyszysc ekran" << endl << "7.Wyloguj sie" <<  endl;
            cin >> operation;
            switch(operation){
                case 1:
                    showClass(pupils);
                    break;
                case 2:
                    pupils = markSet(nauczyciel, pupils);
                    cout << "\n\n";
                    break;
                case 3:
                    pupils = markDel(nauczyciel, pupils);
                    cout << "\n\n";
                    break;
                case 4:
                    showMarks(nauczyciel, pupils);
                    cout << "\n\n";
                    break;
                case 5:
                    cout << "\n";
                    cout << nauczyciel.name << " " << nauczyciel.surname << " ==> nauczyciel przedmiotu " << nauczyciel.subject << endl;
                    cout << "\n\n";
                    break;
                case 6:
                    system("cls");
                    break;
                case 7:
                    cout << "\nWylogowano pomyslnie" << endl;
                    log = 0;
                    break;
                default:
                    cout << "Podany numer nie odpowiada zadnej operacji" << endl;
                    cout << "\n\n";
            }
        }
        return pupils;    
    }
    //Metoda umożliwiająca wstawianie ocen
    vector<Pupil> markSet(Teacher nauczyciel, vector<Pupil> pupils ){
        int num, mark, log;
        string subject = nauczyciel.subject;
        log = 1;
        while(log != 0){
            cout << "Wprowadz numer ucznia, ktoremu chcesz wstawic ocene: ";
            cin >> num;
            cout << "Jaka ocene chcesz wstawic ?: ";
            cin >> mark;
            if((mark >= 1 && mark <= 6) && (num >=1 && num <= pupils.size())){
                if(subject == "Angielski"){
                    pupils[num-1].english.push_back(mark);
                    log = 0;        
                }else if(subject == "Historia"){
                    pupils[num-1].history.push_back(mark);
                    log = 0;
                }else if(subject == "Chemia"){
                    pupils[num-1].chemistry.push_back(mark);
                    log = 0;
                }else if(subject == "Matematyka"){
                    pupils[num-1].maths.push_back(mark);
                    log = 0;
                }else if(subject == "Geografia"){
                    pupils[num-1].science.push_back(mark);
                    log = 0;
                }
            }else{
                cout << "Wprowadzona bledna wartosc oceny lub bledny numer ucznia" << endl;
                cout << "\n\n";
                log = 1;
            }
        }
        cout << "Wstawiono ocene (" << mark << ") dla ucznia ==> " << pupils[num-1].name << " " << pupils[num-1].surname << " z przedmiotu " << subject << endl;
        return pupils;            
    }
    //Metoda umożliwiająca usuwanie ocen
    vector<Pupil> markDel(Teacher nauczyciel, vector<Pupil> uczniowie){
        int numPupil, log, numMark;
        string subject = nauczyciel.subject;
        log = 1;
        while(log != 0){
            cout << "Wprowadz numer ucznia, ktoremu chcesz usunac ocene: ";
            cin >> numPupil;
            cout << "Liczac od lewej podaj numer oceny, ktora chcesz usunac: ";
            cin >> numMark;
            if(numPupil >= 1 && numPupil <= uczniowie.size()){
                if(subject == "Angielski"){
                    if( numMark >= 1 && numMark <= uczniowie[numPupil-1].english.size()){
                        uczniowie[numPupil-1].english.erase(uczniowie[numPupil-1].english.begin() + numMark - 1);
                        log = 0;
                    }else{
                        cout << "Podano bledny numer oceny" << endl;
                    }
                }else if(subject == "Historia"){
                    if( numMark >= 1 && numMark <= uczniowie[numPupil-1].history.size()){
                        uczniowie[numPupil-1].history.erase(uczniowie[numPupil-1].history.begin() + numMark - 1);
                        log = 0;
                    }else{
                        cout << "Podano bledny numer oceny" << endl;
                    }
                }else if(subject == "Chemia"){
                    if( numMark >= 1 && numMark <= uczniowie[numPupil-1].chemistry.size()){
                        uczniowie[numPupil-1].chemistry.erase(uczniowie[numPupil-1].chemistry.begin() + numMark - 1);
                        log = 0;
                    }else{
                        cout << "Podano bledny numer oceny" << endl;
                    }
                }else if(subject == "Matematyka"){
                    if( numMark >= 1 && numMark <= uczniowie[numPupil-1].maths.size()){
                        uczniowie[numPupil-1].maths.erase(uczniowie[numPupil-1].maths.begin() + numMark - 1);
                        log = 0;
                    }else{
                        cout << "Podano bledny numer oceny" << endl;
                    }
                }else if(subject == "Geografia"){
                    if( numMark >= 1 && numMark <= uczniowie[numPupil-1].science.size()){
                        uczniowie[numPupil-1].science.erase(uczniowie[numPupil-1].science.begin() + numMark - 1);
                        log = 0;
                    }else{
                        cout << "Podano bledny numer oceny" << endl;
                    }
                }
            }else{
                cout << "Podano bledny numer ucznia" << endl;
            }
        }
        cout << "Usunieto ocene o numerze (" << numMark << ") uczniowi " << uczniowie[numPupil-1].name << " " << uczniowie[numPupil-1].surname << " z przedmiotu " << subject << endl;
        return uczniowie;
    }

    //Metody charakterystyczne dla zajec ucznia
    //Metoda obslugująca interfejs ucznia
    void pupilWork(Pupil uczen, int numer, vector<Teacher> nauczyciele){
        int operation, log;
        cout << "Witaj " << uczen.name << " " << uczen.surname << " !" << endl;
        log = 1;
        while(log != 0){
            cout << "Menu operacji:" << endl << "1.Zobacz oceny" << endl << "2.Szkola i nauczyciele" << endl << "3.Kto jest zalogowany?" << endl <<"4.Wyczysc ekran" << endl << "5.Wyloguj sie" << endl;
            cin >> operation;
            switch(operation){
                case 1:
                    showMarkForPupil(uczen, numer);
                    cout << "\n\n";
                    break;
                case 2:
                    showTeachers(nauczyciele);
                    cout << "\n\n";
                    break;
                case 3:
                    cout << uczen.name << " " << uczen.surname << " uczen klasy 1'i'" << endl;
                    cout << "\n\n";
                    break;
                case 4:
                    system("cls");
                    break;
                case 5:
                    cout << "\nWylogowano pomyslnie" << endl;
                    log = 0;
                    break;
                default:
                    cout << "Podany numer nie odpowiada zadnej operacji" << endl;
                    cout << "\n\n";    
            }
        }
    }

    //Metody odpowiedzialne za sprawdzanie i dzialania na wektorach związanych z uczniem
    //Metoda ustawiająca nowe hasło dla ucznia
    vector<Pupil> newPupilPassword(vector<Teacher> opt1, vector<Pupil> opt2, int num, int role){
        string update = firstLogIn(opt1, opt2, role, num);
        opt2[num-1].passwd = update;
        return opt2;
    }
    //Metoda wyświetlająca liste klasy
    void showClass(vector<Pupil> pupils){
        int size = pupils.size();
        cout << "Lista klasy 1'i'" << endl;
        for(int i = 0; i < size; i++){
        cout << i+1 << "." << pupils[i].name << " " << pupils[i].surname << endl;
        }
        cout << "\n\n";
    }
    //Metoda umożliwiająca wyświetlenie ocen poszczególnego ucznia
    void showMarks(Teacher nauczyciel, vector<Pupil> uczniowie){
        int num;
        string subject = nauczyciel.subject;
        int log = 1;
        while(log != 0){
            cout << "Podaj numer ucznia, ktorego oceny chcesz wyswietlic: ";
            cin >> num;
            if(num >=1 && num <= uczniowie.size()){
                log = 0;
                cout << "\n\n";
                if(subject == "Angielski"){  
                    iterateMarksForTeacher(num, uczniowie[num-1].english, uczniowie[num-1], subject);         
                }else if(subject == "Historia"){
                    iterateMarksForTeacher(num, uczniowie[num-1].history, uczniowie[num-1], subject);
                }else if(subject == "Chemia"){
                    iterateMarksForTeacher(num, uczniowie[num-1].chemistry, uczniowie[num-1], subject);
                }else if(subject == "Matematyka"){
                    iterateMarksForTeacher(num, uczniowie[num-1].maths, uczniowie[num-1], subject);
                }else if(subject == "Geografia"){
                    iterateMarksForTeacher(num, uczniowie[num-1].science, uczniowie[num-1], subject);            
                }
            }else{
                cout << "Podano bledny numer ucznia" << endl;
            }
        }
    }
    //Metoda umożliwiająca wyświetlenie ocen dla ucznia
    void showMarkForPupil(Pupil uczen, int num){
        int subject, log;
        log = 1;
        while (log != 0){
            cout << "Podaj przedmiot z ktorego oceny chcesz zobaczyc" << endl << "1.Angielski" << endl << "2.Historia" << endl << "3.Chemia" << endl << "4.Matematyka" << endl << "5.Geografia" << endl;
            cin >> subject;
            switch(subject){
                case 1:
                    iterateMarksForTeacher(num, uczen.english, uczen, "Angielski");
                    log = 0;
                    break;
                case 2:
                    iterateMarksForTeacher(num, uczen.history, uczen, "Historia");
                    log = 0;
                    break;
                case 3:
                    iterateMarksForTeacher(num, uczen.chemistry, uczen, "Chemia");
                    log = 0;
                    break;
                case 4:
                    iterateMarksForTeacher(num, uczen.maths, uczen, "Matematyka");
                    log = 0;
                    break;
                case 5:
                    iterateMarksForTeacher(num, uczen.science, uczen, "Geografia");
                    log = 0;
                    break;
                default:
                    cout << "Zostal podany bledny przedmiot" << endl;
                    cout << "\n\n";                  
            }
        }
    }
    //Metoda wyświetlająca oceny i licząca średnią
    void iterateMarksForTeacher(int num, vector<int> marks, Pupil uczen, string przedmiot){
        cout << "Oceny ucznia " << uczen.name << " " << uczen.surname << " z przedmiotu " << przedmiot << endl;
        if(marks.size() > 0){
            float srednia;
            cout << "{ ";
            for(int i = 0; i < marks.size() - 1 ; i++){
                cout << marks[i] << " , ";
                srednia += marks[i];
            }
            cout << marks[marks.size() -1] << " }"<< endl;
            srednia += marks[marks.size() -1];
            srednia = (float) srednia / marks.size();
            cout << setprecision(2) << fixed;
            cout << "Srednia ocen ==> " << srednia << endl;    
        }else{
            cout << "Brak elementow do wyswietlenia (uczen nie zdobyl ocen)";
        } 
    }
    //Metody odpowiedzialne za sprawdzanie i dzialania na wektorach związanych z nauczycielem
    //Metoda ustawiająca nowe haslo dla nauczyciela
    vector<Teacher> newTeacherPassword(vector<Teacher> opt1, vector<Pupil> opt2, int num, int role){
        string update = firstLogIn(opt1, opt2, role, num);
        opt1[num-1].passwd = update;
        return opt1;
    }
    //Metoda pokazująca uczniowi wszystkich nauczycieli wraz z przedmiotami, których uczą
    void showTeachers(vector<Teacher> teachers){
        cout << "Nauczyciele klasy 1'i': " << endl;
        for(int i = 0; i < teachers.size(); i++){
            cout << teachers[i].name << " " << teachers[i].surname << " nauczyciel przedmiotu " << teachers[i].subject << endl;
        }
    }
    //Metoda odpowiedzialna za pierwsze logowanie użytkownika w aplikacji
    string firstLogIn(vector<Teacher> opt1, vector<Pupil> opt2, int role, int num){
        int j = 0;
        string newPasswd;        
        cout << "Witam w Dzienniku elektronicznym klasy 1'i'" << endl;
        system("cls");
        if (logIn(opt1, opt2, role, num)){
            cout << "To twoje pierwsze logowanie" << endl <<  "Musisz ustawic nowe, niepowtarzalne haslo" << endl;
            for(int i = 0; i < 3; i++){
                cout << "Wprowadz nowe haslo: ";
                cin >> newPasswd;
                if(newPasswd != "uczniowie" && newPasswd != "nauczyciel"){
                    cout << "Zmiana hasla zakonczona pomyslnie" << endl;
                    cout << "Wymagane ponowne zalogowanie z uzyciem nowego hasla" << endl;
                    cout << "Przenosze na strone glowna..." << endl;
                    i = 3;
                    j = 10;
                return newPasswd;
                }else{
                    cout << "Nowe haslo musi roznic sie od poprzedniego" << endl;
                    j++;
                }
            }
            if(j < 10){
                cout << "Podjales zbyt wiele prob" << endl << "Sproboj ponownie pozniej" << endl;
            }
        }
    }


    //Metoda umożliwiająca zalogowanie się użytkownikowi
    bool logIn(vector<Teacher> opt1, vector<Pupil> opt2, int role, int num){
        system("cls");
        int j;
        string login,passwd;
        if(role == 1){
            cout << "Wprowadz login: ";
            cin >> login;
            if(opt1[num - 1].login == login){
                for(int i = 0; i < 3; i++){
                    cout << "Wprowadz haslo: ";
                    cin >> passwd;
                    if(passwd == opt1[num-1].passwd){
                        cout << "Zalogowano pomyslnie !" << endl;
                        i = 3;
                        j = 10;
                        return true;
                    }else{
                        cout << "Haslo niepoprawne!" << endl << "Pozostaly " << 3 - (i+1) << " proby" << endl;;
                        j = 1;
                        j ++;
                    }
                }
                if (j < 10){
                    cout << "Za duzo razy wprowadzono bledne haslo" << endl << "Sproboj ponownie pozniej" << endl;
                    return false;
                }     
            }else{
                cout << "Wprowadzono bledny login lub nie pasuje on do loginu systemowego" << endl << "Sproboj ponownie pozniej" << endl;
                return false;
            }
        }else if(role == 2){
            cout << "Wprowadz login: ";
            cin >> login;
            if(opt2[num-1].login == login){
                for(int i = 0; i < 3; i++){
                    cout << "Wprowadz haslo: ";
                    cin >> passwd;
                    if(passwd == opt2[num-1].passwd){
                        cout << "Zalogowano pomyslnie !" << endl;
                        i = 3;
                        j = 10;
                        return true;
                    }else{
                        cout << "Haslo niepoprawne!" << endl << "Pozostaly " << 3 - (i+1) << "proby" << endl;
                        j = 1;
                        j ++;
                    }
                }
                if (j < 10){
                    cout << "Za duzo razy wprowadzono bledne haslo" << endl << "Sproboj ponownie pozniej" << endl;
                    return false;
                }     
            }else{
                cout << "Wprowadzono bledny login, lub nie pasuje on do numeru systemowego" << endl << "Sproboj ponownie pozniej" << endl;
                return false;
            }
        }
    }


    //Metoda tworząca bazę nauczycieli
    vector<Teacher> declareTeacher(){
        vector<Teacher> Teachers;
        cout << "Wczytuje baze nauczycieli..." << endl;
        Teachers.push_back({"Piotr", "Abramowicz", "piotr.abramowicz@1lo.swidnik.pl", "nauczyciel", "Angielski"});
        Teachers.push_back({"Andrzej", "Burek", "andrzej.burek@1lo.swidnik.pl", "nauczyciel", "Historia"});
        Teachers.push_back({"Gracja", "Fijalkowska", "gracja.fijalkowska@1lo.swidnik.pl", "nauczyciel", "Chemia"});
        Teachers.push_back({"Dorota", "Kutnik", "dorota.kutnik@1lo.swidnik.pl", "nauczyciel", "Matematyka"});
        Teachers.push_back({"Adam", "Kuna", "adam.kuna@1lo.swidnik.pl", "nauczyciel", "Geografia"});
        cout << "Gotowe" << endl;
        return Teachers;
    }


    //Metoda tworząca bazę uczniów
    vector<Pupil> declarePupil(){
        vector<Pupil> Pupils;
        cout << "Wczytuje baze uczniow..." << endl;
        Pupils.push_back({"Jakub", "Adamiak", "jakub.adamiak@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Szymon", "Bozek", "szymon.bozek@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Bartosz", "Czuchryta", "bartosz.czuchryta@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Zuzanna", "Czyzewska", "zuzanna.czyzewska@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Kornel", "Dys", "kornel.dys@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Kacper", "Galecki", "kacper.galecki@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Julia", "Kocot", "julia.kocot@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Hubert", "Kopiuk", "hubert.kopiuk@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Antoni", "Krysa", "antoni.krysa@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Mateusz", "Libicki", "mateusz.libicki@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Piotr", "Rusak", "piotr.rusak@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Olaf", "Rybczynski", "olaf.rybczynski@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Bartosz", "Sawczuk", "bartosz.sawczuk@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Adam", "Szuryga", "adam.szuryga@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Leon", "Wasiak", "leon.wasiak@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        Pupils.push_back({"Adam", "Wojcik", "adam.wojcik@1lo.swidnik.pl", "uczniowie", {}, {}, {}, {}, {}});
        cout << "Gotowe" << endl;
        return Pupils;
    }
};
//Funkcja główna zawierająca umożliwiająca uruchomienie całego programu
int main(){
    Metody methods;
    methods.mainMenu();
    return 0;
}