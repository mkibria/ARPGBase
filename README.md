# ARPGBase
## A Starter Project Framework for an Action RPG Style game
This is a starter project/template to allow anyone to create a stats-driven action RPG-style game with a character leveling system and ability Unlock System.
The system will also have equipable weapons, armor, and a basic magic system. 

## Getting Started
Because of Github space limitations, Binaries are not included. Source files need to be built. You may need to:
1. Generate Visual Studio Project Files by Right Clicking on ARPGBase.uproject
2. Build the Visual Studio Project File through ARPGBase.sln

## Current Features
### Game Ability System
The Base character is configured to use the ability system and has a basic Attribute set with RPG-like stats. This combined with abilities allows for Damage calculations and modularized abilities that eventually will be able to be enabled and disabled based on the current context. The HP has been clamped between zero and an editable MAX HP that can be updated throughout the gameplay
### Damage sweep
Basic implementation to ensure that multiple overlap events do not deal multiple damage during a single attack. 
### Physical Animation (damage reaction)
Reduce the need to add manual animation for hit reactions. 
### Faction System
The game starter project has a faction system using Unreal Engines  for use in preventing friendly fire as well as for use  
### Pickups
Currently Have Health and Mana pickups that allow for the recovery of these stats.
## Features In Progress
### Ability Pickups
### Ability Addition and Removal
## Planned Features
### Inventory System
### Equipment System
### Physical Animation
* Knockback Effects based on Impulse Intensity
* Recovery after Falling
* Physically Blended Fall Reactions from varying Jump Heights

