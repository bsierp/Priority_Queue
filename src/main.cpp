/**
 * @file main.cpp
 * @brief Plik zawierający kod drivera oraz dodatkowe funkcje
 * 
 */
#include<iostream>
#include<algorithm>
#include "Queue.hh"

using std::cout;
using std::cin;
using std::endl;

/**
 * @brief Funkcja oczekująca na wciśnięcie przycisku
 * 
 * Używana do oddzielenia prezentowanych metod klasy.
 */
void wait4key() {                                                               
  do {                                                                          
    std::cout << "\n Nacisnij przycisk by kontynuowac..." << std::endl;                  
  } while(std::cin.get() != '\n');                                              
}
/**
 * @brief Funkcja licząca słowa w ciągu znaków
 * 
 * Funkcja liczy słowa na podstawie ilości spacji
 * pomiędzy nimi. Funkcja liczy słowa poprawnie, jeżeli
 * pomiędzy słowami występuje jedna spacja, oraz na końcu zdania
 * jej nie ma. Jeżeli pomiędzy słowami wystąpi
 * więcej niż jedna spacja, potraktowane to zostanie
 * jako dodatkowe słowo.
 * 
 * @param input - ciąg znaków do przeliczenia słów
 * @return int - liczba słów w ciągu znaków(w przypadku pustego stringa zwraca 0)
 */
int count_words(const string & input){
    if(input=="")
    {
        return 0;
    }
    else
    {
    int space_count=0;//liczba spacji
    for (auto c : input) 
    {
        if (c == ' ')
        {
            space_count++;
        }
    }
    //Liczba jest powiekszona o 1, bo po ostatnim wyrazie(domyślnie) nie ma już spacji
    return space_count+1;
    }
}
/**
 * @brief Funkcja zmieniająca ciąg znaków w tablicę
 * 
 * Rozmiar tablicy generowany jest na podstawie liczby słów
 * zwróconych przez funkcję count_words. Funkcja działa na 
 * takiej samej zasadzie co funkcja count_words, więc w przypadku
 * niewłaściwej ilości spacji wygenerowana zostanie tablica o zwiększonej
 * ilości miejsc.
 * 
 * @param input - ciąg znaków do zmiany na tablicę
 * @return string* - wskaźnik do dynamicznej tablicy elementów
 * @throw std::underflow_error - w przypadku pustego ciągu znaków
 */
string* string_to_array(const string & input){
    //Zapobiegamy tworzeniu tablicy o rozmiarze 0 wyrzucając wyjątek
    if(input=="")
    {
        throw std::underflow_error("Nic nie zostalo wpisane");
    }
    string* string_array = new string[count_words(input)];
    string word; //zmienna do przechowywania pojedynczego słowa
    int i=0; //zmienna do indeksowania tablicy
    for (auto c : input) 
    {
        if (c == ' ')
        {
            string_array[i] = word;
            word = "";
            i++;
        }
        else {
            word = word + c;
        }
    }
    //tak jak w przypadku funkcji count_words ostatni wyraz(domyślnie)
    //nie ma po sobie spacji, więc jest dodany poza pętlą
    string_array[i] = word;
    return string_array;
}

//Kod drivera

int main(){
    std::srand(time(0));
    PriorityQueue<int,string> myqueue;
    string str;
    cout<<"Wpisz zdanie do wlozenia do kolejki:";
    getline(cin, str);//Potrzebujemy stringa ze spacjami, więc używamy getline
    try
    {
    string *string_array=string_to_array(str);//wskaźnik na tablicę wyrazów
    int* keys = new int[count_words(str)];// tablica kluczy, ma tyle samo elementów co tablica wyrazów
    //Klucze początkowo ustawione są od 0 do maksymalnej ilości elementów w tablicy
    for(int i=0;i<count_words(str);i++){
        keys[i]=i;
    }
    std::random_shuffle(&keys[0],&keys[count_words(str)]);//Przemieszanie tablicy kluczy
    cout<<"Kolejnosc wrzucania do kolejki:"<<endl;
    for(int i=0;i<count_words(str);i++){
        cout<<string_array[keys[i]]<<' ';
        myqueue.insert(keys[i],string_array[keys[i]]);
    }
    //Nie potrzebujemy już tych wskaźników, więc czyścimy pamięć
    delete[] string_array;
    delete[] keys;
    }
    catch(const std::underflow_error& e)
    {
        std::cerr<<endl<<e.what() << endl;
    }
    cout<<endl;
    try
    {   
        cout<<"Liczba elementow kolejki:"<<myqueue.size()<<endl;
        wait4key();
        cout<<"Pierwszy element kolejki:"<<myqueue.min()<<endl;
        wait4key();
        cout<<"Oproznianie kolejki:"<<endl;
        while (!(myqueue.is_empty()))
        {
            cout<<myqueue.remove_min()<<' ';
        }
        cout<<endl;
        wait4key();
    }
    catch(const std::underflow_error& e)
    {
        std::cerr <<endl<< e.what() << endl;
    }
    return 0;
}