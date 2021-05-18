#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <boost/smart_ptr.hpp>
#include <memory>
#include <iostream>
#include <boost/cast.hpp>
#include <boost/smart_ptr.hpp>
#include <cstdio>
#include <new>

#include <cstdio>
#include <memory>
#include <cerrno>

#pragma warning(disable:4996)

using FileGuard = std::shared_ptr<FILE>; 

struct Hal {
	Hal(const FileGuard file) :file{ file } {}
	~Hal() {
		fprintf(file.get(), "Im calling the cops.\n");
	};
	void write_status() const {
		fprintf(file.get(), "Not good at all...\n");
	};
	const FileGuard file;
};

void say_hello(FileGuard file) {
	fprintf(file.get(), "Like furries, huh?\n"); 
}
int main() {
	const auto file = fopen("ReadME.txt", "w");
	if (!file) return errno;
	const FileGuard file_guard{ file, fclose };
	// File open here
	Hal hal9000{ file_guard };
	say_hello(file_guard);
	hal9000.write_status();

}
