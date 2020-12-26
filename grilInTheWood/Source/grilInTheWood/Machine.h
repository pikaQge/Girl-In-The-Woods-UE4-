// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Machine.generated.h"

UCLASS()
class GRILINTHEWOOD_API AMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMachine();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool pulseOn;
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void ActivateMachine();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void InactivateMachine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
