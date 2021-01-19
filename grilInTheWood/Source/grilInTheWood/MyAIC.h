// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIC.generated.h"

/**
 * 
 */
UCLASS()
class GRILINTHEWOOD_API AMyAIC : public AAIController
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	FVector playerPosition;

public:
	AMyAIC();
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
	
};
