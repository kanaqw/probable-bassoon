#include <windows.h>
#include <shellapi.h>
#include <string>

void SearchWeb()
{
	std::string base_URL = "https://www.youtube.com/watch?v=jFU3xBRZ8mc"//put your link in here;
	std::string search_URL = "dummy";
	search_URL = base_URL;

	ShellExecuteA(NULL, "open", search_URL.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

	int main() {
		SearchWeb();
	}
