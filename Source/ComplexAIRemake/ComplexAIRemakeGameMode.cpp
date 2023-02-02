// Copyright Epic Games, Inc. All Rights Reserved.

#include "ComplexAIRemakeGameMode.h"
#include "ComplexAIRemakeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AComplexAIRemakeGameMode::AComplexAIRemakeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
