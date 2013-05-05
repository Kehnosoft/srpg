CC = g++
BUILD = bin/srpg
CFLAGS = -c -g 
IDIR = src 
LIBS = -lSDLmain -lSDL -lSDL_image -lstdc++ -std=c++0x 

all: Armor.o Inventory.o Item.o Weapon.o Abilities.o Attack.o BaseSkills.o Character.o RuleCreature.o Defence.o HitPoints.o SaveThrows.o Dice.o RuleEngine.o  Fps.o Surface.o Entity.o Character.o Event.o Game.o main.o
	$(CC) *.o -o $(BUILD) $(LIBS)

Armor.o: src/rulebook/Items/Armor.cpp src/rulebook/Items/Armor.h
	$(CC) $(CFLAGS) src/rulebook/Items/Armor.cpp

Inventory.o: src/rulebook/Items/Inventory.cpp src/rulebook/Items/Inventory.h
	$(CC) $(CFLAGS) src/rulebook/Items/Inventory.cpp

Item.o: src/rulebook/Items/Item.cpp src/rulebook/Items/Item.h
	$(CC) $(CFLAGS) src/rulebook/Items/Item.cpp

Weapon.o: src/rulebook/Items/Weapon.cpp src/rulebook/Items/Weapon.h
	$(CC) $(CFLAGS) src/rulebook/Items/Weapon.cpp

Abilities.o: src/rulebook/Creatures/Abilities.cpp src/rulebook/Creatures/Abilities.h
	$(CC) $(CFLAGS) src/rulebook/Creatures/Abilities.cpp

Attack.o: src/rulebook/Creatures/Attack.cpp src/rulebook/Creatures/Attack.h
	$(CC) $(CFLAGS) src/rulebook/Creatures/Attack.cpp

BaseSkills.o: src/rulebook/Creatures/BaseSkills.cpp src/rulebook/Creatures/BaseSkills.h
	$(CC) $(CFLAGS) src/rulebook/Creatures/BaseSkills.cpp

RuleCharacter.o: src/rulebook/Creatures/RuleCharacter.cpp src/rulebook/Creatures/RuleCharacter.h
	$(CC) $(CFLAGS) src/rulebook/Creatures/RuleCharacter.cpp

RuleCreature.o: src/rulebook/Creatures/RuleCreature.cpp src/rulebook/Creatures/RuleCreature.h
	$(CC) $(CFLAGS) src/rulebook/Creatures/RuleCreature.cpp

Defence.o: src/rulebook/Creatures/Defence.cpp src/rulebook/Creatures/Defence.h
	$(CC) $(CFLAGS) src/rulebook/Creatures/Defence.cpp

HitPoints.o: src/rulebook/Creatures/HitPoints.cpp src/rulebook/Creatures/HitPoints.h
	$(CC) $(CFLAGS) src/rulebook/Creatures/HitPoints.cpp

SaveThrows.o: src/rulebook/Creatures/SaveThrows.cpp src/rulebook/Creatures/SaveThrows.h
	$(CC) $(CFLAGS) src/rulebook/Creatures/SaveThrows.cpp

Dice.o: src/rulebook/Core/Dice.cpp src/rulebook/Core/Dice.h
	$(CC) $(CFLAGS) src/rulebook/Core/Dice.cpp

RuleEngine.o: src/rulebook/Core/RuleEngine.cpp src/rulebook/Core/RuleEngine.h
	$(CC) $(CFLAGS) src/rulebook/Core/RuleEngine.cpp

Game.o: src/engine/Game.cpp src/engine/Game.h
	$(CC) $(CFLAGS) src/engine/Game.cpp

Event.o: src/engine/Event.cpp src/engine/Event.h
	$(CC) $(CFLAGS) src/engine/Event.cpp

Entity.o: src/engine/Entity.cpp src/engine/Entity.h
	$(CC) $(CFLAGS) src/engine/Entity.cpp

Character.o: src/engine/Character.cpp src/engine/Character.h
	$(CC) $(CFLAGS) src/engine/Character.cpp

Surface.o: src/engine/renderer/Surface.cpp src/engine/renderer/Surface.h
	$(CC) $(CFLAGS) src/engine/renderer/Surface.cpp

Fps.o: src/engine/renderer/Fps.cpp src/engine/renderer/Fps.h
	$(CC) $(CFLAGS) src/engine/renderer/Fps.cpp

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp

clean:
	del *.o
