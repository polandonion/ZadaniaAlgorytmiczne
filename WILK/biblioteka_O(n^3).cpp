#include <iostream>                                                             
 
using namespace std;                                                            
 
int n, odw = 0, wy = 0;                                                         
int arr[100009];                                                                
 
void f(int id) {                                                                
    odw ++;                                                                     
    if (odw == 3) {                                                             
        wy ++, odw --;                                                          
        return;                                                                 
    }                                                                           
    for (int i = id + 1; i <= n; i ++) {                                        
        if (arr[i] > arr[id])                                                   
            f(i);                                                               
    }                                                                           
    odw --;                                                                     
}                                                                               
 
int main() {                                                                    
    ios_base::sync_with_stdio(0);                                               
    cin.tie(0); cout.tie(0);                                                    
    cin >> n;                                                                   
    for (int i = 1; i <= n; i ++)                                               
        cin >> arr[i];                                                          
    for (int i = 1; i <= n; i ++)                                               
        f(i);                                                                   
    cout << wy;                                                                 
}