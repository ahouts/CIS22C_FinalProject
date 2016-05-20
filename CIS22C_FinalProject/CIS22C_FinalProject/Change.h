#include <iostream>

using namespace std;

class Change
{
private:
	Change prev;
	Change next;
	int row;
	int col;
	cell prevData;
	cell newData;
	bool isOpenParen;
	bool isCloseParen;
public:
	
	Change(Change prev, Change next, int row, int col, cell prevData, cell newData);
	void undo();
	void pushBack(int row, int col, cell prevData, cell newData);
	Change(bool isOpenParen, bool iscloseParen);





}