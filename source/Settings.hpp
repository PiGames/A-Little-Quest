#pragma once

#include "fileManaging/INIparser.hpp"

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Simple extension for pi::INIFile class. To get settings simple use Get methods.

	===============================================================================
	*/
	class Settings final :
		public pi::INIFile
	{
	public:
		~Settings()
		{
			delete Settings::instance;
		}

		static Settings& GetInstance()
		{
			if ( !Settings::instance )
				Settings::instance = new Settings();
			return *Settings::instance;
		}

		void GenerateDefault( const std::string& path )
		{
			this->AddString( "WINDOW", "TITLE", "Platform Game" );
			this->AddInt( "WINDOW", "FPS", 64 );

			this->SaveToFile( path, "; Default config. Don't change if you don't know what are you doing!" );
		}

	private:
		static Settings* instance;
	};
}