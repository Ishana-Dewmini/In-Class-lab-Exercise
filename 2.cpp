#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


int main(){
    int a[] = {5,3,1,2,8};
    int b[sizeof(a) / sizeof(a[0])];
    int n = sizeof(a) / sizeof(a[0]);
    b[0]=a[0]/1.0;
    cout<<b[0]<<endl;   
    for (int i=1; i<n; i++){
        int index=0;
        while (true){
            if (b[index]>a[i]){
                for (int j=n-2;j>=index;j--){
                    b[j+1]=b[j];
                }                
                b[index]=a[i];              
                break;
            }
            else {
                index++;
            }
        }
        if (i%2 == 0) {
             cout << fixed << setprecision(1) << b[i/2] << endl;
        } else {
            cout << static_cast<double>(b[i/2] + b[i/2+1]) / 2.0 << endl;
        }

    }
    return 0;
}
