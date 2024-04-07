﻿#pragma once

#include <vector>
#include <unordered_map>

#include <Vane/Config/ICVar.hpp>
#include <Vane/Utils/sid.hpp>

namespace Vane {

/**
 * @brief The registry for holding the map of `StringId`s 
 */
class CVarRegistry {
public:
    /**
     * @brief Registers the CVar into the map of base class ICVar
     *
     * @param cvar variable nameID and pointer to the value placed into the map
     */
    static inline void RegisterVariable(ICVar *cvar) {
        registry.emplace(cvar->nameID, cvar);
        keys.push_back(cvar->name);
    }

    /**
     * @brief Unregister the CVar from the map of base class ICVar
     * 
     * @param sid StringId of the CVar to be removed
     * @return true StringId was found in the map and removed
     * @return false StringId was not found in the map, cannot be removed
     */
    static inline bool UnregisterVariable(const StringId sid) { return registry.erase(sid); }

    /**
     * @brief Finds the CVar of StringId in the map
     * @param sid StringId of the CVar to find
     * @return ICVar* CVar of StringID
     * @return nullptr if StringId isn't found
     */
    inline ICVar *Find(const StringId sid) {
        auto it = registry.find(sid);
        if (it == registry.end()) { return nullptr; }
        return it->second;
    }


    inline std::vector<std::string_view> GetKeys() const { return keys; }

private:
    static std::unordered_map<StringId, ICVar *> registry;
    static std::vector<std::string_view> keys;
};
}
