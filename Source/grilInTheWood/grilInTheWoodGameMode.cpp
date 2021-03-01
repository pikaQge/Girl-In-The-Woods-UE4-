// Copyright Epic Games, Inc. All Rights Reserved.

#include "grilInTheWoodGameMode.h"
#include "grilInTheWoodPlayerController.h"
#include "grilInTheWoodCharacter.h"
#include "UObject/ConstructorHelpers.h"

AgrilInTheWoodGameMode::AgrilInTheWoodGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AgrilInTheWoodPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}