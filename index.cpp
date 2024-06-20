// Your function should take a sorted vector of integers and a target integer as input.

// You should use recursion to implement the binary search algorithm.

// The function should return the index of the target integer in the vector if it is present, and -1 otherwise.

// Bonus:

// Implement a function to check if the array is sorted. This function should return true if the array is sorted in 

// ascending order, and false otherwise. Implement a function to generate a vector of n random integers. Use this 

// function to generate test cases for your binary search function.




// Copy in the custom vector that you built already and this will be the algorithm portion of the implimentation that you 
// Have so far. You already wanted to impliment the classic algorithm for search and sort and after this you will also impliment 
// Some recursive applications of those algorithms and then you will have filled in one of your gaps in computer science.
// You will be that much closer to solving leetcode problems after doing the same with all the elementary data structures.
// The primary goal is to get to graphs. Graphs are used for all cool stuff AI cryotograohy crypto blockchain etc. It all starts from 
// Graphs and then optimizing the code is where modern c++ comes in. Solve your leetcode problems
// Finish learning the backend dev
// Build the website for the BSSC and then youre golden.
// Learn how to build and design computers
// Dabble in operating systems
// Finally chip design --- 

 /*
    1. Create a templated vector class with move assignment operator, Copy Constructor & Move constructor member funtions.
    
    2. You should also include basic and fundimental operations such as, pushBack(), pushFront(), popFront(), popBack(), find(), 
    remove(), size(), and a destructor.  

    3. You should also include some special sorting algorithms implimented as member functions such as 
    bubble sort, Quick Sort, Merge Sort, 

    4. You should also make use of the STL exception class and must write exception safe code when possible given the data structure 
    that you have to work with. 
*/ 

// Remember to handle any exceptions that might be thrown by your member functions. For example, your operator[] 
// function throws an exception if the index is out of range. You can use a try-catch block in your main function 
// to catch this exception and print an error message.

//////////////// Completed Functions  //////////////
// sizeOf() to check the size of the array
// print() To print the value of the elements in the array. 
// operator[] for access to elements
// pushBack() to add to the back 
// exit() To exit the user based interface. 
// destructor to delete dynamically allocated memory
// find()   To find a specific value of that may be in an array
// pushFront() To add an element to the front of the array
// front() to access the first element
// back() to access the last element
// clear() to remove all elements from the vector
// popFront()  To remove an element from the front of an array.
// popBack()   To remove an element from the back of an array 
// remove()  To remove a specific element in an array
// empty() to check if the vector is empty
// insert() to insert an element at a specific position
// reverse() To reverse or flip the order of the elements in the array.

// bubbleSOrt To impliment this well known algorith

// mergeSort() To impliment this well known algorithm
// slelctionSort() To impliment this well known algorithm. 









#include <iostream>
using namespace std;





template <typename T>
class vector {

private: 
    int size{0}; 
    int capacity;
    T *arr; 

public:
    vector(T v): capacity(v), arr(new T[v]){
        for(int i = 0; i < capacity; i++ ){
            arr[i] = 0; 
        }
    }

    void pushBack(const T &val) {
        if(size >= capacity){
            capacity *= 2; 
            T * arrNew = new T[capacity];
            for (int k = 0; k < size; k++){
                arrNew[k] = arr[k]; 
            }
            delete []arr;
                arr = arrNew;
        }
        arr[size] = val; 
        size++; 
    }

    void pushFront(const T& val){
        T* temp = nullptr;
        if(size >= capacity){
            capacity *=2;
            temp = new T[capacity];
        } else {
            temp = new T[capacity + 1]; 
            temp[0] = 0; 
            for(int i = 0; i < size; i++){
                temp[i + 1] = arr[i];  
            }
        }

        temp[0] = val; 
        arr = temp;
        size++;
    }

    void popFront(){
        if(size == 0 ){
            return; 
        }
        for(int i = 0; i < size; i++){
            arr[i] = arr[i + 1]; 
        }
    }

    void popBack(){
        if (size == 0){
            return;
        }
        arr[size + 1 ] = 0; 
    }

    void remove(int const index){
        if (size == 0 ){
            return; 
        }
        for(int i = index; i < size; i++){
            arr[i] = arr[i + 1]; 
        }
    }

    inline int sizeOf() const  {
        return size; 
    }

    void print(){
        empty();

        if (arr == nullptr){
            std::cout << "Array has not been created " << std:: endl;
            return;
        }
        if(size != 0 ){
            std::cout << "vector: ";
        }
        for(int i = 0; i < size; i++){
            std::cout << arr[i] << ", "; 
        }
        std::cout << "" << std::endl; 
    }

    T& operator[](int index) const{
        if(index < 0 || index >size){
            std::cerr << "Index out of range: " << index << std::endl;
            static T defaultObj{}; 
            return defaultObj;
        }
        return arr[index]; 
    }


    void insert(T value, int index){
        if (index > capacity || index < 0 ){
            std::cerr << "Index out of range " << index << std::endl; 
        }
        arr[index] = value; 
    }

    void find(const T val) const {
        bool found = false;
       for (int i = 0; i < size; i++){
            if (arr[i] == val){
                std::cout << std::endl;
                std::cout << "value found at index: "; 
                std::cout << i << ", " << std::endl; 
                std::cout << std::endl; 
                found = true;
            }
        }
        if (!found){
        std::cout << "value not found: " << std::endl; 
        }
    }

    T front() const{
        return arr[0]; 
    }

    T back() const{
        return arr[size - 1]; 
    }

    void reSize(const int SIZE){
        T * sizedArr = new T[SIZE]();
        for(int i = 0; i < size; i++){
            arr[i] = sizedArr[1];
        }
        sizedArr = arr;
    }

    void reverse(){
        T *reversed = new T[capacity]; 
        int base = 0;
        int tail = size - 1; 
        int emptyIndexies = size + 2;
        for(int i = 0; i < size; i++){
            reversed[base ++] = arr[tail --]; 
            for(int j= emptyIndexies; j < capacity; j++){
                reversed[j] = 0; 
            } 
        }
        for(int j= emptyIndexies; j < capacity; j++){
            reversed[j] = 0; 
        } 
        delete [] arr;
        arr = reversed;
    }




    void clear(){
        for(int i = 0; i < capacity; i++){
            arr[i] = 0; 
            size--;
        }
        size = 0;
    }



    void exit(){
        return;
    }


    bool empty(){
        if(size == 0){
            std::cout << "Vector is: empty. " << std::endl; 
            return true;
        } else 
            std::cout << "Vector is not emplty. " << std::endl; 
            return false; 
    }


////////////////////////////////////////////////////////////////////////////////////// Marked for integration ////////////////////////////////////////////////////////////////////////////////


    // void selectSort(int arr[], int n) {
    //     for (int i = 0; i < n - 1; i++) {
    //         int minIndex = i;
    //         for (int j = i + 1; j < n; j++) {
    //             if (arr[j] < arr[minIndex]) {
    //                 minIndex = j;
    //             }
    //         }
    //         int temp = arr[i];
    //         arr[i] = arr[minIndex];
    //         arr[minIndex] = temp;
            
    //     }
    // }

////////////////////////////////////////////////////////////////////////////////////// Marked for integration ////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////// Marked For Testing ////////////////////////////////////////////////////////////////////////////////

    void BubbleSort(int target) {
    bool swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int c = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = c;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            } 
            std::cout << std::endl;
            std::cout << "Sorting pass " << i+1 << ": "; 
            for (int l = 0; l < n; l++){
                std::cout << arr[l] << " ";
            }
            std::cout << "" << std::endl;
        }

    }

    bool isSorted(vec<T> & arr){
        SIZE = vec.size;
        for(int i = 0; i < size; i++){
            for(int j = 1; j <= size; j++){
                if arr[i] > arr[j]
                return false;
                std::cout << "Vector is not sorted" << endl; 
            }
        }
        return true; 
        std::cout << "Vector is sorted" << endl; 
    }


////////////////////////////////////////////////////////////////////////////////////// Marked For Testing ////////////////////////////////////////////////////////////////////////////////









    void listt(){
        std::cout << "pushBack() To add to the back of the array. " << std::endl;
        std::cout << "pushFront() To add an element to the front of the array. " << std::endl;
        std::cout << "popFront() To remove an element from the front of an array. " << std::endl;
        std::cout << "popBack() To remove an element from the back of an array.  " << std::endl;
        std::cout << "find() To find a specific value of that may be in an array " << std::endl;
        std::cout << "remove() To remove a specific element in an array " << std::endl;
        std::cout << "sizeOf() To check the size of the array " << std::endl;
        std::cout << "print() To print the value of the elements in the array. " << std::endl;
        std::cout << "clear() To remove all elements from the vector. " << std::endl; 
        std::cout << "empty() To check if the vector is empty " << std::endl;
        std::cout << "insert() To insert an element at a specific position. " << std::endl;
        std::cout << "erase() To remove an element at a specific position " << std::endl;
        std::cout << "front() To access the first element. " << std::endl;
        std::cout << "back() To access the last element. " << std::endl;
    }

    ~vector(){
        delete [] arr;
    }


}; 






int main() {
    // Create a vector with initial capacity of  10
    vector<int> v1(10);

    // Test pushBack
    v1.pushBack(5);
    v1.pushBack(10);
    v1.pushBack(15);
    v1.pushBack(20);
    v1.pushBack(25);
    v1.print();  // Should print "vector: 5, vector: 10, vector: 15, vector: 20, vector: 25,"

    // Test sizeOf
    std::cout << "Size: " << v1.sizeOf() << std::endl;  // Should print "Size: 5"

    // Test operator[]
    std::cout << "Element at index 0: " << v1[0] << std::endl;  // Should print "Element at index 0: 5"
    std::cout << "Element at index 4: " << v1[4] << std::endl;  // Should print "Element at index 4: 25"

    // Test with an out-of-range index
    std::cout << "Element at index 10: " << v1[10] << std::endl;  // Should throw an exception or print an error message
    // Test other member functions as needed...

    v1.find(15); 

    v1.pushFront(1);

    v1.print();

    std::cout << "Size: " << v1.sizeOf() << std::endl;  // Should print "Size: 5"


    std::cout << "The element at the front of the vector is " << v1.front() << std::endl; 
    std::cout << "The element at the rear of the vector is " << v1.back() << std::endl; 

    v1.reverse();
    std::cout << "The reversed vector is: "; 
    v1.print();
    v1.clear();
    v1.print();
    v1.pushBack(7); 
    v1.pushBack(11);
    v1.pushBack(5);
    v1.pushBack(10);
    v1.pushBack(55);
    v1.pushBack(28);
    v1.pushBack(4);
    v1.pushBack(19);
    v1.pushBack(2);
    v1.print();
    std::cout << "Bubble sort first pass \n" << std::endl; 
    v1.BubbleSort(5);
    v1.print();

    return 0;
}