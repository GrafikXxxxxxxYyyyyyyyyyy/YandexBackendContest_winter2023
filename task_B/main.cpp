#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int Calculate (map<int, int>& A, map<int, int>& B){
    int num = 0;
    
    for (auto p : A){
        if (B.find(p.first) != B.end()){
            num += max(A[p.first], B[p.first]) - min(A[p.first], B[p.first]);
        }
        else{
            num += p.second;
        }
    }
    
    for (auto p : B){
        if (A.find(p.first) == A.end()){
            num += p.second;
        }
    }

    return num;
}

int main (){
    int N, M, Q;
    cin >> N >> M >> Q;

    map<int, int> A;
    map<int, int> B;

    // Получаем карты А
    for (int i = 0; i < N; i++){
        int card;
        cin >> card; 
        A[card]++;
    }
    
    // Получаем карты В
    for (int i = 0; i < M; i++){
        int card;
        cin >> card; 
        B[card]++;
    }

    // Получаем начальное состояние
    int divergency = Calculate(A, B);


    vector<int> result;

    for (int i = 0; i < Q; i++){
        int type; 
        char player;
        int card;

        cin >> type >> player >> card;

        if (type == 1){
            if (player == 'A'){
                // Если на данный момент, количество карт равное или в А их больше
                if (A[card] >= B[card]){
                    // То при манипуляции с картой дивергенция должна будет вырасти   
                    divergency++;
                }
                // А если в В было больше таких карт, то падает
                else{
                    divergency--;
                }

                A[card]++;
            }
            // Аналогично
            else{
                if (B[card] >= A[card]){
                    divergency++;
                }
                else{
                    divergency--;
                }
                
                B[card]++;
            }
        }
        else{
            if (player == 'A'){
                if (A[card] <= B[card]){
                    divergency++;
                }
                else{
                    divergency--;
                }

                A[card]--;
            }
            else{
                if (B[card] <= A[card]){
                    divergency++;
                }
                else{
                    divergency--;
                }

                B[card]--;
            }
        }

        result.push_back(divergency);
    }

    for (auto i : result){
        cout << i << " ";
    }

    return 0;
}



/*
1   2   
1   2   3   4   5
*/