#include <jni.h>
#include <string>
#include <vector>
#include <chrono>
#include <format>

/*
 * If the item is a parent of itself then it is equal to the default value.
 *
 */

extern "C"
JNIEXPORT jstring JNICALL
Kotlin_com_example_MobileInventory_MainActivity_stringFromCpp(JNIEnv* env, jobject) {
    return env->NewStringUTF("Hello from C++!");
}


struct Item{
    std::string name;
    std::string date; // month-day-year XX-XX-XXXX
    int count;

    Item(std::string given_name, int given_count, std::string given_date){
        name = given_name;
        count = given_count;
        date = given_date;
    }

};

class UnionFind {
public:
    std::vector<int> parent;

    UnionFind(int size) {
        parent.resize(size);
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    int find(int x) {
//        if (parent[x] != x) // This is done recursivley rather do it iterativly
//            parent[x] = find(parent[x]); // path compression
//        return parent[x];
        int root = x;
        while (parent[root] != root) { // checking if parent is itself
            root = parent[root];
        }

        while (x != root) { // point back to root
            int next = parent[x];
            parent[x] = root;
            x = next;
        }

        return root;

    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
            parent[rootY] = rootX;
    }
};

