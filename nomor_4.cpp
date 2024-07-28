#include <iostream>
#include <string>

using namespace std;

// Struktur data untuk node binary tree
struct Node {
    int noRekening;
    string namaNasabah;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat node baru
Node* createNode(int noRekening, string namaNasabah) {
    Node* newNode = new Node();
    newNode->noRekening = noRekening;
    newNode->namaNasabah = namaNasabah;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk memasukkan data ke dalam binary tree
Node* insertNode(Node* root, int noRekening, string namaNasabah) {
    if (root == NULL) {
        root = createNode(noRekening, namaNasabah);
    } else if (noRekening < root->noRekening) {
        root->left = insertNode(root->left, noRekening, namaNasabah);
    } else if (noRekening > root->noRekening) {
        root->right = insertNode(root->right, noRekening, namaNasabah);
    }
    return root;
}

// Fungsi untuk mencari data dalam binary tree
Node* searchNode(Node* root, int noRekening) {
    if (root == NULL || root->noRekening == noRekening) {
        return root;
    } else if (noRekening < root->noRekening) {
        return searchNode(root->left, noRekening);
    } else {
        return searchNode(root->right, noRekening);
    }
}

// Fungsi untuk menghapus data dari binary tree
Node* deleteNode(Node* root, int noRekening) {
    if (root == NULL) {
        return root;
    } else if (noRekening < root->noRekening) {
        root->left = deleteNode(root->left, noRekening);
    } else if (noRekening > root->noRekening) {
        root->right = deleteNode(root->right, noRekening);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->noRekening = temp->noRekening;
            root->namaNasabah = temp->namaNasabah;
            root->right = deleteNode(root->right, temp->noRekening);
        }
    }
    return root;
}

// Fungsi untuk menampilkan data dalam binary tree
void displayTree(Node* root) {
    if (root != NULL) {
        displayTree(root->left);
        cout << "No. Rekening: " << root->noRekening << ", Nama Nasabah: " << root->namaNasabah << endl;
        displayTree(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Memasukkan data ke dalam binary tree
    root = insertNode(root, 12345, "John Doe");
    root = insertNode(root, 67890, "Jane Doe");
    root = insertNode(root, 34567, "Bob Smith");

    // Menampilkan data dalam binary tree
    cout << "Data dalam binary tree:" << endl;
    displayTree(root);

    // Mencari data dalam binary tree
    int noRekening = 12345;
    Node* foundNode = searchNode(root, noRekening);
    if (foundNode != NULL) {
        cout << "Data nasabah dengan no. rekening " << noRekening << " ditemukan:" << endl;
        cout << "Nama Nasabah: " << foundNode->namaNasabah << endl;
    } else {
        cout << "Data nasabah dengan no. rekening " << noRekening << " tidak ditemukan." << endl;
    }

    // Menghapus data dari binary tree
    noRekening = 67890;
    root = deleteNode(root, noRekening);

    // Menampilkan data dalam binary tree setelah penghapusan
    cout << "Data dalam binary tree setelah penghapusan:" << endl;
    displayTree(root);

    return 0;
}