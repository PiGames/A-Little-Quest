/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Logger/Logger.hpp"
#include "ResourceWrapper.hpp"

namespace pi
{
	using textureResource_t = ResourceWrapper<sf::Texture>;
	using fontResource_t = ResourceWrapper<sf::Font>;
	using uiTextResource_t = ResourceWrapper<sf::Text>;

	/*
	===============================================================================
	Created by: Condzi
		Static structure for resource managing. Initialize it before use and shutdown
		on the end of the program. To add resources use public vectors. To custom
		delete use DeleteAll... methods. To get resource, use Get... methods.

	===============================================================================
	*/
	struct ResourceHolder final
	{
		ResourceHolder() = delete;

		static std::vector<std::shared_ptr<textureResource_t>> textures;
		static std::vector<std::shared_ptr<uiTextResource_t>> texts;
		static std::vector<std::shared_ptr<fontResource_t>> fonts;

		static void Initialize();
		static void Shutdown();

		static void DeleteAllResources();
		static void DeleteAllResourcesByPriority( uint8_t priority );
		static void DeleteAllResourcesByID( uint8_t id );

		static std::weak_ptr<textureResource_t> GetTexture( uint8_t id );
		static std::weak_ptr<uiTextResource_t> GetText( uint8_t id );
		static std::weak_ptr<fontResource_t> GetFont( uint8_t id );
	};
}