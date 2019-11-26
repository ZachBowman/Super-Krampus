#pragma once

template <typename T>
class List_Node
  {
    public:

    T data;
    List_Node *next;
    List_Node *previous;
  };

template <typename T>
class Linked_List
  {
    public:

    Linked_List ();
    Linked_List (int Max);
    ~Linked_List ();
    List_Node<T> add ();
    void add (T Data);
    void set_data (int index, T Data);
    T get_data (int index);

    int count = 0;

    private:

    List_Node<T> *head, *tail;
  };

template <typename T>
Linked_List<T>::Linked_List ()
  {
  head = nullptr;
  tail = nullptr;
  }

template <typename T>
Linked_List<T>::Linked_List (int Count)
  {
  count = Count;
  List_Node *node = nullptr;
  List_Node *last_node = nullptr;

  for (int i = 0; i < count; i += 1)
    {
    node = new List_Node;
    //node->data = i;

    if (i == 0)
      {
      node->previous = nullptr;
      head = node;
      }
    else
      {
      node->previous = last_node;
      last_node->next = node;
      }
    if (i == max) tail = node;
    last_node = node;
    }
  }

template <typename T>
Linked_List<T>::~Linked_List () {}

template <typename T>
List_Node<T> Linked_List<T>::add ()
  {
  List_Node<T> *node = new List_Node<T>;
  if (count == 0)
    {
    head = node;
    }
  else
    {
    tail->next = node;
    node->previous = tail;
    }

  tail = node;
  count += 1;

  return *node;
  }

template <typename T>
void Linked_List<T>::add (T Data)
  {
  List_Node<T> node = add ();
  node.data = Data;
  }

template <typename T>
void Linked_List<T>::set_data (int index, T Data)
  {
  List_Node *node = head;

  for (int i = 0; i < index; i += 1)
    {
    node = node->next;
    }

  node->data = Data;
  }

template <typename T>
T Linked_List<T>::get_data (int index)
  {
  List_Node<T> *node = head;

  for (int i = 0; i < index; i += 1)
    {
    node = node->next;
    }

  return node->data;
  }
