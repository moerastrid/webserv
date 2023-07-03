#include <sys/socket.h>
#include <iostream>

using namespace std;

int main() {
	int fd = socket(AF_UNIX, SOCK_RAW, 0);

	cout << fd << endl;
}