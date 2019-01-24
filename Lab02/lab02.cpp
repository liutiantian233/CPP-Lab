#include <iostream>
using std::cout; using std::cin; using std::endl;

int main() {
    int num, b = 0, persistence = 0, c=0;
    cin >> num;
    if (num > 0 && num < 10){
        cout << " 0 " << num << endl;
        return 0;
    }
    if (num <=0) {
        cout << "Error" << endl;
        return 0;
    }
    if (num >=10) {
        while (num >= 10){
            b = num % 10;
            c += b;
            num /= 10;
            if (num < 10 ){
                num +=c ;
                persistence+= 1;
                c=0;
            }
        }
    }
    
    cout << persistence << " " << num << endl;
    return 0;
}
