/*
ID:ilimugu1
LANG:C++
PROB:heritage
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

void postTraverse(const string& preOrder, int preP, int preR,
                  const string& inOrder, int inP, int inR,
                  string& postOrder)
{
    if(preP < preR)
    {
        int leftSubtreeSize = (inOrder.find(preOrder[preP]) - inP);
        postTraverse(preOrder, preP + 1, preP + leftSubtreeSize,
                     inOrder, inP, inP + leftSubtreeSize - 1, postOrder);
        postTraverse(preOrder, preP + leftSubtreeSize + 1, preR,
                     inOrder, inP + leftSubtreeSize + 1, inR, postOrder);
    }

    if(preP <= preR)
    {
        postOrder.push_back(preOrder[preP]);
    }
}

int main()
{
    string inOrder, preOrder, postOrder;
	freopen("heritage.in", "r", stdin);
	freopen("heritage.out", "w", stdout);
	cin >> inOrder >> preOrder;

    postTraverse(preOrder, 0, preOrder.size() - 1,
                 inOrder, 0, inOrder.size() - 1, postOrder);
    cout << postOrder << endl;
	
	return 0;
}
