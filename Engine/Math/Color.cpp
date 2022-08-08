#include "Color.h"
#include <string>

namespace cool
{
	std::istream& operator >> (std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);

		std::string str;

		//red
		str = line.substr(line.find("{") + 1, line.find(",") - (line.find("{") + 1));
		color.r = (uint8_t)(std::stof(str) * 255);

		line = line.substr(line.find(",") + 1);

		//green
		str = line.substr(0, line.find(","));
		color.g = (uint8_t)(std::stof(str) * 255);

		//blue
		str = line.substr(line.find(",") + 1, line.find("}") - (line.find(",") + 1));
		color.b = (uint8_t)(std::stof(str) * 255);


		color.a = 255;

		return stream;
	}
}