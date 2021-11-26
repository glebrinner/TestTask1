// Copyright Epic Games, Inc. All Rights Reserved.

#include "TTGameMode.h"

#include "TTHUD.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ATTGameMode::ATTGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnOriginalCharacter(TEXT("/Game/FirstPersonCPP/Blueprints/OriginalCharacter"));
	DefaultPawnClass = PlayerPawnOriginalCharacter.Class;
	
	// use our custom HUD class
	HUDClass = ATTHUD::StaticClass();

}




