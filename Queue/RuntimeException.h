#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
using std::ostream;
#include <string>
using std::string;
class RuntimeException
{
private:
	string errorMsg;
public:
	RuntimeException(const string& err) { errorMsg = err; }
	string getMessage() const { return errorMsg; }
};
inline ostream& operator<<(ostream& out, const RuntimeException& e) { return out << e.getMessage(); }

class QueueEmpty : public RuntimeException {
public:
	QueueEmpty(const string& err) :RuntimeException(err) {}
};

class QueueFull : public RuntimeException {
public:
	QueueFull(const string& err) :RuntimeException(err) {}
};

#endif
