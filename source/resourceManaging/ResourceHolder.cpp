/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#include "ResourceHolder.hpp"

namespace pi
{
	std::vector<std::shared_ptr<textureResource_t>> ResourceHolder::textures;
	std::vector<std::shared_ptr<uiTextResource_t>> ResourceHolder::texts;
	std::vector<std::shared_ptr<fontResource_t>> ResourceHolder::fonts;


	void ResourceHolder::Initialize()
	{
		Logger::Log( "Resource Holder initialized!", Logger::BOTH, Logger::INFO );
	}

	void ResourceHolder::Shutdown()
	{
		ResourceHolder::DeleteAllResources();
		Logger::Log( "Resource Holder shutdown!", Logger::BOTH, Logger::INFO );
	}

	void ResourceHolder::DeleteAllResources()
	{
		Logger::Log( "Starting to delete all resources...", Logger::BOTH, Logger::INFO );
		Logger::Log( std::to_string( ResourceHolder::textures.size() ) + " Textures", Logger::BOTH, Logger::INFO );
		ResourceHolder::textures.clear();
		Logger::Log( std::to_string( ResourceHolder::texts.size() ) + " Texts", Logger::BOTH, Logger::INFO );
		ResourceHolder::texts.clear();
		Logger::Log( std::to_string( ResourceHolder::fonts.size() ) + " Fonts", Logger::BOTH, Logger::INFO );
		ResourceHolder::fonts.clear();
		Logger::Log( "All resources deleted!", Logger::BOTH, Logger::INFO );
	}

	void ResourceHolder::DeleteAllResourcesByPriority( uint8_t priority )
	{
		Logger::Log( "Starting to delete all resources of priority " + std::to_string( priority ), Logger::BOTH, Logger::INFO );

		uint16_t counter = 0;

		for ( auto textureIterator = ResourceHolder::textures.begin(); textureIterator != ResourceHolder::textures.end(); )
		{
			if ( ( *textureIterator )->GetResourcePriority() == priority )
			{
				textureIterator = ResourceHolder::textures.erase( textureIterator );
				counter++;
			} else
				textureIterator++;
		}
		for ( auto textsIterator = ResourceHolder::texts.begin(); textsIterator != ResourceHolder::texts.end(); )
		{
			if ( ( *textsIterator )->GetResourcePriority() == priority )
			{
				textsIterator = ResourceHolder::texts.erase( textsIterator );
				counter++;
			} else
				textsIterator++;
		}
		for ( auto fontIterator = ResourceHolder::fonts.begin(); fontIterator != ResourceHolder::fonts.end(); )
		{
			if ( ( *fontIterator )->GetResourcePriority() == priority )
			{
				fontIterator = ResourceHolder::fonts.erase( fontIterator );
				counter++;
			} else
				fontIterator++;
		}

		Logger::Log( std::to_string( counter ) + " resources of priority " + std::to_string( priority ) + " deleted", Logger::BOTH, Logger::INFO );
	}

	void ResourceHolder::DeleteAllResourcesByID( uint8_t id )
	{
		Logger::Log( "Starting to delete all resources of ID " + std::to_string( id ), Logger::BOTH, Logger::INFO );

		uint16_t counter = 0;

		for ( auto textureIterator = ResourceHolder::textures.begin(); textureIterator != ResourceHolder::textures.end(); )
		{
			if ( ( *textureIterator )->GetResourceID() == id )
			{
				textureIterator = ResourceHolder::textures.erase( textureIterator );
				counter++;
			} else
				textureIterator++;
		}
		for ( auto textsIterator = ResourceHolder::texts.begin(); textsIterator != ResourceHolder::texts.end(); )
		{
			if ( ( *textsIterator )->GetResourceID() == id )
			{
				textsIterator = ResourceHolder::texts.erase( textsIterator );
				counter++;
			} else
				textsIterator++;
		}
		for ( auto fontIterator = ResourceHolder::fonts.begin(); fontIterator != ResourceHolder::fonts.end(); )
		{
			if ( ( *fontIterator )->GetResourceID() == id )
			{
				fontIterator = ResourceHolder::fonts.erase( fontIterator );
				counter++;
			} else
				fontIterator++;
		}

		Logger::Log( std::to_string( counter ) + " resources of ID " + std::to_string( id ) + " deleted", Logger::BOTH, Logger::INFO );
	}

	std::weak_ptr<textureResource_t> ResourceHolder::GetTexture( uint8_t id )
	{
		for ( auto ptr : ResourceHolder::textures )
			if ( ptr->GetResourceID() == id )
				return ptr;

		Logger::Log( "Cannot find Texture of ID " + std::to_string( id ), Logger::BOTH, Logger::ERROR );
		return std::weak_ptr<textureResource_t>();
	}

	std::weak_ptr<uiTextResource_t> ResourceHolder::GetText( uint8_t id )
	{
		for ( auto ptr : ResourceHolder::texts )
			if ( ptr->GetResourceID() == id )
				return ptr;

		Logger::Log( "Cannot find Text of ID " + std::to_string( id ), Logger::BOTH, Logger::ERROR );
		return std::weak_ptr<uiTextResource_t>();
	}

	std::weak_ptr<fontResource_t> ResourceHolder::GetFont( uint8_t id )
	{
		for ( auto ptr : ResourceHolder::fonts )
			if ( ptr->GetResourceID() == id )
				return ptr;

		Logger::Log( "Cannot find Font of ID " + std::to_string( id ), Logger::BOTH, Logger::ERROR );
		return std::weak_ptr<fontResource_t>();
	}
}