// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "grilInTheWoodCharacter.generated.h"

UCLASS(Blueprintable)
class AgrilInTheWoodCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	AgrilInTheWoodCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;
	
	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	UFUNCTION(BlueprintCallable)
	FVector GetCursorToWorld();
	void ForwardWalk(float val);
	void RightWalk(float val);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SeeTo();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void Skill0();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void Skill1();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void Skill2();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void Skill3();


	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	FTransform playerTransform;
	FHitResult hit;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FRotator CamRotation;


protected:
	virtual void BeginPlay() override;

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;

	
};

