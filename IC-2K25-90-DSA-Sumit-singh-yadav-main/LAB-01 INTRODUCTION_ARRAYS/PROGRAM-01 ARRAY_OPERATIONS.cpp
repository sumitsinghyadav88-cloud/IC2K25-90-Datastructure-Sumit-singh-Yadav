#include <iostream.h>
#include <conio.h>
class arr{
    int ar[5], i;
    public:
    void insert(){
        cout<<"Enter 5 elements in the array"<<endl;
        for(i=0; i<5; i++){
            cout<<"Enter the element "<<i+1<<":";
            cin>>ar[i];
        }
        cout<<endl;
    }
    void display(){
        cout<<"the array is:"<<endl;
        for(i=0; i<5; i++){
        cout<<ar[i]<<" ";}
    }
        void deleteElement() {
        int pos;

        cout << "Enter position to delete: ";
        cin >> pos;

        for (i = pos - 1; i < 4; i++) {
            ar[i] = ar[i + 1];
        }

        cout << "After deletion: ";

        for (i = 0; i < 4; i++) {
            cout << ar[i] << " ";
        }

        cout << endl;
    }
         void search() {
        int value;
        cout << "Enter value to search: ";
        cin >> value;

        for (int i = 0; i < 5; i++) {
            if (ar[i] == value) {
                cout << "Element found at position " << i << endl;
                return;
            }
        }

        cout << "Element not found\n";
    }

};
int main(){
    arr s;
    s.insert();
    s.deleteElement();
    s.display();
    s.search();
    return 0;
    }
