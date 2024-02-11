#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void parseConstDef();
void parseVarDef();
void parseFuncDef();
void parseStmt();
int parseExp();
void parseReadStmt();
void parsePrint();
void parseReturnStmt();
void parseMainFunc();
void parseBlock(bool isNeedReturn);
void parseFuncFParams();
int parseLVal(int type);
void parseFuncRParamsWithoutError();
void error(int lineId, string errType);
string toLowerCase(string in);
void levelUp();
void levelDown();
void parseErrorA(char ch, bool isAlreadyError);
bool parseErrorB(string idenfr, int lineID);
int parseErrorC(string idenfr, int lineID);
void parseErrorH(string idenfr, int lineID);
void parseErrorI();
void parseErrorJ();
void parseErrorK();

FILE *inputFile;
ifstream inFile("input.txt");
ofstream fout("output.txt");
ofstream errorOut("error.txt");
ofstream pcodeOut("pcoderesult.txt");

string token;
string inputedString="";

int inputedStringLength = 0;
int num;
int global_line;
/* l, printf오류를 위한 변수 */
int lastNonTerminalLine = 0;
/* m, break,comtinue가 순환이 아닌 변수에서 나올때를 위한 변수 */
bool isCirculer[100] = {false};
/* g, 함수에 return 이 없을때 를위한변수 */
bool isReturnCalled=false;

bool isCameFromParam = false;
int blocks[100000] = {0};
int blocksTop = 0;

struct Word
{
	string label;
	string idenfr;
	int lineId;
};
Word wordList[10000];
int top = 0;
int wordCnt = 0;
Word wordNow;

enum KindEnum {
	CONST,
	VAR,
	FUNC,
	PARAM
};

enum TypeEnum {
	INT,
	VOID,
	ARR1,
	ARR2
};
int currentFunctionType;

struct Symbol22
{
	string idenfr;
	int kind;
	int type;
	int level;
};
Symbol22 symbolTable[10000];
int symbolTableTop = -1;
int levelNow = 0;

struct errorType
{
	int lineId;
	string errType;
} errorList[100];

struct FuncInfo
{
	int pos;
	int paramNum;
	int type;
	int paramPos[100];
};
FuncInfo getFuncInfo(string idenfr);
void parseFuncRParams(FuncInfo funcInfo);

class Label{
    private:
        int point = 0;

    public:
        Label() { }

        int getPoint() {
            return point;
        }

        void setPoint(int point) {
            this->point = point;
        }
};

class Code{
    private:
        string name;
        int level=0;
        int addr=0;
        string print="";
        Label* label=nullptr; // Label 클래스가 정의되어 있어야 합니다.

        int type = 0;

    public:
        // 1, 2, 3, 4, 5는 각 생성자의 타입을 나타냅니다.
        // 1: name, level, addr
        // 2: name, addr
        // 3: name
        // 4: name, print
        // 5: name, label
		Code() { } // 기본 생성자 추가

        Code(string name, int level, int addr) : name(name), level(level), addr(addr), type(1) { }

        Code(string name, int addr) : name(name), addr(addr), type(2) { }

        Code(string name) : name(name), type(3) { }

        Code(string name, string print) : name(name), print(print), type(4) { }

        Code(string name, Label* label) : name(name), label(label), type(5) { }

        void show(){
            if(type == 1){
                cout << name << "  " << level << "  " << addr << endl;
            }else if(type == 2){
                cout << name << "  " << addr << endl;
            }else if(type == 3){
                cout << name << endl;
            }else if(type == 4){
                cout << name << "  " << print << endl;
            }else if(type == 5){
                cout << name << "  " << label->getPoint() << endl; // Label 클래스의 getPoint() 함수가 필요합니다.
            }
        }

        string getName(){
            return name;
        }

        Label* getLabel(){
            return label;
        }

        int getLevel(){
            return level;
        }

        int getAddr(){
            return addr;
        }

        string getPrint(){
            return print;
        }
};
vector<Code> codeList;
int codeAt = 0;

////////////



class Symbol {
private:
    string name;
    int dim;
    int dim1 = 0;
    int dim2 = 0;
    int address = 0;
    bool isConst = false;
    bool isGlobal = false;
public:
    Symbol(string name, int dim) : name(name), dim(dim) {}

    bool operator==(const Symbol& sym) {
        return this->name == sym.name;
    }

    virtual void show_value() {}

    // 이하 getter, setter 함수는 자바 코드와 유사하게 변환하였습니다.

    int getAddress() {
        return address;
    }

    void setAddress(int address) {
        this->address = address;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    int getDim() {
        return dim;
    }

    void setDim(int dim) {
        this->dim = dim;
    }

    int getDim1() {
        return dim1;
    }

    void setDim1(int dim1) {
        this->dim1 = dim1;
    }

    int getDim2() {
        return dim2;
    }

    void setDim2(int dim2) {
        this->dim2 = dim2;
    }

	//c++은 오버라이드 안되니까 isConst->getIsConst로 바꾼다
    bool getIsConst() {
        return isConst;
    }

    void setConst(bool aConst) {
        isConst = aConst;
    }
	//오버라이드 되니까 isGlobal -> getIsGlobal로 바꾼다
    bool getIsGlobal() {
        return isGlobal;
    }

    void setGlobal(bool global) {
        isGlobal = global;
    }

    virtual string getType() {
        return "";
    }
};

class Block {
private:
    string type;
    vector<Block*> CBlock;
    Block* FBlock;
    vector<Symbol*> SymbolTable;
    int level;
    bool returnTk;
public:
    Block(string type, Block* FBlock, int level)
        : type(type), FBlock(FBlock), level(level), returnTk(false) {}
    
    void addCBlock(Block* block) {
        this->CBlock.push_back(block);
    }

    bool addSymbol(Symbol* symbol) {
        if(find(SymbolTable.begin(), SymbolTable.end(), symbol) == SymbolTable.end()){
            SymbolTable.push_back(symbol);
            return true;
        }else {
            return false;
        }
    }

    bool containSymbol(Symbol* symbol) {
        return find(SymbolTable.begin(), SymbolTable.end(), symbol) != SymbolTable.end();
    }

    Symbol* search(string str) {
        Block* searchBlock = this;
        Symbol* target = nullptr;
        bool found = false;
        while(searchBlock != nullptr && !found){
            for (Symbol* symbol : searchBlock->getSymbolTable()) {
                if (symbol->getName() == str) {
                    found = true;
                    target = symbol;
                    break;
                }
            }
            searchBlock = searchBlock->getFBlock();
        }
        return target;
    }

    // 이하 getter, setter 및 show 함수는 자바 코드와 유사하게 변환하였습니다.

    vector<Block*> getCBlock() {
        return CBlock;
    }

    Block* getFBlock() {
        return FBlock;
    }

    vector<Symbol*> getSymbolTable() {
        return SymbolTable;
    }

    bool isReturnTk() {
        return returnTk;
    }

    int getLevel() {
        return level;
    }

    string getType() {
        return type;
    }

    void setBlockItems(vector<Symbol*> blockItems) {
        this->SymbolTable = blockItems;
    }

    void setFBlock(Block* FBlock) {
        this->FBlock = FBlock;
    }

    void setLevel(int level) {
        this->level = level;
    }

    void setReturnTk(bool returnTk) {
        this->returnTk = returnTk;
    }

    void setType(string type) {
        this->type = type;
    }

    /* void show() {
        cout << "------------------" << type << "----------------------\n";
        cout << "level: " << level << "\n";
        for (Symbol* symbol : SymbolTable) {
            cout << symbol->getName() << "   dim: " << symbol->getDim() << "   dim1: " << symbol->getDim1()
                      << "   dim2: " << symbol->getDim2() << "  type: " << symbol->getType()
                      << "  address: " << symbol->getAddress() << "  global: " << symbol->isGlobal() << "\n";
            if (symbol->isConst()) {
                symbol->show_value();
            } else if(symbol->getName() == "func"){
                dynamic_cast<Func_symbol*>(symbol)->show();
            }
        }
        for (Block* cblock : CBlock) {
            cblock->show();
        }
    } */
};

class Param_symbol : public Symbol {
private:
    string type = "param";
public:
    Param_symbol(string name, int dim) : Symbol(name, dim) {}

    bool operator==(const Param_symbol& sym) {
        return Symbol::operator==(sym);
    }

    string getType() {
        return type;
    }

    void setType(string type) {
        this->type = type;
    }
};
class Var_symbol : public Symbol {
private:
    string type = "var";
public:
    Var_symbol(string name, int dim) : Symbol(name, dim) {}

    bool operator==(const Var_symbol& sym) {
        return Symbol::operator==(sym);
    }

    string getType() {
        return type;
    }

    void setType(string type) {
        this->type = type;
    }
};

class Func_symbol : public Symbol {
private:
    string type = "func";
    vector<Param_symbol*> params;
    int startCode;
public:
    Func_symbol(string name, int dim) : Symbol(name, dim) {}

    void addParam(Param_symbol* param_symbol) {
        this->params.push_back(param_symbol);
    }

    bool operator==(const Func_symbol& sym) {
        return Symbol::operator==(sym);
    }

    void show() {
        for (Param_symbol* param : params) {
            cout << "param: " << param->getName() << "\n";
        }
    }

    string getType() {
        return type;
    }

    void setType(string type) {
        this->type = type;
    }

    int getStartCode() {
        return startCode;
    }

    vector<Param_symbol*> getParams() {
        return params;
    }

    void setParams(vector<Param_symbol*> params) {
        this->params = params;
    }

    void setStartCode(int startCode) {
        this->startCode = startCode;
    }
};

int level = 1;
Block *curBlock = new Block("global", NULL, level);
Func_symbol *cur_func_symbol = NULL;
int address = 0;
bool isMainFunc = false;
/////////////////

void insertWordList(string label, string idenfr)
{
	wordList[top].label = label;
	wordList[top].idenfr = idenfr;
	wordList[top++].lineId = global_line;
}

void init()
{
    char inputString[500];
    inputFile = fopen("testfile.txt", "r");
	int line = 0;
	while (fgets(inputString, sizeof(inputString), inputFile) != NULL)
	{
		line++;
		string line_string=to_string(line);
		inputedString += "@!";
		inputedString += line_string;
		inputedString += inputString;
	}
    inputedStringLength = inputedString.length();
}

bool parsingAnnotation() {
	string temp = inputedString.substr(wordCnt, 1);
	if(temp=="\n"||temp=="\r"||temp=="\t")
		return true;
	return false;
}

void parseLineNumber(){
	if (inputedString[wordCnt] == '@' && inputedString[wordCnt + 1] == '!')
	{
		inputedString = inputedString.erase(wordCnt, 2);
		inputedStringLength -= 2;
		string temp = "";
		while (isdigit(inputedString[wordCnt]))
		{
			temp+=inputedString[wordCnt++];
		}
		wordCnt -= temp.length();
		inputedString = inputedString.erase(wordCnt, temp.length());
		inputedStringLength -= temp.length();
		global_line = stoi(temp);
	}
}

void skip() {
	parseLineNumber();
	while (inputedString[wordCnt] == ' ' || parsingAnnotation())
	{
		wordCnt++;
	}
}

void removeLineComment(){
	while(1)
	{
		string temp = inputedString.substr(wordCnt, 1);
		if(temp=="\n"||temp=="\r")
			break;
		wordCnt++;
	}
}
void removeBlockComment(){
	while(wordCnt<inputedStringLength)
	{
		if(inputedString[wordCnt]=='*'&&inputedString[wordCnt+1]=='/')
			break;
		wordCnt++;
	}
	if(wordCnt+2>=inputedStringLength)
		return;
	wordCnt += 2;
}

// 英语的部分
bool checkReserver() {
	if (token=="main")
		insertWordList("MAINTK", "main");
	else if (token == "const")
		insertWordList("CONSTTK", "const");
	else if (token == "int")
		insertWordList("INTTK", "int");
	else if (token == "break")
		insertWordList("BREAKTK", "break");
	else if (token == "continue")
		insertWordList("CONTINUETK", "continue");
	else if (token == "if")
		insertWordList("IFTK", "if");
	else if (token == "else")
		insertWordList("ELSETK", "else");
	else if (token == "for")
		insertWordList("FORTK", "for");
	else if (token == "getint")
		insertWordList("GETINTTK", "getint");
	else if (token == "printf")
		insertWordList("PRINTFTK", "printf");
	else if (token == "return")
		insertWordList("RETURNTK", "return");
	else if (token == "void")
		insertWordList("VOIDTK", "void");
	else
		return false;
	return true;
}

void Lexical_Analysis_Main() {
	skip();
	token = "";
	if (isalpha(inputedString[wordCnt])||inputedString[wordCnt]=='_') {
		while(isalpha(inputedString[wordCnt]) || isdigit(inputedString[wordCnt])|| inputedString[wordCnt]=='_') 
		{
			token += inputedString[wordCnt];
			wordCnt++;
		}
		if (!checkReserver()) {
			insertWordList("IDENFR", token);
		}
	}
     // if test has float
        /* bool isFloat = false;
        while(isdigit(inputedString[wordCnt])||inputedString[wordCnt]=='.') {
            if(inputedString[wordCnt]=='.')
                isFloat = true;
            token += inputedString[wordCnt];
            wordCnt++;
		}
        if(isFloat)
        {
            mapList[top][0] = "Float";
            mapList[top++][1] = token;
        }
        else{
            mapList[top][0] = "INTCON";
            mapList[top++][1] = token;
        } */
	else if (isdigit(inputedString[wordCnt]))
	{
		while(isdigit(inputedString[wordCnt])) {
			token += inputedString[wordCnt];
			wordCnt++;
		}
		insertWordList("INTCON", token);
	}
	else if (inputedString[wordCnt] == '+'){
		insertWordList("PLUS", "+");
		wordCnt++;
	}
	else if (inputedString[wordCnt] == '-')
	{
		insertWordList("MINU", "-");
		wordCnt++;
	}
	else if (inputedString[wordCnt] == '*')
	{
		insertWordList("MULT", "*");
		wordCnt++;
	}
	else if (inputedString[wordCnt] == '/')
	{
		if(inputedString[wordCnt+1]=='/'){
			removeLineComment();
		}
		else if(inputedString[wordCnt+1]=='*')
		{
			removeBlockComment();
		}
		else{
			insertWordList("DIV", "/");
			wordCnt++;
		}
	}
	else if (inputedString[wordCnt] == '%')
	{
		insertWordList("MOD", "%");
		wordCnt++;
	}
	else if (inputedString[wordCnt] == '<')
	{
		if(inputedString[wordCnt+1]=='=')
		{
			wordCnt++;
			insertWordList("LEQ", "<=");
		}
		else
		{
			insertWordList("LSS", "<");
		}
		wordCnt++;
	}
	else if (inputedString[wordCnt] =='>')
	{
		if(inputedString[wordCnt+1]=='=')
		{
			insertWordList("GEQ", ">=");
			wordCnt++;
		}
		else
		{
			insertWordList("GRE", ">");
		}
		wordCnt++;
	}else if (inputedString[wordCnt] =='=')
	{
		if(inputedString[wordCnt+1]=='=')
		{
			insertWordList("EQL", "==");
			wordCnt++;
		}
		else
		{
			insertWordList("ASSIGN", "=");
		}
		wordCnt++;
	}else if (inputedString[wordCnt] =='!')
	{
		if(inputedString[wordCnt+1]=='=')
		{
			insertWordList("NEQ", "!=");
			wordCnt++;
		}
		else
		{
			insertWordList("NOT", "!");
		}
		wordCnt++;
	}else if (inputedString[wordCnt]=='(') {
		insertWordList("LPARENT", "(");;
		wordCnt++;
	}else if (inputedString[wordCnt]==')') {
		insertWordList("RPARENT", ")");
		wordCnt++;
	}else if (inputedString[wordCnt]==',') {
		insertWordList("COMMA", ",");
		wordCnt++;
	}else if (inputedString[wordCnt]==';') {
		insertWordList("SEMICN", ";");
		wordCnt++;
	}else if (inputedString[wordCnt]=='[') {
		insertWordList("LBRACK", "[");
		wordCnt++;
	}else if (inputedString[wordCnt]==']') {
		insertWordList("RBRACK", "]");
		wordCnt++;
	}else if (inputedString[wordCnt]=='{') {
		insertWordList("LBRACE", "{");
		wordCnt++;
	}else if (inputedString[wordCnt]=='}') {
		insertWordList("RBRACE", "}");
		wordCnt++;
	}else if(inputedString[wordCnt]=='&'&&inputedString[wordCnt+1]=='&'){
		insertWordList("AND", "&&");
		wordCnt+=2;
	}else if(inputedString[wordCnt]=='|'&&inputedString[wordCnt+1]=='|'){
		insertWordList("OR", "||");
		wordCnt+=2;
	}else if(inputedString[wordCnt]=='\"'){
		token += inputedString[wordCnt++];
		bool isAlreadyError = false;
		while (inputedString[wordCnt] != '\"')
		{
			char ch = inputedString[wordCnt];
			parseErrorA(ch, isAlreadyError);
			token += inputedString[wordCnt];
			wordCnt++;
		}
		token += inputedString[wordCnt++];
		insertWordList("STRCON", token);
	}
}

void Lexical_Analysis()
{
	while (wordCnt != inputedStringLength)
		Lexical_Analysis_Main();

	// Lexical부분 출력
	/* for (int i = 0; i < top;i++)
	{
		fout << wordList[i].label << " " << wordList[i].idenfr << endl;
		cout << wordList[i].label << " " << wordList[i].idenfr << " " << wordList[i].lineId << endl;
	} */
}

void outputSyntax_Analysis(string input)
{
	cout << "<" << input << ">" << endl;
	fout << "<" << input << ">" << endl;
}

int Syntax_Analysis_Main(bool forward, bool withOutput = false)
{
	if (forward)
	{
		//출력 하고 앞으로 가기
		if (withOutput && wordNow.label != "" && wordNow.idenfr != "")
		{
			cout << wordNow.label << " " << wordNow.idenfr << endl;
			fout << wordNow.label << " " << wordNow.idenfr << endl;
		}
		//끝까지 갔을때 끝내기
		if (wordCnt >= top)
		{
			wordNow.label = wordNow.idenfr = "";
			return 0;
		}
		//한칸 앞으로 가기
		else
		{
			wordNow = wordList[wordCnt];
			wordCnt++;
			return 1;
		}
	}
	else
	{
		wordNow = wordList[wordCnt - 2];
		wordCnt--;
		return 1;
	}
}

int primaryExp(int type){
	// 1. (EXP)
	if(wordNow.idenfr=="(")
	{
		Syntax_Analysis_Main(true, true); //'('출력
		parseExp(); //EXP로 돌아가기
		Syntax_Analysis_Main(true, true); //') 출력
	}
	else
	{
		// 2. number
		if(wordNow.idenfr[0]>='0'&&wordNow.idenfr[0]<='9')
		{
			//11
			Code code1("LDC", stoi(wordNow.idenfr));
			codeList.push_back(code1);
			Syntax_Analysis_Main(true, true);
			outputSyntax_Analysis("Number");
		}
		// 3. LVal
		else 
		{
			type=parseLVal(type);
			//11
			// if(need_loads)??
			Code code1("LODS");
			codeList.push_back(code1);
		}
	}
	outputSyntax_Analysis("PrimaryExp");

	return type;
}

void unaryOP(){
	Syntax_Analysis_Main(true, true); //부호 출력
	outputSyntax_Analysis("UnaryOp");
}

int unaryExp(int type){
	Syntax_Analysis_Main(true, false);
	string temp = wordNow.idenfr;
	Syntax_Analysis_Main(false, false);
	string op;

	if (wordNow.label == "PLUS" || wordNow.label == "MINU" || wordNow.label == "NOT")
	{
		op = wordNow.label;
		unaryOP();
		type = unaryExp(type);

		//22
		if(op=="MINU")
		{
			Code code1("MINU");
			codeList.push_back(code1);
		}
	}
	else if(wordNow.label=="IDENFR"&&temp=="(")
	{
		//  Ident '(' [FuncParams] ');
		//error handeler
		lastNonTerminalLine = wordNow.lineId;
		parseErrorC(wordNow.idenfr, wordNow.lineId); // error c

		FuncInfo funcInfo = getFuncInfo(wordNow.idenfr);
		Syntax_Analysis_Main(true, true); // Ident(함수명) 출력
		Syntax_Analysis_Main(true, true); // ( 출력

		//지금 보고있는 줄에 인자가 있다는 뜻이다.
		if(wordNow.idenfr != ")" && wordNow.idenfr != ";")
		{
			//지금 보고있는 줄에 인자가 있는데, 부르는 함수에는 인자가 없으면, d에러
			if(funcInfo.paramNum==0)
			{
				error(wordNow.lineId, "d");
				parseFuncRParamsWithoutError();
			}
			else{
				type = funcInfo.type;
				parseFuncRParams(funcInfo);
			}
		}
        //원래 함수에는 인자가 있는데 지금은 )인 경우
        else if (funcInfo.paramNum > 0 && wordNow.idenfr == ")")
            error(wordNow.lineId, "d");
		// ()가 잘 닫히는지 확인하는 오류. 함수에서 )까지 출력한다.
		parseErrorJ();
	}
	else    type=primaryExp(type);
	
	outputSyntax_Analysis("UnaryExp");
	return type;
}

int mulExp(int type){
	type = unaryExp(type);
	
	outputSyntax_Analysis("MulExp");
	if (wordNow.label == "MULT" || wordNow.label == "DIV" || wordNow.label == "MOD")
	{
		string op = wordNow.label;
		Syntax_Analysis_Main(true, true);
		type=mulExp(type);
		if(op=="MULT")
		{
			Code code1("MUL");
			codeList.push_back(code1);
		}
		else if(op=="DIV")
		{
			Code code1("DIV");
			codeList.push_back(code1);
		}
		else if(op=="MOD")
		{
			Code code1("MOD");
			codeList.push_back(code1);
		}
	}
	return type;
}

int addExp(int type){
	type=mulExp(type);
	
	outputSyntax_Analysis("AddExp");
	if (wordNow.label == "PLUS" || wordNow.label == "MINU")
	{
		string op = wordNow.label;
		Syntax_Analysis_Main(true, true);
		type=addExp(type);
		if(op=="PLUS")
		{
			Code code1("ADD");
			codeList.push_back(code1);
		}
		else if(op=="MINU")
		{
			Code code1("SUB");
			codeList.push_back(code1);
		}
	}
	return type;
}

int parseExp(){
	int type = INT;
	type=addExp(type);

	outputSyntax_Analysis("Exp");
	return type;
}

void parseConstExp(){
	addExp(-1);

	outputSyntax_Analysis("ConstExp");
}

// < > <= >=
void parseRelExp()
{
	addExp(-1);

	outputSyntax_Analysis("RelExp");
	if (wordNow.idenfr == "<" || wordNow.idenfr == "<=" || wordNow.idenfr == ">" || wordNow.idenfr == ">=")
	{
		Syntax_Analysis_Main(true, true); // < > <= >=
		parseRelExp();
	}
}

void parseEqExp()
{
	parseRelExp();
	outputSyntax_Analysis("EqExp");
	if (wordNow.idenfr == "!=" || wordNow.idenfr == "==")
	{
		Syntax_Analysis_Main(true, true); // == !=
		parseEqExp();
	}
}

void parseLAndExp()
{
	parseEqExp();

	outputSyntax_Analysis("LAndExp");
	if (wordNow.label == "AND")
	{
		Syntax_Analysis_Main(true, true); // &&
		parseLAndExp();
	}
}

void parseLOrExp()
{
	parseLAndExp();

	outputSyntax_Analysis("LOrExp");
	if (wordNow.label == "OR")
	{
		Syntax_Analysis_Main(true, true); // ||
		parseLOrExp();
	}
}

void parseCond(){
	parseLOrExp();
	
	outputSyntax_Analysis("Cond");
}

void parseIf()
{
	lastNonTerminalLine = wordNow.lineId;
	Syntax_Analysis_Main(true, true); //if
	Syntax_Analysis_Main(true, true); //(
	parseCond();
	//if하고 {가 같은 줄에 있으면 이거, 다음 줄에 있으면 -1을 해야함.
	// ()가 잘 닫히는지 확인하는 오류. 함수에서 )까지 출력한다.
	parseErrorJ();
	parseStmt();
	if(wordNow.label=="ELSETK")
	{
		
		Syntax_Analysis_Main(true, true); //else
		parseStmt();
	}
}

void parseForStmt()
{
	parseErrorH(wordNow.idenfr, wordNow.lineId); 
	parseLVal(-1);
	Syntax_Analysis_Main(true, true); // =
	parseExp();

	outputSyntax_Analysis("ForStmt");
}

void parseFor()
{
	Syntax_Analysis_Main(true, true); // for
	Syntax_Analysis_Main(true, true); // (
	if (wordNow.idenfr != ";")
	{
		parseForStmt();
	}
	Syntax_Analysis_Main(true, true); //;
	if (wordNow.idenfr != ";")
	{
		parseCond();
	}
	Syntax_Analysis_Main(true, true); // ;
	if(wordNow.idenfr!=")")
	{
		parseForStmt();
	}
	
	// ()가 잘 닫히는지 확인하는 오류. 함수에서 )까지 출력한다.
	parseErrorJ();

	int numOfBlocks = 0;
	int temp = wordCnt-1;
	while (wordList[temp++].idenfr == "{")
		numOfBlocks++;

	isCirculer[levelNow + numOfBlocks] = true;
	parseStmt();
}

void parseReadStmt()
{
	Syntax_Analysis_Main(true, true); //getint
	Syntax_Analysis_Main(true, true); //(
	Syntax_Analysis_Main(true, true); //)
}

void parseReturnStmt()
{
	//22
	Code *code1 = new Code("LDA", 0, 0);
	codeList.push_back(code1);

	isReturnCalled = true;
	Syntax_Analysis_Main(true, true); // return 출력

	// 함수가 반환값이 있다면
	if (wordNow.idenfr != ";")
	{
		if(currentFunctionType==VOID)
			error(wordNow.lineId, "f");
		parseExp();
	}
	//22
	Code *code2 = new Code("STOS");
	codeList.push_back(code2);
	Code *code3 = NULL;
	if(isMainFunc)
		code3 = new Code("RET_TO_END");
	else
		code3 = new Code("RET");
	codeList.push_back(code3);

	//없으면 종료
}

int countFormatSpecifier(string& s) {
    int count = 0;
    size_t pos = 0;

    while ((pos = s.find("%d", pos)) != string::npos) {
        count++;
        pos += 2; // "%d" 길이만큼 건너뜁니다.
    }

    return count;
}

void parsePrint()
{
	Syntax_Analysis_Main(true, true); //printf
	Syntax_Analysis_Main(true, true); //'('
	int numOfOutput = countFormatSpecifier(wordNow.idenfr);
	int checkCount = 0;
	string strcon = wordNow.idenfr;
	Syntax_Analysis_Main(true, true); // formatString

	while(wordNow.label == "COMMA") // ,라면
	{
		checkCount++;
		Syntax_Analysis_Main(true, true); //,출력
		parseExp();
	}
	if(checkCount!=numOfOutput)
	{
		error(wordNow.lineId, "l");
	}
	Code code1("PRF", strcon);
	codeList.push_back(code1);
}

int parseLVal(int type)
{
	//error handeler getType은 선언됐던 타입이 나옴. 
	int getType = parseErrorC(wordNow.idenfr, wordNow.lineId);
	if(getType!=-1)
		type = getType;
	
	//22
	string lval_name = wordNow.idenfr;
	Symbol *symbol = curBlock->search(lval_name);

	int arrNum = 0;
	Syntax_Analysis_Main(true, true); // IDent 출력;
	while(wordNow.idenfr=="[")
	{
		arrNum++;

		Syntax_Analysis_Main(true, true); //[ 출력
		parseExp();

		// k error : ]가 있는지 없는지 확인후 있으면 ] 출력
		parseErrorK();
	}
	//func(a)같은 본인만 있는 상황 타입은 변하지 않는다.
	if(arrNum==0)
	{} 
	// int a[]; func(a[])	, int a[][]; func(a[][])인 상황. 타입은 int가 된다.
	else if ((arrNum == 1 && getType == ARR1) || (arrNum==2 && getType==ARR2))
		type = INT;
	// 나머지 상황. int a[2][2]; func(a[2])같은 상황. 그럼 arrNum대로 정해진다
	else {
		if (arrNum == 1 && type==ARR2)
			type = ARR1;
		//만약 3차원 배열이 나오면, 그대로 type=arrNum의 갯수대로 간다.
	}
	//여기 보완해야할거 씹많음
	int isGlobal = symbol->getIsGlobal() ? 1 : 0;
	Code code1("LDA", isGlobal, symbol->getAddress());
	codeList.push_back(code1);
	outputSyntax_Analysis("LVal");
	return type;
}

void parseStmt()
{
	if (wordNow.label== "IFTK")
	{
		parseIf();
	}
	else if (wordNow.label == "FORTK")
	{
		lastNonTerminalLine = wordNow.lineId;
		parseFor();
	}
	else if (wordNow.label== "BREAKTK" ||wordNow.label == "CONTINUETK")
	{
		lastNonTerminalLine = wordNow.lineId;

		if(!isCirculer[levelNow])
			error(wordNow.lineId, "m");

		Syntax_Analysis_Main(true, true);

		//;가 없는지 확인하는 에러. 있으면 ;까지 출력
		parseErrorI();
	}
	else if (wordNow.idenfr== ";")
	{
		Syntax_Analysis_Main(true, true); // ; 출력
	}
	else if (wordNow.label == "RETURNTK")
	{
		lastNonTerminalLine = wordNow.lineId;
		parseReturnStmt();

		//;가 없는지 확인하는 에러. 있으면 ;까지 출력
		parseErrorI();
	}
	else if (wordNow.label== "PRINTFTK")
	{
		lastNonTerminalLine = wordNow.lineId;
		parsePrint();

		// ()가 잘 닫히는지 확인하는 오류. 함수에서 )까지 출력한다.
		parseErrorJ();
		//;가 없는지 확인하는 에러. 있으면 ;까지 출력
		parseErrorI();
	}
	//block
	else if(wordNow.idenfr=="{")
	{
		//22
		Block *block = new Block("block", curBlock, curBlock->getLevel() + 1);
		block->setFBlock(curBlock);
		curBlock->addCBlock(block);
		curBlock = block;

		parseBlock(false);

		//22
		curBlock = curBlock->getFBlock();
	}
	// 1. stmt -> LVal = Exp;
	// 2. stmt -> LVal = getint();
	// 3 exp; 
	else
	{
		//Judge  LVel
		int index = 0;
		int isLVal = false;
		while (true)
		{
			if(wordNow.label=="SEMICN")
				break;
			if(wordNow.idenfr == "=")
			{
				isLVal = true;
				break;
			}
			index++;

			//오류나면 끝내기
			if (!Syntax_Analysis_Main(true, false)) break;
		}
		//go back for LVal index
		while(index)
		{
			Syntax_Analysis_Main(false, false);
			index--;
		}

		if(isLVal)
		{
			parseErrorH(wordNow.idenfr, wordNow.lineId); 
			parseLVal(-1); // Ident 출력
			Syntax_Analysis_Main(true, true); // =
			// 2. stmt -> LVal = getint();
			if (wordNow.label == "GETINTTK")
			{
				//22
				Code *code1 = new Code("GET");
				codeList.push_back(code1);

				lastNonTerminalLine = wordNow.lineId;
				Syntax_Analysis_Main(true, true); //getint
				Syntax_Analysis_Main(true, true); //(
				
				// ()가 잘 닫히는지 확인하는 오류. 함수에서 )까지 출력한다.
				parseErrorJ();
				
				//;가 없는지 확인하는 에러. 있으면 ;까지 출력
				parseErrorI();
			}
			// 1. stmt -> LVal = Exp;
			else
			{
				lastNonTerminalLine = wordNow.lineId;
				parseExp(); //exp출력}

				//;가 없는지 확인하는 에러. 있으면 ;까지 출력
				parseErrorI();
			}
			//2
			Code *code2 = new Code("STOS");
			codeList.push(code2);
		}
		// 3 바로 Exp
		else
		{
			lastNonTerminalLine = wordNow.lineId;
			parseExp(); //exp출력}

			//;가 없는지 확인하는 에러. 있으면 ;까지 출력
			parseErrorI();
		}
	}
	
	outputSyntax_Analysis("Stmt");
}

void parseConstInitVal()
{
	// 11
	/* code[codeAt++] = {"INT", 0, 1, "", "", 0};
	code[codeAt++] = {"LDA", 0, address, "", "", 0};
	address++;
	code[codeAt++] = {"LDC", 0, 1, "", "", 0};
	code[codeAt++] = {"STOS", 0, 0, "", "", 0}; */

	lastNonTerminalLine = wordNow.lineId;
	if (wordNow.idenfr == "{")
	{
		Syntax_Analysis_Main(true, true);
		if(wordNow.idenfr!="}")
		{
			parseConstInitVal();
			while(wordNow.idenfr==",")
			{
				Syntax_Analysis_Main(true, true);
				parseConstInitVal();
			}
		}
		Syntax_Analysis_Main(true, true);
	}
	else
	{
		parseConstExp();
	}
	
	outputSyntax_Analysis("ConstInitVal");
}

void parseConstDef()
{
	//error handeler
	int type = INT;
	if (!parseErrorB(wordNow.idenfr, wordNow.lineId)) // 변수명 확인
	{
		symbolTable[++symbolTableTop] = Symbol22{ wordNow.idenfr, CONST, type, levelNow };
	}
	Syntax_Analysis_Main(true, true); //c 출력
	int numOfArrLayer = 0;
	while (wordNow.idenfr == "[") // [ (배열)이면
	{
		numOfArrLayer++;
		Syntax_Analysis_Main(true, true); // [
		parseConstExp(); //숫자

		// k error : ]가 있는지 없는지 확인후 있으면 ] 출력
		parseErrorK();
	}
	if(numOfArrLayer==1)
		symbolTable[symbolTableTop].type = ARR1;
	else if(numOfArrLayer==2)
		symbolTable[symbolTableTop].type = ARR2;

	Syntax_Analysis_Main(true, true); // = 출력
	parseConstInitVal();
		
	outputSyntax_Analysis("ConstDef");
}

void parseConstDecl()
{
    
	Syntax_Analysis_Main(true, true); //CONST 출력
	Syntax_Analysis_Main(true, true); //int 출력

	parseConstDef();
	while(wordNow.idenfr==",")// ; 가 나오는동안
	{
		if (!Syntax_Analysis_Main(true, true)) break; // 일단 , 출력하고 틀리면 끝내기
		if (wordNow.label== "SEMICN") break;

		parseConstDef();
	}

	//;가 없는지 확인하는 에러. 있으면 ;까지 출력
	parseErrorI();

	outputSyntax_Analysis("ConstDecl");
}

void parseInitVal()
{
    if(wordNow.idenfr=="{")
    {
        Syntax_Analysis_Main(true, true); // {
        if(wordNow.idenfr!="}")
        {
            parseInitVal();
            while(wordNow.idenfr==",")
            {
                Syntax_Analysis_Main(true, true); // ,
                parseInitVal();
            }
        }
        Syntax_Analysis_Main(true, true); // }
    }
    else
    {
		//11
		Code code1("INT", 1);
		Code code2("LDA", 0, address);
		codeList.push_back(code1);
		codeList.push_back(code2);
		address++;
		parseExp();
		Code code3("STOS");
		codeList.push_back(code3);
	}

	outputSyntax_Analysis("InitVal");
}

void parseVarDef()
{
	Var_symbol* var_symbol = new Var_symbol("", 0);
	curBlock->addSymbol(var_symbol);
	var_symbol->setName(wordNow.idenfr);
	// error handeler
	int type = INT;
	if (!parseErrorB(wordNow.idenfr, wordNow.lineId)) // 변수명 확인
	{
		symbolTable[++symbolTableTop] = Symbol22{ wordNow.idenfr, VAR, type, levelNow};
	}
	Syntax_Analysis_Main(true, true); //c 출력
	int numOfArrLayer = 0;
	while (wordNow.idenfr == "[") // [ (배열)이면
	{
		numOfArrLayer++;
		Syntax_Analysis_Main(true, true); // [
		parseConstExp(); //숫자
		
		// k error : ]가 있는지 없는지 확인후 있으면 ] 출력
		parseErrorK();
	}
	// 2
	var_symbol->setAddress(address);

	if (numOfArrLayer == 1)
		symbolTable[symbolTableTop].type = ARR1;
	else if(numOfArrLayer==2)
		symbolTable[symbolTableTop].type = ARR2;


	if (wordNow.idenfr== "=") // = 즉 초기화가 있으면
	{
	    Syntax_Analysis_Main(true, true); // = 출력
		parseInitVal();
	}

	outputSyntax_Analysis("VarDef");
}

void parseVarDecl()
{
	lastNonTerminalLine = wordNow.lineId;
	Syntax_Analysis_Main(true, true); //int 출력

	parseVarDef();
	while(wordNow.idenfr==",")// ; 가 나오는동안
	{
		if (!Syntax_Analysis_Main(true, true)) break; // 일단 , 출력하고 틀리면 끝내기
		if (wordNow.label== "SEMICN") break;

		parseVarDef();
	}


	//;가 없는지 확인하는 에러. 있으면 ;까지 출력
	parseErrorI();

	outputSyntax_Analysis("VarDecl");
}
void parseDecl(){
	if(wordNow.label=="INTTK")
		parseVarDecl();
	else if(wordNow.label=="CONSTTK")
		parseConstDecl();
}

// Block → '{' { BlockItem } '}'   
void parseBlock(bool isNeedReturn)
{
	//함수에서 호출된 levelUp은 그전에 처리했다.
	if(!isCameFromParam)
		levelUp();
	isCameFromParam = false;

	Syntax_Analysis_Main(true, true); // {
	while(wordNow.idenfr!="}")
	{
		//if Decl
		if (wordNow.label == "INTTK" ||wordNow.label == "CONSTTK")
		{
			parseDecl();
		}
		//if Stmt
		else{
			parseStmt();
		}
	}

	//int 함수인데 && 반환값이 없다면 && 메인함수, 일반 함수에서 불린 return은 true, stmt에서 불린 block은 없다.
	if(currentFunctionType == INT && !isReturnCalled && isNeedReturn)
	{
		error(wordNow.lineId, "g");
	}
	isReturnCalled = false;
	isCirculer[levelNow] = false;

	Syntax_Analysis_Main(true, true); // }
	levelDown();

	outputSyntax_Analysis("Block");
}

void parseFuncRParamsWithoutError()
{
	parseExp();
	while (wordNow.idenfr == ",") // , 가 나오는동안
	{
		if (!Syntax_Analysis_Main(true, true)) break; // 일단 , 출력하고 틀리면 끝내기

		parseExp();
	}
	fout << "<FuncRParams>" << endl; 
	cout << "<FuncRParams>" << endl;
}

/** parseErrorE */
void parseFuncRParams(FuncInfo funcInfo)
{
	//함수와 대조하는 것이 아닌, 함수 다음에 있는 인자와 비교하기 때문에 +1이 된다.
	int cnt = 1;
	int type = parseExp();
	//type은 지금보고있는 줄의 함수가 호출될때의 타입, symboltable[]부분이 함수의 타입
	if (type != symbolTable[cnt + funcInfo.pos].type) 
		error(wordNow.lineId, "e");

	int numOfParam = 1;
	while (wordNow.idenfr == ",") // , 가 나오는동안
	{
		cnt++;
		if (!Syntax_Analysis_Main(true, true))
			break; // 일단 , 출력하고 틀리면 끝내기
		numOfParam++;
		type = parseExp();
		if (type != symbolTable[cnt + funcInfo.pos].type) 
			error(wordNow.lineId, "e");
	} 
	if(funcInfo.paramNum!=numOfParam)
		error(wordNow.lineId, "d");

	outputSyntax_Analysis("FuncRParams");
}

void parseFuncFParam()
{
	Syntax_Analysis_Main(true, true); //int

	//error handeler
	int type = INT;
	if (!parseErrorB(wordNow.idenfr, wordNow.lineId)) // 변수명 확인
	{
		symbolTable[++symbolTableTop] = Symbol22{ wordNow.idenfr, PARAM, type, levelNow};
	}
	Syntax_Analysis_Main(true, true); //ident
	int numOfArrLayer = 0;
	if (wordNow.idenfr == "[") // [ 라면, 즉 배열이라면
	{
		numOfArrLayer++;
		Syntax_Analysis_Main(true, true); // 배열 [

		// k error : ]가 있는지 없는지 확인후 있으면 ] 출력
		parseErrorK();

        //2 혹은 3,4,5,6...
		while(wordNow.idenfr=="[") // [
		{
			numOfArrLayer++;
			Syntax_Analysis_Main(true, true); // [
			parseConstExp();

			// k error : ]가 있는지 없는지 확인후 있으면 ] 출력
			parseErrorK();
		}
	}
	if(numOfArrLayer==1)
		symbolTable[symbolTableTop].type = ARR1;
	else if(numOfArrLayer==2)
		symbolTable[symbolTableTop].type = ARR2;

	outputSyntax_Analysis("FuncFParam");
}

void parseFuncFParams()
{
	parseFuncFParam();
	while(wordNow.label=="COMMA")// ; 가 나오는동안
	{
		if (!Syntax_Analysis_Main(true, true)) break; // 일단 , 출력하고 틀리면 끝내기

		parseFuncFParam();
	}
	outputSyntax_Analysis("FuncFParams");
}

// 나머지 함수일때 사용
void parseFuncDef()
{
	int type;
	if (wordNow.idenfr == "void")
		type = VOID;
	else if(wordNow.idenfr=="int")
		type = INT;

	Syntax_Analysis_Main(true, true); // void, int 구분할 필요가 없는게 return에서 차피 구분하게 만들어놓음
	
	outputSyntax_Analysis("FuncType");

	//error handeler
	if (!parseErrorB(wordNow.idenfr, wordNow.lineId)) // error b 함수명 중복 확인
	{
		symbolTable[++symbolTableTop] = Symbol22{ wordNow.idenfr, FUNC, type, levelNow };
	}
	Syntax_Analysis_Main(true, true); // Ident : 함수이름


	lastNonTerminalLine = wordNow.lineId;
	//여기서 레벨업해야지 인자가 한단계 높게 설정된다.
	levelUp();
    isCameFromParam = true;
    
    Syntax_Analysis_Main(true, true); // '('
    // 두번째는 )가 없을때 바로 {가 나올테니 그걸 노린 에러
    if(wordNow.label!="RPARENT" && wordNow.idenfr != "{")
		parseFuncFParams();
	
	// ()가 잘 닫히는지 확인하는 오류. 함수에서 )까지 출력한다.
	parseErrorJ();

	parseBlock(true);

	outputSyntax_Analysis("FuncDef");
}

//메인 함수일떄 사용
void parseMainFunc()
{
	//22
	Func_symbol *func_symbol = new Func_symbol("", 0);
	string type;
	string name;
	address = 0;
	func_symbol->setStartCode(codeList.size());
	func_symbol->setName("main");

	curBlock->addSymbol(func_symbol);
	Block* block1 = new Block("int", curBlock, curBlock->getLevel()+1);
	curBlock->addCBlock(block1);
	curBlock = block1;
	cur_func_symbol = func_symbol;

	// 11
	Label *label = new Label();
	Code code("INT_L", label);
	codeList.push_back(code);


	Syntax_Analysis_Main(true, true); // int
	Syntax_Analysis_Main(true, true); //main
	Syntax_Analysis_Main(true, true); // (

	lastNonTerminalLine = wordNow.lineId;
	// ()가 잘 닫히는지 확인하는 오류. 함수에서 )까지 출력한다.
	parseErrorJ();
	parseBlock(true);

	// 22
	label->setPoint(address);

	outputSyntax_Analysis("MainFuncDef");
}

void parseCompUnit()
{
	string temp1 = wordNow.label;
	Syntax_Analysis_Main(true, false);
	string isMain = wordNow.label;
	Syntax_Analysis_Main(true, false);
	string temp3 = wordNow.label;
	Syntax_Analysis_Main(false, false);
	Syntax_Analysis_Main(false, false);
	// 메인 함수라면
	if(temp1=="INTTK"&&isMain=="MAINTK")
	{
		//11
		Label label;
		Code code1("JTM", &label);
		codeList.push_back(code1);
		isMainFunc = true;

		currentFunctionType = INT;
		parseMainFunc();
		outputSyntax_Analysis("CompUnit");
		return;
	}
	// 함수라면
	else if((temp1=="VOIDTK"&&temp3=="LPARENT")||(temp1=="INTTK"&&temp3=="LPARENT"))
	{
		//11
		/* Label label;
		code[codeAt] = {"JTM", 0, 0, 0, label, 0}; */

		if(temp1=="VOIDTK")
			currentFunctionType = VOID;
		else if(temp1=="INTTK")
			currentFunctionType = INT;

		parseFuncDef();
		parseCompUnit();
	}
	// 전역 변수라면
	else
	{
		parseDecl();
		parseCompUnit();
	}
}

void Syntax_Analysis(){
	wordCnt = 0;
	if (Syntax_Analysis_Main(true, true))
	{
		parseCompUnit();
	}
}

string toLowerCase(string in)
{
	string out = "";
	for (int i = 0; i < in.length(); i++)
	{
		out += in[i] >= 'a' && in[i] <= 'z' ? in[i] : in[i] - ('A' - 'a');
	}
	return out;
}

// 만약 void f1(int x,int y,int z)가 있으면,
//funcInfo = { symbolTable에서 의 f1위치, 3개, void타입 } 이다.
FuncInfo getFuncInfo(string idenfr)
{
	FuncInfo funcInfo = { -1, -1, -1 };// [0]:func pos [1]:param num [2]:return type
	for (int i = symbolTableTop; i >= 0; i--)
	{
		if (toLowerCase(symbolTable[i].idenfr) == toLowerCase(idenfr) && symbolTable[i].kind == FUNC)
		{
			funcInfo.type = symbolTable[i].type;
			funcInfo.pos = i;
			int cnt = 0, ind = i + 1;
			int paramPoint[100];
			while (symbolTable[ind].kind == PARAM)
			{
				funcInfo.paramPos[cnt] = ind;
				ind++;
				cnt++;
			}
			funcInfo.paramNum = cnt;
		}
	}
	return funcInfo;
}

 
// 기본적으로 { 하나 감지될때마다 레벨업한다. main, 그냥함수, stmt에 있는 { 3가지 경우다. 나는 parseBlock에 넣었다.
void levelUp()
{
	levelNow++;
	blocks[blocksTop++] = symbolTableTop;
}

void levelDown()
{
	levelNow--;
}

int numOfErrors = 0;

/** ] 오류 */
void parseErrorK(){
	if(wordNow.idenfr!="]")
		error(wordNow.lineId, "k");
	else
		Syntax_Analysis_Main(true, true); // ]
}

/** ) 오류 */
void parseErrorJ(){
	if (wordNow.idenfr != ")")
	{
		error(lastNonTerminalLine, "j");
	}
	else
		Syntax_Analysis_Main(true, true); // ')'
}

/** ; 오류 */
void parseErrorI(){
	if (wordNow.idenfr != ";")
	{
		error(lastNonTerminalLine, "i");
	}
	else
		Syntax_Analysis_Main(true, true); // ; 출력
}

/** 상수 재선언 */
void parseErrorH(string idenfr, int lineID)
{
	for (int i = symbolTableTop; i >= 0; i--)
	{
		if (idenfr == symbolTable[i].idenfr)
		{
			if(symbolTable[i].kind==CONST)
			{
				error(lineID, "h");
			}
            else
                return;
        }
    }
}

/** 선언안된 변수 */
int parseErrorC(string idenfr, int lineID)
{
	for (int i = symbolTableTop; i >= 0; i--)
	{
		if (idenfr == symbolTable[i].idenfr)
		{
			return symbolTable[i].type;
		}
	}
	error(lineID, "c");
	return -1;
}

/** 변수 겹침 */
bool parseErrorB(string idenfr, int lineID)
{
    if(blocksTop==0)
    {
        for (int i = symbolTableTop; i >= 0; i--)
        {
            if (idenfr == symbolTable[i].idenfr && symbolTable[i].level == levelNow)
            {
                error(lineID, "b");
                return 1;
            }
        } 
    }
    else if (levelNow == 0)
    {
        for (int i = symbolTableTop; i >= 0; i--)
        {
            if (idenfr == symbolTable[i].idenfr && symbolTable[i].level == levelNow)
            {
                error(lineID, "b");
                return 1;
            }
        }
    }
    else
    {
        for (int i = symbolTableTop; i > blocks[blocksTop - 1]; i--)
        {
            if (idenfr == symbolTable[i].idenfr && symbolTable[i].level == levelNow)
            {
                error(lineID, "b");
                return 1;
            }
        }
    }
	return 0;
}

void parseErrorA(char ch, bool isAlreadyError)
{
	if(ch==37 && inputedString[wordCnt+1]!='d' && !isAlreadyError)
	{
		error(global_line, "a");
		isAlreadyError = true;
	}
	else if(ch=='\\' && inputedString[wordCnt+1]!='n' && !isAlreadyError){
		error(global_line, "a");
		isAlreadyError = true;
	}
	else if(ch!=32 && ch!=33 && ch != 37 && (ch < 40 || ch > 126) && !isAlreadyError)
	{
		error(global_line, "a");
		isAlreadyError = true;
	}
}

void error(int lineId,string errType)
{
	errorList[numOfErrors++] = {lineId, errType};
}

bool compareByLineId(const errorType& a, const errorType& b) {
    return a.lineId < b.lineId;
}

void outputError()
{
	sort(errorList, errorList + numOfErrors, compareByLineId);
	/* bool skipList[100] = {false};
	int skipNumber = 0;
	for (int i = 0; i < numOfErrors - 1; i++)
	{
		if(errorList[i].lineId==errorList[i+1].lineId)
			skipList[skipNumber++] = true;
	} */
	for (int i = 0; i < numOfErrors; i++)
	{
		/* if(skipList[i]==true)
			continue; */
		cout << errorList[i].lineId << " " << errorList[i].errType << endl;
		errorOut << errorList[i].lineId << " " << errorList[i].errType << endl;
	}
}

class Interpreter {
private:
	int dstack[10000] = {0};
	int BAddr = 0;
	int at = 0;
    int sp = -1;

public:
    vector<string> interpret() {
        int addr;
        vector<string> res;
        while (at < codeList.size()) {
            Code curCode = codeList[at];
			
            cout << curCode.getName() << "\n";
            cout << "code.getLevel() = " << curCode.getLevel() << "\n";
            cout << "code.getAddr() = " << curCode.getAddr() << "\n";
            cout << "code.getPrint() = " << curCode.getPrint() << "\n";
			if(curCode.getLabel()!=nullptr)
				cout << "code.getLabel() = "<< curCode.getLabel()->getPoint()<<endl;
			if (curCode.getName() == "INT")
			{
				sp += curCode.getAddr();
				at++;
			}
			else if (curCode.getName() == "DOWN")
			{
				sp -= curCode.getAddr();
				at++;
			}
			else if (curCode.getName() == "LOD")
			{
				sp++;
				if (curCode.getLevel() == 0) {
					addr = BAddr + curCode.getAddr();
				} else {
					addr = curCode.getAddr();
				}
				dstack[sp] = dstack[addr];
				at++;
			}
			else if (curCode.getName() == "LODS")
			{
				dstack[sp] = dstack[dstack[sp]];
				at++;
			}
			else if (curCode.getName() == "LDA")
			{
				sp++;
				if (curCode.getLevel() == 0) {
					addr = BAddr + curCode.getAddr();
				} else {
					addr = curCode.getAddr();
				}
				dstack[sp] = addr;
				at++;
			}
			else if (curCode.getName() == "LDC")
			{
				sp++;
				dstack[sp] = curCode.getAddr();
				at++;
			}
			else if (curCode.getName() == "STOS")
			{
				sp--;
				dstack[dstack[sp]] = dstack[sp + 1];
				sp--;
				at++;
			}
			else if (curCode.getName() == "ADD")
			{
				sp--;
				dstack[sp] = dstack[sp] + dstack[sp + 1];
				at++;
			}
			else if (curCode.getName() == "SUB")
			{
				sp--;
				dstack[sp] = dstack[sp] - dstack[sp + 1];
				at++;
			}
			else if (curCode.getName() == "MUL")
			{
				sp--;
				dstack[sp] = dstack[sp] * dstack[sp + 1];
				at++;
			}
			else if (curCode.getName() == "DIV")
			{
				sp--;
				dstack[sp] = dstack[sp] / dstack[sp + 1];
				at++;
			}
			else if (curCode.getName() == "MOD")
			{
				sp--;
				dstack[sp] = dstack[sp] % dstack[sp + 1];
				at++;
			}
			else if (curCode.getName() == "MINU")
			{
				dstack[sp] = -dstack[sp];
				at++;
			}
			else if (curCode.getName() == "GET")
			{
				int value;
				cin >> value;
				sp++;
				dstack[sp] = value;
				at++;
			}
			else if (curCode.getName() == "PRF")
			{
				string s = curCode.getPrint();
				// 문자열 내의 모든 따옴표(")를 제거합니다.
				s.erase(remove(s.begin(), s.end(), '\"'), s.end());
				// "%d"라는 서식 지정자의 개수를 세기 위한 변수를 초기화 합니다.
				int ci = count(s.begin(), s.end(), '%');
				// 스택 포인터를 "%d"의 개수만큼 뒤로 이동시킵니다.
				sp = sp - ci;
				// "%d"를 스택에서 가져온 숫자로 치환합니다.
				for (int i = 0; i < ci; i++) {
					size_t pos = s.find("%d");
					if (pos != string::npos) {
						// 스택에서 숫자를 가져와 문자열로 변환합니다.
						s.replace(pos, 2, to_string(dstack[sp + i + 1]));
					}
				}
				at++;
				// 문자열 내의 모든 "\\n"을 "\n"으로 교체해 줄바꿈 문자를 처리합니다.
				size_t pos = 0;
				while ((pos = s.find("\\n", pos)) != std::string::npos)
				{
					s.replace(pos, 2, "\n");
					pos += 1;
				}
				res.push_back(s);
			}
			else if (curCode.getName() == "JTM")
			{
				BAddr = sp + 1;
				at = curCode.getLabel()->getPoint();
			}
			else if (curCode.getName() == "CAL")
			{
				dstack[sp + 1] = 0;
				dstack[sp + 2] = BAddr;
				dstack[sp + 3] = at + 1;
				BAddr = sp + 1;
				sp = sp + 3;
				at = curCode.getAddr();
			}
			else if (curCode.getName() == "RET")
			{
				at = dstack[BAddr + 2];
				sp = BAddr;
				BAddr = dstack[BAddr + 1];
			}
			else if (curCode.getName() == "RET_TO_END")
			{
				at = codeList.size();
			}
			else if (curCode.getName() == "INT_L")
			{
				sp += curCode.getLabel()->getPoint();
				at++;
			}
			else
			{
				at++;
			}

			for (int i=0; i < 10; i++) {
                cout << dstack[i] << " ";
            }
            cout << "\n";
            cout << "BAddr = " << BAddr << "\n";
            cout << "at = " << at << "\n";
            cout << "sp = " << sp << "\n";
            cout << "\n\n";
        }
        return res;
    }
	void outputPCode(vector<string> interpret)
	{
		for (int i = 0; i < interpret.size();i++)
		{
			cout << interpret[i] << endl;
			pcodeOut << interpret[i] << endl;
		}
	}
};
int main(void) {
    init(); 
    Lexical_Analysis();
    Syntax_Analysis();
    outputError();

	cout << "=====================================" << endl;
	Interpreter interpreter;
	vector<string> interpret = interpreter.interpret();
	/* cout << interpret[0]; */
	interpreter.outputPCode(interpret);

	fclose(inputFile);
	inFile.close();
    fout.close();
    errorOut.close();
	pcodeOut.close();
	return 0;
}