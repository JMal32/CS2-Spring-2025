template<typename T>
class LinkedList {
public:
  LlinkedLIst();
  void add(const T& value);
  void remove(const T&);
  T get(int);
  void printLList();
  bool isEmpty();
  long length() { return this->size; }
private:
  Node<T>* head;
  long size;
};

template<typename T>
LinkedList<T>::LinkedList() {
  head = nullptr;
  size = 0;
};

// LinkedList class implementation
template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template<typename T>
bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
void LinkedList<T>::add(const T& item) {
    Node<T>* temp = new Node<T>(item);
    temp->setNext(head);
    head = temp;
    size++;
}

