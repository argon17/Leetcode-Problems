class Node
{
public:
    int key, val;
    Node *next;
    Node(int k, int v, Node *n)
    {
        key = k;
        val = v;
        next = n;
    }
};

class MyHashMap
{
public:
    const static int mxN = 937;
    Node *data[mxN];
    /** Initialize your data structure here. */
    MyHashMap()
    {
        for (int i = 0; i < mxN; ++i)
            data[i] = NULL;
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int index = key % mxN;
        Node *head = data[index];
        Node *node = head;
        for (; node != NULL; node = node->next) {
            if (node->key == key) {
                node->val = value;
                return;
            }
        }
        Node *newHead = new Node(key, value, head);
        data[index] = newHead;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int index = key % mxN;
        Node *node = data[index];
        for (; node != NULL; node = node->next)
            if (node->key == key) return node->val;
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int index = key % mxN;
        Node *node = data[index];
        if (!node) return;
        if (node->key == key) data[index] = node->next;
        else
            for (; node->next != NULL; node = node->next) {
                if (node->next->key == key) {
                    node->next = node->next->next;
                    return;
                }
            }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */