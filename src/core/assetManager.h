#pragma once
#include <string>
#include <unordered_map>
#include <raylib.h>
#include <strings.h>


class AssetManager{
private:

    inline static std::unordered_map<std::string, Texture2D> m_asset;

public:

    AssetManager() = default;
    static void loadTexture2D( const std::string& hash_name, const std::string& asset_path );
    static const Texture2D* getTexture2D( const std::string& hash_name );
    static void unloadALLTexture2D();

};