#include <iostream> 
#include <vector>
#include <stack>

using namespace std;


int main () {
    ////////////////////////////////////////////////
    int N;
    cin >> N;

    vector<char> language;
    vector<int> hierarchy;
    
    for (int i = 0; i < N; i++){
        char sym;
        cin >> sym;
        language.push_back(sym);
    }

    for (int i = 0; i < 2*(N+1); i++){
        int id;
        cin >> id;
        hierarchy.push_back(id);
    }

    ////////////////////////////////////////////////
    stack<int> buffer;
    stack<int> nearest_A;
    stack<int> nearest_B;
    vector<int> state(N, -1);

    buffer.push(0);
    nearest_A.push(1);
    nearest_B.push(1);

    for (auto worker : hierarchy) {
        if (worker != 0){
            if (buffer.top() == worker){
                if (language[worker - 1] == 'A'){
                    nearest_A.pop();
                    // cout << nearest_A.top() << " - " << worker << "A - " << buffer.size() << endl;
                    state[worker - 1] = buffer.size() - nearest_A.top() - 1;
                }
                else{
                    nearest_B.pop();
                    // cout << nearest_B.top() << " - " << worker << "B - " << buffer.size()  << endl;
                    state[worker - 1] = buffer.size() - nearest_B.top() - 1;
                }

                buffer.pop();
            }
            else{
                buffer.push(worker);

                // В этом случае буффер точно не пуст
                if (language[worker - 1] == 'A'){
                    nearest_A.push(buffer.size()); // 1
                }
                else{
                    nearest_B.push(buffer.size());
                }
            }
        }
    }

    cout << endl;
    for (auto s : state){
        cout << s << " ";
    }

    return 0;
}



/*
=================================
5
A B B A B
0 1 1 2 3 4 4 5 5 3 2 0

0 0 0 2 0
=================================



=================================
4
A B A A
0 1 2 3 3 4 4 2 1 0


0 1 1 1
=================================
*/