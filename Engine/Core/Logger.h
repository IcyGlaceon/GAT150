#pragma once


namespace cool
{
	class Logger
	{
	public:
		Logger() = default;
		~Logger() = default;


		void Log(const char* format, ...);

	private:
	};

	extern Logger g_logger;
}