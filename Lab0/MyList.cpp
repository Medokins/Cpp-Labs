#include "MyList.h"

MyList::MyList(int n){
  _size = n;
  for(int i = 0; i < n; i++){
    MyNode * temp = new MyNode;
    temp->_next = nullptr;
    temp->_value = i;
    if(i == 0){
      _head = temp;
      _tail = temp;
    } else {
      _tail->_next = temp;
      _tail = temp;
    }
  }
}

MyList::MyList(const MyList& list) : MyList(){
  std::cout << "KONST: Kopiujacy\n";
  _size = list._size;
  MyNode * temp = list._head->_next;
  for(int i = 0; i < list._size; i++){
      if(_head == nullptr){
          MyNode * pivot = new MyNode;
          pivot->_value = list._head->_value;
          pivot->_next = nullptr;
          _tail = _head = pivot;
      }
      else{
          _tail->_next = new MyNode;
          _tail->_next->_value = temp->_value;
          _tail->_next->_next = nullptr;
          temp = temp->_next;
          _tail = _tail->_next;
      }
  }
}

MyList::MyList(MyList&& list){
    _size = list._size;
    list._size = 0;
    _head = std::exchange(list._head, nullptr);
    _tail = std::exchange(list._tail, nullptr);
}

MyList::MyList(std::function<int(MyNode *)> fun, int size){
    std::cout << "KONST: funkcja generujaca\n";
    _size = size;
    _tail = _head = nullptr;
    for(int i = 0; i < size; i++)
    {
        if(_tail == nullptr){
          MyNode * temp = new MyNode;
          temp->_value = fun(_tail);
          temp->_next = nullptr;
          _head = _tail = temp;
        }
        else{
          MyNode * temp = new MyNode;
          temp->_value = fun(_tail);
          temp->_next = nullptr;
          _tail->_next = temp;
          _tail = _tail->_next;
        }
    }
}

MyList::MyList(std::initializer_list<int> list){
    _size = list.size();
    std::cout << "KONST: std::initializer_list\n";
    const int * iterator = list.begin(); 
    iterator++;
    _head = _tail = nullptr;
    for(int i = 0; i < _size; i++){
        if(_head == nullptr){
          MyNode * temp = new MyNode;
          temp->_value = *list.begin();
          temp->_next = nullptr;
          _tail = _head = temp;
        }
        else{
          MyNode * temp = new MyNode;
          temp->_value = *iterator;
          temp->_next = nullptr;
          _tail->_next = temp;
          iterator++;
          _tail = _tail->_next;
        }
    }
}

bool MyList::empty() const{
  if(_size == 0){
    return true;
  } else {
    return false;
  }
}

int MyList::size() const{
  return _size;
}

void MyList::clear(){
   MyNode * temp = _head->_next;
   while(temp != nullptr){
     delete _head;
     _head = temp;
     temp = temp->_next;
  }
  delete _head;
  _head = nullptr;
  _tail = nullptr;
  _size = 0;
}

void MyList::print() const{
  cout << '[';
  MyNode * temp = _head;
  while(temp != nullptr){
    cout << temp->_value;
    if(temp->_next != nullptr){
      cout << ',';
    }
    temp = temp->_next;
  }
  cout << ']' << endl;
}

MyList::~MyList(){
    std::cout << "DESTRUKTOR (rozmiar = " << _size << ")\n"; 
    if(_size != 0){
        MyNode* temp2 = _head->_next;
        while(_head != _tail){
            delete _head;
            _head = temp2;
            temp2 = temp2->_next;
        }
        delete _head;
    }
}

void MyList::add(int n){
  MyNode * temp = new MyNode;
  temp->_value = n;
  temp->_next = nullptr;
  _size += 1;
  if(!_head){
    _head = _tail = temp;
  } else {
    _tail->_next = temp;
    _tail = temp;
  }
}