cmake_minimum_required(VERSION 3.6)
project(Turn_based_battle)

# The version number
set (Turn_based_battle_VERSION_MAJOR 1)
set (Turn_based_battle_VERSION_MINOR 0)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/turn_based_battle/main.cpp src/turn_based_battle/Battle.cpp src/turn_based_battle/Battle.h
        src/turn_based_battle/Combatants/Npc_Enemies/Blob.cpp src/turn_based_battle/Combatants/Npc_Enemies/Blob.h
        src/turn_based_battle/Combatants/Combatant.cpp src/turn_based_battle/Combatants/Combatant.h
        src/turn_based_battle/Combatants/Player.cpp src/turn_based_battle/Combatants/Player.h
        src/turn_based_battle/stdafx.cpp src/turn_based_battle/stdafx.h src/turn_based_battle/TurnEffects/TurnEffect.cpp
        src/turn_based_battle/TurnEffects/TurnEffect.h src/turn_based_battle/TurnEffects/TurnEffect_Defend.cpp
        src/turn_based_battle/TurnEffects/TurnEffect_Defend.h src/turn_based_battle/TurnEffects/TurnEffect_Poison.cpp
        src/turn_based_battle/TurnEffects/TurnEffect_Poison.h src/turn_based_battle/Spells/Spell.cpp
        src/turn_based_battle/Spells/Spell.h src/turn_based_battle/Spells/Spell_PoisonCloud.cpp
        src/turn_based_battle/Spells/Spell_PoisonCloud.h src/turn_based_battle/Combatants/Npc_Enemies/Npc_Enemy.cpp
        src/turn_based_battle/Combatants/Npc_Enemies/Npc_Enemy.h
        src/turn_based_battle/Combatants/Npc_Friendlies/NPC_Friendly.cpp
        src/turn_based_battle/Combatants/Npc_Friendlies/NPC_Friendly.h src/turn_based_battle/Game.cpp
        src/turn_based_battle/Game.h)
add_executable(Turn_based_battle ${SOURCE_FILES})