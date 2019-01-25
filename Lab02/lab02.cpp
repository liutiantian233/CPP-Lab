#include <iostream>
using std::cout; using std::cin; using std::endl;

int main() {
    int num, num_1 = 0, persistence = 0, num_2 = 0;  // num_2 = 1
    cin >> num;
    
    if (num > 0 && num < 10) {
        cout << "0 " << num << endl;
        return 0;
    }
    
    if (num <= 0) {
        cout << "Error" << endl;
        return 0;
    }
    
    if (num >= 10) {
        
        while (num >= 10){
            num_1 = num % 10;
            num_2 += num_1;  // num_2 *= num_1
            num /= 10;
            
            if (num < 10 ){
                num += num_2;  // num *= num_2
                persistence += 1;
                num_2 = 0;  // num_2 = 1
            }
        }
    }
    
    cout << persistence << " " << num << endl;
    return 0;
}
