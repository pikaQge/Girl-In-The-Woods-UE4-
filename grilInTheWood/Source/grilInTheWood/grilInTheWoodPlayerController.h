// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "grilInTheWoodCharacter.h"
#include "grilInTheWoodPlayerController.generated.h"

UCLASS()
class AgrilInTheWoodPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AgrilInTheWoodPlayerController();
	AgrilInTheWoodCharacter* MyPawn;
	FVector moveLocation;
	float walkSpeed;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	bool keyFlag_F;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	float forwardVal;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float rightVal;
	float mouseVal;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	bool mouseRFlag;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	int skillVal;

	FHitResult hit1;
	FHitResult hit2;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	

	// End PlayerController interface

	
	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	void Forward(float val);
	void Right(float val);
	void Jump();
	void SeeToMouseR(float val);
	void MouseWheelVal(float val);
	void F_Pressed();
	void F_Released();

	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
};


