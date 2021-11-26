// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TTCharacter.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerStart.h"
#include "TTGameMode.generated.h"

UCLASS(minimalapi)
class ATTGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY()
	TSubclassOf<APlayerStart> PlayerStarts;

	UPROPERTY()
	TSubclassOf<class ATTCharacter> ToSpawn;


public:
	ATTGameMode();

	
};



