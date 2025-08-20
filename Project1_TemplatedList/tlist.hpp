//Default constructor
template <class T>
TList<T>::TList()
{
    first = nullptr; // intiialize first to nullptr
    last = nullptr; // intiialize last to nullptr
    size = 0; // intiialize size to 0
}

//IsEmpty
template <class T>
bool TList<T>::IsEmpty() const
{
    return (size == 0); // check if list is empty by checking size
}

//Insert back
template <class T>
void TList<T>::InsertBack(const T& d)
{
    Node<T>* newNode = new Node<T>(d); // create new node
    if(IsEmpty())
    {
        first = newNode; // if empty list set both pointers to new node
        last = newNode; // if empty list set both pointers to new node
        size++; // increment size
    }
    else
    {
        newNode->prev = last; // set new node's prev pointer to last
        last->next = newNode; // set last's next pointer to new node
        last = newNode; // set last to new node
        size++; // increment size
    }
}

//Print
template <class T>
void TList<T>::Print(std::ostream& os, char delim) const{
    Node<T>* curr = first; // start from first ndoe
    if(curr == nullptr) // if list is empty
    {
        os << "List is empty" << std :: endl; // print empty list
        return;
    }
    while(curr != nullptr)
    {
        os << curr->data << delim;
        curr = curr->next;
    }
}

//GetFirst
template <class T>
T& TList<T>::GetFirst() const
{
    return first->data; // return first nodes data
}

//GetLast
template <class T>
T& TList<T>::GetLast() const
{
    return last->data; // return last nodes data
}

//InsertFront
template <class T>
void TList<T>::InsertFront(const T& d)
{
    Node<T>* newNode = new Node<T>(d);
    if(IsEmpty()) // if list is empty
    {
        first = newNode; // set both pointers to new node
        last = newNode;
        size++;
    }
    else
    {
        newNode->next = first; // set new node's next pointer to first
        first->prev = newNode;
        first = newNode;
        size++;
    }
}


//GetSize
template <class T>
int TList<T>::GetSize() const
{
    return size; // return size
}

//initialize list
template <class T>
TList<T>::TList(T val, int num)
{
    first = nullptr; // intiialize first to nullptr
    last = nullptr; // intiialize last to nullptr
    size = 0; // intiialize size to 0
    for(int i=0; i<num; i++)
    {
        InsertBack(val); // insert val num times
    }
}


template <typename T>
void TList<T>::RemoveBack()
{
    if (this->IsEmpty())
    {
        // If the list is empty, nothing to remove.
        return;
    }
    else if (size == 1)
    {
        // If there is only one element in the list, remove it.
        first = nullptr;
        last = nullptr;
        delete last;
        size--;
    }
    else
    {
        // If there are more than one elements, remove the last one.
        Node<T>* temp = last;
        last = last->prev;
        last->next = nullptr;
        delete temp;
        size--;
    }
}


//Remove front
template <class T>
void TList<T>::RemoveFront()
{
    if(IsEmpty()) 
    {
        return;
    }
    else if(size == 1)
    {
        delete first; // delete first node
        first = nullptr; // set first to nullptr
        last = nullptr; // set last to nullptr
        size--; // decrement size
    }
    else
    {
        Node<T>* temp = first; // create temp node
        first = first->next; //     set first to next node
        first->prev = nullptr; // set first's prev to nullptr
        delete temp; // delete temp
        size--; // decrement size
    }
}


//Clear
template <class T>
void TList<T>::Clear()
{
    while(!IsEmpty())
    {
        RemoveBack(); // remove back until list is empty
    }
}

//Destructor
template <class T>
TList<T>::~TList()
{
    Clear(); // call clear
}

//Copy constructor
template <class T>
TList<T>::TList(const TList<T>& L)
{
    auto iter = L.GetIterator(); // get iterator
    first = nullptr; // set first to nullptr
    last = nullptr; // set last to nullptr
    size = 0; // set size to 0
    for(int i=0; i<L.GetSize(); i++) // iterate through list
    {
        InsertBack(iter.GetData()); // insert data from iterator
        iter.Next(); // increment iterator
    }
}


//Move assignment operator
template <class T>
TList<T>& TList<T>::operator=(TList && L)
{
    if (this != &L)
    {
        Clear();  // clear out current list

        first = L.first; // move pointers from l side tothe curr object
        last = L.last;
        size = L.size;

        L.first = nullptr; // set l side to nullptr
        L.last = nullptr;
        L.size = 0;
    }

    return *this;
}

//Copy assignment operator
template <class T>
TList<T>& TList<T>::operator=(const TList<T>& other)
{
    if (this != &other)
    {
        Clear(); // clear out current list

        Node<T>* current = other.first;
        while (current != nullptr)
        {
            InsertBack(current->data); // insert data from other list
            current = current->next;
        }
    }

    return *this;
}


//Move constructor
template <class T>
TList<T>::TList(TList && L)
{
    first = L.first; // move pointers from l side tothe curr object
    last = L.last; //   set first to next node
    size = L.size; // set first's prev to nullptr
}


//Get Iterator
template <class T>
TListIterator<T> TList<T>::GetIterator() const
{
    TListIterator<T> iter; // create iterator
    iter.ptr = first; // set iterator's pointer to first
    return iter; // return iterator
}

//Get Iterator End
template <class T>
TListIterator<T> TList<T>::GetIteratorEnd() const
{
    TListIterator<T> iter;
    iter.ptr = last; // set iterator's pointer to last
    return iter;
}

//TList Iterator
template <class T>
TListIterator<T>::TListIterator()
{
    ptr = nullptr; // set pointer to nullptr
}

//TList Iterator has next
template <class T>
bool TListIterator<T>::HasNext() const
{
    return (ptr->next != nullptr); // check if next exists
}

//TList Iterator has previous
template <class T>
bool TListIterator<T>::HasPrevious() const
{
    return (ptr->prev != nullptr); // check if previous exists
}

//TList Iterator next
template <class T>
TListIterator<T> TListIterator<T>::Next()
{
    if(HasNext())
    {
        ptr = ptr->next; // if next exists set pointer to next
    }
    return *this;
}

//TList Iterator previous
template <class T>
TListIterator<T> TListIterator<T>::Previous()
{
    if(HasPrevious()) // if previous exists
    {
        ptr = ptr->prev; // set pointer to previous
    }
    return *this; 
}

//TList Iterator get data
template <class T>
T& TListIterator<T>::GetData() const
{
    return ptr->data; 
}

//TList Iterator remove
template <class T>
TListIterator<T> TList<T>::Remove(TListIterator<T> pos)
{
    Node<T>* curr = pos.ptr; // get current node
    Node<T>* prev = curr->prev; // get previous node
    Node<T>* next = curr->next; // get next node
    pos.Next(); // increment iterator
    prev->next = next; // set previous's next to next
    next->prev = prev; // set next's prev to previous
    delete curr; // delete current node
    size--; // decrement size
    return pos;
}

template <class T>
void TList<T>::Insert(TListIterator<T> pos, const T& d){
	Node<T> *prev = nullptr;
	Node<T> *temp = new Node<T>(d);
	if(pos.HasPrevious() == true) // if previous exists
		prev = pos.ptr->prev; // set prev to previous
	else
		prev = nullptr; // else set prev to nullptr

	temp->next = pos.ptr;  // set temp's next to current
	pos.ptr->prev = temp; // set current's prev to temp
	
	if(prev == nullptr)  // if prev is nullptr
		first = temp;  // set first to temp
	else{
		prev->next = temp; // set prev's next to temp
		temp->prev = prev;	// set temp's prev to prev
	}
	size++; // increment size
}

