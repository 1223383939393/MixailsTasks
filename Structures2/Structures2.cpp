// Подключаем библиотеку для ввода-вывода и строк
#include <iostream>
#include <string>
using namespace std;

// Структура "Заявка". Каждая заявка — это как один листок с информацией.
struct Ticket {
    int number;           // Номер заявки (автоматически 1, 2, 3...)
    string name;          // Имя клиента
    int priority;         // Важность: 1 (низкий), 2 (средний), 3 (высокий)
    int timeMinutes;      // Время поступления (в минутах от 0:00)
    string problem;       // Описание проблемы
    Ticket* next;         // Указатель на следующую заявку в очереди
};

// Структура "Очередь". Хранит адреса первого и последнего человека.
struct Queue {
    Ticket* head;         // Указатель на первого в очереди (кого будут обслуживать)
    Ticket* tail;         // Указатель на последнего в очереди (кто пришёл последним)
};

// Функция "добавить в очередь" (enqueue)
// Принимает саму очередь (ссылку) и заявку, которую нужно добавить.
void enqueue(Queue& q, const Ticket& ticket) {
    // Создаём новую заявку в памяти (новый "конверт")
    Ticket* newTicket = new Ticket;

    // Статическая переменная — она не исчезает после вызова функции.
    // Каждый раз увеличивается на 1, чтобы номера были 1,2,3...
    static int nextNum = 1;
    newTicket->number = nextNum++;   // Присваиваем номер и сдвигаем счётчик

    // Новый элемент становится последним, поэтому его next = nullptr
    newTicket->next = nullptr;

    // Копируем все остальные поля из переданной заявки в новую
    newTicket->name = ticket.name;
    newTicket->priority = ticket.priority;
    newTicket->problem = ticket.problem;
    newTicket->timeMinutes = ticket.timeMinutes;

    // Если очередь пустая (нет ни одного человека)
    if (q.head == nullptr) {
        q.head = newTicket;   // Новый элемент становится и головой, и хвостом
        q.tail = newTicket;
    }
    else {
        // Если очередь не пустая, прицепляем новый элемент в конец
        q.tail->next = newTicket;   // У текущего хвоста next указывает на нового
        q.tail = newTicket;          // Теперь новый элемент стал хвостом
    }
}

// Функция "удалить из головы" (dequeue)
// Забирает первого человека из очереди, возвращает его данные в result.
// Возвращает true, если удаление прошло успешно, и false, если очередь пуста.
bool dequeue(Queue& q, Ticket& result) {
    // Если головы нет — очередь пуста, ничего не делаем
    if (!q.head) {
        return false;
    }

    // Копируем данные головы в result (звёздочка * значит "взять сам объект")
    result = *q.head;

    // Запоминаем адрес головы, чтобы потом удалить этот узел
    Ticket* rem = q.head;

    // Сдвигаем голову на следующий элемент
    q.head = q.head->next;

    // Удаляем старую голову из памяти
    delete rem;

    // Если после сдвига голова стала пустой (очередь опустела), обнуляем и хвост
    if (!q.head) q.tail = nullptr;

    return true;   // Сообщаем, что всё прошло успешно
}

// Функция "посмотреть голову" (peek)
// Возвращает указатель на первого человека, но не удаляет его.
// Если очередь пуста, возвращает nullptr (пустой указатель).
const Ticket* peek(const Queue& q) {
    if (!q.head) {
        return nullptr;
    }
    else {
        return q.head;   // Просто возвращаем адрес головы
    }
}

// Функция "вывести все заявки" (printAll)
// Печатает всех людей в очереди от головы до хвоста.
void printAll(const Queue& q) {
    // Берём временный указатель curr, чтобы не потерять голову
    Ticket* curr = q.head;
    while (curr != nullptr) {
        // Печатаем все поля текущей заявки
        cout << "number: " << curr->number
            << " Name: " << curr->name
            << " priority: " << curr->priority
            << " Time: " << curr->timeMinutes
            << " problem: " << curr->problem << endl;
        // Переходим к следующему элементу
        curr = curr->next;
    }
}

// Функция "найти заявку по номеру"
// Возвращает указатель на найденную заявку, либо nullptr, если не нашли.
const Ticket* findByNumber(const Queue& q, int x) {
    Ticket* curr = q.head;
    while (curr != nullptr) {
        // Если номер текущей заявки равен искомому числу
        if (curr->number == x) {
            return curr;   // Возвращаем указатель на эту заявку
        }
        curr = curr->next; // Иначе идём дальше
    }
    return nullptr;   // Не нашли
}

// Функция "очистить очередь" (clear)
// Удаляет все элементы, освобождает память. После этого очередь пуста.
void clear(Queue& q) {
    // Пока есть хотя бы один элемент
    while (q.head != nullptr) {
        Ticket* rem = q.head;      // Запоминаем текущую голову
        q.head = q.head->next;     // Сдвигаем голову на следующий
        delete rem;                // Удаляем запомненный элемент
    }
    q.tail = nullptr;   // Хвост тоже обнуляем, так как очередь пуста
}

// Главная функция — проверяем работу всех написанных функций
int main() {
    // Создаём очередь. Пока она пустая: head = nullptr, tail = nullptr.
    Queue q = { nullptr, nullptr };

    // Создаём три заявки. Поле number временно ставим 0,
    // потому что enqueue сама назначит номер 1,2,3...
    Ticket t1 = { 0, "Ivan", 2, 9 * 60 + 30, "Computer won't turn on" };
    Ticket t2 = { 0, "Maria", 1, 10 * 60 + 15, "No internet" };
    Ticket t3 = { 0, "Peter", 3, 11 * 60 + 0, "Keyboard not working" };

    // Добавляем заявки в очередь
    enqueue(q, t1);
    enqueue(q, t2);
    enqueue(q, t3);

    // Печатаем все заявки
    cout << "All tickets in queue:\n";
    printAll(q);
    cout << endl;

    // Поиск заявки с номером 2
    int num = 2;
    const Ticket* found = findByNumber(q, num);
    if (found)
        cout << "Found ticket #" << found->number << " from " << found->name << endl;
    else
        cout << "Ticket #" << num << " not found\n";
    cout << endl;

    // Обрабатываем (удаляем) одну заявку из головы
    Ticket processed;
    if (dequeue(q, processed)) {
        cout << "Processed ticket: " << processed.name << ", problem: " << processed.problem << endl;
    }

    // Печатаем оставшиеся заявки
    cout << "\nRemaining tickets:\n";
    printAll(q);
    cout << endl;

    // Смотрим, кто следующий на обслуживание (не удаляя)
    const Ticket* nextTicket = peek(q);
    if (nextTicket)
        cout << "Next to serve: " << nextTicket->name << " (#" << nextTicket->number << ")\n";
    else
        cout << "Queue is empty\n";
    cout << endl;

    // Очищаем всю очередь
    clear(q);
    cout << "After clearing, queue is empty? " << (q.head == nullptr ? "Yes" : "No") << endl;

    return 0;
}