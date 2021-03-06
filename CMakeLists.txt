cmake_minimum_required(VERSION 2.8)

project(srpg)

set(RuleBookCore
src/rulebook/Core/Dice.cpp src/rulebook/Core/Dice.h
src/rulebook/Core/RuleEngine.cpp src/rulebook/Core/RuleEngine.h)

set(RuleBookCreature
src/rulebook/Creatures/Abilities.cpp src/rulebook/Creatures/Abilities.h
src/rulebook/Creatures/Attack.cpp src/rulebook/Creatures/Attack.h
src/rulebook/Creatures/BaseSkills.cpp src/rulebook/Creatures/BaseSkills.h
src/rulebook/Creatures/Defence.cpp src/rulebook/Creatures/Defence.h
src/rulebook/Creatures/HitPoints.cpp src/rulebook/Creatures/HitPoints.h
src/rulebook/Creatures/RuleCharacter.cpp src/rulebook/Creatures/RuleCharacter.h
src/rulebook/Creatures/RuleCreature.cpp src/rulebook/Creatures/RuleCreature.h
src/rulebook/Creatures/SaveThrows.cpp src/rulebook/Creatures/SaveThrows.h)

set(RuleBookItems
src/rulebook/Items/Armor.cpp src/rulebook/Items/Armor.h
src/rulebook/Items/Inventory.cpp src/rulebook/Items/Inventory.h
src/rulebook/Items/Item.cpp src/rulebook/Items/Item.h
src/rulebook/Items/Shield.cpp src/rulebook/Items/Shield.h
src/rulebook/Items/Weapon.cpp src/rulebook/Items/Weapon.h)

set(RuleBookTests
test/RuleBookTests.cpp test/RuleBookTests.h
test/Core/RuleBookDiceTest.cpp test/Core/RuleBookDiceTest.h
test/Creatures/RuleBookAbilitiesTest.cpp test/Creatures/RuleBookAbilitiesTest.h)

set(CppUTest
/home/juhol/git/cpputest/include/CppUTest/MemoryLeakDetectorNewMacros.h
/home/juhol/git/cpputest/include/CppUTest/MemoryLeakDetectorMallocMacros.h)

find_library(CPPUTEST_LIBRARY NAMES CppUTest
            PATHS   /home/juhol/git/cpputest/lib)
            
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(rulebook ${RuleBookCore} ${RuleBookCreature} ${RuleBookItems} ${CppUTest} ${RuleBookTests})
target_link_libraries(rulebook ${CPPUTEST_LIBRARY})

install(TARGETS rulebook RUNTIME DESTINATION bin)