/*
Nama = Muhamad Ilham Habib
NPM = 140810180018
Tahun = 2019
Deskripsi = Program mencetak smua node, kedalaman, level, dan anak.
*/
#include <iostream>
using namespace std;

struct Simpul
{
    int info;
    Simpul *left;
    Simpul *right;
};
typedef Simpul *pointer;
typedef pointer Tree;

void createTree(Tree &Root)
{
    Root = NULL;
}
void createNode(pointer &pBaru)
{
    pBaru = new Simpul;
    cout << "Masukan satu huruf =";
    cin >> pBaru->info;
    pBaru->left = NULL;
    pBaru->right = NULL;
}
void insertBST(Tree &Root, pointer pBaru)
{
    if (Root = NULL)
        Root = pBaru;
    else if (pBaru->info < Root->info)
        insertBST(Root->left, pBaru);
    else if (pBaru->info >= Root->info)
        insertBST(Root->right, pBaru);
    else
        cout << "Tos aya";
}
int kedalaman(Tree Root)
{
    int kiri, kanan;
    if (Root = NULL)
    {
        return 0;
    }
    else
    {
        kiri = kedalaman(Root->left);
        kanan = kedalaman(Root->right);
        if (kiri > kanan)
        {
            return (kiri + 1);
        }
        else
        {
            return (kanan + 1);
        }
    }
}
void level(Tree Root, int x)
{
    if (Root = NULL)
    {
        return;
    }
    if (x == 1)
    {
        cout << Root->info << " ";
    }
    else if (x > 1)
    {
        level(Root->left, x - 1);
        level(Root->right, x - 1);
    }
}
void urutanLevel(Tree Root)
{
    int dalam = kedalaman(Root);
    for (int i = 1; i < dalam; i++)
    {
        cout << i << " : ";
        level(Root, i);
        cout << endl;
    }
}
void anak(Tree Root, pointer pBaru)
{
    pBaru = Root;
    if (pBaru != NULL)
    {
        cout << "Ayah = " << pBaru->info << endl;
        cout << "Anak = " << endl;
        if (pBaru->left == NULL)
        {
            cout << " kiri : " << endl;
        }
        else
        {
            cout << " kiri :" << pBaru->left->info << endl;
        }
        if (pBaru->right == NULL)
        {
            cout << " kanan :" << endl;
        }
        else
        {
            cout << " kanan :" << pBaru->right->info << endl;
        }
        cout << endl;
        anak(Root->left, pBaru);
        anak(Root->right, pBaru);
    }
}
void preorder(Tree Root)
{
    if (Root != NULL)
    {
        cout << Root->info << endl;
        preorder(Root->left);
        preorder(Root->right);
    }
}
void postorder(Tree Root)
{
    if (Root != NULL)
    {
        postorder(Root->left);
        postorder(Root->right);
        cout << Root->info << endl;
    }
}
void inorder(Tree Root)
{
    if (Root != NULL)
    {
        inorder(Root->left);
        cout << Root->info << endl;
        inorder(Root->right);
    }
}
int main()
{
    Tree r;
    pointer p;
    int n, menu;

    createTree(r);
    cout << " Masukan banyak Data = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        createNode(p);
        insertBST(r, p);
    }
    do
    {
        system("cls");
        cout << "==================================";
        cout << "\n1. insert\n2. Pre Order\n3. In Order\n4. Post Order\n5. Kedalaman\n6. Leve\n7. Anak\n8. Exit\n";
        cout << "==================================\n";
        cout << "Opsi = ";
        cin >> menu;
        cout << endl;

        switch (menu)
        {
        case 1:
            createNode(p);
            insertBST(r, p);
            break;
        case 2:
            cout << "Pre order" << endl;
            preorder(r);
            break;
        case 3:
            cout << "In order" << endl;
            inorder(r);
            break;
        case 4:
            cout << "Post Order" << endl;
            postorder(r);
            break;
        case 5:
            cout << "Kedalaman = " << kedalaman(r);
            break;
        case 6:
            cout << " Level pohon =" << endl;
            urutanLevel(r);
            break;
        case 7:
            cout << " Anak =" << endl;
            anak(r, p);
            break;
        default:
            exit(0);
        }
        cout << endl;
        system("pause");
    } while (menu != 8);
}
