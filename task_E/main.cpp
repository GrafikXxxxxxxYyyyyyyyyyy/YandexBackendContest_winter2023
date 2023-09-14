#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;



class PrefixTree {
public:
    PrefixTree () {
        root = new TreeNode; // Инициализируем корневой узел
    }

    ~PrefixTree () {
        DeleteTree(root);
    }

    int Calculate () {
        return CalculateTree(root, 0);
    }

    void AddInfo (const vector<int>& v){
        return FillFromVector(root, v, 0);
    }

    void Print () {
        return PrintTree(root, 0);
    }

private:
    // Узел дерева
    struct TreeNode {
        // Хранит словарь потомков
        unordered_map<int, TreeNode*> children;

        // И информацию о том, сколько массивов посещало данный узел
        int N = 0;
    };


    void FillFromVector (TreeNode* current, const vector<int>& v, int depth){
        if (depth < v.size()){
            // Проверка что значение не пусто
            if (current->children.find(v[depth]) == current->children.end()){
                current->children[v[depth]] = new TreeNode;
            }

            // Рекурсивный вызов
            FillFromVector (current->children[v[depth]], v, depth + 1);
        }

        // Обновление информации о том, что ещё один массив прошел через данный узел
        current->N++;
    
        return;
    }


    int CalculateTree (TreeNode* current, int depth) {
        if (current == nullptr) {
            return 0;
        }   

        // Тут надо делать сдвиг на единицу количества побывавших в этом
        // узле массивов тупо потому, что при создании узла, исходный массив
        // сам в нем бывает, а его учитывать не нужно
        int value = (current->N - 1) * depth;

        for (const auto& child : current->children){
            value += CalculateTree(child.second, depth + 1);
        }

        return value;
    }


    // Рекурсивная функция для печати дерева
    void PrintTree(TreeNode* current, int depth) {
        if (current == nullptr) {
            return;
        }

        // Выводим информацию о текущем узле
        for (int i = 0; i < depth; i++) {
            cout << "---";  // Вставляем отступы для наглядности
        }
        cout << " Node: N=" << current->N << endl;

        // Рекурсивно вызываем функцию для потомков
        for (const auto& kvp : current->children) {
            cout << "Child " << kvp.first << ": ";
            PrintTree(kvp.second, depth + 1);
        }
    }

    // Вспомогательная функция для удаления дерева
    void DeleteTree(TreeNode* current) {
        if (current == nullptr) {
            return;
        }
        for (auto& kvp : current->children) {
            DeleteTree(kvp.second);
        }
        delete current;
    }

private:
    TreeNode* root;
};

int main() {
    // Пример 1:
    {   
        PrefixTree tree;

        tree.AddInfo({1,2,3});
        tree.AddInfo({1,2});
        tree.AddInfo({1,3});
        cout << endl << endl;
        tree.Print();
        cout << endl << endl;

        assert(tree.Calculate() == 4 && "Wrong answer");
    }
    
    // Пример 2:
    {   
        PrefixTree tree;
        
        tree.AddInfo({5});
        tree.AddInfo({1,2});
        tree.AddInfo({5,1,2});
        cout << endl << endl;
        tree.Print();
        cout << endl << endl;

        assert(tree.Calculate() == 1 && "Wrong answer");
    }

    return 0;
}
