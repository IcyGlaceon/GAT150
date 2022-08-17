#include "File.h"
#include "Logger.h"
#include <filesystem>
#include <fstream>

namespace cool
{
	void SetFilePath(const std::string& pathname)
	{
		std::filesystem::current_path(pathname);
	}

	std::string GetFilePath()
	{
		return std::filesystem::current_path().string();
	}

	bool FileExists(const std::string& pathname)
	{
		return std::filesystem::exists(pathname);
	}
	
	bool GetFileSize(const std::string& pathname, size_t& size)
	{
		if (!FileExists(pathname)) return false;
		size = std::filesystem::file_size(pathname);

		return true;
	}
	
	bool ReadFile(const std::string& pathname, std::string& buffer)
	{
		if (!FileExists(pathname)) {
		
			LOG("Error NO FILE %s", pathname.c_str());
			return false;
		}
		//getting file size and setting buffer size
		size_t size;
		GetFileSize(pathname, size);
		buffer.resize(size);

		std::ifstream fstream(pathname);
		fstream.read(buffer.data(), size);
		fstream.close();



		return false;
	}
}


