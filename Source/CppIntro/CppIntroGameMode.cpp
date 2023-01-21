// Copyright Epic Games, Inc. All Rights Reserved.

#include "CppIntroGameMode.h"
#include "CppIntroCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACppIntroGameMode::ACppIntroGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
