//This version only support Windows due to the use of conio.h.
//Hopefully, cross-platform support will be added in the future.
#include <iostream>
#include <deque>
#include <string>
#include <stack>
#include <map>
#include <conio.h>
#include <fstream>
#include <sstream>

using namespace std;

class BF_machine {
private :
	deque<int> mem;
	int mem_p;
	int code_p;
	int mem_size;
	int code_size;
	map<int, int> dic;

public :
	string code;
	bool number_mode;
	bool debug_mode;
	//if number_mode is true, input() and output() will deal with
	//decimal numbers separated by newlines, instead of ascii characters.

	BF_machine (string code, bool number_mode, bool debug_mode) {
		this->mem = deque<int>(16, 0);
		this->code = code;
		this->code_p = 0;
		this->mem_p = 8;
		this->mem_size = 16;
		this->code_size = code.size();
		this->number_mode = number_mode;
		this->debug_mode = debug_mode;
		stack<int> s;
		int depth = 0;
		int match;
		for (int i = 0; i < code_size; i++) {
			if (code[i] == '[') {
				depth++;
				s.push(i);
			}
			else if (code[i] == ']') {
				if (depth != 0) {
					match = s.top();
					s.pop();
					depth--;
				} else {
					match = 0;
				}
				this->dic.insert(make_pair(match, i));
				this->dic.insert(make_pair(i, match));
			}
		}
		while (!s.empty()) {
			match = s.top();
			s.pop();
			this->dic.insert(make_pair(match, code_size));
		}
	}

	void code_go_right() {
		if (code_p < code_size) {
			code_p++;
		}
	}

	void code_go_left() {
		if (0 <= code_p) {
			code_p--;
		}
	}

	void plus() {
		mem[mem_p]++;
		code_go_right();
	}

	void minus() {
		mem[mem_p]--;
		code_go_right();
	}

	void mem_go_right() {
		mem_p++;
		if (mem_p == mem_size) {
			mem.push_back(0);
			mem_size++;
		}
		code_go_right();
	}
	
	void mem_go_left() {
		if (mem_p == 0) {
			mem.push_front(0);
			mem_size++;
		} else {
			mem_p--;
		}
		code_go_right();
	}

	void output() {
		if (debug_mode) {
			cout << "output:";
		}
		if (number_mode)
			cout << mem[mem_p] << endl;
		else
			cout << (char)mem[mem_p];
		if (debug_mode) {
			cout << endl;
		}

		code_go_right();
	}

	void input() {
		int n;
		if (debug_mode) {
			cout << "\ninput:";
		}
		if (number_mode) {
			cin >> n;
		}
		else {
			n = getch();
		}
		if (debug_mode) {
			cout << endl;
		}
		mem[mem_p] = (int)n;
		code_go_right();
	}

	void loop_start() {
		if (mem[mem_p] == 0) {
			code_p = dic[code_p]+1;
		}
		else {
			code_p++;
		}
	}

	void loop_end() {
		if (mem[mem_p] != 0) {
			code_p = dic[code_p]+1;
		}
		else {
			code_p++;
		}
	}

	void run() {
		if (debug_mode) {
			cout << "#" << code << "#" << endl;
			cout << "code_size: " << code_size << endl;
			show_mem_state();
		}
		while (code_p < code_size) {
			if (debug_mode)
				show_code_state();
			if (code[code_p] == '+')
				plus();
			else if (code[code_p] == '-')
				minus();
			else if (code[code_p] == '>')
				mem_go_right();
			else if (code[code_p] == '<')
				mem_go_left();
			else if (code[code_p] == ',')
				input();
			else if (code[code_p] == '.')
				output();
			else if (code[code_p] == '[')
				loop_start();
			else if (code[code_p] == ']')
				loop_end();
			else
				code_go_right();
			if (debug_mode)
				show_mem_state();
		}
		code_go_left();
	}
	

	void show_code_state() {
		cout << endl << "code(" << code_p << "): " << code.substr(0, code_p) <<  " {{ " << code[code_p] << " }} " << code.substr(code_p+1) << endl;
	}

	void show_mem_state() {
		cout << "mem(" << mem_p << "): ";
		for (int i=0; i < mem_size; i++) {
			if (i == mem_p) {
				cout << " {" << mem[i] << "}";
			} else {
				cout << " " << mem[i];
			}
		}
		cout << endl;
	}
};

string help(string argv0) {
		stringstream ss;
	       	ss << "Usage: " << argv0 << " [options] file_name.bf [extra_file_names.bf ...]" << endl;
		ss << "Options:\n";
		ss << "\t-v, --version\tDisplay the version of the interpreter.\n";
		ss << "\t-h, --help\tDisplay this information.\n";
		ss << "\t-n, --number\tEnable number_mode so that the interpreter deals with decimal numbers separated by newlines, instead of ASCII characters. This is useful when executing programs written for arithmetic operations.\n";
		ss << "\t-d, --debug\tEnable debug_mode so that the interpreter displays every step of instruction execution.\n";
		return ss.str();
}

int main(int argc, char* argv[]) {
	bool number_mode = false;
	bool debug_mode = false;
	string file_path("");
	string argv0(argv[0]);
	string argvi;
	bool got_file_path = false;
	bool got_v_or_h = false;

	for (int i=1; i < argc; i++) {
		argvi = (string)argv[i];
		
		if (argvi == "-v" || argvi == "--version") {
			cout << "Haseon's C++ Brainfuck Interpreter version 0.1.0" << endl;
			got_v_or_h = true;
			return 0;
		}
		else if (argvi == "-h" || argvi == "--help") {
			cout << help(argv0);
			got_v_or_h = true;
			return 0;
		}
		else if (argvi == "-n" || argvi == "--number") {
			number_mode = true;
		}
		else if (argvi == "-d" || argvi == "debug") {
			debug_mode = true;
		}
		else if (argvi == "-nd" || argvi == "-dn") {
			number_mode = true;
			debug_mode = true;
		}
		else {
			if (got_file_path) {
				cerr << argv0 << ":Too many file arguments.\n";
				return 1;
			}
			file_path.append(argvi);
			got_file_path = true;
		}
	}

	if (!got_file_path && !got_v_or_h) {
		cerr << help(argv0);
		return 1;
	}

	ifstream open_file(file_path);
	string our_code;
	string code_to_run("");

	if ( open_file.is_open() ) {
		open_file.seekg(0, ios::end);
		int file_size = open_file.tellg();
		our_code.resize(file_size);
		open_file.seekg(0, ios::beg);
		open_file.read(&our_code[0], file_size);
	} else {
		cout << "No such file: " << file_path << endl;
		return 1;
	}

	char instr_set[] = { '+', '-', '>', '<', '.', ',', '[', ']'};
	for (int i=0; i < our_code.size(); i++) {
		for (int j=0; j < 8; j++) {
			if ( our_code[i] == instr_set[j] ) {
				code_to_run.push_back(our_code[i]);
			}
		}
	}

	BF_machine machine(code_to_run, number_mode, debug_mode);
	machine.run();

	return 0;
}
