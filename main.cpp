#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

enum CommandTypes { invalidParam, insert_0, insert_end, print_0, print_end, print, delete_end, delete_0, dim, remove_all, find_item, find_max, delete_pos, invert_range };
enum ErrorTypes { invalid_command_error, invalid_number_error, exceed_size, not_find, invalid_position, empty_list };
map<string, CommandTypes> s_mapCommandTypes;
map<string, ErrorTypes> s_mapErrorTypes;

int size = 0;
int maxSize = 100;
int listOfNumbers [100] = { };
int number = 0;
string command = "";


void getCommonError(string error){

    switch(s_mapErrorTypes[error]){
        case invalid_command_error:
            cout << "Invalid command " << command << endl;
            break;
        case invalid_number_error:
            cout << "Invalid number " << number  << endl;
            break;

        case exceed_size:
            cout << "Excedido a quantidade de itens";
            break;

        case not_find:
            cout << "Item " << number << " nao encontrado " << endl;
            break;

        case invalid_position:
            cout << "Posicao invalida";
            break;

        case empty_list:
            cout << "Lista vazia " << endl;
            break;
    }
}

void Initialize()
{
      s_mapCommandTypes["insert_0"] = insert_0;
      s_mapCommandTypes["insert_end"] = insert_end;
      s_mapCommandTypes["print_0"] = print_0;
      s_mapCommandTypes["print_end"] = print_end;
      s_mapCommandTypes["print"] = print;
      s_mapCommandTypes["delete_0"] = delete_0;
      s_mapCommandTypes["delete_end"] = delete_end;
      s_mapCommandTypes["dim"] = dim;
      s_mapCommandTypes["clear"] = remove_all;
      s_mapCommandTypes["find_item"] = find_item;
      s_mapCommandTypes["find_max"] = find_max;
      s_mapCommandTypes["invert_range"] = invert_range;
      s_mapCommandTypes["delete_pos"] = delete_pos;
      s_mapErrorTypes["invalid_command_error"] = invalid_command_error;
      s_mapErrorTypes["invalid_number_error"] = invalid_number_error;
      s_mapErrorTypes["exceed_size"] = exceed_size;
      s_mapErrorTypes["not_find"] = not_find;
      s_mapErrorTypes["invalid_position"] = invalid_position;
      s_mapErrorTypes["empty_list"] = empty_list;
}

void replaceValues(int arr[]){
    for(int i=0; i < size; i++){
        listOfNumbers[i] = arr[i];
    }
}

void printList(){
    cout << "Lista=";
    for(int i=0; i < size; i++){
        cout << " " << listOfNumbers[i];
    }
    cout << endl;
}

void digitNumber(){
     cout << "Digite um numero: " << endl;
    cin >> number;
}

void insertIntoListInitial(){
    digitNumber();
    int tempList [100] = {};
    if(size < maxSize) {
        for(int i=0; i < size; i++){
           tempList[i + 1] = listOfNumbers[i];
        }
        tempList[0] = number;
        size++;
        replaceValues(tempList);

    }else{
        getCommonError("exceed_size");
    }
}

void insertIntoListEnded(){
    digitNumber();
    int tempList [100] = {};
    if(size < maxSize) {
        for(int i=0; i < size; i++){
            tempList[i] = listOfNumbers[i];
        }
        tempList[size++] = number;
        size++;
        replaceValues(tempList);
    }else{
        getCommonError("exceed_size");
    }

}

void printType(string typePrint){
    if(typePrint == "initial"){
        cout << "Lista(0)= " << listOfNumbers[0] << endl;
    }else if(typePrint == "end"){
        cout << "Lista(end)= " << listOfNumbers[size] << endl;
    }else if(typePrint == "all"){
        printList();
    }
}

void deleteInitial(){
    int tempList [100] = {};
    if(size == 0) {
        for(int i=0; i < size; i++){
            if(i != 0){
                tempList[i-1] = listOfNumbers[i];
            }
        }
        size--;
        replaceValues(tempList);
    }else{
        getCommonError("empty_list");
    }
}

void removeAll(){
     int tempList [100] = {};
     size = 0;
     replaceValues(tempList);
}

void deleteEnd(){
    int tempList [100] = {};
    if(size == 0) {
        for(int i=0; i < size -1; i++){
            tempList[i] = listOfNumbers[i];
        }
        size--;
        replaceValues(tempList);
    }else{
        getCommonError("empty_list");
    }
}

void deletePos(){
    digitNumber();
    int tempList [100] = {};
    if(size == 0) {
        for(int i=0; i < size -1; i++){
            if(i != number){
                tempList[i] = listOfNumbers[i];
            }
        }
        size--;
        replaceValues(tempList);
    }else{
        getCommonError("empty_list");
    }
}

void invertRange(){
    int tempList [100] = {};
    int index = 0;
    if(size > 0) {
        for(int i=size; i >= 0 ; i--){
            tempList[index] = listOfNumbers[i];
            index++;
        }
        replaceValues(tempList);
    }else{
        getCommonError("empty_list");
    }
}

void findItem(){
        digitNumber();
        bool found = false;
        for(int i=0; i < size; i++){
            if(listOfNumbers[i] == number){
                found = true;
                cout << "item " << number << " na posicao " << i << endl;
                break;
            }
        }
        if(!found){
            getCommonError("not_find");
        }
}

void findMax(){
    int maxNumber = -1;
    int position = -1;
    for(int i=0; i < size; i++){
        if(listOfNumbers[i] > maxNumber){
            maxNumber = listOfNumbers[i];
            position = i;
        }
    }
    if(maxNumber != -1){
        cout << "Max item " << number << " na posicao " << position << endl;
    }else{
         getCommonError("empty_list");
    }
}


void getCommand(string command){
    switch(s_mapCommandTypes[command]){
        case insert_0:
            insertIntoListInitial();
            break;
        case insert_end:
            insertIntoListEnded();
            break;
        case print_0:
            printType("initial");
            break;
        case print_end:
            printType("end");
            break;
        case print:
            printType("all");
            break;
        case dim:
            cout << "Lista tem " << size << " itens" << endl;
            break;
        case remove_all:
            removeAll();
            break;
        case find_item:
            findItem();
            break;
        case find_max:
            findMax();
            break;
        case delete_pos:
            deletePos();
            break;
        case invert_range:
            invertRange();
            break;
        default:
            getCommonError("invalid_command_error");
            break;

    }
}

int main()
{
    Initialize();
    while(1){
        cout << "Digite um comando: " << endl;
        cin >> command;
        getCommand(command);
    }

    system("pause");
    return 0;
}
