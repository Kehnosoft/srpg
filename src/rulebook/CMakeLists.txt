cmake_minimum_required(VERSION 2.8)

project(rulebook)

set(RuleBookCore
Core/Dice.cpp Core/Dice.h
Core/RuleEngine.cpp Core/RuleEngine.h)

set(RuleBookCreature
Creatures/Abilities.cpp Creatures/Abilities.h
Creatures/Attack.cpp Creatures/Attack.h
Creatures/BaseSkills.cpp Creatures/BaseSkills.h
Creatures/Defence.cpp Creatures/Defence.h
Creatures/HitPoints.cpp Creatures/HitPoints.h
Creatures/RuleCharacter.cpp Creatures/RuleCharacter.h
Creatures/RuleCreature.cpp Creatures/RuleCreature.h
Creatures/SaveThrows.cpp Creatures/SaveThrows.h)

set(RuleBookItems
Items/Armor.cpp Items/Armor.h
Items/Inventory.cpp Items/Inventory.h
Items/Item.cpp Items/Item.h
Items/Shield.cpp Items/Shield.h
Items/Weapon.cpp Items/Weapon.h)

set(RuleBookTests
Tests/RuleBookTests.h
Tests/Core/RuleBookDiceTest.cpp Tests/Core/RuleBookDiceTest.h
Tests/Creatures/RuleBookAbilitiesTest.cpp Tests/Creatures/RuleBookAbilitiesTest.h)

set(RuleBookMain main.cpp)

set(CppUTest
/home/juhol/git/cpputest/include/CppUTest/MemoryLeakDetectorNewMacros.h
/home/juhol/git/cpputest/include/CppUTest/MemoryLeakDetectorMallocMacros.h)

find_library(CPPUTEST_LIBRARY NAMES CppUTest
            PATHS   /home/juhol/git/cpputest/lib)
            
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(rulebook ${RuleBookCore} ${RuleBookCreature} ${RuleBookItems} ${CppUTest} ${RuleBookTests} ${RuleBookMain})
target_link_libraries(rulebook ${CPPUTEST_LIBRARY})

install(TARGETS rulebook RUNTIME DESTINATION bin)