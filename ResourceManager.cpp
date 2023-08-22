#include "ResourceManager.h"


ResourceManager ResourceManager::_instance = ResourceManager();


ResourceManager::ResourceManager()
{
}


sf::Font& ResourceManager::get_font(const std::string& name)
{
    if (_instance._fonts.find(name) == _instance._fonts.end())
    {
        _instance._fonts[name] = sf::Font();
        _instance._fonts[name].loadFromFile(name);
    }
    return _instance._fonts[name];
}


sf::Texture& ResourceManager::get_texture(const std::string& name)
{
    if (_instance._textures.find(name) == _instance._textures.end())
    {
        _instance._textures[name] = sf::Texture();
        _instance._textures[name].loadFromFile(name);
    }
    return _instance._textures[name];
}