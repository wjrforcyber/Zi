# Take @Catherine's answer https://stackoverflow.com/a/2110796
AUX_SOURCE_DIRECTORY(bst BST)
AUX_SOURCE_DIRECTORY(rbt RBT) 
ADD_LIBRARY( ziTree STATIC ${BST} ${RBT} )