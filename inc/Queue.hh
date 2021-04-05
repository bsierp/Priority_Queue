#ifndef QUEUE_HH
#define QUEUE_HH
/**
 * @file Queue.hh
 * @brief Plik zawiera definicję szablony klasy PriorityQueue
 * oraz deklarację jego metod
 * 
 */
#include <string>
#include <stdexcept>

using std::string;

/**
 * @brief Model pojęcia kolejki priorytetowej
 * 
 * Klasa modeluje pojęcie kolejki priorytetowej
 * z parametrami informującymi o typie przechowywanych
 * danych oraz typie klucza.
 * 
 * @tparam KEY_TYPE - typ klucza informujacego o kolejności elementu
 * @tparam VALUE_TYPE - typ przechowywanej wartości
 */
template<class KEY_TYPE, class VALUE_TYPE>
class PriorityQueue {
    /**
     * @brief Model pojęcia węzła
     * 
     * Struktura modeluje pojęcie pojedynczego
     * węzła kolejki priorytetowej 
     */
    struct Node{
    /**
     * @brief Klucz informujący o kolejności w kolejce
     * 
     */
    KEY_TYPE key;
    /**
     * @brief Wartość przechowywana w węźle
     * 
     */
    VALUE_TYPE data;
    /**
     * @brief Wskaźnik na następny węzeł
     * 
     */
    Node *next;
};
    /**
     * @brief Wskaźnik na węzeł o najmniejszym kluczu
     * 
     */
    Node *first;
    public:
    /**
     * @brief Konstruktor bezparametryczny kolejki priotytetowej
     * 
     * Inicjalizuje pustą kolejkę priorytetową
     * 
     */
    PriorityQueue(){this->first=nullptr;}
    /**
     * @brief Metoda dodająca nowy element do kolejki
     * 
     * Metoda ustawia element w odpowiednim miejscu, tak
     * by klucze ustawione były rosnąco. Na potrzeby zadania 
     * metoda zdefiniowana jest tylko dla kluczy typu int 
     * oraz wartości typu string.
     * 
     * @param new_key - klucz nowego elementu
     * @param new_data - wartość nowego elementu
     */
    void insert(KEY_TYPE new_key, VALUE_TYPE new_data);
    /**
     * @brief Metoda usuwa element o najmniejszym kluczu
     * 
     * Usuwa element o najmniejszym kluczu oraz zmienia wskaźnik
     * first na następny element. Zwraca wartość elementu o najmniejszym
     * kluczu.
     * 
     * @return VALUE_TYPE - wartość elementu o najmniejszym kluczu
     * @throw std::underflow_error - jeżeli kolejka jest pusta
     */
    VALUE_TYPE remove_min();
    /**
     * @brief Metoda zwraca wartość elementu o najmniejszym kluczu
     * 
     * Zwraca wartość elementu o najmniejszym kluczu, ale nie usuwa go.
     * 
     * @return const VALUE_TYPE& - wartość elementu o najmniejszym kluczu
     * @throw std::underflow_error - jeżeli kolejka jest pusta
     */
    const VALUE_TYPE & min() const;
    /**
     * @brief Metoda sprawdza czy kolejka jest pusta
     * 
     * Sprawdza czy kolejka jest pusta na podstawie 
     * wartości wskazywanej przez wskaźnik first.
     * @return true - jeżeli first wskazuje na nullptr
     * @return false - w przeciwnym wypadku
     */
    bool is_empty() const;
    /**
     * @brief Metoda zwraca liczbę elementów kolejki
     * 
     * @return int - liczba elementów kolejki
     */
    int size() const;
};

template<> void PriorityQueue<int,string>::insert(int new_key, string new_data);
#endif