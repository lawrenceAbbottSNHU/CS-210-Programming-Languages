#ifndef PYTHON_API_H
#define PYTHON_API_H

class PythonApi {
	public:
		void CallProcedure(string);
		int CallIntFunc(string, string);
		int CallIntFunc(string, int);
};

#endif