#include "assetManager.h"


void AssetManager::loadTexture2D( const std::string& hash_name, const std::string& asset_path ){

    m_asset.insert({  hash_name, LoadTexture( asset_path.c_str() ) } );
}


const Texture2D* AssetManager::getTexture2D( const std::string& hash_name ) {

    if ( m_asset.contains( hash_name ) ) {

        return &m_asset.find( hash_name )->second;
    }
    else {

        return nullptr;
    }

}

void AssetManager::unloadALLTexture2D(){

    for (const auto& [name, _] : m_asset) {
        
        if ( getTexture2D( name ) != nullptr ) {
            
            UnloadTexture(  *(getTexture2D( name ) )  );
        }

    }
}

