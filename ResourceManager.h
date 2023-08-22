#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>


class ResourceManager
{
public:
    ResourceManager(const ResourceManager&) = delete;

    static sf::Font& get_font(const std::string& name);
    static sf::Texture& get_texture(const std::string& name);

private:
    ResourceManager();

    static ResourceManager _instance;

    std::unordered_map<std::string, sf::Font> _fonts;
    std::unordered_map<std::string, sf::Texture> _textures;
};