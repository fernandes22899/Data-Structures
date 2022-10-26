#include "HuffTree.h"
#include <queue>

void buildTree(char * chs, int * freqs, int size)
{
  queue<HuffNode> qu;
  for(int i = 0; i < size; i++ )
  {
    HuffNode *origNodes = new HuffNode;
    origNodes->freq = freqs[i];
    origNodes->data = chs[i];
    qu.insert(origNodes);
  }

  while( queue.size() > 1 )
  {
    HuffNode * low = queue.findMin();

    int oneFreq = low->freq;
    char oneData = low->data;
    qu.deleteMin();

    HuffNode * nextLow = queue.findMin();

    int twoFreq = nextLow->freq;
    char twoData = nextLow->data;
    qu.deleteMin();

    int newFreq = oneFreq + twoFreq;
    HuffNode nRoot = new HuffNode;
    nRoot->freq = newFreq;
    nRoot->left = low;
    nRoot->right = nextLow;
    qu.insert(nRoot);
  }
  _root->left = nRoot;
}
