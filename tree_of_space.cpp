#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include<unordered_set>

using namespace std;

struct Node{
	string nodeName;
	vector<Node*>childNodes;
	Node*parentNode;
	int ancestorLockedCount;
	int descendantLockedCount;
	int uniqueID;
	bool isLocked;

	Node(string name,Node*parent){
		nodeName=name;
		parentNode = parent;
		ancestorLockedCount=0;
		descendantLockedCount=0;
		uniqueID=0;
		isLocked=false;
	}
	void addChildren(vector<string>childNames,Node*parent){
		for(auto& childName:childNames)
		childNodes.push_back(new Node(childName,parent));
	}
};
void printTree(Node*root){
	cout<<"Parent:"<<root->nodeName<<"\n";
	cout<<"Children:\n";
	for(auto child:root->childNodes){
		cout<<child->nodeName<<"ancestorLockedCount:"<<
		child->ancestorLockedCount
		<<" descendantLockedCount:"<<child->descendantLockedCount
		<<"isLocked:"<<child->isLocked<<" uniqueID:"<<child->uniqueID
		<<"\n";
	}
	cout<<"\n";
	for(auto child:root->childNodes){
		printTree(child);
	}
}
struct Node*buildTree(Node*root,int& childCount,vector<string>& nodeNames){
	queue<Node*>q;
	q.push(root);
	int startIndex=1;
	while(!q.empty()){
		Node*currentNode=q.front();
		q.pop();

		if(startIndex >= nodeNames.size())continue;
		vector<string>temp;
		for(int i=startIndex;i<startIndex + childCount;i++)
		temp.push_back(nodeNames[i]);
	currentNode-> addChildren(temp,currentNode);
		startIndex += childCount;
		for(auto child:currentNode->childNodes)
		q.push(child);

	}
	return root;
}
class Tree{
private:
	Node*root;
	unordered_map<string, Node*>nameToNode;
    unordered_set<Node*> lockedNodes;
public:
	Tree(Node*rootNode){root=rootNode;}
	Node*getRoot() {return root;}
	void fillNameToNode(Node*currentNode){
		if(!currentNode)return;
		nameToNode[currentNode->nodeName]=currentNode;
		for(auto child:currentNode->childNodes)
		  fillNameToNode(child);
	}
	void informDescendants(Node*currentNode,int value){
		for(auto child:currentNode->childNodes){
			child->ancestorLockedCount += value;
			informDescendants(child,value);
		}
	}
	bool verifyDescendants(Node*currentNode,int&id,vector<Node*>& lockedNodes){
		if(currentNode->isLocked){
			if(currentNode->uniqueID!=id)return false;
			lockedNodes.push_back(currentNode);
		}
		if(currentNode->descendantLockedCount == 0)return true;
		bool result=true;
		for(auto child:currentNode->childNodes){
			result &= verifyDescendants(child,id,lockedNodes);
			if(result == false)return false;
		}
		return result;
	}
	bool lockNode(string nodeName,int id){
		Node*currentNode=nameToNode[nodeName];
		if(currentNode->isLocked)return false;
		if(currentNode->ancestorLockedCount != 0)return false;
		if(currentNode->descendantLockedCount != 0)return false;
		Node*current=currentNode->parentNode;
		while (current) {
			current->descendantLockedCount++;
			current=current->parentNode;
		}
		informDescendants(currentNode, 1);
		currentNode->isLocked=true;
		currentNode->uniqueID=id;
    	lockedNodes.insert(currentNode);
		return true;
    }
	bool unlockNode(string nodeName,int id){
		Node*currentNode=nameToNode[nodeName];
		if(!currentNode->isLocked)return false;
		if(currentNode->isLocked && currentNode->uniqueID != id)return false;
		
		Node*current=currentNode->parentNode;
		while (current) {
			current->descendantLockedCount--;
			current=current->parentNode;
		}
		informDescendants(currentNode, -1);
		currentNode->isLocked=false;
    lockedNodes.erase(currentNode); 
		return true;

}
bool upgradeNode(string nodeName,int id){
		Node*currentNode=nameToNode[nodeName];
		if(currentNode->isLocked)return false;
		if(currentNode->ancestorLockedCount != 0)return false;
		if(currentNode->descendantLockedCount == 0)return false;
		vector<Node*>lockedNodes;
		if(verifyDescendants(currentNode, id, lockedNodes)){
			for(auto node : lockedNodes){
				unlockNode(node->nodeName,id);
			}
		}else{
			return false;
		}
		lockNode(nodeName, id);
		return true;
	}
};
int main(){
	int totalNodes,childCount,queryCount;
	cin>>totalNodes>>childCount>>queryCount;
	vector<string>nodeNames(totalNodes);
	for(int i=0;i<totalNodes;i++)
	cin>>nodeNames[i];
Node*rootNode=new Node(nodeNames[0],nullptr);
rootNode=buildTree(rootNode, childCount, nodeNames);
Tree tree(rootNode);
tree.fillNameToNode(tree.getRoot());
int opcode,uniqueID;
string nodeName;
for(int i=0;i<queryCount;i++){
	cin>>opcode>>nodeName>>uniqueID;
	switch (opcode) {
		case 1:
		if(tree.lockNode(nodeName, uniqueID)){
			cout<<"true\n";
		}else{
			cout<<"false\n";
		}
		break;
		case 2:
		if(tree.unlockNode(nodeName, uniqueID)){
			cout<<"true\n";
		}else {
		cout<<"false\n";
		}
		break;
		case 3:
		if(tree.upgradeNode(nodeName, uniqueID)){
			cout<<"true\n";
		}else {
		cout<<"false\n";
		}
		break;
	}
}
return 0;
}