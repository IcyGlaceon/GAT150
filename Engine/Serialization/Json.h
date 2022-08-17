#pragma once
#include "rapidjson/document.h"
#include <string>

#define READ_DATA(value,data) cool::json::Get(value, #data, data);

namespace cool
{
	struct Vector2;
	struct Color;
}

namespace cool 
{
	namespace json
	{

		bool Load(const std::string& filename, rapidjson::Document& document);

		bool Get(const rapidjson::Value& value, const std::string& name, int& data);
		bool Get(const rapidjson::Value& value, const std::string& name, float& data);
		bool Get(const rapidjson::Value& value, const std::string& name, bool& data);
		bool Get(const rapidjson::Value& value, const std::string& name, std::string& data);
		bool Get(const rapidjson::Value& value, const std::string& name, Vector2& data);
		bool Get(const rapidjson::Value& value, const std::string& name, Color& data);
	}
}