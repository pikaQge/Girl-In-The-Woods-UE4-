// Copyright Epic Games, Inc. All Rights Reserved.

#include "grilInTheWoodPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "grilInTheWoodCharacter.h"
#include "Engine/World.h"


AgrilInTheWoodPlayerController::AgrilInTheWoodPlayerController()
{
	forwardVal = 0.0f;
	rightVal = 0.0f;
	mouseLFlag = false;
	mouseVal = 100000000.0f;
}

void AgrilInTheWoodPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MyPawn = Cast<AgrilInTheWoodCharacter>(GetPawn());
	walkSpeed = 10.0f;
}

void AgrilInTheWoodPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	// keep updating the destination every tick while desired

}

void AgrilInTheWoodPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("MouseL", IE_Pressed, this, &AgrilInTheWoodPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("MouseL", IE_Released, this, &AgrilInTheWoodPlayerController::OnSetDestinationReleased);
	InputComponent->BindAction("Space", IE_Pressed, this, &AgrilInTheWoodPlayerController::Jump);
	InputComponent->BindAction("F", IE_Pressed, this, &AgrilInTheWoodPlayerController::F_Pressed);
	InputComponent->BindAction("F", IE_Released, this, &AgrilInTheWoodPlayerController::F_Released);

	InputComponent->BindAxis("Forward", this, &AgrilInTheWoodPlayerController::Forward);
	InputComponent->BindAxis("Right", this, &AgrilInTheWoodPlayerController::Right);
	InputComponent->BindAxis("MouseR", this, &AgrilInTheWoodPlayerController::SeeToMouseR);
	InputComponent->BindAxis("MouseMid", this, &AgrilInTheWoodPlayerController::MouseWheelVal);
	
}

void AgrilInTheWoodPlayerController::Forward(float val)
{
	forwardVal = val;
	MyPawn->ForwardWalk(val * walkSpeed);
}

void AgrilInTheWoodPlayerController::Right(float val)
{
	rightVal = val;
	MyPawn->RightWalk(val * walkSpeed);
}

void AgrilInTheWoodPlayerController::Jump()
{
	MyPawn->Jump();
}


void AgrilInTheWoodPlayerController::SeeToMouseR(float val)
{
	if (val > 0.5f)
	{
		MyPawn->SeeTo();
		if (mouseLFlag) 
		{
			int skillVal = (int)mouseVal % 400 / 100;
			if (skillVal == 1)
			{
				MyPawn->Skill1();
			}
			else if (skillVal == 2)
			{
				MyPawn->Skill2();
			}
			else if (skillVal == 3)
			{
				MyPawn->Skill3();
			}
			else
			{
				MyPawn->Skill0();
			}
		}
	}
}

void AgrilInTheWoodPlayerController::MouseWheelVal(float val)
{
	mouseVal += val * 100;
}

void AgrilInTheWoodPlayerController::F_Pressed()
{
	keyFlag_F = true;
}

void AgrilInTheWoodPlayerController::F_Released()
{
	keyFlag_F = false;
}

void AgrilInTheWoodPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AgrilInTheWoodPlayerController::OnSetDestinationPressed()
{
	mouseLFlag = true;
}

void AgrilInTheWoodPlayerController::OnSetDestinationReleased()
{
	mouseLFlag = false;
}
